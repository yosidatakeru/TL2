#include "TextureConverter.h"
#include<Windows.h>
//#include "stringapiset.h"
#include<assert.h>
using namespace DirectX;


void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);

	SaveDDSTextureToFile();
	
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{

	//ファイルパスをワイド文字列に変換する
	std::wstring wfilePath = ConverMultiByteStringToWideString(filePath);
	HRESULT result = DirectX::LoadFromWICFile(wfilePath.c_str(), DirectX::WIC_FLAGS_NONE, &metadata_, scrathImge_);
	assert(SUCCEEDED(result));

	//ファイルパスとファイル名を分離
	SeparateFilepath(wfilePath);

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

void TextureConverter::SeparateFilepath(const std::wstring& filePath)
{
	size_t pos1;
	std::wstring exceptExt;

	//区切り文字'.'が出てくる一番最後の部分の探索
	pos1 = filePath.rfind('.');

	//検索がヒットしたら
	if (pos1 != std::wstring::npos)
	{
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
		//区切り文字の前までを抜き出す
		exceptExt = filePath.substr(0, pos1);
	}
	else
	{
		fileExt_ = L"";
		exceptExt = filePath;
	}

	//区切り文字'//'がでてくると一番最後の部分を検索
	pos1 = exceptExt.rfind('\\');
	if (pos1 != std::wstring::npos)
	{
		directoryPath_ = exceptExt.substr(0, pos1 + 1);

		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);
		return;
	}

	//区切り文字'/'が出てくる一番最後の部分を検索
	pos1 = exceptExt.rfind('/');
	if (pos1 != std::wstring::npos)
	{
		directoryPath_ = exceptExt.substr(0, pos1 + 1);

		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);
		return;
	}
	//区切り文字がないのでファイル名のみとして扱う
	directoryPath_ = L"";
	fileName_ = exceptExt;



}

void TextureConverter::SaveDDSTextureToFile()
{
	metadata_.format = MakeSRGB(metadata_.format);

	HRESULT result;

	//出力ファイル名を設定する
	std::wstring filePath = directoryPath_ + fileName_ + L".dds";

	//DDSファイル書き出し
	result = SaveToDDSFile(scrathImge_.GetImages(), scrathImge_.GetImageCount(), metadata_, DDS_FLAGS_NONE, filePath.c_str());
	assert(SUCCEEDED(result));


}