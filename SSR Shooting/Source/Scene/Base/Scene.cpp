// 必要ファイルのインクルード
#include "Scene.h"
//
// ネームスペース
namespace furukawa {
	// コンストラクタ
	Scene::Scene(GameManager* pGameManager)
		: mpNextScene(this)
		, mpBackground(nullptr)
		, mpSound(nullptr)
		, mpGameManager(pGameManager)
		, mKey(Keyboard::getInstance())
	{
	}
	// デストラクタ
	Scene::~Scene() {
		delete mpBackground;
		delete mpSound;
	}
}