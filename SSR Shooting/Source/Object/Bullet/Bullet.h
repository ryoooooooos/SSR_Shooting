#pragma once
// 必要ファイルのインクルード
#include "../Base/Object.h"
#include "../../Parameter/Parameter.h"
//
// ネームスペース
namespace furukawa {
    // 弾クラス
    class Bullet : public Object {
    public:
        /* コンストラクタ・デストラクタ */
        Bullet(const char* FileName); // コンストラクタ
        ~Bullet(); // デストラクタ
        /* 関数 */
        HRESULT init()override; // 初期化
        void update(); // 更新
        void appear(const Vector2& v); // 出現
        void draw()const override; // 描画
        /* アクセサ */
        Vector2 getPos()const; // 座標を返す
        void setIsVisible(const bool t_or_f); // 出現フラグをセット
        bool getIsVisible()const; // 出現フラグを返す
    private:
        /* 変数 */
        Image* mpImage; // 画像クラス
        Vector2 pos; // 座標
        bool isVisible; // 出現フラグ
    };
}