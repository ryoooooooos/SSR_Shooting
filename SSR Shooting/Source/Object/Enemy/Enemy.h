#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../Images/EnemyImages/EnemyImages.h"
#include "../Base/Object.h"
#include "../Bullet/Bullet.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �G�N���X
	class Enemy : public Object {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Enemy(); // �R���X�g���N�^
		~Enemy(); // �f�X�g���N�^
		/* �֐� */
		HRESULT init()override; // ������
		void update(); // �X�V
		void appear(const int level); // �o��
		void UpdateLife(const int damage); // �G�̗̑͂��X�V
		void draw()const override; // �`��
		/* �A�N�Z�T */
		int getLife()const; // �̗͂�Ԃ�
		void setIsVisible(const bool t_or_f); // �o���t���O���Z�b�g
		bool getIsVisible()const; // �o���t���O��Ԃ�
		Vector2 getPos()const; // ���W��Ԃ�
	private:
		/* �ϐ� */
		EnemyImages* mpImages; // �摜�N���X
		ENEMY_IMG_TYPE mImgType; // �摜�^�C�v
		int Life; // �̗�
		int CurrentFrame; // ���݂̃t���[����
		int CurrentAnimation; // �A�j���[�V��������Ă���摜
		bool isVisible; // �o���t���O
	};
}