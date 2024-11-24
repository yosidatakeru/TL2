#include<cstdio>
#include<cstdlib>
#include <cassert>
#include<Windows.h>
#include"engine/TextureConverter.h"


//�R�}���h���C������
enum Argument
{
	kApplicationPath,//�A�v���P�[�V�����̃p�X
	kFilePath,       //�n���ꂽ�t�@�C���p�X
	NumArgument
};

int main(int argc, char* argv[])
{
	

	assert(argc >= NumArgument);

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));


	//�e�N�X�`���R���o�[�^�[
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	//����ɃE�B���h������̂�h�~���Ă���
	system("pause");
	return 0;
}