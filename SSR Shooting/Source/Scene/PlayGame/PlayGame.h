#pragma once
// 必要ファイルのインクルード
#include "../../Object/Player/Player.h"
#include "../../Object/Enemy/Enemy.h"
#include "../../EnemyManagement/EnemyManagement.h"
#include "../GameResult/GameResult.h"
#include "../Base/Scene.h"
#include "../../Parameter/Parameter.h"
//
// ネームスペース
namespace furukawa {
	// ゲームクラス
	class PlayGame : public Scene
	{
	public:
		/* コンストラクタ・デストラクタ */
		PlayGame(GameManager* pGameManager); // コンストラクタ
		~PlayGame(); // デストラクタ
		/* 関数 */
		HRESULT init()override; // 初期化
		Scene* run()override; // 実行
	private:
		/* 関数 */
		void input(); // 入力
		void update(); // 更新
		void updateEnemy(); // 敵の更新
		void HitCheck(); // 当たり判定
		bool isHit(const Vector2& v1, const Vector2& v2, const int r1, const int r2); // 当たり判定チェック
		void UpdateScore(); // スコアの更新
		void draw()const; // 描画
		void MyDrawLine()const; // 区切り線の描画
		void DrawLife()const; // ライフ関連の描画
		void DrawWeapon()const; // 武器関連の描画
		void DrawInstruction()const; // 操作説明の描画
		void DrawScore()const; // スコアの描画
		/* 変数 */
		int NormalFontHandle; // フォントサイズ(中)
		Player* mpPlayer; // プレイヤー
		Enemy** mppEnemy; // 敵
		EnemyManagement* mpEnemyManagement; // 敵のレベル管理
		Image* mpLifeImage; // ライフ画像
		Image* mpWeaponImage; // 
	};
}