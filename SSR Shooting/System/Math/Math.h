#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include <Windows.h>
#include <cmath>
#include <algorithm>
//
// �l�[���X�y�[�X
namespace furukawa {
	// ���w�N���X
	class Math {
	public:
		/* �֐� */
		// ���Ό덷(FloatError*max(1,max(x,y))�j�͈̔͂�2�̒l�����������𔻒�
		static bool Equal(float x, float y);
		/* �ϐ� */
		// float�̌덷
		static constexpr float FloatError = 0.00001f;
	};
}