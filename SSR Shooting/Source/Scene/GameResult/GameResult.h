#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../Title/Title.h"
#include "../Base/Scene.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// ���ʔ��\�N���X
	class GameResult : public Scene {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		GameResult(GameManager* pGameManager); // �R���X�g���N�^
		~GameResult(); // �ŃG�X�g���N�^
		/* �֐� */
		HRESULT init()override; // ������
		Scene* run()override; // ���s
	private:
		/* �֐� */
		void input(); // ����
		void update(); // �X�V
		void draw(); // �`��
		void MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle);
		/* �ϐ� */
		int SceneChangeTimer; // �^�C�g����ʑJ�ڌ�A�o�߂�������
		int BigFontHandle; // �t�H���g�n���h��(��)
		int SmallFontHandle; // �t�H���g�n���h��(��)
	};
}