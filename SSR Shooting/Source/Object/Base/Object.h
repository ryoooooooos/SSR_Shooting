#pragma once
// 必要ファイルのインクルード
#include "../../../System/Image/Image.h"
#include "../../../System/Vector2/Vector2.h"
#include "../../../System/Keyboard/Keyboard.h"
//
// ネームスペース
namespace furukawa {
	// キャラクタークラス
	class Object {
	public:
		/* コンストラクタ・デストラクタ */
		Object(); // コンストラクタ
		virtual ~Object(); // デストラクタ
		/* 関数 */
		virtual HRESULT init() = 0; // 初期化
		virtual void draw()const = 0; // 描画
	protected:
		/* 変数 */
		Vector2 pos;
	};
}