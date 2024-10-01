#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include <cassert>
#include"engine/TextureConverter.h"

int main(int argc, char* argv[10])
{
	
	//コマンドライン引数
	enum Argument
	{
		kApplicationPath,//アプリケーションのパス
		kFilePath,       //渡されたファイルパス
		NumArgument
	};


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