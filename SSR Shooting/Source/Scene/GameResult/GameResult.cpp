// 必要ファイルのインクルード
#include "GameResult.h"
// Scene.h で GameManagerクラス を不完全型で定義しているため、中身がわからない
// そのため、それぞれのシーンで Gamemanager.h をインクルードし
// GameManagerクラス の中身を把握できるようにする。
#include "../../GameManager/GameManager.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	GameResult::GameResult(GameManager* pGameManager)
		: Scene(pGameManager)
		, SceneChangeTimer(-1)
		, BigFontHandle(-1)
		, SmallFontHandle(-1)
	{
	}
	// デストラクタ
	GameResult::~GameResult() {

	}
	// 初期化
	HRESULT GameResult::init() {
		// 背景
		mpBackground = new BackGround("Images/BackGround.jpg");
		if (FAILED(mpBackground->init())) {
			return E_FAIL;
		}

		// 画面遷移後経過した時間
		SceneChangeTimer = 0;

		// フォントサイズ
		BigFontHandle = CreateFontToHandle(NULL, Parameter::BigFontSize, Parameter::FontThick);
		SmallFontHandle = CreateFontToHandle(NULL, Parameter::SmallFontSize, Parameter::FontThick);


		return S_OK;
	}
	// 実行
	Scene* GameResult::run() {
		input();
		update();
		draw();
		return mpNextScene;
	}
	// 入力
	void GameResult::input() {
		// SPACEキーが押されたら画面遷移。しかし、以下のパターンがある。
		// ①実行後１回目のプレイの場合、タイトルでの経過時間に関係なく次へ
		// ②実行後２回目以降のプレイの場合、タイトルで40フレーム分経過したら次へ
		if (mKey.isKeyPush(KeyType::SPACE)) {
			if (SceneChangeTimer >= Parameter::MinSceneChangeTimer) {
				mpNextScene = new Title(mpGameManager);
			}
		}
	}
	// 更新
	void GameResult::update() {
		// 経過時間をインクリメント
		SceneChangeTimer++;
	}
	// 描画
	void GameResult::draw() {
		ClearDrawScreen(); // 裏画面をクリア

		mpBackground->draw(); // 背景

		// スコアの表示
		DrawFormatStringToHandle(Parameter::WindowWidth / 4, Parameter::WindowHeight / 2 - 100, ColorParameter::Black, BigFontHandle, "スコア：%d", mpGameManager->getScore());
		MyDrawString(Parameter::WindowWidth / 2 - 100, Parameter::WindowHeight / 2 + 50, "SPACEを押してください", ColorParameter::Black, SmallFontHandle);

		ScreenFlip(); // 裏画面と表画面を入れ替える
	}
	//
	// 文字列の描画
	void GameResult::MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle) {
		DrawStringToHandle(drawX, drawY, string, color, FontHandle);
	}
}
