#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../../System/Keyboard/Keyboard.h"
#include "../../Images/PlayerImages/PlayerImages.h"
#include "../../../System/Sound/Sound.h"
#include "../Base/Object.h"
#include "../Bullet/Bullet.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �v���C���[�N���X
	class Player : public Object {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Player(); // �R���X�g���N�^
		~Player(); // �f�X�g���N�^
		/* �֐� */
		HRESULT init()override; // ������
		void update(); // �X�V
		void moveUp(); // ��ړ�
		void moveDown(); // ���ړ�
		void shotBullet(); // �e����
		void EarnPosession(const int level); // �������Q�b�g����
		void WeaponLevelUp(); // ���탌�x�����グ��
		void Damage(); // �_���[�W���󂯂�
		void Heal(); // �̗͂��񕜂���
		void draw()const override; // �`��
		/* �A�N�Z�T */
		Bullet* getBulletPointer(const int index)const; // �w�肵���Y�����̒e�N���X��Ԃ�
		void setPosession(const int p); // ���������Z�b�g
		int getPosession()const; // ��������Ԃ�
		int getWeaponLevel()const; // ���탌�x����Ԃ�
		int getWeaponLevelUpCost()const; // ���탌�x���A�b�v�ɕK�v�ȃR�X�g��Ԃ�
		int getBulletPower()const; // �U���͂�Ԃ�
		int getLife()const; // �̗͂�Ԃ�
		int getHealCost()const; // �̗͉񕜂ɕK�v�ȃR�X�g��Ԃ�
	private:
		/* �ϐ� */
		PlayerImages* mpImages; // �摜�N���X
		Bullet** mppBullet; // �e�N���X
		Sound* mpShotSound; // �e�̔��ˉ�
		PLAYER_IMG_TYPE mImgType; // �摜�^�C�v
		int CurrentLane; // ���݂̃��[���|�W�V����
		int Life; // �̗�
		int HealTime; // �̗͂��񕜂�����
		int HealCost; // �̗͉񕜂ɕK�v�ȃR�X�g
		int WeaponLevel; // ���탌�x��
		int WeaponLevelUpCost; // ���탌�x���㏸�ɕK�v�ȃR�X�g
		int BulletPower; // �e�̍U����
		int Posession; // ������
	};
}