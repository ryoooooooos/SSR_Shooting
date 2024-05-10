// 必要ファイルのインクルード
#include "DxLib.h"
#include "../GameManager/GameManager.h"
// 以下メモリリーク対策 DirectX関連のヘッダファイルをインクルード後に記述のこと
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#if _DEBUG
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif
// ここまでメモリリーク対策

// プログラムは WinMain から始まります
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // メモリリーク対策

	// 監督クラス
	furukawa::GameManager* game = new furukawa::GameManager();
	
	// 実行
	game->run();

	// 削除
	delete game;

	return 0;				// ソフトの終了 
}
