#pragma once
// 必要ファイルのインクルード
#include "../../../System/Image/Image.h"
//
// ネームスペース
namespace furukawa {
	// プレイヤー画像の種類
	enum class ENEMY_IMG_TYPE {
		KORONESUKI,
		MATSURISU,
		MINIORUYANKE,
		ONIGIRYA,
		ORUYANKE,
		PEKORA,
		ROBOKOARM,
		SUBARUDODUCK,
		MAX
	};
	// プレイヤー画像クラス
	class EnemyImages {
	public:
		/* コンストラクタ・デストラクタ */
		EnemyImages(); // コンストラクタ
		~EnemyImages(); // デストラクタ				 
		//　getImagePointerを呼び出す前に必ず実行すること
		HRESULT loadImages()const;
		//　各ステージ毎に使いまわす画像のImageポインタを返す
		Image* getImagePointer(ENEMY_IMG_TYPE n)const;
	private:
		ENEMY_IMG_TYPE mNumOfImage;
		Image** mppImages;
	};
}