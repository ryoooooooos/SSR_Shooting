// �K�v�t�@�C���̃C���N���[�h
#include "EnemyManagement.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	EnemyManagement::EnemyManagement() 
		: EnemyProbability(-1)
		, EnemyLevel(-1)
		, EnemyDefeatCount(-1)
	{
	}
	// �f�X�g���N�^
	EnemyManagement::~EnemyManagement() {

	}
	// ������
	void EnemyManagement::init() {
		EnemyProbability = EnemyParameter::MaxProbability;
		EnemyLevel = 1;
		EnemyDefeatCount = 0;
	}
	// �G��|�������ɌĂяo��
	void EnemyManagement::update() {
		// �G��|���������C���N�������g
		EnemyDefeatCount++;
		// �G�̃��x�����グ�A�o���m����������
		if (EnemyDefeatCount >= EnemyParameter::LevelUpInterval) {
			EnemyLevel++;
			EnemyDefeatCount = 0;
			EnemyProbability -= EnemyParameter::ProbabilityDecrease;
			// �o���m���͍Œ�ł�1
			if (EnemyProbability <= 0) {
				EnemyProbability = 1;
			}

			// 10���x�����Ƃɏo���m���������l�Ƀ��Z�b�g
			if (EnemyLevel % 10 == 0) {
				EnemyProbability = EnemyParameter::MaxProbability;
			}
		}
	}
	// �G�̏o���m����Ԃ�
	int EnemyManagement::getEnemyProbability()const {
		return EnemyProbability;
	}
	// �G�̃��x����Ԃ�
	int EnemyManagement::getEnemyLevel()const {
		return EnemyLevel;
	}
}