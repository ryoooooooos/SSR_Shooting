#pragma once
// 必要ファイルのインクルード
#include "../../Images/EnemyImages/EnemyImages.h"
#include "../Base/Object.h"
#include "../Bullet/Bullet.h"
//
// ネームスペース
namespace furukawa {
	// 敵クラス
	class Enemy : public Object {
	public:
		/* コンストラクタ・デストラクタ */
		Enemy(); // コンストラクタ
		~Enemy(); // デストラクタ
		/* 関数 */
		HRESULT init()override; // 初期化
		void update(); // 更新
		void appear(const int level); // 出現
		void UpdateLife(const int damage); // 敵の体力を更新
		void draw()const override; // 描画
		/* アクセサ */
		int getLife()const; // 体力を返す
		void setIsVisible(const bool t_or_f); // 出現フラグをセット
		bool getIsVisible()const; // 出現フラグを返す
		Vector2 getPos()const; // 座標を返す
	private:
		/* 変数 */
		EnemyImages* mpImages; // 画像クラス
		ENEMY_IMG_TYPE mImgType; // 画像タイプ
		int Life; // 体力
		int CurrentFrame; // 現在のフレーム数
		int CurrentAnimation; // アニメーションされている画像
		bool isVisible; // 出現フラグ
	};
}