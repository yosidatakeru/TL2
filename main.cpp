#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[10])
{

	//printf("Hello,World\n");
	//����ɃE�B���h������̂�h�~���Ă���
	//system("pause");

	for (int i = 0; i < argc; i++)
	{
		//������argv��1�Ԃ�\��
		printf(argv[i]);
		//���s
		printf("\n");
	}
	//����ɃE�B���h������̂�h�~���Ă���
	system("pause");
	return 0;
}