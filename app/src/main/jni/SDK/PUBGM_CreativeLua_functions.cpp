// PUBG MOBILE (4.2.0 -- 64bit Beta) SDK Generate By @ByDwoz
// Telegram Channel:- @XelahotOfficial
// Generate on Wed Jan  7 13:17:30 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------❣︎➪ 𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------
//Functions
//---------------------❣︎➪𝗕𝗬𝗗𝗪𝗢𝗭 𝗗𝗘𝗩𝗘𝗟𝗢𝗣𝗘𝗥༆✈︎🇪🇬---------------------------

// Function CreativeLua.CreativeBridgeLuaVM.UGCLuaError
// (Final, Native, Public, Const)
// Parameters:
// int                            ErrCode                        (Parm, ZeroConstructor, IsPlainOldData)

void UCreativeBridgeLuaVM::UGCLuaError(int ErrCode)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.UGCLuaError");

	UCreativeBridgeLuaVM_UGCLuaError_Params params;
	params.ErrCode = ErrCode;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CreativeLua.CreativeBridgeLuaVM.RegisterSluaCallUgcluaEventHandler
// (Final, Native, Public)

void UCreativeBridgeLuaVM::RegisterSluaCallUgcluaEventHandler()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.RegisterSluaCallUgcluaEventHandler");

	UCreativeBridgeLuaVM_RegisterSluaCallUgcluaEventHandler_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function CreativeLua.CreativeBridgeLuaVM.PostInit
// (Native, Public, BlueprintCallable)

void UCreativeBridgeLuaVM::PostInit()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function CreativeLua.CreativeBridgeLuaVM.PostInit");

	UCreativeBridgeLuaVM_PostInit_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

