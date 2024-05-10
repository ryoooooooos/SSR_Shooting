// �K�v�t�@�C���̃C���N���[�h
#include "Image.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Image::Image(const char* fileName)
		: mpFileName(std::string(fileName))
		, mImgNo(-1)
	{
	}
	// �f�X�g���N�^
	Image::~Image() {
		if (mImgNo >= 0) {
			DeleteGraph(mImgNo);
		}
	}
	// �摜�t�@�C���̃��[�h
	HRESULT Image::load() {
		auto str = mpFileName.data();
		if ((mImgNo = LoadGraph(str)) == -1) {
			FILE_NOT_FOUND(str);
			return E_FAIL;
		}
		return S_OK;
	}
	// �摜No��Ԃ�
	int Image::getImgNo()const {
		return mImgNo;
	}
}