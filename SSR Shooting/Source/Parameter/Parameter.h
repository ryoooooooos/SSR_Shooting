#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "DxLib.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �萔�N���X
	class Parameter {
	public:
		// �E�C���h�E�֘A
		static constexpr int WindowWidth = 960; // �E�B���h�E��
		static constexpr int WindowHeight = 640; // �E�B���h�E����
		static constexpr int ColorBit = 32;	// 1�s�N�Z��������̃r�b�g��(32�r�b�g�J���[)

		// �^�C�g���֘A
		static constexpr int MinSceneChangeTimer = 40; // �^�C�g������J�ڂ���܂ł̍Œ�҂�����

		// ������֘A
		static constexpr int BigFontSize = 75; // �t�H���g�T�C�Y(��)
		static constexpr int NormalFontSize = 30; // �t�H���g�T�C�Y(��)
		static constexpr int SmallFontSize = 20; // �t�H���g�T�C�Y(��)
		static constexpr int FontThick = 5; // �����̑���

		// �Q�[���֘A
		static constexpr int NumOfLane = 11; // ���[���̐�
		static constexpr int LineThickNess = 5; // ���[������؂���̑���
		static constexpr int NumOfLine = 12; // ���[������؂���̐�
		static constexpr int DamageLine = 250; // �G���G�ꂽ�Ƃ��ɑ̗͂�������̈ʒu
		static constexpr int LaneInterval = 50; // ���Ɛ��̊Ԋu
		static constexpr int InitScore = 100; // ���炦��X�R�A�̊�b�l
		static constexpr int ScoreUpRate = 25; // ���x�����オ�邲�Ƃɑ�����X�R�A�̏㏸�l

		// �摜�֘A
		static constexpr int LifeImageWidth = 420; // HP�摜��
		static constexpr int LifeImageHeight = 360; // HP�摜����
		static constexpr int WeaponImageWidth = 56; // ����摜��
		static constexpr int WeaponImageHeight = 40; // ����摜����
		static constexpr int ImagePosAdjust = 50; // �摜�̈ʒu����
	};

	// �F�֘A
	class ColorParameter {
	public:
		static const unsigned int White; // ��
		static const unsigned int Black; // ��
		static const unsigned int Red; // ��
		static const unsigned int Blue; // ��
		static const unsigned int Green; // ��
		static const unsigned int Yellow; // ��
	};

	// �v���C���[�֘A
	class PlayerParameter {
	public:
		static constexpr int ImageSize = 48; // �v���C���[�摜�̑傫��
		static constexpr int InitX = 250; // �v���C���[�̏����ʒu(x���W)
		static constexpr int InitY = 32; // �v���C���[�̏����ʒu(y���W)
		static constexpr int MaxLife = 3; // �ő�̗�
		static constexpr int InitHealCost = 3000; // �̗͉񕜂ɕK�v�Ȃ���
		static constexpr int BulletImageSize = 48; // �e�摜�̑傫��
		static constexpr float BulletSpeed = 5.0f; // �e�̑��x
		static constexpr int InitWeaponLevelUpCost = 500; // ���탌�x���A�b�v�ɕK�v�Ȃ���
		static constexpr int InitBulletPower = 20; // �e�̊�b�U����
		static constexpr int BulletPowerRate = 20; // ���x�����オ�邲�ƂɐG���U���͂̏㏸��
		static constexpr int NumOfBullet = 100; // �e�̍ő吔
	};

	// �G�֘A
	class EnemyParameter {
	public:
		static constexpr int ImageSize = 48; // �G�摜�̑傫��
		static constexpr int InitX = Parameter::WindowWidth; // �G�̏����ʒu(x���W)
		static constexpr int InitY = 32; // �G�̏����ʒu(y���W)
		static constexpr float MoveSpeed = 0.5f; // �G�̈ړ����x
		static constexpr int AnimationPerFrame = 20; // �A�j���[�V��������t���[����
		static constexpr int NumOfAnimation = 3; // �A�j���[�V��������摜�̖���
		static constexpr int NumOfEnemy = 25; // �G�̍ő吔
		static constexpr int LevelUpInterval = 15; // ���x�����オ��Ԋu
		static constexpr int MaxProbability = 100; // �G�̏o���m��
		static constexpr int ProbabilityDecrease = 5; // �G�̏o���m���̌�����
		static constexpr int InitLife = 50; // �̗͂̊�b�l
		static constexpr int LifeUpRate = 20; // ���x�����オ�邲�Ƃɑ�����̗͂̏㏸�l
		static constexpr int InitPosession = 70; // ���Ƃ������̊�b�l
		static constexpr int PosessionUpRate = 25; // ���x�����オ�邲�Ƃɑ����邨���̏㏸�l
	};
}