#pragma once
// 必要ファイルのインクルード
#include "../../System/Image/Image.h"
#include "../../System/Vector2/Vector2.h"
#include "../Parameter/Parameter.h"
//
// ネームスペース
namespace furukawa {
	// 背景クラス
	class BackGround
	{
	public:
		/* コンストラクタ・デストラクタ */
		BackGround(const char* fileName);
		~BackGround();
		// BackGroundはコピー不可
		BackGround(const BackGround& scene) = delete;
		const BackGround& operator= (const BackGround& rhs) = delete;
		/* 関数 */
		void draw()const; // 描画
		HRESULT init(); // 初期化
	private:
		/* 変数 */
		Image* mpImage; // 画像クラス
		Vector2 mPos; // 座標
	};
}