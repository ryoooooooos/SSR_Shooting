#pragma once
#define FILE_NOT_FOUND(x) MessageBox(NULL, "ファイルがありません", x, MB_OK)
#define FUNC_ERR(x) MessageBox(NULL, "次の関数でエラーになりました", x, MB_OK)
#define SAFE_DELETE(x) delete(x);x=nullptr;
#define SAFE_DELETE_ARRAY(x) delete[](x);x=nullptr;
#define SAFE_RELEASE(x) if(x){x->Release(); x=nullptr;}
