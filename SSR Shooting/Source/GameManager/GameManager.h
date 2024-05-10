#pragma once
// 必要ファイルのインクルード
#include <cstdlib>
#include <ctime>
#include "DxLib.h"
#include "../../System/Keyboard/Keyboard.h"
#include "../Parameter/Parameter.h"
#include "../Scene/Base/Scene.h"
#include "../Scene/Title/Title.h"
//
// ネームスペース
namespace furukawa {
	//
	// 監督クラス
	class GameManager {
	public:
		/* コンストラクタ・デストラクタ */
		GameManager(); // コンストラクタ
		~GameManager(); // デストラクタ
		// GameManagerはコピー不可
		GameManager(const GameManager& scene) = delete;
		const GameManager& operator= (const GameManager& rhs) = delete;
		/* 関数 */
		void run();// 実行
		/* アクセサ */
		void setScore(const int s); // スコアをセット
		int getScore()const; // スコアを返す
	private:
		/* 関数 */
		HRESULT init(); // 初期化
		void final(); // 終了
		HRESULT gameLoop(); // ゲームループ
		/* 変数 */
		Scene* mpScene; // シーンクラス
		int Score; // スコア
	};
}