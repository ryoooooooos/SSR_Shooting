// 必要ファイルのインクルード
#include "Vector2.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ（値指定なし）
	Vector2::Vector2()
		: mX(0.0f)
		, mY(0.0f)
	{
	}
	// コンストラクタ（値指定あり）
	Vector2::Vector2(float x, float y)
		: mX(x)
		, mY(y)
	{
	}
	// 等値比較
	bool Vector2::operator==(const Vector2& rhs)const {
		return (mX == rhs.mX) && (mY == rhs.mY);
	}
	// ゼロベクトルと等しいか
	bool Vector2::isZeroStrict()const {
		return (mX == 0.0f) && (mY == 0.0f);
	}
	// 2つのベクトルが誤差の範囲内で等しいか
	bool Vector2::equals(const Vector2& vec)const {
		return Math::Equal(mX, vec.mX) && Math::Equal(mY, vec.mY);
	}
	//
	// 四則演算
	// 符号を反転したものを返す
	Vector2 Vector2::operator-()const {
		return Vector2(-mX, -mY);
	}
	// ベクトルを加算し結果を代入
	Vector2& Vector2::operator+=(const Vector2& rhs) {
		mX += rhs.mX;
		mY += rhs.mY;
		return *this;
	}
	// ベクトルを減算し結果を代入
	Vector2& Vector2::operator-=(const Vector2& rhs) {
		return *this += (-rhs);
	}
	// ベクトルの実数倍を計算し結果を代入
	Vector2& Vector2::operator*=(float rhs) {
		mX *= rhs;
		mY *= rhs;
		return *this;
	}
	// ベクトルを実数で割った結果を代入
	Vector2& Vector2::operator/=(float rhs) {
		mX /= rhs;
		mY /= rhs;
		return *this;
	}
	// 2つのベクトルの和を返す
	Vector2 Vector2::operator+(const Vector2& rhs)const {
		auto vec(*this);
		vec += rhs;
		return vec;
	}
	// 2つのベクトルの差を返す
	Vector2 Vector2::operator-(const Vector2& rhs)const {
		return *this + (-rhs);
	}
	// ベクトルの実数倍を返す
	Vector2 Vector2::operator*(float rhs)const {
		auto vec(*this);
		vec *= rhs;
		return vec;
	}
	// ベクトルを実数で割った値を返す
	Vector2 Vector2::operator/(float rhs)const {
		auto vec(*this);
		vec /= rhs;
		return vec;
	}
	//
	// その他の機能
	// 内積を求める
	float Vector2::dot(const Vector2& vec)const {
		return (mX * vec.mX) + (mY * vec.mY);
	}
	// 外積を求める
	float Vector2::cross(const Vector2& vec)const {
		return (mX * vec.mY) - (mY * vec.mX);
	}
	// 余弦を求める(数学的には2次元ベクトルに外積はないが、この関数の使い道はあるので・・・）
	float Vector2::cos(const Vector2& vec)const {
		auto d = dot(vec);
		auto l = length() * vec.length();
		assert(l > 0.0f); // ゼロベクトル対策
		auto result = d / l;	// 内積の結果を大きさ＊大きさで割ることでcosθが求まる
		// 誤差対策(-1 <= cosθ <= 1 の範囲なので)
		if (result > 1.0f) {
			result = 1.0f;
		}
		else if (result < -1.0f) {
			result = -1.0f;
		}
		return result;
	}
	// なす角を求める(単位はラジアン)
	float Vector2::angle(const Vector2& vec)const {
		return std::acos(cos(vec));  // cosはVector2::cos
	}
	// ベクトルの長さを求める
	float Vector2::length()const {
		return std::sqrt(squareLength());
	}
	// ベクトルの長さの二乗を求める
	float Vector2::squareLength()const {
		return (mX * mX) + (mY * mY);
	}
	// 位置ベクトルとの距離を求める
	float Vector2::dist(const Vector2& point)const {
		return std::sqrt(squareDist(point));
	}
	// 位置ベクトルとの距離の二乗を求める
	float Vector2::squareDist(const Vector2& point)const {
		auto x2 = (mX - point.mX) * (mX - point.mX);
		auto y2 = (mY - point.mY) * (mY - point.mY);
		return x2 + y2;
	}
	// 一定の長さに正規化。len省略時は1.0f（void unitAssign(float len = 1.0f);）
	void Vector2::unitAssign(float len) {
		assert(len > 0.0f); // 長さが0以下はダメよ
		*this /= length(); // まずは大きさ１で正規化
		*this *= len;
	}
	// 一定の長さに正規化されたベクトルを返す。 len省略時は1.0f（Vector2 unit(float len = 1.0f)const;）
	Vector2 Vector2::unit(float len)const {
		assert(len > 0.0f); // 長さが0以下はダメよ
		auto vec(*this);
		vec.unitAssign(len);
		return vec;
	}
	// ベクトルを指定された角度(ラジアン)反時計回りに回転
	void Vector2::rotateRadAssign(float rad) {
		auto newX = std::cos(rad) * mX - std::sin(rad) * mY;
		auto newY = std::sin(rad) * mX + std::cos(rad) * mY;
		mX = newX;
		mY = newY;
	}
	// 指定された角度(ラジアン)反時計回りに回転させたベクトルを返す
	Vector2 Vector2::rotateRad(float rad)const {
		auto vec(*this);
		vec.rotateRadAssign(rad);
		return vec;
	}
	// ベクトルを引数で指定されたベクトルに射影
	// (結果、求めたベクトルと引数で指定されたベクトルは平行になり、元の大きさより小さくなる)
	void Vector2::projectAssign(const Vector2& vec) {
		auto l = vec.length();
		assert(l > 0.0f); // ゼロベクトル対策
		l = this->dot(vec) / l; // 内積の結果を引数に指定されたベクトルの大きさで割ることで、射影方向の長さがわかる
		auto result = vec.unit() * l; // 引数に指定されたベクトルを大きさ１に正規化し、上で求めた長さ(l)を掛ければそれが答え
		mX = result.mX;
		mY = result.mY;
	}
	// 引数で指定されたベクトルに射影したベクトルを返す
	// (結果、返されたベクトルと引数で指定されたベクトルは平行になり、元の大きさより小さくなる)
	Vector2 Vector2::project(const Vector2& vec)const {
		auto v(*this);
		v.projectAssign(vec);
		return v;
	}
}