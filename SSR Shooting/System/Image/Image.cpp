// 必要ファイルのインクルード
#include "Image.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Image::Image(const char* fileName)
		: mpFileName(std::string(fileName))
		, mImgNo(-1)
	{
	}
	// デストラクタ
	Image::~Image() {
		if (mImgNo >= 0) {
			DeleteGraph(mImgNo);
		}
	}
	// 画像ファイルのロード
	HRESULT Image::load() {
		auto str = mpFileName.data();
		if ((mImgNo = LoadGraph(str)) == -1) {
			FILE_NOT_FOUND(str);
			return E_FAIL;
		}
		return S_OK;
	}
	// 画像Noを返す
	int Image::getImgNo()const {
		return mImgNo;
	}
}