// �K�v�t�@�C���̃C���N���[�h
#include "PlayerImages.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	PlayerImages::PlayerImages()
		: mNumOfImage(PLAYER_IMG_TYPE::MAX)
		, mppImages(nullptr)
	{
		mppImages = new Image * [static_cast<int>(PLAYER_IMG_TYPE::MAX)];
		mppImages[static_cast<int>(PLAYER_IMG_TYPE::BOTAN)] = new Image("Images/Player/Botan.png");
		mppImages[static_cast<int>(PLAYER_IMG_TYPE::LAMY)] = new Image("Images/Player/Lamy.png");
		mppImages[static_cast<int>(PLAYER_IMG_TYPE::NENE)] = new Image("Images/Player/Nene.png");
		mppImages[static_cast<int>(PLAYER_IMG_TYPE::POLKA)] = new Image("Images/Player/Polka.png");
	}
	// �f�X�g���N�^
	PlayerImages::~PlayerImages() {
		for (int i = 0; i < static_cast<int>(PLAYER_IMG_TYPE::MAX); i++) {
			delete(mppImages[i]);
		}
		delete mppImages;
	}
	//�@getImagePointer���Ăяo���O�ɕK�����s���邱��
	HRESULT PlayerImages::loadImages()const {
		for (auto i = 0; i < static_cast<int>(mNumOfImage); i++) {
			if (FAILED(mppImages[i]->load())) {
				return E_FAIL;
			}
		}
		return S_OK;
	}
	//�@�e�X�e�[�W���Ɏg���܂킷�摜��Image�|�C���^��Ԃ�
	Image* PlayerImages::getImagePointer(PLAYER_IMG_TYPE n)const {
		assert(static_cast<PLAYER_IMG_TYPE>(0) <= n && n < mNumOfImage);
		return mppImages[static_cast<int>(n)];
	}
}