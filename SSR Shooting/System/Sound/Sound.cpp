// 必要ファイルのインクルード
#include "Sound.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Sound::Sound(const char* FileName)
		: mpFileName(std::string(FileName))
		, mHandle(-1)
	{
	}
	// デストラクタ
	Sound::~Sound() {
		if (mHandle >= 0) {
			DeleteSoundMem(mHandle);
		}
	}
	// 音楽ファイルのロード
	HRESULT Sound::init() {
		auto str = mpFileName.data();
		if ((mHandle = LoadSoundMem(str)) == -1) {
			FILE_NOT_FOUND(str);
			return E_FAIL;
		}
		return S_OK;
	}
	// 音楽の通常再生
	void Sound::play()const {
		// 通常再生だと実行画面が止まるためバックグラウンド再生
		PlaySoundMem(mHandle, DX_PLAYTYPE_BACK);
	}
	// 音楽のループ再生
	void Sound::loop()const {
		if (CheckSoundMem(mHandle) == 0) {
			PlaySoundMem(mHandle, DX_PLAYTYPE_LOOP);
		}
	}
}