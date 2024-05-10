// 必要ファイルのインクルード
#include "Math.h"
//
// ネームスペース
namespace furukawa {
	// 誤差範囲内での等値比較
	bool Math::Equal(float x, float y) {
		return fabs(x - y) <= FloatError * max(1, max(fabs(x), fabs(y)));
	}
}