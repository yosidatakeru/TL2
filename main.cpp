#include<cstdio>
#include<cstdlib>
#include <cassert>
#include<Windows.h>
#include"engine/TextureConverter.h"


//コマンドライン引数
enum Argument
{
	kApplicationPath,//アプリケーションのパス
	kFilePath,       //渡されたファイルパス
	NumArgument
};

int main(int argc, char* argv[])
{
	

	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));


	//テクスチャコンバーター
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	//勝手にウィンドが閉じるのを防止している
	system("pause");
	return 0;
}