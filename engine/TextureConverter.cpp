#include "TextureConverter.h"





void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);
	
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//HRESULT result;
	//ファイルパスをワイド文字列に変換する
	std::wstring wfilePath = ConverMultiByteStringToWideString(filePath);
	//result = DirectX::LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scrathImge_);
	//assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConverMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);


	return wString;
}