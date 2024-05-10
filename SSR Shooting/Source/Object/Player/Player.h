#pragma once
// 必要ファイルのインクルード
#include "../../../System/Keyboard/Keyboard.h"
#include "../../Images/PlayerImages/PlayerImages.h"
#include "../../../System/Sound/Sound.h"
#include "../Base/Object.h"
#include "../Bullet/Bullet.h"
//
// ネームスペース
namespace furukawa {
	// プレイヤークラス
	class Player : public Object {
	public:
		/* コンストラクタ・デストラクタ */
		Player(); // コンストラクタ
		~Player(); // デストラクタ
		/* 関数 */
		HRESULT init()override; // 初期化
		void update(); // 更新
		void moveUp(); // 上移動
		void moveDown(); // 下移動
		void shotBullet(); // 弾発射
		void EarnPosession(const int level); // お金をゲットする
		void WeaponLevelUp(); // 武器レベルを上げる
		void Damage(); // ダメージを受ける
		void Heal(); // 体力を回復する
		void draw()const override; // 描画
		/* アクセサ */
		Bullet* getBulletPointer(const int index)const; // 指定した添え字の弾クラスを返す
		void setPosession(const int p); // 所持金をセット
		int getPosession()const; // 所持金を返す
		int getWeaponLevel()const; // 武器レベルを返す
		int getWeaponLevelUpCost()const; // 武器レベルアップに必要なコストを返す
		int getBulletPower()const; // 攻撃力を返す
		int getLife()const; // 体力を返す
		int getHealCost()const; // 体力回復に必要なコストを返す
	private:
		/* 変数 */
		PlayerImages* mpImages; // 画像クラス
		Bullet** mppBullet; // 弾クラス
		Sound* mpShotSound; // 弾の発射音
		PLAYER_IMG_TYPE mImgType; // 画像タイプ
		int CurrentLane; // 現在のレーンポジション
		int Life; // 体力
		int HealTime; // 体力を回復した回数
		int HealCost; // 体力回復に必要なコスト
		int WeaponLevel; // 武器レベル
		int WeaponLevelUpCost; // 武器レベル上昇に必要なコスト
		int BulletPower; // 弾の攻撃力
		int Posession; // 所持金
	};
}