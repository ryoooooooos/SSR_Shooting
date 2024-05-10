#pragma once
// 必要ファイルのインクルード
#include "DxLib.h"
//
// ネームスペース
namespace furukawa {
	// 定数クラス
	class Parameter {
	public:
		// ウインドウ関連
		static constexpr int WindowWidth = 960; // ウィンドウ幅
		static constexpr int WindowHeight = 640; // ウィンドウ高さ
		static constexpr int ColorBit = 32;	// 1ピクセル当たりのビット数(32ビットカラー)

		// タイトル関連
		static constexpr int MinSceneChangeTimer = 40; // タイトルから遷移するまでの最低待ち時間

		// 文字列関連
		static constexpr int BigFontSize = 75; // フォントサイズ(大)
		static constexpr int NormalFontSize = 30; // フォントサイズ(中)
		static constexpr int SmallFontSize = 20; // フォントサイズ(小)
		static constexpr int FontThick = 5; // 文字の太さ

		// ゲーム関連
		static constexpr int NumOfLane = 11; // レーンの数
		static constexpr int LineThickNess = 5; // レーンを区切る線の太さ
		static constexpr int NumOfLine = 12; // レーンを区切る線の数
		static constexpr int DamageLine = 250; // 敵が触れたときに体力が減る線の位置
		static constexpr int LaneInterval = 50; // 線と線の間隔
		static constexpr int InitScore = 100; // もらえるスコアの基礎値
		static constexpr int ScoreUpRate = 25; // レベルが上がるごとに増えるスコアの上昇値

		// 画像関連
		static constexpr int LifeImageWidth = 420; // HP画像幅
		static constexpr int LifeImageHeight = 360; // HP画像高さ
		static constexpr int WeaponImageWidth = 56; // 武器画像幅
		static constexpr int WeaponImageHeight = 40; // 武器画像高さ
		static constexpr int ImagePosAdjust = 50; // 画像の位置調整
	};

	// 色関連
	class ColorParameter {
	public:
		static const unsigned int White; // 白
		static const unsigned int Black; // 黒
		static const unsigned int Red; // 赤
		static const unsigned int Blue; // 青
		static const unsigned int Green; // 緑
		static const unsigned int Yellow; // 黄
	};

	// プレイヤー関連
	class PlayerParameter {
	public:
		static constexpr int ImageSize = 48; // プレイヤー画像の大きさ
		static constexpr int InitX = 250; // プレイヤーの初期位置(x座標)
		static constexpr int InitY = 32; // プレイヤーの初期位置(y座標)
		static constexpr int MaxLife = 3; // 最大体力
		static constexpr int InitHealCost = 3000; // 体力回復に必要なお金
		static constexpr int BulletImageSize = 48; // 弾画像の大きさ
		static constexpr float BulletSpeed = 5.0f; // 弾の速度
		static constexpr int InitWeaponLevelUpCost = 500; // 武器レベルアップに必要なお金
		static constexpr int InitBulletPower = 20; // 弾の基礎攻撃力
		static constexpr int BulletPowerRate = 20; // レベルが上がるごとに触れる攻撃力の上昇量
		static constexpr int NumOfBullet = 100; // 弾の最大数
	};

	// 敵関連
	class EnemyParameter {
	public:
		static constexpr int ImageSize = 48; // 敵画像の大きさ
		static constexpr int InitX = Parameter::WindowWidth; // 敵の初期位置(x座標)
		static constexpr int InitY = 32; // 敵の初期位置(y座標)
		static constexpr float MoveSpeed = 0.5f; // 敵の移動速度
		static constexpr int AnimationPerFrame = 20; // アニメーションするフレーム数
		static constexpr int NumOfAnimation = 3; // アニメーションする画像の枚数
		static constexpr int NumOfEnemy = 25; // 敵の最大数
		static constexpr int LevelUpInterval = 15; // レベルが上がる間隔
		static constexpr int MaxProbability = 100; // 敵の出現確率
		static constexpr int ProbabilityDecrease = 5; // 敵の出現確率の減少幅
		static constexpr int InitLife = 50; // 体力の基礎値
		static constexpr int LifeUpRate = 20; // レベルが上がるごとに増える体力の上昇値
		static constexpr int InitPosession = 70; // 落とすお金の基礎値
		static constexpr int PosessionUpRate = 25; // レベルが上がるごとに増えるお金の上昇値
	};
}