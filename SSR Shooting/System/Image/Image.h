#pragma once
// 必要ファイルのインクルード
#include <Windows.h>
#include <string>
#include "DxLib.h"
#include "../Vector2/Vector2.h"
#include "../Macro/Macro.h"
//
// ネームスペース
namespace furukawa {
	// 画像クラス
	class Image {
	public:
		// コンストラクタ
		Image(const char* fileName);
		// デストラクタ
		~Image();
		// 画像ファイルのロード
		// drawメソッドを呼び出す前に必ず呼び出すこと。
		HRESULT load();
		// 画像Noを返す
		int getImgNo()const;
	private:
		// 画像ファイル名　
		// ポインタにすると、
		// 利点：メモリ節約
		// 欠点：2重解放対策をしなくてはいけない
		// 欠点が利点を上回るため、実体で保持
		std::string mpFileName;
		// 画像No（DxlibのLoadGraph関数の戻り値)
		int mImgNo;
	};
}//furukawa
//EOF