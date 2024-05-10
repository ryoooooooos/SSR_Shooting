// �K�v�t�@�C���̃C���N���[�h
#include "Enemy.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Enemy::Enemy()
		: Object()
		, mpImages(nullptr)
		, mImgType(static_cast<ENEMY_IMG_TYPE>(-1))
		, Life(-1)
		, CurrentFrame(-1)
		, CurrentAnimation(-1)
		, isVisible(false)
	{
	}
	// �f�X�g���N�^
	Enemy::~Enemy() {
		delete mpImages;
	}
	// ������
	HRESULT Enemy::init() {
		// �v���C���[�摜
		mpImages = new EnemyImages();
		if (FAILED(mpImages->loadImages())) {
			return E_FAIL;
		}

		// �̗�
		Life = EnemyParameter::InitLife;

		// �A�j���[�V�����֘A
		CurrentFrame = CurrentAnimation = 0;

		// �o���t���O
		isVisible = false;

		return S_OK;
	}
	// �X�V
	void Enemy::update() {
		// �A�j���[�V������i�߂�
		CurrentFrame++;
		// ���̉摜��
		if (CurrentFrame >= EnemyParameter::AnimationPerFrame) {
			CurrentAnimation++;
			CurrentFrame = 0;
			// �ŏ��̉摜�ɖ߂�
			if (CurrentAnimation >= EnemyParameter::NumOfAnimation) {
				CurrentAnimation = 0;
			}
		}

		// �G�̈ړ�
		pos.mX -= EnemyParameter::MoveSpeed;
	}
	// �`��
	void Enemy::draw()const {
		auto image = mpImages->getImagePointer(mImgType);
		DrawRectGraph(static_cast<int>(pos.mX), static_cast<int>(pos.mY),
			EnemyParameter::ImageSize * CurrentAnimation, 0,
			EnemyParameter::ImageSize, EnemyParameter::ImageSize,
			image->getImgNo(), TRUE);
	}
	// �o��
	void Enemy::appear(const int level) {
		// �v���C���[�摜�������_���Ō��߂�
		mImgType = static_cast<ENEMY_IMG_TYPE>(rand() % static_cast<int>(ENEMY_IMG_TYPE::MAX));

		// �o���ʒu�������_���Ō��߂�
		int Lane = rand() % (Parameter::NumOfLane + 1);

		// ���W
		pos.mX = static_cast<float>(Parameter::WindowWidth);
		pos.mY = static_cast<float>(EnemyParameter::InitY + Parameter::LaneInterval * Lane);

		// �̗�
		Life = EnemyParameter::InitLife + (level - 1) * EnemyParameter::LifeUpRate;

		// �o���t���O�𗧂Ă�
		isVisible = true;
	}
	// �G�̗̑͂̍X�V
	void Enemy::UpdateLife(const int damage) {
		Life -= damage;
	}
	// �̗͂�Ԃ�
	int Enemy::getLife()const {
		return Life;
	}
	// �o���t���O���Z�b�g
	void Enemy::setIsVisible(const bool t_or_f) {
		isVisible = t_or_f;
	}
	// �o���t���O��Ԃ�
	bool Enemy::getIsVisible()const {
		return isVisible;
	}
	// ���W��Ԃ�
	Vector2 Enemy::getPos()const {
		return pos;
	}
}