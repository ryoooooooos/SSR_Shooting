// 必要ファイルのインクルード
#include "BackGround.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	BackGround::BackGround(const char* fileName)
		: mpImage(new Image(fileName))
		, mPos(Vector2(0.0f, 0.0f))
	{
	}
	// デストラクタ
	BackGround::~BackGround() {
		delete mpImage;
	}
	// 描画
	void BackGround::draw()const {
		DrawGraph(static_cast<int>(mPos.mX), static_cast<int>(mPos.mY), mpImage->getImgNo(), TRUE);
	}
	// 初期化
	HRESULT BackGround::init() {
		if (FAILED(mpImage->load())) {
			return E_FAIL;
		}
		return S_OK;
	}
}