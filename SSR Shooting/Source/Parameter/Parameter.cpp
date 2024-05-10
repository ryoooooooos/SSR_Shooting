// 必要ファイルのインクルード
#include "Parameter.h"
//
// ネームスペース
namespace furukawa {
	// 色関連
	const unsigned int ColorParameter::White = GetColor(255, 255, 255); // 白
	const unsigned int ColorParameter::Black = GetColor(0, 0, 0); // 黒
	const unsigned int ColorParameter::Red = GetColor(255, 0, 0); // 赤
	const unsigned int ColorParameter::Blue = GetColor(0, 0, 255); // 青
	const unsigned int ColorParameter::Green = GetColor(0, 255, 0); // 緑
	const unsigned int ColorParameter::Yellow = GetColor(255, 255, 0); // 黄
}