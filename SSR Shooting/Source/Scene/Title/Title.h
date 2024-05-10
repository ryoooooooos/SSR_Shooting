#pragma once
// 必要ファイルのインクルード
#include "../PlayGame/PlayGame.h"
#include "../Base/Scene.h"
#include "../../Parameter/Parameter.h"
//
// ネームスペース
namespace furukawa {
	// タイトルクラス
	class Title : public Scene
	{
	public:
		/* コンストラクタ・デストラクタ */
		Title(GameManager* pGameManager); // コンストラクタ
		~Title(); // デストラクタ
		/* 関数 */
		HRESULT init()override; // シーン毎の初期化
		Scene* run()override; // シーンの実行
	private:
		/* 関数 */
		void input(); // 入力
		void update(); // 更新
		void draw(); // 描画
		void MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle);
		/* 変数 */
		int GamePlayCount; // 実行後、プレイした回数
		int SceneChangeTimer; // タイトル画面遷移後、経過した時間
		int BigFontHandle; // フォントハンドル(大)
		int SmallFontHandle; // フォントハンドル(小)
	};
}