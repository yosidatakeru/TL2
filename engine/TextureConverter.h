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
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const std::string& filePath);

	//マルチバイト文字列に変換
	static std::wstring ConverMultiByteStringToWideString(const std::string& mString);

	//DirectX::TexMetadata metadata_;

	//DirectX::ScratchImage scrathImge_;

};
