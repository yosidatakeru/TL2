#pragma once
#include <string>
#include"DirectXTex/DirectXTex.h"




class TextureConverter
{
public:

	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const std::string& filePath);

	//マルチバイト文字列に変換
	static std::wstring ConverMultiByteStringToWideString(const std::string& mString);

	void SeparateFilepath(const std::wstring& filePath);

	void SaveDDSTextureToFile();
private:
	DirectX::TexMetadata metadata_;

	DirectX::ScratchImage scrathImge_;

	//ディレクトリパス
	std::wstring  directoryPath_;

	std::wstring fileName_;

	std::wstring fileExt_;

	

};
