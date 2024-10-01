#pragma once
#include <string>
#include <winerror.h>
#include <combaseapi.h>

class TextureConverter
{
public:

	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�}���`�o�C�g������ɕϊ�
	static std::wstring ConverMultiByteStringToWideString(const std::string& mString);

};
