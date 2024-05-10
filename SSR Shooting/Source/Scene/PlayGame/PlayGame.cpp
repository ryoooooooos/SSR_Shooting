// �K�v�t�@�C���̃C���N���[�h
#include "PlayGame.h"
// Scene.h �� GameManager�N���X ��s���S�^�Œ�`���Ă��邽�߁A���g���킩��Ȃ�
// ���̂��߁A���ꂼ��̃V�[���� Gamemanager.h ���C���N���[�h��
// GameManager�N���X �̒��g��c���ł���悤�ɂ���B
#include "../../GameManager/GameManager.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	PlayGame::PlayGame(GameManager* pGameManager) 
		: Scene(pGameManager)
		, NormalFontHandle(-1)
		, mpPlayer(nullptr)
		, mppEnemy(nullptr)
		, mpEnemyManagement(nullptr)
		, mpWeaponImage(nullptr)
		, mpLifeImage(nullptr)
	{
	}
	// �f�X�g���N�^
	PlayGame::~PlayGame() {
		// �v���C���[
		delete mpPlayer;

		// �G
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			delete(mppEnemy[i]);
		}
		delete mppEnemy;

		// �G�Ǘ�
		delete mpEnemyManagement;
	}
	// ������
	HRESULT PlayGame::init() {
		// �w�i
		mpBackground = new BackGround("Images/BackGround.jpg");
		if (FAILED(mpBackground->init())) {
			return E_FAIL;
		}

		// ���y
		mpSound = new Sound("Sounds/BattleBGM.wav");
		if (FAILED(mpSound->init())) return E_FAIL;

		// �v���C���[
		mpPlayer = new Player();
		if (FAILED(mpPlayer->init())) return E_FAIL;

		// �G
		mppEnemy = new Enemy * [EnemyParameter::NumOfEnemy];
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			mppEnemy[i] = new Enemy();
			if (FAILED(mppEnemy[i]->init())) return E_FAIL;
		}

		// �G�Ǘ�
		mpEnemyManagement = new EnemyManagement();
		mpEnemyManagement->init();

		// ����摜
		mpWeaponImage = new Image("Images/Weapon.png");
		if(FAILED(mpWeaponImage->load())) return E_FAIL;

		// ���C�t�摜
		mpLifeImage = new Image("Images/Heart.png");
		if (FAILED(mpLifeImage->load())) return E_FAIL;

		// �X�R�A��������
		mpGameManager->setScore(0);

		// �t�H���g�T�C�Y
		NormalFontHandle = CreateFontToHandle(NULL, Parameter::NormalFontSize, Parameter::FontThick);

		return S_OK;
	}
	// ���s
	Scene* PlayGame::run() {
		input();
		update();
		draw();
		return mpNextScene;
	}
	// ����
	void PlayGame::input() {
		// �v���C���[�̏�ړ�
		if (mKey.isKeyPush(KeyType::W)) {
			mpPlayer->moveUp();
		}
		// �v���C���[�̉��ړ�
		if (mKey.isKeyPush(KeyType::S)) {
			mpPlayer->moveDown();
		}
		// �e����
		if (mKey.isKeyPush(KeyType::SPACE)) {
			mpPlayer->shotBullet();
		}
		// ���탌�x���A�b�v
		if (mKey.isKeyPush(KeyType::E)) {
			mpPlayer->WeaponLevelUp();
		}
		// ��
		if (mKey.isKeyPush(KeyType::R)) {
			mpPlayer->Heal();
		}
	}
	// �X�V
	void PlayGame::update() {
		// ���y�̍Đ�
		mpSound->loop();
		
		// �v���C���[�̍X�V
		mpPlayer->update();

		// �G�̍X�V
		updateEnemy();

		// �����蔻��
		HitCheck();
	}
	// �G�̍X�V
	void PlayGame::updateEnemy() {
		// �G�̏o��
		if ((rand() % mpEnemyManagement->getEnemyProbability()) == 0) {
			for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
				// �o�����Ă��Ȃ��G���o��������
				if (!mppEnemy[i]->getIsVisible()) {
					mppEnemy[i]->appear(mpEnemyManagement->getEnemyLevel());
					break; // ��̏o���������甲����
				}
			}
		}

		// �G�̍��W��A�j���[�V�����̍X�V
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			// �o�����Ă���G�̂�
			if (mppEnemy[i]->getIsVisible()) {
				mppEnemy[i]->update();
				// �G���_���[�W���󂯂����ɂ�����
				if (static_cast<int>(mppEnemy[i]->getPos().mX) <= Parameter::DamageLine - EnemyParameter::ImageSize / 2) {
					// �G�̏o���t���O�����낷
					mppEnemy[i]->setIsVisible(false);
					// �_���[�W���󂯂�
					mpPlayer->Damage();
					// ���C�t�� 0 �ɂȂ����烊�U���g��ʂ�
					if (mpPlayer->getLife() <= 0) {
						mpNextScene = new GameResult(mpGameManager);
					}
				}
			}
		}
	}
	// �����蔻��
	void PlayGame::HitCheck() {
		// �e�ƓG�̓����蔻��
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			// �e�N���X���Ăяo��
			auto bullet = mpPlayer->getBulletPointer(i);

			// ���˂��Ă��Ȃ�������X�L�b�v
			if (!bullet->getIsVisible()) continue;

			// �G
			for (int j = 0; j < EnemyParameter::NumOfEnemy; j++) {
				// �G�N���X
				auto enemy = mppEnemy[j];

				// �o�����Ă��Ȃ�������X�L�b�v
				if (!enemy->getIsVisible()) continue;

				// �����蔻��`�F�b�N
				if (isHit(bullet->getPos(), enemy->getPos(), PlayerParameter::BulletImageSize / 2, EnemyParameter::ImageSize / 2)) {
					
					// �e�̏o���t���O�����낷
					bullet->setIsVisible(false);

					// �G�̗͍̑X�V
					enemy->UpdateLife(mpPlayer->getBulletPower());
					
					// �G�̗̑͂� 0 �ȉ��ɂȂ�����X�R�A�̍X�V
					if (enemy->getLife() <= 0) {
						// �G�̏o���t���O�����낷
						enemy->setIsVisible(false);

						// �������Q�b�g����
						mpPlayer->EarnPosession(mpEnemyManagement->getEnemyLevel());

						// �G��|�����̂ŌĂяo��
						mpEnemyManagement->update();

						// �X�R�A�̍X�V
						UpdateScore();
					}
				}
			}
		}
	}

	// �����蔻��
	bool PlayGame::isHit(const Vector2& v1, const Vector2& v2, const int r1, const int r2) {
		// �߂�l
		bool result = false;

		// 2�_�Ԃ̋����𑪂�
		auto dPos = v1 - v2;
		auto d = sqrtf((dPos.mX * dPos.mX) + (dPos.mY * dPos.mY));

		// �������Ă����� true
		if (d <= static_cast<float>(r1 + r2)) {
			result = true;
		}

		return result;
	}

	// �X�R�A�̍X�V
	void PlayGame::UpdateScore() {
		// ���݂̃X�R�A���擾
		auto score = mpGameManager->getScore();

		// �V���ɃX�R�A�����Z
		auto level = mpEnemyManagement->getEnemyLevel();
		score += Parameter::InitScore + (level - 1) * Parameter::ScoreUpRate;

		// �X�R�A�����Ƃɖ߂�
		mpGameManager->setScore(score);
	}

	// �`��
	void PlayGame::draw()const {
		ClearDrawScreen(); // ����ʂ��N���A

		mpBackground->draw(); // �w�i

		// ��؂��
		MyDrawLine();

		// �G
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			// �o�����Ă���G�̂ݕ`��
			if (mppEnemy[i]->getIsVisible()) {
				mppEnemy[i]->draw();
			}
		}

		// �v���C���[
		mpPlayer->draw();

		// ���C�t�摜
		DrawLife();

		// ����摜
		DrawWeapon();

		// �X�R�A
		DrawScore();

		// �������
		DrawInstruction();

		ScreenFlip(); // ����ʂƕ\��ʂ����ւ���
	}
	// ��؂���̕`��
	void PlayGame::MyDrawLine()const {
		int drawX, drawY;

		// �X�R�A�ƃv���C��ʂ̋�؂��
		drawY = Parameter::NormalFontSize;
		DrawLine(0, drawY, Parameter::WindowWidth, drawY, ColorParameter::Black, Parameter::LineThickNess);

		// �A�C�e�����ƃv���C��ʂ̋�؂��
		drawX = Parameter::DamageLine;
		DrawLine(drawX, Parameter::NormalFontSize, drawX, Parameter::WindowHeight, ColorParameter::Black, Parameter::LineThickNess);

		// ���[���̕`��
		for (int i = 1; i <= Parameter::NumOfLine; i++) {
			drawY = Parameter::NormalFontSize + Parameter::LaneInterval * i;
			DrawLine(Parameter::DamageLine, drawY, Parameter::WindowWidth, drawY, ColorParameter::Black, Parameter::LineThickNess);
		}
	}
	// ���C�t�֘A�̕`��
	void PlayGame::DrawLife()const {
		// �`����W
		auto left = Parameter::ImagePosAdjust; // ���[
		auto top = Parameter::ImagePosAdjust * 4; // ��[
		auto right = Parameter::ImagePosAdjust * 3; // �E�[
		auto bottom = Parameter::ImagePosAdjust * 6; // ���[
		
		// �`��
		DrawExtendGraph(left, top, right, bottom, mpLifeImage->getImgNo(), TRUE); // �摜
		//�̗͉񕜂ɕK�v�ȃR�X�g
		DrawFormatStringToHandle(left, bottom, ColorParameter::Black, NormalFontHandle, "[E]%dz", mpPlayer->getHealCost());
	}
	// ����֘A�̕`��
	void PlayGame::DrawWeapon()const {
		// �`����W
		auto left = Parameter::ImagePosAdjust; // ���[
		auto top = Parameter::ImagePosAdjust; // ��[
		auto right = Parameter::ImagePosAdjust * 4; // �E�[
		auto bottom = Parameter::ImagePosAdjust * 3; // ���[
		
		// ���탌�x��
		auto level = mpPlayer->getWeaponLevel();

		// �`��
		DrawExtendGraph(left / 4, top, right, bottom, mpWeaponImage->getImgNo(), TRUE); // �摜
		// ����̃��x���A�b�v�ɕK�v�ȃR�X�g
		DrawFormatStringToHandle(left, bottom, ColorParameter::Black, NormalFontHandle, "Lv.%d��Lv.%d\n[R]%dz", level, level + 1, mpPlayer->getWeaponLevelUpCost());
	}
	// ��������̕`��
	void PlayGame::DrawInstruction()const {
		DrawStringToHandle(0, Parameter::ImagePosAdjust * 8, "[W][S]�ړ�\n[SPACE]�e����", ColorParameter::Black, NormalFontHandle);
	}
	// �X�R�A�̕`��
	void PlayGame::DrawScore()const {
		DrawFormatStringToHandle(0, 0, ColorParameter::Black, NormalFontHandle,
			"�G���x�� %d�@������ %dz�@�X�R�A %d�@���C�t %d",
			mpEnemyManagement->getEnemyLevel(), mpPlayer->getPosession(),
			mpGameManager->getScore(), mpPlayer->getLife());
	}
}