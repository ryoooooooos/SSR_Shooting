// 必要ファイルのインクルード
#include "Bullet.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Bullet::Bullet(const char* FileName)
		: Object()
		, mpImage(new Image(FileName))
		, pos(Vector2(0.0f, 0.0f))
		, isVisible(false)
	{
	}
	// デストラクタ
	Bullet::~Bullet() {
		delete mpImage;
	}
	// 初期化
	HRESULT Bullet::init() {
		// 画像
		if (FAILED(mpImage->load())) {
			return E_FAIL;
		}

		// 出現フラグ
		isVisible = false;

		return S_OK;
	}
	// 更新
	void Bullet::update() {
		// 弾の移動
		pos.mX += PlayerParameter::BulletSpeed;
		// 弾の出現フラグをおろす
		if (pos.mX >= Parameter::WindowWidth) {
			isVisible = false;
		}
	}
	// 出現
	void Bullet::appear(const Vector2& v) {
		pos = v;
		isVisible = true;
	}
	// 描画
	void Bullet::draw()const {
		DrawGraph(static_cast<int>(pos.mX), static_cast<int>(pos.mY), mpImage->getImgNo(), TRUE);
	}
	// 座標を返す
	Vector2 Bullet::getPos()const {
		return pos;
	}
	// 出現フラグをセット
	void Bullet::setIsVisible(const bool t_or_f) {
		isVisible = t_or_f;
	}
	// 出現フラグを返す
	bool Bullet::getIsVisible()const {
		return isVisible;
	}
}
