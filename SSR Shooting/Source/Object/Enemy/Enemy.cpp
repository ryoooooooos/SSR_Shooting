// 必要ファイルのインクルード
#include "Enemy.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Enemy::Enemy()
		: Object()
		, mpImages(nullptr)
		, mImgType(static_cast<ENEMY_IMG_TYPE>(-1))
		, Life(-1)
		, CurrentFrame(-1)
		, CurrentAnimation(-1)
		, isVisible(false)
	{
	}
	// デストラクタ
	Enemy::~Enemy() {
		delete mpImages;
	}
	// 初期化
	HRESULT Enemy::init() {
		// プレイヤー画像
		mpImages = new EnemyImages();
		if (FAILED(mpImages->loadImages())) {
			return E_FAIL;
		}

		// 体力
		Life = EnemyParameter::InitLife;

		// アニメーション関連
		CurrentFrame = CurrentAnimation = 0;

		// 出現フラグ
		isVisible = false;

		return S_OK;
	}
	// 更新
	void Enemy::update() {
		// アニメーションを進める
		CurrentFrame++;
		// 次の画像へ
		if (CurrentFrame >= EnemyParameter::AnimationPerFrame) {
			CurrentAnimation++;
			CurrentFrame = 0;
			// 最初の画像に戻す
			if (CurrentAnimation >= EnemyParameter::NumOfAnimation) {
				CurrentAnimation = 0;
			}
		}

		// 敵の移動
		pos.mX -= EnemyParameter::MoveSpeed;
	}
	// 描画
	void Enemy::draw()const {
		auto image = mpImages->getImagePointer(mImgType);
		DrawRectGraph(static_cast<int>(pos.mX), static_cast<int>(pos.mY),
			EnemyParameter::ImageSize * CurrentAnimation, 0,
			EnemyParameter::ImageSize, EnemyParameter::ImageSize,
			image->getImgNo(), TRUE);
	}
	// 出現
	void Enemy::appear(const int level) {
		// プレイヤー画像をランダムで決める
		mImgType = static_cast<ENEMY_IMG_TYPE>(rand() % static_cast<int>(ENEMY_IMG_TYPE::MAX));

		// 出現位置をランダムで決める
		int Lane = rand() % (Parameter::NumOfLane + 1);

		// 座標
		pos.mX = static_cast<float>(Parameter::WindowWidth);
		pos.mY = static_cast<float>(EnemyParameter::InitY + Parameter::LaneInterval * Lane);

		// 体力
		Life = EnemyParameter::InitLife + (level - 1) * EnemyParameter::LifeUpRate;

		// 出現フラグを立てる
		isVisible = true;
	}
	// 敵の体力の更新
	void Enemy::UpdateLife(const int damage) {
		Life -= damage;
	}
	// 体力を返す
	int Enemy::getLife()const {
		return Life;
	}
	// 出現フラグをセット
	void Enemy::setIsVisible(const bool t_or_f) {
		isVisible = t_or_f;
	}
	// 出現フラグを返す
	bool Enemy::getIsVisible()const {
		return isVisible;
	}
	// 座標を返す
	Vector2 Enemy::getPos()const {
		return pos;
	}
}