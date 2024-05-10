// �K�v�t�@�C���̃C���N���[�h
#include "Player.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Player::Player()
		: Object()
		, mpImages(nullptr)
		, mppBullet(nullptr)
		, mpShotSound(nullptr)
		, mImgType(static_cast<PLAYER_IMG_TYPE>(-1))
		, CurrentLane(-1)
		, Life(-1)
		, HealTime(-1)
		, HealCost(-1)
		, WeaponLevel(-1)
		, BulletPower(-1)
		, WeaponLevelUpCost(-1)
		, Posession(-1)
	{

	}
	// �f�X�g���N�^
	Player::~Player() {
		// �摜�N���X
		delete mpImages;

		// �e�N���X
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			delete(mppBullet[i]);
		}
		delete mppBullet;

		// �e�̔��ˉ��N���X
		delete mpShotSound;
	}
	// ������
	HRESULT Player::init() {
		// �v���C���[�摜
		mpImages = new PlayerImages();
		if (FAILED(mpImages->loadImages())) {
			return E_FAIL;
		}

		// �e
		mppBullet = new Bullet * [PlayerParameter::NumOfBullet];
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			mppBullet[i] = new Bullet("Images/Bullet.png");
			if (FAILED(mppBullet[i]->init())) {
				return E_FAIL;
			}
		}

		// �e�̔��ˉ�
		mpShotSound = new Sound("Sounds/ShotSound.mp3");
		if (FAILED(mpShotSound->init())) {
			return E_FAIL;
		}

		// ���݂̃��[���|�W�V����
		CurrentLane = 0;

		// ���W
		pos.mX = PlayerParameter::InitX;
		pos.mY = PlayerParameter::InitY;

		// �̗�
		Life = PlayerParameter::MaxLife;

		// �̗͂��񕜂�����
		HealTime = 0;

		// ���탌�x��
		WeaponLevel = 1;

		// �U����
		BulletPower = PlayerParameter::InitBulletPower;

		// ������
		Posession = 0;

		// �R�X�g
		HealCost = PlayerParameter::InitHealCost;
		WeaponLevelUpCost = PlayerParameter::InitWeaponLevelUpCost;

		// �v���C���[�摜�������_���Ō��߂�
		mImgType = static_cast<PLAYER_IMG_TYPE>(rand() % static_cast<int>(PLAYER_IMG_TYPE::MAX));

		return S_OK;
	}
	// �X�V
	void Player::update() {
		// ���W�̍X�V
		pos.mY = static_cast<float>(PlayerParameter::InitY + Parameter::LaneInterval * CurrentLane);
	
		// �e�̍X�V
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			// �o�����Ă���e�̂ݍX�V
			if (mppBullet[i]->getIsVisible()) {
				mppBullet[i]->update();
			}
		}
	}
	// �`��
	void Player::draw()const {
		// �e
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			// �o�����Ă���e�̂ݕ`��
			if (mppBullet[i]->getIsVisible()) {
				mppBullet[i]->draw();
			}
		}

		// �v���C���[
		auto image = mpImages->getImagePointer(mImgType);
		DrawGraph(static_cast<int>(pos.mX), static_cast<int>(pos.mY), image->getImgNo(), TRUE);
	}
	// ��ړ�
	void Player::moveUp() {
		CurrentLane--;
		// �O�ɏo�Ȃ��悤�ɂ���
		if (CurrentLane < 0) CurrentLane++;
	}
	// ���ړ�
	void Player::moveDown() {
		CurrentLane++;
		// �O�ɏo�Ȃ��悤�ɂ���
		if (CurrentLane > Parameter::NumOfLane) CurrentLane--;
	}
	// �e����
	void Player::shotBullet() {
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			if (!mppBullet[i]->getIsVisible()) {
				mppBullet[i]->appear(pos);
				mpShotSound->play();
				break; // ��o������I��
			}
		}
	}
	// �������Q�b�g����
	void Player::EarnPosession(const int level) {
		Posession += EnemyParameter::InitPosession + (level - 1) * EnemyParameter::PosessionUpRate;
	}
	// ���탌�x�����グ��
	void Player::WeaponLevelUp() {
		// �\���ɂ������������烌�x�����グ��
		if (Posession >= WeaponLevelUpCost) {
			WeaponLevel++;
			// �������g��
			Posession -= WeaponLevelUpCost;
			// �U���͂��X�V
			BulletPower = PlayerParameter::InitBulletPower + (WeaponLevel - 1) * PlayerParameter::BulletPowerRate;
			// �R�X�g���X�V
			WeaponLevelUpCost = PlayerParameter::InitWeaponLevelUpCost * WeaponLevel;
		}
	}
	// �_���[�W���󂯂�
	void Player::Damage() {
		Life--;
	}
	// �̗͂��񕜂���
	void Player::Heal() {
		// �̗͂��ő傶��Ȃ���Ή�
		if (Life < PlayerParameter::MaxLife) {
			// �\���ɂ��������������
			if (Posession >= HealCost) {
				Life++;
				// �񕜉񐔂��C���N�������g
				HealTime++;
				// �������g��
				Posession -= HealCost;
				// �R�X�g���X�V
				HealCost = PlayerParameter::InitHealCost * (HealTime + 1);
			}
		}
	}
	// �w�肵���Y�����̒e�N���X��Ԃ�
	Bullet* Player::getBulletPointer(const int index)const {
		return mppBullet[index];
	}
	// ���������Z�b�g
	void Player::setPosession(const int p) {
		Posession = p;
	}
	// ��������Ԃ�
	int Player::getPosession()const {
		return Posession;
	}
	// ���탌�x����Ԃ�
	int Player::getWeaponLevel()const {
		return WeaponLevel;
	}
	// ����̃��x���A�b�v�ɕK�v�ȃR�X�g��Ԃ�
	int Player::getWeaponLevelUpCost()const {
		return WeaponLevelUpCost;
	}
	// �U���͂�Ԃ�
	int Player::getBulletPower()const {
		return BulletPower;
	}
	// �̗͂�Ԃ�
	int Player::getLife()const {
		return Life;
	}
	// �̗͉񕜂ɕK�v�ȃR�X�g��Ԃ�
	int Player::getHealCost()const {
		return HealCost;
	}
}