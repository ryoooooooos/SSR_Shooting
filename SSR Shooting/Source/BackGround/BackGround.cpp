// �K�v�t�@�C���̃C���N���[�h
#include "BackGround.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	BackGround::BackGround(const char* fileName)
		: mpImage(new Image(fileName))
		, mPos(Vector2(0.0f, 0.0f))
	{
	}
	// �f�X�g���N�^
	BackGround::~BackGround() {
		delete mpImage;
	}
	// �`��
	void BackGround::draw()const {
		DrawGraph(static_cast<int>(mPos.mX), static_cast<int>(mPos.mY), mpImage->getImgNo(), TRUE);
	}
	// ������
	HRESULT BackGround::init() {
		if (FAILED(mpImage->load())) {
			return E_FAIL;
		}
		return S_OK;
	}
}