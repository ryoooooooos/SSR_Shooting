// 必要ファイルのインクルード
#include "EnemyImages.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
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
	// デストラクタ
	EnemyImages::~EnemyImages() {
		for (int i = 0; i < static_cast<int>(ENEMY_IMG_TYPE::MAX); i++) {
			delete(mppImages[i]);
		}
		delete mppImages;
	}
	//　getImagePointerを呼び出す前に必ず実行すること
	HRESULT EnemyImages::loadImages()const {
		for (auto i = 0; i < static_cast<int>(mNumOfImage); i++) {
			if (FAILED(mppImages[i]->load())) {
				return E_FAIL;
			}
		}
		return S_OK;
	}
	//　各ステージ毎に使いまわす画像のImageポインタを返す
	Image* EnemyImages::getImagePointer(ENEMY_IMG_TYPE n)const {
		assert(static_cast<ENEMY_IMG_TYPE>(0) <= n && n < mNumOfImage);
		return mppImages[static_cast<int>(n)];
	}
}