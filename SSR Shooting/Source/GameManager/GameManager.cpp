// 必要ファイルのインクルード
#include "GameManager.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	GameManager::GameManager() 
		: mpScene(nullptr)
		, Score(-1)
	{
	}
	// デストラクタ
	GameManager::~GameManager() {
		delete mpScene;
	}
	// 実行
	void GameManager::run() {
		// インスタンスを取得
		auto& key = Keyboard::getInstance();
		// 初期化が成功したらループ
		if (SUCCEEDED(init())) {
			while (1) {	// ESCキーが押されるまで無限ループ
				if (ProcessMessage() == -1) break; // ×ボタンが押されたらループを抜ける
				if (CheckHitKey(KEY_INPUT_ESCAPE)) break; // ESCキーが押されたらループを抜ける
				if (FAILED(key.keyUpdate())) break; // キー入力初期化
				if (FAILED(gameLoop())) break; // ゲーム処理
			}
		}

		// 終了
		final();
	}
	// 初期化
	HRESULT GameManager::init() {
		ChangeWindowMode(TRUE); // ウインドウモードに設定
		SetGraphMode(Parameter::WindowWidth, Parameter::WindowHeight, Parameter::ColorBit); // 800×600、32ビットカラー
		SetBackgroundColor(65, 105, 225); // GetColorの戻り値を指定するすべがないので、ここはマジックナンバー
		SetDrawScreen(DX_SCREEN_BACK); // 標準がDX_SCREEN_FRONTだとは知らなかった。ごめんなさい
		//SetWaitVSyncFlag(0); // 垂直同期をOFF
		if (DxLib_Init() == -1) {	// ＤＸライブラリ初期化処理
			return E_FAIL;			// エラーが起きたら直ちに終了
		}
		// 乱数の種を作る
		std::srand(static_cast <unsigned int>(time(NULL)));
		// 最初はタイトルから
		mpScene = new Title(this);
		// 初期化
		if (FAILED(mpScene->init())) return E_FAIL;

		return S_OK;
	}
	// 終了
	void GameManager::final() {
		DxLib_End();
	}
	// ゲームループ
	HRESULT GameManager::gameLoop() {
		// 次のシーンを実行
		Scene* pNext = mpScene->run();
		// 違うシーンだったら新しく作る
		if (pNext != mpScene) {
			delete mpScene;
			mpScene = pNext;
			// 初期化
			if (FAILED(mpScene->init())) {
				return E_FAIL;
			}
		}
		return S_OK;
	}
	// スコアをセット
	void GameManager::setScore(const int s) {
		Score = s;
	}
	// スコアを返す
	int GameManager::getScore()const {
		return Score;
	}
}