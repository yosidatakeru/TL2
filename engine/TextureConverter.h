#pragma once
#include <string>
#include <winerror.h>
#include <combaseapi.h>

class TextureConverter
{
public:

	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const std::string& filePath);

	//マルチバイト文字列に変換
	static std::wstring ConverMultiByteStringToWideString(const std::string& mString);

};
