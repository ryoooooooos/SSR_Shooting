#pragma once
// 必要ファイルのインクルード
#include "../../../System/Image/Image.h"
//
// ネームスペース
namespace furukawa {
	// プレイヤー画像の種類
	enum class PLAYER_IMG_TYPE {
		BOTAN,
		LAMY,
		NENE,
		POLKA,
		MAX
	};
	// プレイヤー画像クラス
	class PlayerImages {
	public:
		/* コンストラクタ・デストラクタ */
		PlayerImages(); // コンストラクタ
		~PlayerImages(); // デストラクタ				 
		//　getImagePointerを呼び出す前に必ず実行すること
		HRESULT loadImages()const;
		//　各ステージ毎に使いまわす画像のImageポインタを返す
		Image* getImagePointer(PLAYER_IMG_TYPE n)const;
	private:
		PLAYER_IMG_TYPE mNumOfImage;
		Image** mppImages;
	};
}