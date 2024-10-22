#include "TextureConverter.h"





void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//�e�N�X�`���t�@�C����ǂݍ���
	LoadWICTextureFromFile(filePath);
	
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//HRESULT result;
	//�t�@�C���p�X�����C�h������ɕϊ�����
	std::wstring wfilePath = ConverMultiByteStringToWideString(filePath);
	//result = DirectX::LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scrathImge_);
	//assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConverMultiByteStringToWideString(const std::string& mString)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);


	return wString;
}