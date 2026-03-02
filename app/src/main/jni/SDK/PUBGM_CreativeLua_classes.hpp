#pragma once

// PUBG MOBILE (4.2.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jan  7 13:17:30 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class CreativeLua.CreativeBridgeLuaVM
// 0x0030 (0x0390 - 0x0360)
class UCreativeBridgeLuaVM : public UCreativeLuaVM
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0360(0x0008) MISSED OFFSET
	class UObject*                                     LuaVMManager;                                             // 0x0368(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FString                                     RegisterUGCVMFunctionHandlerName;                         // 0x0370(0x0010) (ZeroConstructor)
	struct FString                                     UGCVMPostInitFunctionHandlerName;                         // 0x0380(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CreativeLua.CreativeBridgeLuaVM");
		return pStaticClass;
	}


	void UGCLuaError(int ErrCode);
	void RegisterSluaCallUgcluaEventHandler();
	void PostInit();
};


}

