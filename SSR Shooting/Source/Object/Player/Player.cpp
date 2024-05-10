// 必要ファイルのインクルード
#include "Player.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Player::Player()
		: Object()
		, mpImages(nullptr)
		, mppBullet(nullptr)
		, mpShotSound(nullptr)
		, mImgType(static_cast<PLAYER_IMG_TYPE>(-1))
		, CurrentLane(-1)
		, Life(-1)
		, HealTime(-1)
		, HealCost(-1)
		, WeaponLevel(-1)
		, BulletPower(-1)
		, WeaponLevelUpCost(-1)
		, Posession(-1)
	{

	}
	// デストラクタ
	Player::~Player() {
		// 画像クラス
		delete mpImages;

		// 弾クラス
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			delete(mppBullet[i]);
		}
		delete mppBullet;

		// 弾の発射音クラス
		delete mpShotSound;
	}
	// 初期化
	HRESULT Player::init() {
		// プレイヤー画像
		mpImages = new PlayerImages();
		if (FAILED(mpImages->loadImages())) {
			return E_FAIL;
		}

		// 弾
		mppBullet = new Bullet * [PlayerParameter::NumOfBullet];
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			mppBullet[i] = new Bullet("Images/Bullet.png");
			if (FAILED(mppBullet[i]->init())) {
				return E_FAIL;
			}
		}

		// 弾の発射音
		mpShotSound = new Sound("Sounds/ShotSound.mp3");
		if (FAILED(mpShotSound->init())) {
			return E_FAIL;
		}

		// 現在のレーンポジション
		CurrentLane = 0;

		// 座標
		pos.mX = PlayerParameter::InitX;
		pos.mY = PlayerParameter::InitY;

		// 体力
		Life = PlayerParameter::MaxLife;

		// 体力を回復した回数
		HealTime = 0;

		// 武器レベル
		WeaponLevel = 1;

		// 攻撃力
		BulletPower = PlayerParameter::InitBulletPower;

		// 所持金
		Posession = 0;

		// コスト
		HealCost = PlayerParameter::InitHealCost;
		WeaponLevelUpCost = PlayerParameter::InitWeaponLevelUpCost;

		// プレイヤー画像をランダムで決める
		mImgType = static_cast<PLAYER_IMG_TYPE>(rand() % static_cast<int>(PLAYER_IMG_TYPE::MAX));

		return S_OK;
	}
	// 更新
	void Player::update() {
		// 座標の更新
		pos.mY = static_cast<float>(PlayerParameter::InitY + Parameter::LaneInterval * CurrentLane);
	
		// 弾の更新
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			// 出現している弾のみ更新
			if (mppBullet[i]->getIsVisible()) {
				mppBullet[i]->update();
			}
		}
	}
	// 描画
	void Player::draw()const {
		// 弾
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			// 出現している弾のみ描画
			if (mppBullet[i]->getIsVisible()) {
				mppBullet[i]->draw();
			}
		}

		// プレイヤー
		auto image = mpImages->getImagePointer(mImgType);
		DrawGraph(static_cast<int>(pos.mX), static_cast<int>(pos.mY), image->getImgNo(), TRUE);
	}
	// 上移動
	void Player::moveUp() {
		CurrentLane--;
		// 外に出ないようにする
		if (CurrentLane < 0) CurrentLane++;
	}
	// 下移動
	void Player::moveDown() {
		CurrentLane++;
		// 外に出ないようにする
		if (CurrentLane > Parameter::NumOfLane) CurrentLane--;
	}
	// 弾発射
	void Player::shotBullet() {
		for (int i = 0; i < PlayerParameter::NumOfBullet; i++) {
			if (!mppBullet[i]->getIsVisible()) {
				mppBullet[i]->appear(pos);
				mpShotSound->play();
				break; // 一つ出したら終了
			}
		}
	}
	// お金をゲットする
	void Player::EarnPosession(const int level) {
		Posession += EnemyParameter::InitPosession + (level - 1) * EnemyParameter::PosessionUpRate;
	}
	// 武器レベルを上げる
	void Player::WeaponLevelUp() {
		// 十分にお金があったらレベルを上げる
		if (Posession >= WeaponLevelUpCost) {
			WeaponLevel++;
			// お金を使う
			Posession -= WeaponLevelUpCost;
			// 攻撃力を更新
			BulletPower = PlayerParameter::InitBulletPower + (WeaponLevel - 1) * PlayerParameter::BulletPowerRate;
			// コストを更新
			WeaponLevelUpCost = PlayerParameter::InitWeaponLevelUpCost * WeaponLevel;
		}
	}
	// ダメージを受ける
	void Player::Damage() {
		Life--;
	}
	// 体力を回復する
	void Player::Heal() {
		// 体力が最大じゃなければ回復
		if (Life < PlayerParameter::MaxLife) {
			// 十分にお金があったら回復
			if (Posession >= HealCost) {
				Life++;
				// 回復回数をインクリメント
				HealTime++;
				// お金を使う
				Posession -= HealCost;
				// コストを更新
				HealCost = PlayerParameter::InitHealCost * (HealTime + 1);
			}
		}
	}
	// 指定した添え字の弾クラスを返す
	Bullet* Player::getBulletPointer(const int index)const {
		return mppBullet[index];
	}
	// 所持金をセット
	void Player::setPosession(const int p) {
		Posession = p;
	}
	// 所持金を返す
	int Player::getPosession()const {
		return Posession;
	}
	// 武器レベルを返す
	int Player::getWeaponLevel()const {
		return WeaponLevel;
	}
	// 武器のレベルアップに必要なコストを返す
	int Player::getWeaponLevelUpCost()const {
		return WeaponLevelUpCost;
	}
	// 攻撃力を返す
	int Player::getBulletPower()const {
		return BulletPower;
	}
	// 体力を返す
	int Player::getLife()const {
		return Life;
	}
	// 体力回復に必要なコストを返す
	int Player::getHealCost()const {
		return HealCost;
	}
}