#pragma once
#define FILE_NOT_FOUND(x) MessageBox(NULL, "�t�@�C��������܂���", x, MB_OK)
#define FUNC_ERR(x) MessageBox(NULL, "���̊֐��ŃG���[�ɂȂ�܂���", x, MB_OK)
#define SAFE_DELETE(x) delete(x);x=nullptr;
#define SAFE_DELETE_ARRAY(x) delete[](x);x=nullptr;
#define SAFE_RELEASE(x) if(x){x->Release(); x=nullptr;}
