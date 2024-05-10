#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../PlayGame/PlayGame.h"
#include "../Base/Scene.h"
#include "../../Parameter/Parameter.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �^�C�g���N���X
	class Title : public Scene
	{
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Title(GameManager* pGameManager); // �R���X�g���N�^
		~Title(); // �f�X�g���N�^
		/* �֐� */
		HRESULT init()override; // �V�[�����̏�����
		Scene* run()override; // �V�[���̎��s
	private:
		/* �֐� */
		void input(); // ����
		void update(); // �X�V
		void draw(); // �`��
		void MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle);
		/* �ϐ� */
		int GamePlayCount; // ���s��A�v���C������
		int SceneChangeTimer; // �^�C�g����ʑJ�ڌ�A�o�߂�������
		int BigFontHandle; // �t�H���g�n���h��(��)
		int SmallFontHandle; // �t�H���g�n���h��(��)
	};
}