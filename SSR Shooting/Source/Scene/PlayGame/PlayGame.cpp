// 必要ファイルのインクルード
#include "PlayGame.h"
// Scene.h で GameManagerクラス を不完全型で定義しているため、中身がわからない
// そのため、それぞれのシーンで Gamemanager.h をインクルードし
// GameManagerクラス の中身を把握できるようにする。
#include "../../GameManager/GameManager.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	PlayGame::PlayGame(GameManager* pGameManager) 
		: Scene(pGameManager)
		, NormalFontHandle(-1)
		, mpPlayer(nullptr)
		, mppEnemy(nullptr)
		, mpEnemyManagement(nullptr)
		, mpWeaponImage(nullptr)
		, mpLifeImage(nullptr)
	{
	}
	// デストラクタ
	PlayGame::~PlayGame() {
		// プレイヤー
		delete mpPlayer;

		// 敵
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			delete(mppEnemy[i]);
		}
		delete mppEnemy;

		// 敵管理
		delete mpEnemyManagement;
	}
	// 初期化
	HRESULT PlayGame::init() {
		// 背景
		mpBackground = new BackGround("Images/BackGround.jpg");
		if (FAILED(mpBackground->init())) {
			return E_FAIL;
		}

		// 音楽
		mpSound = new Sound("Sounds/BattleBGM.wav");
		if (FAILED(mpSound->init())) return E_FAIL;

		// プレイヤー
		mpPlayer = new Player();
		if (FAILED(mpPlayer->init())) return E_FAIL;

		// 敵
		mppEnemy = new Enemy * [EnemyParameter::NumOfEnemy];
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			mppEnemy[i] = new Enemy();
			if (FAILED(mppEnemy[i]->init())) return E_FAIL;
		}

		// 敵管理
		mpEnemyManagement = new EnemyManagement();
		mpEnemyManagement->init();

		// 武器画像
		mpWeaponImage = new Image("Images/Weapon.png");
		if(FAILED(mpWeaponImage->load())) return E_FAIL;

		// ライフ画像
		mpLifeImage = new Image("Images/Heart.png");
		if (FAILED(mpLifeImage->load())) return E_FAIL;

		// スコアを初期化
		mpGameManager->setScore(0);

		// フォントサイズ
		NormalFontHandle = CreateFontToHandle(NULL, Parameter::NormalFontSize, Parameter::FontThick);

		return S_OK;
	}
	// 実行
	Scene* PlayGame::run() {
		input();
		update();
		draw();
		return mpNextScene;
	}
	// 入力
	void PlayGame::input() {
		// プレイヤーの上移動
		if (mKey.isKeyPush(KeyType::W)) {
			mpPlayer->moveUp();
		}
		// プレイヤーの下移動
		if (mKey.isKeyPush(KeyType::S)) {
			mpPlayer->moveDown();
		}
		// 弾発射
		if (mKey.isKeyPush(KeyType::SPACE)) {
			mpPlayer->shotBullet();
		}
		// 武器レベルアップ
		if (mKey.isKeyPush(KeyType::E)) {
			mpPlayer->WeaponLevelUp();
		}
		// 回復
		if (mKey.isKeyPush(KeyType::R)) {
			mpPlayer->Heal();
		}
	}
	// 更新
	void PlayGame::update() {
		// 音楽の再生
		mpSound->loop();
		
		// プレイヤーの更新
		mpPlayer->update();

		// 敵の更新
		updateEnemy();

		// 当たり判定
		HitCheck();
	}
	// 敵の更新
	void PlayGame::updateEnemy() {
		// 敵の出現
		if ((rand() % mpEnemyManagement->getEnemyProbability()) == 0) {
			for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
				// 出現していない敵を出現させる
				if (!mppEnemy[i]->getIsVisible()) {
					mppEnemy[i]->appear(mpEnemyManagement->getEnemyLevel());
					break; // 一体出現させたら抜ける
				}
			}
		}

		// 敵の座標やアニメーションの更新
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			// 出現している敵のみ
			if (mppEnemy[i]->getIsVisible()) {
				mppEnemy[i]->update();
				// 敵がダメージを受ける線上にいた時
				if (static_cast<int>(mppEnemy[i]->getPos().mX) <= Parameter::DamageLine - EnemyParameter::ImageSize / 2) {
					// 敵の出現フラグをおろす
					mppEnemy[i]->setIsVisible(false);
					// ダメージを受ける
					mpPlayer->Damage();
					// ライフが 0 になったらリザルト画面へ
					if (mpPlayer->getLife() <= 0) {
						mpNextScene = new GameResult(mpGameManager);
					}
				}
			}
		}
	}
	// 当たり判定
	void PlayGame::HitCheck() {
		// 弾と敵の当たり判定
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			// 弾クラスを呼び出す
			auto bullet = mpPlayer->getBulletPointer(i);

			// 発射していなかったらスキップ
			if (!bullet->getIsVisible()) continue;

			// 敵
			for (int j = 0; j < EnemyParameter::NumOfEnemy; j++) {
				// 敵クラス
				auto enemy = mppEnemy[j];

				// 出現していなかったらスキップ
				if (!enemy->getIsVisible()) continue;

				// 当たり判定チェック
				if (isHit(bullet->getPos(), enemy->getPos(), PlayerParameter::BulletImageSize / 2, EnemyParameter::ImageSize / 2)) {
					
					// 弾の出現フラグをおろす
					bullet->setIsVisible(false);

					// 敵の体力更新
					enemy->UpdateLife(mpPlayer->getBulletPower());
					
					// 敵の体力が 0 以下になったらスコアの更新
					if (enemy->getLife() <= 0) {
						// 敵の出現フラグをおろす
						enemy->setIsVisible(false);

						// お金をゲットする
						mpPlayer->EarnPosession(mpEnemyManagement->getEnemyLevel());

						// 敵を倒したので呼び出す
						mpEnemyManagement->update();

						// スコアの更新
						UpdateScore();
					}
				}
			}
		}
	}

	// 当たり判定
	bool PlayGame::isHit(const Vector2& v1, const Vector2& v2, const int r1, const int r2) {
		// 戻り値
		bool result = false;

		// 2点間の距離を測る
		auto dPos = v1 - v2;
		auto d = sqrtf((dPos.mX * dPos.mX) + (dPos.mY * dPos.mY));

		// 当たっていたら true
		if (d <= static_cast<float>(r1 + r2)) {
			result = true;
		}

		return result;
	}

	// スコアの更新
	void PlayGame::UpdateScore() {
		// 現在のスコアを取得
		auto score = mpGameManager->getScore();

		// 新たにスコアを加算
		auto level = mpEnemyManagement->getEnemyLevel();
		score += Parameter::InitScore + (level - 1) * Parameter::ScoreUpRate;

		// スコアをもとに戻す
		mpGameManager->setScore(score);
	}

	// 描画
	void PlayGame::draw()const {
		ClearDrawScreen(); // 裏画面をクリア

		mpBackground->draw(); // 背景

		// 区切り線
		MyDrawLine();

		// 敵
		for (int i = 0; i < EnemyParameter::NumOfEnemy; i++) {
			// 出現している敵のみ描画
			if (mppEnemy[i]->getIsVisible()) {
				mppEnemy[i]->draw();
			}
		}

		// プレイヤー
		mpPlayer->draw();

		// ライフ画像
		DrawLife();

		// 武器画像
		DrawWeapon();

		// スコア
		DrawScore();

		// 操作説明
		DrawInstruction();

		ScreenFlip(); // 裏画面と表画面を入れ替える
	}
	// 区切り線の描画
	void PlayGame::MyDrawLine()const {
		int drawX, drawY;

		// スコアとプレイ画面の区切り線
		drawY = Parameter::NormalFontSize;
		DrawLine(0, drawY, Parameter::WindowWidth, drawY, ColorParameter::Black, Parameter::LineThickNess);

		// アイテム情報とプレイ画面の区切り線
		drawX = Parameter::DamageLine;
		DrawLine(drawX, Parameter::NormalFontSize, drawX, Parameter::WindowHeight, ColorParameter::Black, Parameter::LineThickNess);

		// レーンの描画
		for (int i = 1; i <= Parameter::NumOfLine; i++) {
			drawY = Parameter::NormalFontSize + Parameter::LaneInterval * i;
			DrawLine(Parameter::DamageLine, drawY, Parameter::WindowWidth, drawY, ColorParameter::Black, Parameter::LineThickNess);
		}
	}
	// ライフ関連の描画
	void PlayGame::DrawLife()const {
		// 描画座標
		auto left = Parameter::ImagePosAdjust; // 左端
		auto top = Parameter::ImagePosAdjust * 4; // 上端
		auto right = Parameter::ImagePosAdjust * 3; // 右端
		auto bottom = Parameter::ImagePosAdjust * 6; // 下端
		
		// 描画
		DrawExtendGraph(left, top, right, bottom, mpLifeImage->getImgNo(), TRUE); // 画像
		//体力回復に必要なコスト
		DrawFormatStringToHandle(left, bottom, ColorParameter::Black, NormalFontHandle, "[E]%dz", mpPlayer->getHealCost());
	}
	// 武器関連の描画
	void PlayGame::DrawWeapon()const {
		// 描画座標
		auto left = Parameter::ImagePosAdjust; // 左端
		auto top = Parameter::ImagePosAdjust; // 上端
		auto right = Parameter::ImagePosAdjust * 4; // 右端
		auto bottom = Parameter::ImagePosAdjust * 3; // 下端
		
		// 武器レベル
		auto level = mpPlayer->getWeaponLevel();

		// 描画
		DrawExtendGraph(left / 4, top, right, bottom, mpWeaponImage->getImgNo(), TRUE); // 画像
		// 武器のレベルアップに必要なコスト
		DrawFormatStringToHandle(left, bottom, ColorParameter::Black, NormalFontHandle, "Lv.%d→Lv.%d\n[R]%dz", level, level + 1, mpPlayer->getWeaponLevelUpCost());
	}
	// 操作説明の描画
	void PlayGame::DrawInstruction()const {
		DrawStringToHandle(0, Parameter::ImagePosAdjust * 8, "[W][S]移動\n[SPACE]弾発射", ColorParameter::Black, NormalFontHandle);
	}
	// スコアの描画
	void PlayGame::DrawScore()const {
		DrawFormatStringToHandle(0, 0, ColorParameter::Black, NormalFontHandle,
			"敵レベル %d　所持金 %dz　スコア %d　ライフ %d",
			mpEnemyManagement->getEnemyLevel(), mpPlayer->getPosession(),
			mpGameManager->getScore(), mpPlayer->getLife());
	}
}