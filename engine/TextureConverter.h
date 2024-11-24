#pragma once
#include <string>
#include"DirectXTex/DirectXTex.h"




class TextureConverter
{
public:

	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�}���`�o�C�g������ɕϊ�
	static std::wstring ConverMultiByteStringToWideString(const std::string& mString);

	void SeparateFilepath(const std::wstring& filePath);

	void SaveDDSTextureToFile();
private:
	DirectX::TexMetadata metadata_;

	DirectX::ScratchImage scrathImge_;

	//�f�B���N�g���p�X
	std::wstring  directoryPath_;

	std::wstring fileName_;

	std::wstring fileExt_;

	

};
