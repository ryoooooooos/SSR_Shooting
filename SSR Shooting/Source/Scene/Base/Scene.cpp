// �K�v�t�@�C���̃C���N���[�h
#include "Scene.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Scene::Scene(GameManager* pGameManager)
		: mpNextScene(this)
		, mpBackground(nullptr)
		, mpSound(nullptr)
		, mpGameManager(pGameManager)
		, mKey(Keyboard::getInstance())
	{
	}
	// �f�X�g���N�^
	Scene::~Scene() {
		delete mpBackground;
		delete mpSound;
	}
}