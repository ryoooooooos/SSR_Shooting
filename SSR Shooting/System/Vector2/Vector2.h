#pragma once
// 必要ファイルのインクルード
#include "../Math/Math.h"
#include <cmath>
#include <cassert>
//
// ネームスペース
namespace furukawa {
	// 二次元ベクトルクラス
	class Vector2 {
	public:
		/* コンストラクタ・デストラクタ */
		Vector2(); // コンストラクタ（値指定なし）
		Vector2(float x, float y); // コンストラクタ（値指定あり）
		~Vector2() = default; // デストラクタ
		/* 関数 */
		// 等値比較
		// 2つのベクトルが等しいか
		bool operator==(const Vector2& rhs)const;
		// ゼロベクトルと等しいか
		bool isZeroStrict()const;
		// 2つのベクトルが誤差の範囲内で等しいか
		bool equals(const Vector2& vec)const;
		//
		// 四則演算
		// 符号を反転したものを返す
		Vector2 operator-()const;
		// ベクトルを加算し結果を代入
		Vector2& operator+=(const Vector2& rhs);
		// ベクトルを減算し結果を代入
		Vector2& operator-=(const Vector2& rhs);
		// ベクトルの実数倍を計算し結果を代入
		Vector2& operator*=(float rhs);
		// ベクトルを実数で割った結果を代入
		Vector2& operator/=(float rhs);
		// 2つのベクトルの和を返す
		Vector2 operator+(const Vector2& rhs)const;
		// 2つのベクトルの差を返す
		Vector2 operator-(const Vector2& rhs)const;
		// ベクトルの実数倍を返す
		Vector2 operator*(float rhs)const;
		// ベクトルを実数で割った値を返す
		Vector2 operator/(float rhs)const;
		//
		// その他の機能
		// 内積を求める
		float dot(const Vector2& vec)const;
		// 外積を求める（数学的には2次元ベクトルに外積はないが、この関数の使い道はあるので・・・）
		float cross(const Vector2& vec)const;
		// 余弦を求める
		float cos(const Vector2& vec)const;
		// なす角を求める(単位はラジアン)
		float angle(const Vector2& vec)const;
		// ベクトルの長さを求める
		float length()const;
		// ベクトルの長さの二乗を求める
		float squareLength()const;
		// 位置ベクトルとの距離を求める
		float dist(const Vector2& point)const;
		// 位置ベクトルとの距離の二乗を求める
		float squareDist(const Vector2& point)const;
		// 一定の長さに正規化
		void unitAssign(float len = 1.0f);
		// 一定の長さに正規化されたベクトルを返す
		Vector2 unit(float len = 1.0f)const;
		// ベクトルを指定された角度(ラジアン)反時計回りに回転
		void rotateRadAssign(float rad);
		// 指定された角度(ラジアン)反時計回りに回転させたベクトルを返す
		Vector2 rotateRad(float rad)const;
		// ベクトルを引数で指定されたベクトルに射影
		// (結果、求めたベクトルと引数で指定されたベクトルは平行になり、元の大きさより小さくなる)
		void projectAssign(const Vector2& vec);
		// 引数で指定されたベクトルに射影したベクトルを返す
		// (結果、返されたベクトルと引数で指定されたベクトルは平行になり、元の大きさより小さくなる)
		Vector2 project(const Vector2& vec)const;
		/* 変数 */
		// メンバ変数はprivateにし、publicなアクセサメソッドを用意することで
		// 安全性がUPするが、実行速度が低下する。今回のケースは速度重視であえてpublic
		// おそらく、Vector2クラスの場合はpublicの方がメリットが大きいと思う
		float mX;    // ベクトルの x 要素　あえてpublic
		float mY;    // ベクトルの y 要素   あえてpublic
	};
}