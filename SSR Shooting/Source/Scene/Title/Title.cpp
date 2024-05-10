// 必要ファイルのインクルード
#include "Title.h"
// Scene.h で GameManagerクラス を不完全型で定義しているため、中身がわからない
// そのため、それぞれのシーンで Gamemanager.h をインクルードし
// GameManagerクラス の中身を把握できるようにする。
#include "../../GameManager/GameManager.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Title::Title(GameManager* pGameManager)
		: Scene(pGameManager)
		, GamePlayCount(-1)
		, SceneChangeTimer(-1)
		, BigFontHandle(-1)
		, SmallFontHandle(-1)
	{
	}
	// デストラクタ
	Title::~Title() {
	}
	//
	// シーン毎の初期化
	HRESULT Title::init() {
		// 背景
		mpBackground = new BackGround("Images/BackGround.jpg");	// この程度がnewできないとなにもできないので、失敗は考えない
		if (FAILED(mpBackground->init())) {
			return E_FAIL;
		}

		// 音楽
		mpSound = new Sound("Sounds/TitleBGM.wav");
		if (FAILED(mpSound->init())) {
			return E_FAIL;
		}

		// ゲームプレイ回数, タイトル遷移後経過した時間
		GamePlayCount = 0;
		SceneChangeTimer = 0;

		// フォントサイズ
		BigFontHandle = CreateFontToHandle(NULL, Parameter::BigFontSize, Parameter::FontThick);
		SmallFontHandle = CreateFontToHandle(NULL, Parameter::SmallFontSize, Parameter::FontThick);

		return S_OK;
	}
	//
	// シーンの実行
	Scene* Title::run() {
		input();
		update();
		draw();
		return mpNextScene;
	}
	//
	// 入力
	void Title::input() {
		// SPACEキーが押されたら画面遷移。しかし、以下のパターンがある。
		// ①実行後１回目のプレイの場合、タイトルでの経過時間に関係なく次へ
		// ②実行後２回目以降のプレイの場合、タイトルで40フレーム分経過したら次へ
		if (mKey.isKeyPush(KeyType::SPACE)) {
			if (GamePlayCount == 0 || SceneChangeTimer >= Parameter::MinSceneChangeTimer) {
				mpNextScene = new PlayGame(mpGameManager);
			}
		}
	}
	//
	// 更新
	void Title::update() {
		// 経過時間をインクリメント
		SceneChangeTimer++;

		// 音楽の再生
		mpSound->loop();
	}
	//
	// 描画
	void Title::draw() {
		ClearDrawScreen(); // 裏画面をクリア

		mpBackground->draw(); // 背景

		MyDrawString(Parameter::WindowWidth / 10, Parameter::WindowHeight / 2 - 100, "ししろシューティング", ColorParameter::Black, BigFontHandle);
		MyDrawString(Parameter::WindowWidth / 2 - 100, Parameter::WindowHeight / 2 + 50, "SPACEを押してください", ColorParameter::Black, SmallFontHandle);

		ScreenFlip(); // 裏画面と表画面を入れ替える
	}
	//
	// 文字列の描画
	void Title::MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle) {
		DrawStringToHandle(drawX, drawY, string, color, FontHandle);
	}
}