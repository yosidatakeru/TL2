#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[10])
{

	//�R�}���h���C������
	enum Argument
	{
		kApplicationPath,//�A�v���P�[�V�����̃p�X
		kFilePatj,       //�n���ꂽ�t�@�C���p�X
		NumArgument
	};



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