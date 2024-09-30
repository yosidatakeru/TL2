#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[10])
{

	//コマンドライン引数
	enum Argument
	{
		kApplicationPath,//アプリケーションのパス
		kFilePatj,       //渡されたファイルパス
		NumArgument
	};



	for (int i = 0; i < argc; i++)
	{
		//文字列argvの1番を表示
		printf(argv[i]);
		//改行
		printf("\n");
	}
	//勝手にウィンドが閉じるのを防止している
	system("pause");
	return 0;
}