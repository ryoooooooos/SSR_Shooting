#pragma once
// 必要ファイルのインクルード
#include "../Title/Title.h"
#include "../Base/Scene.h"
//
// ネームスペース
namespace furukawa {
	// 結果発表クラス
	class GameResult : public Scene {
	public:
		/* コンストラクタ・デストラクタ */
		GameResult(GameManager* pGameManager); // コンストラクタ
		~GameResult(); // でエストラクタ
		/* 関数 */
		HRESULT init()override; // 初期化
		Scene* run()override; // 実行
	private:
		/* 関数 */
		void input(); // 入力
		void update(); // 更新
		void draw(); // 描画
		void MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle);
		/* 変数 */
		int SceneChangeTimer; // タイトル画面遷移後、経過した時間
		int BigFontHandle; // フォントハンドル(大)
		int SmallFontHandle; // フォントハンドル(小)
	};
}