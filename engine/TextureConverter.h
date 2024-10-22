#pragma once
#include <string>
#include <winerror.h>
#include <combaseapi.h>
#include<stringapiset.h>

//#include<Windows.h>
//using namespace DirectX;

class TextureConverter
{
public:

	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�}���`�o�C�g������ɕϊ�
	static std::wstring ConverMultiByteStringToWideString(const std::string& mString);

	//DirectX::TexMetadata metadata_;

	//DirectX::ScratchImage scrathImge_;

};
