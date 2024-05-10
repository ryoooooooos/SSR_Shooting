// �K�v�t�@�C���̃C���N���[�h
#include "DxLib.h"
#include "../GameManager/GameManager.h"
// �ȉ����������[�N�΍� DirectX�֘A�̃w�b�_�t�@�C�����C���N���[�h��ɋL�q�̂���
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#if _DEBUG
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif
// �����܂Ń��������[�N�΍�

// �v���O������ WinMain ����n�܂�܂�
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // ���������[�N�΍�

	// �ēN���X
	furukawa::GameManager* game = new furukawa::GameManager();
	
	// ���s
	game->run();

	// �폜
	delete game;

	return 0;				// �\�t�g�̏I�� 
}
