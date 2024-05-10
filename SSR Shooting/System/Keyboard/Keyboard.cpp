// 必要ファイルのインクルード
#include "keyboard.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Keyboard::Keyboard()
		: mKeyToVK{
			KEY_INPUT_W,
			KEY_INPUT_S,
			KEY_INPUT_E,
			KEY_INPUT_R,
			KEY_INPUT_SPACE
		}
		, mPreKeyStat(0U)
		, mNowKeyStat(0U)
	{
	}
	// インスタンスの取得
	Keyboard& Keyboard::getInstance() {
		static Keyboard inst;
		return inst;
	}
	//
	// 毎フレーム最初に呼び出す
	HRESULT Keyboard::keyUpdate() {
		char Buf[256];
		if (GetHitKeyStateAll(Buf) == -1) {
			FUNC_ERR("GetHitKeyStateAll");
			return E_FAIL;
		}
		mPreKeyStat = mNowKeyStat;
		mNowKeyStat = 0;
		for (auto i = 0; i < static_cast <int>(KeyType::MAX); i++) {
			if (Buf[mKeyToVK[i]] == 1) {
				mNowKeyStat |= (1U << i);
			}
		}

		return S_OK;
	}
	//
	// キーボードが押下された瞬間だけ真、その他は偽を返す。
	// 今回使用できるキーボードの種類は8種類までです。
	bool Keyboard::isKeyPush(KeyType keyNo) const {
		auto pre = (mPreKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		auto now = (mNowKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		return !pre && now;
	}
	//
	// キーが離された瞬間だけ真、その他は偽を返す。
	// 今回使用できるキーボードの種類は８種類までです。
	bool Keyboard::isKeyRelease(KeyType keyNo) const {
		auto pre = (mPreKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		auto now = (mNowKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		return pre && !now;
	}
}