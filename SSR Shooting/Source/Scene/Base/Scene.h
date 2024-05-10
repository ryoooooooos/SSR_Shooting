#pragma once
// 必要ファイルのインクルード
#include "DxLib.h"
#include "../../../System/Keyboard/Keyboard.h"
#include "../../../System/Sound/Sound.h"
#include "../../BackGround/BackGround.h"
//
// ネームスペース
namespace furukawa {
	// GameManager.hをインクルードすると循環インクルードになってしまうため、不完全型で定義
	class GameManager;
	// シーンの基底クラス
	class Scene
	{
	public:
		/* コンストラクタ・デストラクタ */
		Scene(GameManager* pGameManager); // コンストラクタ
		virtual ~Scene(); // デストラクタ
		// Sceneはコピー不可
		Scene(const Scene& scene) = delete;
		const Scene& operator= (const Scene& rhs) = delete;
		/* 関数 */
		virtual HRESULT init() = 0; // シーン毎の初期化
		virtual Scene* run() = 0; // シーンの実行
	protected:
		/* 変数 */
		Scene* mpNextScene; //次のフレームで実行するSceneクラスへのポインタ
		BackGround* mpBackground;//背景画像
		Sound* mpSound; // 音楽
		//各シーンで共通に使うものは GameManagerクラス経由で参照＆更新
		GameManager* mpGameManager;
		//KeyboardクラスとMouseクラスはsingletonなので、各クラスで持ってもOK。
		//GameManagerクラス経由でも良いが、利便性向上のため、ここにも定義
		Keyboard& mKey;
	};
}