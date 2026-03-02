static int prevXSuits = preferences.Config.Skin.XSuits;
static auto start = std::chrono::high_resolution_clock::now();
static bool callFunction = false;
static bool callNotify = false;
static bool callModSkin = false;
std::chrono::steady_clock::time_point lastChangeTime;
void (*orig_Broadcast)(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter);
void hk_Broadcast(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter) {
if (ModSkinn && KillMessage){
if (g_LocalController->PlayerKey == FatalDamageParameter->CauserKey) {
if (g_LocalPlayer -> WeaponManagerComponent) {
if (g_LocalPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated) {
CauserDeadBox::KillByWeaponID = std::to_string((int) g_LocalPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated -> GetWeaponID());
CauserDeadBox::CurBulletNumInClipNew = ((ASTExtraShootWeapon * ) g_LocalPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated) -> CurBulletInClip.CurBulletNumInClip;
}
int KillMsgSkinId = 0;
int KillMsgSkinIdd = 0;
if (HideName) {
FatalDamageParameter->String.causerName  = FString();
}
if (preferences.Config.Skin.XSuits >= 1)
KillMsgSkinIdd = new_Skin.XSuits;
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "103007")) {
if (preferences.Config.Skin.MK14 >= 1)
KillMsgSkinId = new_Skin.MK14;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "105010")) {
if (preferences.Config.Skin.MG3 >= 1)
KillMsgSkinId = new_Skin.MG3;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "102105")) {
if (preferences.Config.Skin.P90 >= 1)
KillMsgSkinId = new_Skin.P90;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "103007")) {
if (preferences.Config.Skin.MK14 >= 1)
KillMsgSkinId = new_Skin.MK14;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101001")) {
if (preferences.Config.Skin.AKM >= 1)
KillMsgSkinId = new_Skin.AKM;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101002")) {
if (preferences.Config.Skin.M16A4 >= 1)
KillMsgSkinId = new_Skin.M16A4;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101003")) {
if (preferences.Config.Skin.Scar >= 1)
KillMsgSkinId = new_Skin.Scar;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101004")) {
if (preferences.Config.Skin.M416 >= 1)
KillMsgSkinId = new_Skin.M416_1;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101005")) {
if (preferences.Config.Skin.Groza >= 1)
KillMsgSkinId = new_Skin.Groza;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101006")) {
if (preferences.Config.Skin.AUG >= 1)
KillMsgSkinId = new_Skin.AUG;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101008")) {
if (preferences.Config.Skin.M762 >= 1)
KillMsgSkinId = new_Skin.M762;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "101102")) {
if (preferences.Config.Skin.ACE32 >= 1)
KillMsgSkinId = new_Skin.ACE32;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "102001")) {
if (preferences.Config.Skin.UZI >= 1)
KillMsgSkinId = new_Skin.UZI;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "102002")) {
if (preferences.Config.Skin.UMP >= 1)
KillMsgSkinId = new_Skin.UMP;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "102003")) {
if (preferences.Config.Skin.Vector >= 1)
KillMsgSkinId = new_Skin.Vector;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "102004")) {
if (preferences.Config.Skin.Thompson >= 1)
KillMsgSkinId = new_Skin.Thompson;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "102005")) {
if (preferences.Config.Skin.Bizon >= 1)
KillMsgSkinId = new_Skin.Bizon;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "103001")) {
if (preferences.Config.Skin.K98 >= 1)
KillMsgSkinId = new_Skin.K98;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "103002")) {
if (preferences.Config.Skin.M24 >= 1)
KillMsgSkinId = new_Skin.M24;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "103003")) {
if (preferences.Config.Skin.AWM >= 1)
KillMsgSkinId = new_Skin.AWM;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "105002")) {
if (preferences.Config.Skin.DP28 >= 1)
KillMsgSkinId = new_Skin.DP28;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "105001")) {
if (preferences.Config.Skin.M249 >= 1)
KillMsgSkinId = new_Skin.M249;
}
if (strstr(CauserDeadBox::KillByWeaponID.c_str(), "108004")) {
if (preferences.Config.Skin.Pan >= 1)
KillMsgSkinId = new_Skin.Pan;
}
FatalDamageParameter->CauserWeaponAvatarID = KillMsgSkinId;
FatalDamageParameter->CauserClothAvatarID = KillMsgSkinIdd;
}}}
return orig_Broadcast(thiz, FatalDamageParameter);
}

