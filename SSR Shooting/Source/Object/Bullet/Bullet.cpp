// �K�v�t�@�C���̃C���N���[�h
#include "Bullet.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Bullet::Bullet(const char* FileName)
		: Object()
		, mpImage(new Image(FileName))
		, pos(Vector2(0.0f, 0.0f))
		, isVisible(false)
	{
	}
	// �f�X�g���N�^
	Bullet::~Bullet() {
		delete mpImage;
	}
	// ������
	HRESULT Bullet::init() {
		// �摜
		if (FAILED(mpImage->load())) {
			return E_FAIL;
		}

		// �o���t���O
		isVisible = false;

		return S_OK;
	}
	// �X�V
	void Bullet::update() {
		// �e�̈ړ�
		pos.mX += PlayerParameter::BulletSpeed;
		// �e�̏o���t���O�����낷
		if (pos.mX >= Parameter::WindowWidth) {
			isVisible = false;
		}
	}
	// �o��
	void Bullet::appear(const Vector2& v) {
		pos = v;
		isVisible = true;
	}
	// �`��
	void Bullet::draw()const {
		DrawGraph(static_cast<int>(pos.mX), static_cast<int>(pos.mY), mpImage->getImgNo(), TRUE);
	}
	// ���W��Ԃ�
	Vector2 Bullet::getPos()const {
		return pos;
	}
	// �o���t���O���Z�b�g
	void Bullet::setIsVisible(const bool t_or_f) {
		isVisible = t_or_f;
	}
	// �o���t���O��Ԃ�
	bool Bullet::getIsVisible()const {
		return isVisible;
	}
}
