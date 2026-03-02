#pragma once

// PUBG MOBILE (4.2.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jan  7 13:17:30 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class QRCodeUtility.VideoThumbnailGenerator
// 0x0000 (0x0028 - 0x0028)
class UVideoThumbnailGenerator : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class QRCodeUtility.VideoThumbnailGenerator");
		return pStaticClass;
	}


	static void GenerateVideoThumbnailAsync(const struct FString& videoPath, int thumbnailSize, const struct FScriptDelegate& OnThumbnailGenerated);
};


// Class QRCodeUtility.ZXingScanner
// 0x0000 (0x0028 - 0x0028)
class UZXingScanner : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class QRCodeUtility.ZXingScanner");
		return pStaticClass;
	}


	static class UTexture2D* Encode(const struct FString& Text);
	static bool Decode(class UTexture2D* Texture, const struct FVector4& InRect, struct FZXingScanResult* OutResult);
};


}

