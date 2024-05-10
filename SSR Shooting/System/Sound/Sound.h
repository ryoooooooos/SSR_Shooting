#pragma once
// 必要ファイルのインクルード
#include <string>
#include "DxLib.h"
#include "../Macro/Macro.h"
//
// ネームスペース
namespace furukawa {
	// 音楽クラス
	class Sound
	{
	public:
		/* コンストラクタ・デストラクタ */
		Sound(const char* FileName); // コンストラクタ
		~Sound(); // デストラクタ
		/* 関数 */
		HRESULT init(); // 音楽ファイルのロード
		void play()const; // 音楽の通常再生
		void loop()const; // 音楽のループ再生
	private:
		/* 変数 */
		std::string mpFileName; // 音楽ファイル名
		int mHandle; // 音楽ハンドル
	};
}