void MtrRender(AHUD *HUD, int SizeX, int SizeY) {
updateSkin();
ASTExtraPlayerCharacter *localPlayer = 0;
ASTExtraPlayerController *localPlayerController = 0;
UCanvas *Canvas = HUD->Canvas;
if (Canvas) {
UGameplayStatics *gGameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
auto GWorld = GetWorld();
if (GWorld) {
UNetDriver *NetDriver = GWorld->NetDriver;
if (NetDriver) {
UNetConnection *ServerConnection = NetDriver->ServerConnection;
if (ServerConnection) {
localPlayerController = (ASTExtraPlayerController *) ServerConnection->PlayerController;
}}
if (localPlayerController) { 
std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
GetAllActors(PlayerCharacter);
for (auto actor = PlayerCharacter.begin();
 actor != PlayerCharacter.end(); actor++) {
auto Actor = *actor;
if (Actor->PlayerKey ==
((ASTExtraPlayerController *) localPlayerController)->PlayerKey) {
localPlayer = Actor;
break;
}}
{
if (localPlayer) {
if (ModSkinn){
if (KillMessage){
int pController = 1000;
auto VTable = (void **) g_LocalController->VTable;
auto f_mprotect = [](uintptr_t addr, size_t len,
 int32_t prot) -> int32_t {
static_assert(PAGE_SIZE == 4096);
constexpr
size_t page_size = static_cast<size_t>(PAGE_SIZE);
void *start = reinterpret_cast<void *>(addr & -page_size);
uintptr_t end = (addr + len + page_size - 20) & -page_size;
return mprotect(start, end -
 reinterpret_cast<uintptr_t>(start),
prot);
};
if (VTable && (VTable[pController] != hk_Broadcast)) {
orig_Broadcast = decltype(orig_Broadcast)(
VTable[pController]);

f_mprotect((uintptr_t)(&VTable[pController]),
 sizeof(uintptr_t), PROT_READ | PROT_WRITE);
VTable[pController] = (void *) hk_Broadcast;
}}
if (localPlayer->WeaponManagerComponent != 0) {
if (localPlayer->WeaponManagerComponent->CurrentWeaponReplicated != 0) {
int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
auto currentTime = std::chrono::steady_clock::now();
auto& landchud = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->synData;
auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWeaponChangeTime).count();
if (timeDiff > 1000) {
for (int j = 0; j < landchud.Num(); j++) {
auto& weaponInfo = landchud[j];
auto weaponid = weaponInfo.DefineID.TypeSpecificID;
if (weaponid != 0) {
if (preferences.AKM && weapowep== 101001 , 1010011 , 1010012 , 1010013 , 1010014 , 1010015 , 1010016 , 1010017) {
for (int id : akmv) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM;
break;
}}
for (int id : akmmag) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM_Mag;
break;
}}}

if (preferences.KAR98 && weapowep == 103001) {
for (int id : kar) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.K98;
break;
}}}

if (preferences.M24 && weapowep== 103002 , 1030021 , 1030022 , 1030023 , 1030024 , 1030025 , 1030026) {
for (int id : m24) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M24;
break;
}}}

if (preferences.AWM && weapowep== 103003 , 1030031 , 1030032 , 1030033 , 1030034 , 1030035 , 1030036 , 1030037) {
for (int id : awm) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.AWM;
break;
}}}

if (preferences.TOMMY && weapowep == 102004) {
for (int id : tommy) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.Thompson;
break;
}}}

if (preferences.ACE32 && weapowep== 101102 , 1011021 , 1011022 , 1011023 , 1011024 , 101125 , 101126 , 101127) {
for (int id : ace32) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.ACE32;
break;
}}}

if (preferences.BIZON && weapowep == 102005) {
for (int id : bizon) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.Bizon;
break;
}}}

if (preferences.UMP && weapowep== 102002 , 1020021 , 1020022 , 1020023 , 1020024 , 1020025 , 1020026 , 1020027) {
for (int id : ump) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.UMP;
break;
}}}

if (preferences.UZI && weapowep == 102001) {
for (int id : uzi) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.UZI;
break;
}}}

if (preferences.M16 && weapowep== 101002 , 1010021 , 1010022 , 1010023 , 1010024 , 1010025 , 1010026 , 1010027) {
for (int id : m16) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4;
break;
}}
for (int id : m16s) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Stock;
break;
}}
for (int id : m16mag) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Mag;
break;
}}}

if (preferences.PAN && weapowep == 108004) {
for (int id : pan) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.Pan;
break;
}}}

if (preferences.AUG && weapowep== 101006 , 1010061 , 1010062 , 1010063 , 1010064 , 1010065 , 1010066 , 1010067) {
for (int id : aug) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.AUG;
break;
}}}

