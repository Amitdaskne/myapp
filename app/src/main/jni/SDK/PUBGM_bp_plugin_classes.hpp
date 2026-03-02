#pragma once

// PUBG MOBILE (4.2.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jan  7 13:17:30 2026
 
namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Classes
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Class bp_plugin.bp_pluginBPLibrary
// 0x0000 (0x0028 - 0x0028)
class Ubp_pluginBPLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class bp_plugin.bp_pluginBPLibrary");
		return pStaticClass;
	}


	static void bp_pluginSendEvent(const struct FString& jsonEventCmd);
	static int bp_pluginRequestInstallWidget(int wigetType, const struct FString& authInfo);
	static float bp_pluginLaunchMeemoFunction(const struct FString& Param);
	static bool bp_pluginIsInForeground();
	static int bp_pluginGetInstalledWidgetType();
};


}

