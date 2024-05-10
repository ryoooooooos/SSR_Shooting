// 必要ファイルのインクルード
#include "EnemyManagement.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	EnemyManagement::EnemyManagement() 
		: EnemyProbability(-1)
		, EnemyLevel(-1)
		, EnemyDefeatCount(-1)
	{
	}
	// デストラクタ
	EnemyManagement::~EnemyManagement() {

	}
	// 初期化
	void EnemyManagement::init() {
		EnemyProbability = EnemyParameter::MaxProbability;
		EnemyLevel = 1;
		EnemyDefeatCount = 0;
	}
	// 敵を倒した時に呼び出す
	void EnemyManagement::update() {
		// 敵を倒した数をインクリメント
		EnemyDefeatCount++;
		// 敵のレベルを上げ、出現確率をあげる
		if (EnemyDefeatCount >= EnemyParameter::LevelUpInterval) {
			EnemyLevel++;
			EnemyDefeatCount = 0;
			EnemyProbability -= EnemyParameter::ProbabilityDecrease;
			// 出現確率は最低でも1
			if (EnemyProbability <= 0) {
				EnemyProbability = 1;
			}

			// 10レベルごとに出現確率を初期値にリセット
			if (EnemyLevel % 10 == 0) {
				EnemyProbability = EnemyParameter::MaxProbability;
			}
		}
	}
	// 敵の出現確率を返す
	int EnemyManagement::getEnemyProbability()const {
		return EnemyProbability;
	}
	// 敵のレベルを返す
	int EnemyManagement::getEnemyLevel()const {
		return EnemyLevel;
	}
}