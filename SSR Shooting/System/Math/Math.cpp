// �K�v�t�@�C���̃C���N���[�h
#include "Math.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �덷�͈͓��ł̓��l��r
	bool Math::Equal(float x, float y) {
		return fabs(x - y) <= FloatError * max(1, max(fabs(x), fabs(y)));
	}
}