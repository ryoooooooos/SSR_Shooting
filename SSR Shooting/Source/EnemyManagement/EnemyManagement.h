#pragma once
// 必要ファイルのインクルード
#include "../Parameter/Parameter.h"
//
// ネームスペース
namespace furukawa {
	// 敵管理クラス
	class EnemyManagement
	{
	public:
		/* コンストラクタ・デストラクタ */
		EnemyManagement(); // コンストラクタ
		~EnemyManagement(); // デストラクタ
		/* 関数 */
		void init(); // 初期化(画像処理等をしないのでvoid)
		void update(); // 敵を倒した時に呼び出す
		/* アクセサ */
		int getEnemyProbability()const; // 敵の出現確率を返す
		int getEnemyLevel()const; // 敵のレベルを返す
	private:
		/* 変数 */
		int EnemyProbability; // 敵の出現確率
		int EnemyLevel; // 敵のレベル
		int EnemyDefeatCount; // 敵を倒した数(敵のレベルに用いる)
	};
}