#pragma once
// 必要ファイルのインクルード
#include <Windows.h>
#include <cmath>
#include <algorithm>
//
// ネームスペース
namespace furukawa {
	// 数学クラス
	class Math {
	public:
		/* 関数 */
		// 相対誤差(FloatError*max(1,max(x,y))）の範囲で2つの値が等しいかを判定
		static bool Equal(float x, float y);
		/* 変数 */
		// floatの誤差
		static constexpr float FloatError = 0.00001f;
	};
}