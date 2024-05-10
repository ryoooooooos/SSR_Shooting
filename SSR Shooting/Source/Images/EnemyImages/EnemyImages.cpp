// �K�v�t�@�C���̃C���N���[�h
#include "EnemyImages.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	EnemyImages::EnemyImages()
		: mNumOfImage(ENEMY_IMG_TYPE::MAX)
		, mppImages(nullptr)
	{
		mppImages = new Image * [static_cast<int>(ENEMY_IMG_TYPE::MAX)];
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::KORONESUKI)] = new Image("Images/Enemy/KoroneSuki.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::MATSURISU)] = new Image("Images/Enemy/Matsurisu.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::MINIORUYANKE)] = new Image("Images/Enemy/MiniOruyanke.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::ONIGIRYA)] = new Image("Images/Enemy/Onigirya.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::ORUYANKE)] = new Image("Images/Enemy/Oruyanke.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::PEKORA)] = new Image("Images/Enemy/Pekora.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::ROBOKOARM)] = new Image("Images/Enemy/RobokoArm.png");
		mppImages[static_cast<int>(ENEMY_IMG_TYPE::SUBARUDODUCK)] = new Image("Images/Enemy/SubaruDoDuck.png");
	}
	// �f�X�g���N�^
	EnemyImages::~EnemyImages() {
		for (int i = 0; i < static_cast<int>(ENEMY_IMG_TYPE::MAX); i++) {
			delete(mppImages[i]);
		}
		delete mppImages;
	}
	//�@getImagePointer���Ăяo���O�ɕK�����s���邱��
	HRESULT EnemyImages::loadImages()const {
		for (auto i = 0; i < static_cast<int>(mNumOfImage); i++) {
			if (FAILED(mppImages[i]->load())) {
				return E_FAIL;
			}
		}
		return S_OK;
	}
	//�@�e�X�e�[�W���Ɏg���܂킷�摜��Image�|�C���^��Ԃ�
	Image* EnemyImages::getImagePointer(ENEMY_IMG_TYPE n)const {
		assert(static_cast<ENEMY_IMG_TYPE>(0) <= n && n < mNumOfImage);
		return mppImages[static_cast<int>(n)];
	}
}