if (preferences.GROZA && weapowep== 101005 , 1010051 , 1010052 , 1010053 , 1010054 , 1010055 , 1010056 , 1010057) {
for (int id : groza) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.Groza;
break;
}}}
if (preferences.GROZA && weapowep== 105010) {
for (int id : MG3) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.MG3;
break;
}}}

if (preferences.MG3 && weapowep== 105002 , 1050021 , 1050022 , 1050023 , 1050024 , 1050025 , 1050026 , 1050027) {
for (int id : dp) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.DP28;
break;
}}}

if (preferences.M249 && weapowep== 105001 , 1050011 , 1050012 , 1050013 , 1050014 , 1050015 , 1050016 , 1050017) {
for (int id : m249) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M249;
break;
}}}

if (preferences.SCARL && weapowep== 101003 , 1010031 , 1010032 , 1010033 , 1010034 , 1010035 , 1010036 , 1010037) {
for (int id : scar) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar;
break;
}}
for (int id : scarmag) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar_Mag;
break;
}}}
if (preferences.M762 && weapowep== 101008 , 1010081 , 1010082 , 1010083 , 1010084 , 1010085 , 1010086 , 1010087) {
for (int id : m7) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M762;
break;
}}
for (int id : m7mag) {
if (weaponid == id) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M762_Mag;
break;
}}}
if (preferences.P90 && weapowep== 102105 , 1021051 , 1021052 , 1021053 , 1021054 , 1021055 , 1021056 , 1021057){
for (int i = 0; i < sizeof(P90) / sizeof(P90[0]); i++) {
if (weaponid == P90[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.P90;
break;
}}}
if (preferences.MG3 && weapowep== 105010 , 1050101 , 1050102 , 1050103 , 1050104 , 1050105 , 1050106 , 1050107){
for (int i = 0; i < sizeof(MG3) / sizeof(MG3[0]); i++) {
if (weaponid == MG3[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.MG3;
break;
}}}
if (preferences.MK14 && weapowep == 103007 , 1030071 , 1030072 , 1030073 , 1030074 , 1030075 , 1030076 , 1030077){
for (int i = 0; i < sizeof(mk14) / sizeof(mk14[0]); i++) {
if (weaponid == mk14[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.MK14;
break;
}}}

if (preferences.M416 && weapowep == 101004){
for (int i = 0; i < sizeof(m4v) / sizeof(m4v[0]); i++) {
if (weaponid == m4v[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_1;
break;
}
}
for (int i = 0; i < sizeof(m4mag) / sizeof(m4mag[0]); i++) {
if (weaponid == m4mag[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_2;
break;
}
}
for (int i = 0; i < sizeof(m4sight) / sizeof(m4sight[0]); i++) {
if (weaponid == m4sight[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_3;
break;
}
}
for (int i = 0; i < sizeof(m4stock) / sizeof(m4stock[0]); i++) {
if (weaponid == m4stock[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_4;
break;
}
}
for (int i = 0; i < sizeof(m4stock1) / sizeof(m4stock1[0]); i++) {
if (weaponid == m4stock1[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_stock;
break;
}
}
for (int i = 0; i < sizeof(m4reddot) / sizeof(m4reddot[0]); i++) {
if (weaponid == m4reddot[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_reddot;
break;
}
}
for (int i = 0; i < sizeof(m4x3) / sizeof(m4x3[0]); i++) {
if (weaponid == m4x3[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x3;
break;
}
}
for (int i = 0; i < sizeof(m4x4) / sizeof(m4x4[0]); i++) {
if (weaponid == m4x4[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x4;
break;
}
}
for (int i = 0; i < sizeof(m4x6) / sizeof(m4x6[0]); i++) {
if (weaponid == m4x6[i]) {
weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x6;
break;
}
}


}}}
localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->DelayHandleAvatarMeshChanged();
lastWeaponChangeTime = currentTime;
}}}
if (localPlayer -> CurrentVehicle) {
if (localPlayer -> CurrentVehicle -> VehicleAvatar) {
std::string SkinIDStr = std::to_string((int) localPlayer -> CurrentVehicle -> VehicleAvatar -> GetDefaultAvatarID());
Active::SkinCarDefault = localPlayer -> CurrentVehicle -> GetAvatarID();
if (preferences.Moto && strstr(SkinIDStr.c_str(), "1901")) {
Active::SkinCarMod = new_Skin.Moto;
Active::SkinCarNew = true;
} else if (preferences.Dacia && strstr(SkinIDStr.c_str(), "1903")) {
Active::SkinCarMod = new_Skin.Dacia;
Active::SkinCarNew = true;
} else if (preferences.Boat && strstr(SkinIDStr.c_str(), "1911")) {
Active::SkinCarMod = new_Skin.Boat;
Active::SkinCarNew = true;
} else if (preferences.MiniBus && strstr(SkinIDStr.c_str(), "1904")) {
Active::SkinCarMod = new_Skin.MiniBus;
Active::SkinCarNew = true;
} else if (preferences.Mirado && strstr(SkinIDStr.c_str(), "1914")) {
Active::SkinCarMod = new_Skin.Mirado;
Active::SkinCarNew = true;
} else if (preferences.Mirado && strstr(SkinIDStr.c_str(), "1915")) {
Active::SkinCarMod = new_Skin.Mirado;
Active::SkinCarNew = true;
} else if (preferences.Buggy && strstr(SkinIDStr.c_str(), "1907")) {
Active::SkinCarMod = new_Skin.Buggy;
Active::SkinCarNew = true;
}else if (preferences.CoupeRB && strstr(SkinIDStr.c_str(), "1961")) {
Active::SkinCarMod = new_Skin.CoupeRP;
Active::SkinCarNew = true;
} else if (preferences.BigFoot && strstr(SkinIDStr.c_str(), "1953")) {
Active::SkinCarMod = new_Skin.Bigfoot;
Active::SkinCarNew = true;
} else if (preferences.UAZ && strstr(SkinIDStr.c_str(), "1908")) {
Active::SkinCarMod = new_Skin.UAZ;
Active::SkinCarNew = true;
} else Active::SkinCarNew = false;
if (Active::SkinCarDefault != Active::SkinCarMod && Active::SkinCarNew) {
localPlayer -> CurrentVehicle -> VehicleAvatar -> ChangeItemAvatar(Active::SkinCarMod, true);
}}}
 if (localPlayerController->BackpackComponent){
 auto data = localPlayerController->BackpackComponent->ItemListNet;
 auto bag = data.IncArray;
 for (int j = 0; j < bag.Num(); j++) {
 int ID = bag[j].Unit.DefineID.TypeSpecificID;
 if (preferences.Outfit){
 for (int i = 0; i < sizeof(SuitX) / sizeof(SuitX[0]); i++) {
 if (ID == SuitX[i]) {
 bag[j].Unit.DefineID.TypeSpecificID = new_Skin.XSuits;
 break;
}}}
if (preferences.Bagg){
for (int i = 0; i < sizeof(Bag) / sizeof(Bag[0]); i++) {
 if (ID == Bag[i]) {
 bag[j].Unit.DefineID.TypeSpecificID = bag3;
 break;
}}}
if (preferences.Helmett){
for (int i = 0; i < sizeof(Helmet) / sizeof(Helmet[0]); i++) {
 if (ID == Helmet[i]) {
 bag[j].Unit.DefineID.TypeSpecificID = helmett3;
 break;
}}}

if (preferences.PAN){
 for (int i = 0; i < sizeof(pan) / sizeof(pan[0]); i++) {
 if (ID == pan[i]) {
 bag[j].Unit.DefineID.TypeSpecificID = new_Skin.Pan;
 break;
}}}}}
uintptr_t NetAvatarSyncData_Offset;
NetAvatarSyncData_Offset = 0x2A8; //32

if (localPlayer->AvatarComponent2){
auto AvatarComponent = localPlayer->AvatarComponent2;
if (AvatarComponent != 0) {
auto NetAvatarData = *(FNetAvatarSyncData *)((uintptr_t)AvatarComponent + NetAvatarSyncData_Offset);
auto Slotsybc = NetAvatarData.SlotSyncData;
for (int j = 0; j < Slotsybc.Num(); j++) {
if (preferences.Outfit) {
Slotsybc[2].ItemId = new_Skin.XSuits;
}

auto& MTR = Slotsybc[j];
auto MTRid = MTR.ItemId;
if (MTRid != 0) {
if (preferences.Helmett) {
for (int i = 0; i < sizeof(Helmet) / sizeof(Helmet[0]); i++) {
if (MTRid == Helmet[i]) {
MTR.ItemId = helmett3;
}}}
if (preferences.Bagg) {
for (int i = 0; i < sizeof(Bag) / sizeof(Bag[0]); i++) {
if (MTRid == Bag[i]) {
MTR.ItemId = bag3;
}}}}}
auto now = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
if (elapsed < 100) {
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}}}
}}}}
g_LocalPlayer = localPlayer;
g_LocalController = localPlayerController;
}}}

