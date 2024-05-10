 #pragma once
// 必要ファイルのインクルード
#include "DxLib.h"
#include "../Macro/Macro.h"
//
// ネームスペース
namespace furukawa {
	// isKeyPush(キーが押された瞬間)、isKeyRelease(キーが離された瞬間)メソッドの引数に使用します。
	// mKeyToVk配列(本クラスのprivateメンバ,コンストラクタで初期化)と対応させて、指定してください。
	// 最大8種類まで＋最後にKEY_MAXを入れておいてください
	enum class KeyType {
		W,
		S,
		E,
		R,
		SPACE,
		MAX
	};

	// Keyboardクラスはsingletonです。
	class Keyboard {
	public:
		/* コンストラクタ */
		Keyboard(const Keyboard&) = delete;	// コピーコンストラクタdelete指定
		Keyboard& operator= (const Keyboard&) = delete;	// コピー代入演算子delete指定
		Keyboard(Keyboard&&) = delete;	// ムーブコンストラクタdelete指定
		Keyboard& operator= (Keyboard&&) = delete; // ムーブ代入演算子delete指定
		/* 関数 */
		static Keyboard& getInstance(); // インスタンスの取得
		//
		// 毎フレーム最初に呼び出す
		HRESULT keyUpdate();
		//
		// キーボードが押下された瞬間だけ真、その他は偽を返す。
		// 今回使用できるキーボードの種類は8種類までです。
		bool isKeyPush(KeyType keyNo) const;
		//
		// キーが離された瞬間だけ真、その他は偽を返す。
		// 今回使用できるキーボードの種類は８種類までです。
		bool isKeyRelease(KeyType keyNo) const;
		//
		//キーが押され続けている間については、DXLIBの関数(int CheckHitKey( int KeyCode ))を使用のこと
	private:
		/* コンストラクタ・デストラクタ */
		Keyboard(); // コンストラクタ
		~Keyboard() = default; // デストラクタ
		/* 変数 */
		const BYTE mKeyToVK[8];	//キーコード変換テーブル
		BYTE mPreKeyStat; //直前フレームのキー状態
		BYTE mNowKeyStat; //現フレームのキー状態
	};
}