#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../Parameter/Parameter.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �G�Ǘ��N���X
	class EnemyManagement
	{
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		EnemyManagement(); // �R���X�g���N�^
		~EnemyManagement(); // �f�X�g���N�^
		/* �֐� */
		void init(); // ������(�摜�����������Ȃ��̂�void)
		void update(); // �G��|�������ɌĂяo��
		/* �A�N�Z�T */
		int getEnemyProbability()const; // �G�̏o���m����Ԃ�
		int getEnemyLevel()const; // �G�̃��x����Ԃ�
	private:
		/* �ϐ� */
		int EnemyProbability; // �G�̏o���m��
		int EnemyLevel; // �G�̃��x��
		int EnemyDefeatCount; // �G��|������(�G�̃��x���ɗp����)
	};
}