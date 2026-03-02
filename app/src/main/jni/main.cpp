#include "SONIC/Includes.h"
#include "SONIC/Includes/obfuscate.h"
#include "SONIC/Tools.h"
#include "SONIC/Vector3.hpp"
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_android.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include "SONIC/Tools.h"
#include "SONIC/Vector3.hpp"
#include "SONIC/KittyMemory/MemoryPatch.h"
#include "SONIC/base64/base64.h"
#include "SONIC/StrEnc.h"
#include "SONIC/ITEMS/json.hpp"
#include "SONIC/ITEMS/Items.h"
#include "SONIC/font/Font.h"
#include "SONIC/font/Iconcpp.h"
#include "SONIC/font/Icon.h"
#include "SONIC/font/Arabic.h"
#include "SONIC/font/tahoma.h"
#include "SONIC/Includes/Logger.h"
#include "SONIC/Includes/Utils.h"
#include "SONIC/Includes/Macros.h"
#include "SONIC/Oxorany/oxorany.h"
#include "SONIC/font/XorStr.h"
#include "SDK.hpp"
using namespace SDK;
#include <curl/curl.h>
#include "SONIC/image.h"
#include "hook.h"

// ------ FUCKIN COLORS
ImU32 Black = IM_COL32(0, 0, 0, 255);
ImU32 Green = IM_COL32(0, 255, 0, 255);
ImU32 Yellow = IM_COL32(255, 255, 0, 255);
ImU32 Red = IM_COL32(255, 0, 0, 255);
ImU32 Red2 = IM_COL32(255, 0, 0, 255);
ImU32 ORANGE = IM_COL32(255,125,0,255);
// -------
static char s[64];
char extra[32];
using json = nlohmann::ordered_json;
//========{{{{ Offset }}}}=========///
//64bit
#define GNames_Offset 0x83412f0
#define GUObject_Offset 0xe57bca0
#define GetActorArray_Offset 0xa0afed4
#define GNativeAndroidApp_Offset 0xe2b9e80
#define SkinOffset 0x9C06454
#define Actors_Offset 0xa0

#define MtrSkinEvent_Offset 0x9C06454
#define Broadcast_Offset 0x608c6c4
#define IM_PI 3.14159265358979323846f
#define MEROX(x) ((float)(x) * (float)(180.f / IM_PI))
#define MRB(x) ((float)(x) * (float)(IM_PI / 180.f))
#define IM_COL32_RED IM_COL32 (255,0,0,255)
//=====================================//
std::string expiredDate = " ";
std::string g_Token, g_Auth;
std::string name ="";
std::string EXP = "";
std::string device = "";
std::string status = "";
std::string floating ="";
static std::string mod_status = "";
// ---- خطوط سونيك
ImFont* tahoma;
ImFont* real;
ImFont* Arabic;
ImFont* flamee;
ImFont* font_8;
ImFont* Pra;
ImFont* GetBoldFont();
// -----
uintptr_t anogs,UE4;
uintptr_t MtrEvent_Offset;
android_app *g_App = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;
json items_data;
json mItemData; 
//=====================================//
enum EAimTrigger {
None = 0,
Shooting = 1,
Scoping = 2,
Both = 3,
Any = 4
};
enum EAimTarget {
Head = 0,
Chest = 1
};
//=====================================//
std::map<int, bool> Items;
std::map<int, float *> ItemColors;
bool ModSkinn;
bool KillMessage;
bool DeasBoxSkin;
bool HideName;
#include "Mod/jsonPreferences.h"
int sEmote1 = 2200101;
int sEmote2 = 2200201;
int sEmote3 = 2200301;
static int helmett3 = 0;
static int bag3 = 0;
int ModEmote1 = 0;
namespace Active {
inline int SkinCarDefault = 0;
inline int SkinCarMod = 0;
inline int SkinCarNew = 0;
}
namespace CauserDeadBox {
inline bool Active = false;
inline std::string KillByWeaponID = "";
inline int CurBulletNumInClipNew = 0;
inline int CurBulletNumInClipLast = 0;
inline UDeadBoxAvatarComponent * DeadBoxPointer = 0;
}
#include "Mod/Menu.h"
bool bValid = false;
bool HIDEESP = true;
bool active = false;
bool initImGui = false;
bool LOBBY;
bool GAME;
static int AimSet = 1;
static int EspStyle = 1;
bool ESP;
bool island;
bool Bypass = true;
bool FakeDamage;
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;
float menu[4] = {0,255,0,255};
//=====================================//
std::string GetSystemProperty(const char* property) {
char value[PROP_VALUE_MAX];
__system_property_get(property, value);
return std::string(value);
}
std::string DeviceName = GetSystemProperty("ro.product.manufacturer");
std::string Model = GetSystemProperty("ro.product.model");
std::string SDK_Version = GetSystemProperty("ro.build.version.sdk");
std::string AndroidVersion = GetSystemProperty("ro.build.version.release");
std::time_t now = std::time(0);
std::tm* localtm = std::localtime(&now);
std::string date = std::to_string(localtm->tm_year + 1900) + "/" +
std::to_string(localtm->tm_mon + 1) + "/" +
std::to_string(localtm->tm_mday);
//=====================================//
struct sConfig {
float Line;
float Skeleton;
struct sESPMenu {
bool Line;
bool Health;
bool Skeleton;
bool Box;
bool Name;
bool Distance;
bool ID;
bool ShowTarget;
bool Warning;
bool AirDrop;
bool TeamID;
bool NoBot;
bool Vehicle;
bool Vehiclehp;
bool VehicleFuel;
bool GrenadeWarn;
bool GameInfo;
bool LootBox;
};
sESPMenu ESPMenu;
struct sMEROX {
bool wide_view;
float set_field_of_view;
bool small;
bool hitef;
bool RGbcro;
};
sMEROX MEROX{0};

struct sWeaponAim {
bool Enable;
int Cross;
int Meter;
float AimSmooth;
bool Recoil;
float Recc;
EAimTarget Target;
EAimTrigger Trigger;
EAimTarget Target2;
EAimTrigger Trigger2;
bool IgnoreKnocked;
bool VisCheck;
bool IgnoreBot;
};
sWeaponAim AimBot{0};
sWeaponAim SilentAim{0};

struct sOTHER {
bool HIDEESP;
};
sOTHER OTHER{0};

struct sColorsESP {
float *Vehicle;
float *Fov1;
float *Fov2;
	    float *PlayerVisLine;
        float *PlayerHideLine;
		float *BotVisLine;
		float *BotHideLine;
        float *PlayerVisSkeleton;
        float *PlayerHideSkeleton;
        float *BotVisSkeleton;
		float *BotHideSkeleton;
        float *PlayerVisBox;
        float *PlayerHideBox;
        float *BotVisBox;
        float *BotHideBox;
};
sColorsESP ColorsESP{0};

};
sConfig Config{0};
//=====================================//


template<typename T>
void Merox(uintptr_t addr, T value) {Tools::WriteAddr((void *) addr, &value, sizeof(T));}
void AimSpeed(FRotator &angles) {
if (angles.Pitch > 180)
angles.Pitch -= 360;
if (angles.Pitch < -180)
angles.Pitch += 360;
if (angles.Pitch < -75.f)
angles.Pitch = -75.f;
else if (angles.Pitch > 75.f)
angles.Pitch = 75.f;
while (angles.Yaw < -180.0f)
angles.Yaw += 360.0f;
while (angles.Yaw > 180.0f)
angles.Yaw -= 360.0f;
}
void AimSpeed(float *angles) {
if (angles[0] > 180)
angles[0] -= 360;
if (angles[0] < -180)
angles[0] += 360;
if (angles[0] < -75.f)
angles[0] = -75.f;
else if (angles[0] > 75.f)
angles[0] = 75.f;
while (angles[1] < -180.0f)
angles[1] += 360.0f;
while (angles[1] > 180.0f)
angles[1] -= 360.0f;
}

void AimSpeed(Vector3 angles) {
if (angles.X > 180)
angles.X -= 360;
if (angles.X < -180)
angles.X += 360;
if (angles.X < -75.f)
angles.X = -75.f;
else if (angles.X > 75.f)
angles.X = 75.f;
while (angles.Y < -180.0f)
angles.Y += 360.0f;
while (angles.Y > 180.0f)
angles.Y -= 360.0f;
}long GetEpochTime()
{
auto duration = std::chrono::system_clock::now().time_since_epoch();
return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}
 



//======================| 𝗢𝗙𝗙𝗦𝗘𝗧𝗦 𝗔𝗥𝗥𝗔𝗬 |==========================//
#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};

static UEngine *GEngine = 0;
UWorld *GetWorld() {
while (!GEngine) {
GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1");
sleep(1);
}
if (GEngine) {
auto ViewPort = GEngine->GameViewport;
if (ViewPort) {
return ViewPort->World;
}}
return 0; }
TNameEntryArray *GetGNames() {
return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}

std::vector<AActor *> getActors() {
auto World = GetWorld();
if (!World)
return std::vector<AActor *>();
auto PersistentLevel = World->PersistentLevel;
if (!PersistentLevel)
return std::vector<AActor *>();
auto Actors = *(TArray<AActor *> *)((uintptr_t) PersistentLevel + 0xa0);
std::vector<AActor *> actors;
for (int i = 0; i < Actors.Num(); i++) {
auto Actor = Actors[i];
if (Actor) {
actors.push_back(Actor);
}}
return actors;
}
bool WriteAddr(void *addr, void *buffer, size_t length) {
unsigned long page_size = sysconf(_SC_PAGESIZE);
unsigned long size = page_size * sizeof(uintptr_t);
return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}
template<typename T>
void Write(uintptr_t addr, T value) {
WriteAddr((void *) addr, &value, sizeof(T));
}
template<class T>
void GetAllActors(std::vector<T *> &Actors) {
UGameplayStatics *gGameplayStatics = (UGameplayStatics *) gGameplayStatics->StaticClass();
auto GWorld = GetWorld();
if (GWorld) {
TArray<AActor *> Actors2;
gGameplayStatics->GetAllActorsOfClass((UObject *) GWorld, T::StaticClass(), &Actors2);
for (int i = 0; i < Actors2.Num(); i++) {
Actors.push_back((T *) Actors2[i]);
}
}
}
struct sRegion {uintptr_t start, end;};
std::vector<sRegion> trapRegions;
bool isObjectInvalid(UObject *obj) {
if (!Tools::IsPtrValid(obj)) {return true;}
if (!Tools::IsPtrValid(obj->ClassPrivate)) {return true;}
if (obj->InternalIndex <= 0) {return true;}
if (obj->NamePrivate.ComparisonIndex <= 0) {return true;}
if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {return true;}
if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) || std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {return true;}
return false;}

const char *getObjectPath(UObject *Object) {
std::string s;
for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
if (!s.empty())
s += ".";
s += super->GetName();}return s.c_str();}
 
int32_t ToColor(float *col) {return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));}
//======================| 𝗪𝗢𝗥𝗟𝗗 𝗘𝗦𝗣 𝗗𝗘𝗙𝗜𝗡𝗘 |==========================//
FRotator ToRotator(FVector local, FVector target) {
FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);
float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
FRotator newViewAngle = {0};
newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
newViewAngle.Roll = (float) 0.f;
if (rotation.X >= 0.f)
newViewAngle.Yaw += 180.0f;
return newViewAngle;}
//==========
FVector WorldToRadar(float Yaw,FVector Origin,FVector LocalOrigin,float PosX,float PosY,Vector3 Size,bool &outbuff) {
bool flag = false; double num = (double)Yaw; double num2 = num * 0.017453292519943295; float num3 = (float)std::cos(num2);
float num4 = (float)std::sin(num2); float num5 = Origin.X - LocalOrigin.X; float num6 = Origin.Y - LocalOrigin.Y; struct FVector Xector;
Xector.X = (num6 * num3 - num5 * num4) / 150.f; Xector.Y = (num5 * num3 + num6 * num4) / 150.f; struct FVector Xector2;
Xector2.X = Xector.X + PosX + Size.X / 2.f; Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f; bool flag2 = Xector2.X > PosX + Size.X;
if (flag2) { Xector2.X = PosX + Size.X; }else{ bool flag3 = Xector2.X < PosX; if (flag3) { Xector2.X = PosX; }} bool flag4 = Xector2.Y > PosY + Size.Y;
if (flag4) { Xector2.Y = PosY + Size.Y; }else{ bool flag5 = Xector2.Y < PosY; if (flag5){ Xector2.Y = PosY; }}bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
if (flag6){ flag = true;} outbuff = flag; return Xector2;}
//==========

void VectorAnglesRadar(Vector3 & forward, FVector & angles) {
if (forward.X == 0.f && forward.Y == 0.f) {
angles.X = forward.Z > 0.f ? -90.f : 90.f;
angles.Y = 0.f;
} else {
angles.X = MEROX(atan2(-forward.Z, forward.Magnitude(forward)));
angles.Y = MEROX(atan2(forward.Y, forward.X));
}angles.Z = 0.f;}
//===========
void RotateTriangle(std::array<Vector3, 3> & points, float rotation) {
const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
for (auto & point : points) {
point = point - points_center;
const auto temp_x = point.X;
const auto temp_y = point.Y;
const auto theta = MRB(rotation);
const auto c = cosf(theta);
const auto s = sinf(theta);
point.X = temp_x * c - temp_y * s;
point.Y = temp_x * s + temp_y * c;
point = point + points_center;}}
//===========
FVector2D pushToScreenBorder(FVector2D Pos, FVector2D PlayerScreen, int borders, int offset) {
 int x = (int)Pos.X;
 int y = (int)Pos.Y;
 if ((borders & 1) == 1) {
 y = 0 - offset;
 }
 if ((borders & 2) == 2) {
 x = (int)PlayerScreen.X + offset;
 }
 if ((borders & 4) == 4) {
 y = (int)PlayerScreen.Y + offset;
 }
 if ((borders & 8) == 8) {
 x = 0 - offset;
 }
 return FVector2D(x, y);
}

int isOutsideSafezone(FVector2D pos, FVector2D PlayerScreen) {
 FVector2D mSafezoneTopLeft(PlayerScreen.X * 0.04f, PlayerScreen.Y * 0.04f);
 FVector2D mSafezoneBottomRight(PlayerScreen.X * 0.96f, PlayerScreen.Y * 0.96f);
 int result = 0;
 if (pos.Y < mSafezoneTopLeft.Y) {
 result |= 1;
 }
 if (pos.X > mSafezoneBottomRight.X) {
 result |= 2;
 }
 if (pos.Y > mSafezoneBottomRight.Y) {
 result |= 4;
 }
 if (pos.X < mSafezoneTopLeft.X) {
 result |= 8;
 }
 return result;
}

#define W2S(w,s) UGameplayStatics::ProjectWorldToScreen(localController,w,true,s)
bool isInsideFOVs(int x, int y) {
if (!Config.AimBot.Cross) return true;
int circle_x = glWidth / 2; int circle_y = glHeight / 2;
int rad = Config.AimBot.Cross*0.5f;
return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}


auto GetTargetForAimBot() {
ASTExtraPlayerCharacter *result = 0;
float max = std::numeric_limits<float>::infinity();
auto Actors = getActors();
auto localPlayer = g_LocalPlayer;
auto localController = g_LocalController;
if (localPlayer) {
for (auto Actor : Actors) {
if (isObjectInvalid(Actor))
continue;
if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
auto Target = (ASTExtraPlayerCharacter *) Actor;

float dist = localPlayer->GetDistanceTo(Target) / 100.0f;
if (dist > Config.AimBot.Meter)
continue;

auto Player = (ASTExtraPlayerCharacter *)Actor;
if (Player->PlayerKey == localPlayer->PlayerKey)
continue;
if (Player->TeamID == localPlayer->TeamID)
continue;
if (Player->bDead)
continue;
if (Config.AimBot.IgnoreKnocked) {
if (Player->Health == 0.0f)
continue;
}
if (Config.AimBot.VisCheck) {
if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
continue;
}
if (Config.AimBot.IgnoreBot) {
if (Player->bEnsure)
continue;
}
auto Root = Player->GetBonePos("Root", {});
auto Head = Player->GetBonePos("Head", {});
FVector2D RootSc, HeadSc;
if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
float height = abs(HeadSc.Y - RootSc.Y);
float width = height * 0.65f;

FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

if (isInsideFOVs((int) middlePoint.X, (int) middlePoint.Y)) {

float dist = FVector2D::Distance(v2Middle, v2Loc);

if (dist < max) {
max = dist;
result = Player;
 }}}}}}}return result;}


const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
switch (Vehicle->VehicleShapeType) {
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart: return "Motorbike"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia: return "Dacia"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus: return "Mini Bus"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup: return "Pick Up"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy: return "Buggy"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ: return "UAZ"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117: return "PG117"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail: return"Aquarail"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01: return "Mirado"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony: return "Rony"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter: return "Scooter"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile: return"Snow Mobile"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk: return"Tuk Tuk"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike: return "Snow Bike"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard: return "Surf Board"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard: return "Snow Board"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious: return "Amphibious"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva: return "Lada Niva"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV: return"UAV"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop: return "Mega Drop"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01: return "Lamborghini"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado: return "Gold Mirado"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot: return "Big Foot"; break;
case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60: return "UH60"; break;
default: return "Vehicle"; break; } return "Vehicle";
}

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;
void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {
if (Config.SilentAim.Enable) {
ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
if (Target) {
bool triggerOk = false;
if (Config.AimBot.Trigger != EAimTrigger::None) {
if (Config.AimBot.Trigger == EAimTrigger::Shooting) {
triggerOk = g_LocalPlayer->bIsWeaponFiring;
} else if (Config.AimBot.Trigger == EAimTrigger::Scoping) {
triggerOk = g_LocalPlayer->bIsGunADS;
} else if (Config.AimBot.Trigger == EAimTrigger::Both) {
triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
} else if (Config.AimBot.Trigger == EAimTrigger::Any) {
triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
}} else triggerOk = true;
if (triggerOk) {
FVector targetAimPos = Target->GetBonePos("Head", {});
if (Config.AimBot.Target == EAimTarget::Chest) {
targetAimPos.Z -= 25.0f;
}
UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;
 if (ShootWeaponEntityComponent) {
ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
if (CurrentVehicle) {
FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
float dist = g_LocalPlayer->GetDistanceTo(Target);
auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
} else {
FVector Velocity = Target->GetVelocity();
float dist = g_LocalPlayer->GetDistanceTo(Target);
auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel)); }
FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, start);
FRotator sex = UKismetMathLibrary::Conv_VectorToRotator(fDir);
rot = sex;
}}}}
return orig_shoot_event(thiz, start, rot, weapon, unk1);
}


class FPSCounter {
protected:
unsigned int m_fps;
unsigned int m_fpscount;
long m_fpsinterval;
public:
FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
}
void update() {
m_fpscount++;
if (m_fpsinterval < time(0)) {
m_fps = m_fpscount;
m_fpscount = 0;
m_fpsinterval = time(0) + 1;
}}
unsigned int get() const {
return m_fps;
}
};

FPSCounter fps;

//=========================================================================== //

void Line(ImDrawList *draw,FVector2D origin, FVector2D dest, ImColor color)
{draw->AddLine({origin.X, origin.Y},{dest.X, dest.Y},color, 1.0f);}
bool W2S2(FVector worldPos, FVector2D *screenPos) {
return g_LocalController->ProjectWorldLocationToScreen(worldPos, true, screenPos);}
void Box4Line(ImDrawList *draw, float thicc, int x, int y, int w, int h, int color) {
 int iw = w / 4;
 int ih = h / 4;
 draw->AddRect(ImVec2(x, y),ImVec2(x + iw, y), color, thicc);
 draw->AddRect(ImVec2(x + w - iw, y),ImVec2(x + w, y), color, thicc);
 draw->AddRect(ImVec2(x, y),ImVec2(x, y + ih), color, thicc);
 draw->AddRect(ImVec2(x + w - 1, y),ImVec2(x + w - 1, y + ih), color, thicc);;

 draw->AddRect(ImVec2(x, y + h),ImVec2(x + iw, y + h), color, thicc);
 draw->AddRect(ImVec2(x + w - iw, y + h),ImVec2(x + w, y + h), color, thicc);
 draw->AddRect(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thicc);
 draw->AddRect(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thicc);
}

void DrawBoxEnemy(ImDrawList* draw, ImVec2 X, ImVec2 Y, float thicc, int color) {
draw->AddLine({ X.x, X.y }, { Y.x, Y.y }, color, thicc);
}

void DrawFilledRectangle(ImDrawList *drawList, float X, float Y, float W, float H, ImU32 Color)
{
drawList->AddRectFilled(ImVec2(X, Y), ImVec2(X - W, Y - H), Color);
}
void DrawBorderStringW(ImDrawList *draw,ImFont* pFont, float FontSize, std::wstring& Text, float X, float Y, ImColor Color ,ImColor Color2, bool Center)
{
 
 std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
 std::string Texts = myconv.to_bytes(Text).c_str();
 
  ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Texts.c_str());
  draw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y + 1.0f), Color2, Texts.c_str());
  draw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y - 1.0f), Color2, Texts.c_str());
  draw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y - 1.0f), Color2, Texts.c_str());
  draw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y + 1.0f), Color2, Texts.c_str());
  draw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Texts.c_str());
 
  
  draw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Texts.c_str());
}


void Box3D(ImDrawList *draw, Vector3 origin, Vector3 extends, ImColor col) {
origin -= extends / 2;
Vector3 one = origin;
Vector3 two = origin; two.X += extends.X;
Vector3 tree = origin; tree.X += extends.X; tree.Y += extends.Y;
Vector3 four = origin; four.Y += extends.Y;
Vector3 five = one; five.Z += extends.Z;
Vector3 six = two; six.Z += extends.Z;
Vector3 seven = tree; seven.Z += extends.Z;
Vector3 eight = four; eight.Z += extends.Z;
FVector2D s1, s2, s3, s4, s5, s6, s7, s8;
    Line(draw,s1, s2, col);
    Line(draw,s2, s3, col);
    Line(draw,s3, s4, col);
    Line(draw,s4, s1, col);
    Line(draw,s5, s6, col);
    Line(draw,s6, s7, col);
    Line(draw,s7, s8, col);
    Line(draw,s8, s5, col);
    Line(draw,s1, s5, col);
    Line(draw,s2, s6, col);
    Line(draw,s3, s7, col);
    Line(draw,s4, s8, col);}  

void DrawESP(ImDrawList *draw, int glWidth, int glHeight) {
ImGui::PushFont(tahoma);
float x = 30.0f;
float y = 300.0f;
draw->AddTextStorke(tahoma, 20, x, y, IM_COL32(255, 0, 0, 255),
"Sonic  Mod : Safe Mod");//@SN_IQQ
draw->AddTextStorke(tahoma, 20, x, y + 25, IM_COL32(255, 255, 255, 255),
"Version : V1.0");//@SN_IQQ
if (Config.AimBot.Enable) {
    draw->AddTextStorke(tahoma, 20, x, y + 50, IM_COL32(0, 255, 0, 255), "Aim : AimBot");//@SN_IQQ
}
if (Config.SilentAim.Enable) {
    draw->AddTextStorke(tahoma, 20, x, y + 50, IM_COL32(0, 255, 0, 255), "Aim : SilentAim");//@SN_IQQ
}
// لو الاتنين مش شغالين يظهر off
if (!Config.AimBot.Enable && !Config.SilentAim.Enable) {
    draw->AddTextStorke(tahoma, 20, x, y + 50, IM_COL32(255, 0, 0, 255), "Aim : off");//@SN_IQQ
}

if (Bypass) {

}

if (Config.OTHER.HIDEESP) {
HIDEESP = false;
} else {
HIDEESP = true;
} if (HIDEESP) {
static float fps = 0.0f;
fps = ImGui::GetIO().Framerate;
char FPS1[32];
snprintf(FPS1, sizeof(FPS1), " FPS : %.2f", fps);
draw->AddText({((float) density / 10.0f), 40}, IM_COL32(0, 255, 0, 255),FPS1); 


auto Actors = getActors();
int totalEnemies = 0, totalBots = 0;
ASTExtraPlayerCharacter *localPlayer = 0;
ASTExtraPlayerController *localController = 0;
//===
if (Config.AimBot.Enable) {
draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, ToColor(Config.ColorsESP.Fov1), 100, 1.0f);
}
if (Config.SilentAim.Enable) {
draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, ToColor(Config.ColorsESP.Fov1), 100, 1.0f);
}
//===
for (int i = 0; i < Actors.size(); i++) { auto Actor = Actors[i]; if (isObjectInvalid(Actor)) continue;
if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {localController = (ASTExtraPlayerController *) Actor; break;}}
//===
if (localController) {
 for (int i = 0; i < Actors.size(); i++) { auto Actor = Actors[i]; if (isObjectInvalid(Actor)) continue;
if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) { if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey == localController->PlayerKey) {
localPlayer = (ASTExtraPlayerCharacter *) Actor; break; }}} if (localPlayer) {

if (localPlayer && localPlayer->PartHitComponent) {
auto PartHitComponent = localPlayer->PartHitComponent;
auto& ConfigAngles = PartHitComponent->ConfigCollisionDistSqAngles;
if (ConfigAngles[5].Angle != 180.0f) {
for (int i = 0; i < 6; ++i) {
ConfigAngles[i].Angle = 180.0f; } } }

if (Config.MEROX.RGbcro) {
static float cnt = 0.0f;
const float RainbowSpeed = 9.0f;
const int RainbowColorCount = 7;
const float FullCircle = 360.0f;
const float IncrementValue = 0.02f;

FLinearColor rainbowColors[RainbowColorCount] = {
FLinearColor(1.0f, 0.0f, 0.0f, 1.0f),
FLinearColor(1.0f, 0.5f, 0.0f, 1.0f),
FLinearColor(1.0f, 1.0f, 0.0f, 1.0f),
FLinearColor(0.0f, 1.0f, 0.0f, 1.0f),
FLinearColor(0.0f, 0.0f, 1.0f, 1.0f),
FLinearColor(0.5f, 0.0f, 1.0f, 1.0f),
FLinearColor(1.0f, 0.0f, 1.0f, 1.0f)
};

int rainbowColorIndex = static_cast<int>(fmod(cnt * RainbowSpeed, RainbowColorCount));
FLinearColor color1 = rainbowColors[rainbowColorIndex];
FLinearColor color2 = rainbowColors[(rainbowColorIndex + 1) % RainbowColorCount];

float rainbowPhase = fmod(cnt * RainbowSpeed, 1.0f);
FLinearColor interpolatedColor = FLinearColor(
color1.R + (color2.R - color1.R) * rainbowPhase,
color1.G + (color2.G - color1.G) * rainbowPhase,
color1.B + (color2.B - color1.B) * rainbowPhase,
1.0f
);
localController->CrossHairColor = interpolatedColor;

if (cnt >= FullCircle) {
cnt = 0.0f;
} else {
cnt += IncrementValue;
}
}

if (Config.MEROX.hitef || Config.MEROX.small) {
auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
if (WeaponManagerComponent) {
auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
if (CurrentWeaponReplicated) {
auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
if (ShootWeaponEntityComp && ShootWeaponEffectComp) {
 if (Config.MEROX.small) {
ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
}
if (Config.MEROX.hitef) {
ShootWeaponEntityComp->DamageImpulse = 50;
ShootWeaponEntityComp->ExtraHitPerformScale = 50;
}

}}}}

if (Config.MEROX.wide_view) {
localPlayer->ThirdPersonCameraComponent->SetFieldOfView(Config.MEROX.set_field_of_view);
}
//==========================》AIM SITTING ============================= //

if (FakeDamage) {
auto WeaponManagerComponent = g_LocalPlayer->WeaponManagerComponent;
if (WeaponManagerComponent) {
auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3) {
auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
if (CurrentWeaponReplicated) {
auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;if (ShootWeaponComponent) {
UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
if (ShootWeaponEntityComponent) {
if (FakeDamage) {
ShootWeaponEntityComponent->BulletNumSingleShot = 0.0f;
}}}}}}}

if (FakeDamage) {
auto PartHitComponent = localPlayer->PartHitComponent;
if (PartHitComponent) {
if (PartHitComponent->ConfigCollisionDistSqAngles[5].Angle != 180.0f) {
PartHitComponent->ConfigCollisionDistSqAngles[0].Angle = 180.0f;
PartHitComponent->ConfigCollisionDistSqAngles[1].Angle = 180.0f;
PartHitComponent->ConfigCollisionDistSqAngles[2].Angle = 180.0f;
PartHitComponent->ConfigCollisionDistSqAngles[3].Angle = 180.0f;
PartHitComponent->ConfigCollisionDistSqAngles[4].Angle = 180.0f;
PartHitComponent->ConfigCollisionDistSqAngles[5].Angle = 180.0f;
}}}


 if (Config.SilentAim.Enable) {
 auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
 if (WeaponManagerComponent) {
 auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
 if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
 auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
 if (CurrentWeaponReplicated) {
 auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
 if (ShootWeaponComponent) {
 int shoot_event_idx = 174;
 auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
 static_assert(PAGE_SIZE == 4096);
 constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
 void* start = reinterpret_cast<void*>(addr & -page_size);
 uintptr_t end = (addr + len + page_size - 1) & -page_size;
 return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
 };
 auto VTable = (void **) ShootWeaponComponent->VTable;
 if (VTable && (VTable[shoot_event_idx] != shoot_event)) {
 orig_shoot_event = decltype(orig_shoot_event)(
 VTable[shoot_event_idx]);
 f_mprotect((uintptr_t)(&VTable[shoot_event_idx]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);
 VTable[shoot_event_idx] = (void *) shoot_event;
 }}}}}}

if (Config.AimBot.Enable) {
ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
if (Target) {
bool triggerOk = false;
if (Config.AimBot.Trigger != EAimTrigger::None) {
if (Config.AimBot.Trigger == EAimTrigger::Shooting) {
triggerOk = localPlayer->bIsWeaponFiring;
} else if (Config.AimBot.Trigger == EAimTrigger::Scoping) {
triggerOk = localPlayer->bIsGunADS;
} else if (Config.AimBot.Trigger == EAimTrigger::Both) {
triggerOk = localPlayer->bIsWeaponFiring && localPlayer->bIsGunADS;
} else if (Config.AimBot.Trigger == EAimTrigger::Any) {
triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
}} else triggerOk = true;
if (triggerOk){
FVector targetAimPos = Target->GetBonePos("Head", {});
if (Config.AimBot.Target == EAimTarget::Chest){
targetAimPos.Z -= 29.55f;
targetAimPos.Y -= 1.224f;}
auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
if (WeaponManagerComponent) {
auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
if ((int) propSlot.GetValue() >= 1 &&
(int) propSlot.GetValue() <= 3) {
auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
if (CurrentWeaponReplicated) {
auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
if (ShootWeaponComponent) {
UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
if (ShootWeaponEntityComponent) {
ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
if (CurrentVehicle) {
FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
float dist = localPlayer->GetDistanceTo(Target);
auto timeToTravel = dist /
ShootWeaponEntityComponent->BulletRange;
targetAimPos = UKismetMathLibrary::Add_VectorVector(
targetAimPos,
UKismetMathLibrary::Multiply_VectorFloat(
LinearVelocity, timeToTravel));
} else {
FVector Velocity = Target->GetVelocity();
float dist = localPlayer->GetDistanceTo(Target);
auto timeToTravel = dist /
ShootWeaponEntityComponent->BulletRange;
targetAimPos = UKismetMathLibrary::Add_VectorVector(
targetAimPos,
UKismetMathLibrary::Multiply_VectorFloat(
Velocity, timeToTravel));}
if (Config.AimBot.Recoil) {
if (g_LocalPlayer->bIsGunADS) {
if (g_LocalPlayer->bIsWeaponFiring) {
float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f; 
targetAimPos.Z -= dist * Config.AimBot.Recc;}}}
FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, g_LocalController->PlayerCameraManager->CameraCache.POV.Location);
FRotator Yaptr = UKismetMathLibrary::Conv_VectorToRotator(fDir);
FRotator CpYaT = localController->PlayerCameraManager->CameraCache.POV.Rotation;
Yaptr.Pitch -= CpYaT.Pitch;
Yaptr.Yaw -= CpYaT.Yaw;
Yaptr.Roll = 0.f;
AimSpeed(Yaptr);
CpYaT.Pitch += Yaptr.Pitch / 1.300f; 
CpYaT.Yaw += Yaptr.Yaw / 1.300f; 
CpYaT.Roll = 0.f;
localController->SetControlRotation(CpYaT,"");
}}}}}}}}

FVector ViewPosY{0, 0, 0};
if (localPlayer) {
ViewPosY = localPlayer->GetBonePos("Head", {});
ViewPosY.Z += 10.f;
 }

 for (auto &i : Actors) {
auto Actor = i;
if (isObjectInvalid(Actor)) continue;
if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {

		//================𝗖𝗢𝗟𝗢𝗥𝗦
        auto Player = (ASTExtraPlayerCharacter *) Actor;
        if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())){
        long PLine =  ToColor(Config.ColorsESP.PlayerVisLine);
        long BLine = ToColor(Config.ColorsESP.BotVisLine);
      	long PBox = ToColor(Config.ColorsESP.PlayerVisBox);
		long BBox = ToColor(Config.ColorsESP.BotVisBox);				
        long PSkeleton = ToColor(Config.ColorsESP.PlayerVisSkeleton);
		long BSkeleton = ToColor(Config.ColorsESP.BotVisSkeleton);					
        //=============
        auto Player = (ASTExtraPlayerCharacter *) Actor;
        if (!localController->LineOfSightTo(Player, {0, 0, 0}, true)){
        PLine = ToColor(Config.ColorsESP.PlayerHideLine);
        BLine = ToColor(Config.ColorsESP.BotHideLine);
		PBox = ToColor(Config.ColorsESP.PlayerHideBox);
        BBox = ToColor(Config.ColorsESP.BotHideBox); 
        PSkeleton = ToColor(Config.ColorsESP.PlayerHideSkeleton);
		BSkeleton = ToColor(Config.ColorsESP.BotHideSkeleton);
		}
		//=============
float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
if (Distance > 500) continue;
if (Player->PlayerKey == localController->PlayerKey) continue;
if (Player->TeamID == localController->TeamID) continue;
if (Player->bDead) continue;
if (Player->bEnsure)
totalBots++; else totalEnemies++;
if (Config.ESPMenu.NoBot)
if (Player->bEnsure) continue;
float magic_number = (Distance);
float mx = (glWidth / 4) / magic_number;
float healthLength = glWidth / 17;
int ColorVisibel; 
bool IsVisible = localController ->LineOfSightTo (Player, {0, 0, 0}, true);
if  (IsVisible) {
ColorVisibel = IM_COL32(0, 255, 0, 255); // أخضر للظاهر
} else {
ColorVisibel = IM_COL32(255, 0, 0, 255); // أحمر للمخفي
}
int SCOLOR;

if (IsVisible) {

SCOLOR = IM_COL32(0,255,0,255);

}else{

SCOLOR = IM_COL32(255,0,0,255);

}
if (healthLength < mx)
healthLength = mx;

auto HeadPos = Player->GetBonePos("Head", {}); ImVec2 headPosSC;
auto RootPos = Player->GetBonePos("Root", {}); ImVec2 RootPosSC;
auto upper_r = Player->GetBonePos("upperarm_r", {}); ImVec2 upper_rPoSC;
auto lowerarm_r = Player->GetBonePos("lowerarm_r", {}); ImVec2 lowerarm_rPoSC;
auto hand_r = Player->GetBonePos("hand_r", {}); ImVec2 hand_rPoSC;
auto upper_l = Player->GetBonePos("upperarm_l", {}); ImVec2 upper_lPoSC;
auto lowerarm_l = Player->GetBonePos("lowerarm_l", {}); ImVec2 lowerarm_lSC;
auto hand_l = Player->GetBonePos("hand_l", {}); ImVec2 hand_lPoSC;
auto thigh_l = Player->GetBonePos("thigh_l", {}); ImVec2 thigh_lPoSC;
auto calf_l = Player->GetBonePos("calf_l", {});ImVec2 calf_lPoSC;
auto foot_l = Player->GetBonePos("foot_l", {}); ImVec2 foot_lPoSC;
auto thigh_r = Player->GetBonePos("thigh_r", {}); ImVec2 thigh_rPoSC;
auto calf_r = Player->GetBonePos("calf_r", {}); ImVec2 calf_rPoSC;
auto foot_r = Player->GetBonePos("foot_r", {}); ImVec2 foot_rPoSC;
auto neck_01 = Player->GetBonePos("neck_01", {}); ImVec2 neck_01PoSC;
auto pelvis = Player->GetBonePos("pelvis", {}); ImVec2 pelvisPoSC;
//int SCOLOR = IsVisible ? IM_COL32(0, 255, 0, 255) : IM_COL32(255, 0, 0, 255);
int SCOLOR2 = IsVisible ? IM_COL32(0, 255, 0, 25) : IM_COL32(255, 0, 0, 25);
FVector2D screen(glWidth, glHeight);
float mScale = glHeight / (float)1080;
//int borders = IsOutsideSafezone(location, screen);
FVector2D top(RootPosSC.x, RootPosSC.y);
FVector2D bot(headPosSC.x, headPosSC.y);
if (top.X > bot.X)
{
top.X -= (top.X - bot.X);
}
else if (top.X < bot.X)
{
top.X += (bot.X - top.X);
}
FVector PlayerScreen{bot.X, bot.Y, std::abs(bot.Y - top.Y)};
if (W2S(HeadPos, (FVector2D *) &headPosSC) && W2S(upper_r, (FVector2D *) &upper_rPoSC) && W2S(upper_l, (FVector2D *) &upper_lPoSC) && W2S(lowerarm_r, (FVector2D *) &lowerarm_rPoSC ) && W2S(hand_r, (FVector2D *) &hand_rPoSC ) && W2S(lowerarm_l, (FVector2D *) &lowerarm_lSC ) && W2S(hand_l, (FVector2D *) &hand_lPoSC ) && W2S(thigh_l, (FVector2D *) &thigh_lPoSC ) && W2S(calf_l, (FVector2D *) &calf_lPoSC ) && W2S(foot_l, (FVector2D *) &foot_lPoSC ) && W2S(thigh_r, (FVector2D *) &thigh_rPoSC ) && W2S(calf_r, (FVector2D *) &calf_rPoSC ) && W2S(foot_r, (FVector2D *) &foot_rPoSC ) && W2S(neck_01, (FVector2D *) &neck_01PoSC ) && W2S(pelvis, (FVector2D *) &pelvisPoSC ) && W2S(RootPos, (FVector2D *) &RootPosSC)){
if (Distance < 500 && totalEnemies > 0 || totalBots > 0) {

if (Config.ESPMenu.ShowTarget) {
auto Target = GetTargetForAimBot();
if (Target) {
auto target = Target->GetBonePos("Head", {});
auto foot = Target->GetBonePos("foot_r", {});
FVector2D targetSC, footSC;
if (W2S(target, (FVector2D *) &targetSC) && W2S(foot, (FVector2D *) &footSC)) {
draw->AddLine({(float)glWidth / 2, glHeight}, {footSC.X, footSC.Y}, IM_COL32_RED, 0.5f);
}}}


// ------ESP
if (Config.ESPMenu.Skeleton) {
	    if (Player->bEnsure) {
                                float boxWidth = 7.f - Distance * 0.03;
                                draw->AddCircle({headPosSC.x, headPosSC.y}, boxWidth, BSkeleton, 0,   Config.Skeleton);
                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, neck_01PoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, neck_01PoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, lowerarm_rPoSC,   BSkeleton, Config.Skeleton);
                                draw->AddLine({lowerarm_rPoSC.x, lowerarm_rPoSC.y}, hand_rPoSC,  BSkeleton, Config.Skeleton);
                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, lowerarm_lSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({lowerarm_lSC.x, lowerarm_lSC.y}, hand_lPoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, thigh_lPoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({thigh_lPoSC.x, thigh_lPoSC.y}, calf_lPoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({calf_lPoSC.x, calf_lPoSC.y}, foot_lPoSC, BSkeleton, Config.Skeleton);
                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, calf_rPoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({calf_rPoSC.x, calf_rPoSC.y}, foot_rPoSC, BSkeleton,  Config.Skeleton);
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, pelvisPoSC, BSkeleton,   Config.Skeleton);
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, headPosSC, BSkeleton,  Config.Skeleton);
							    }else{
							    float boxWidth = 7.f - Distance * 0.03;
                                draw->AddCircle({headPosSC.x, headPosSC.y}, boxWidth, PSkeleton, 0,   Config.Skeleton);
                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, neck_01PoSC, PSkeleton,  Config.Skeleton);
                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, neck_01PoSC, PSkeleton, Config.Skeleton);
                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, lowerarm_rPoSC,    PSkeleton, Config.Skeleton);
                                draw->AddLine({lowerarm_rPoSC.x, lowerarm_rPoSC.y}, hand_rPoSC,  PSkeleton, Config.Skeleton);
                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, lowerarm_lSC, PSkeleton, Config.Skeleton);
                                draw->AddLine({lowerarm_lSC.x, lowerarm_lSC.y}, hand_lPoSC, PSkeleton,   Config.Skeleton);
                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, thigh_lPoSC, PSkeleton,  Config.Skeleton);
                                draw->AddLine({thigh_lPoSC.x, thigh_lPoSC.y}, calf_lPoSC, PSkeleton,  Config.Skeleton);
                                draw->AddLine({calf_lPoSC.x, calf_lPoSC.y}, foot_lPoSC, PSkeleton,   Config.Skeleton);
                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, calf_rPoSC, PSkeleton,    Config.Skeleton);
                                draw->AddLine({calf_rPoSC.x, calf_rPoSC.y}, foot_rPoSC, PSkeleton,  Config.Skeleton);
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, pelvisPoSC, PSkeleton,  Config.Skeleton);
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, headPosSC, PSkeleton, Config.Skeleton);
								}}
								
if (Config.ESPMenu.Box) {
float boxHeight = abs(headPosSC.y - RootPosSC.y); float boxWidth = boxHeight * 0.65f;
Box4Line(draw, 0.2f, headPosSC.x - (boxWidth / 2), headPosSC.y, boxWidth, boxHeight,SCOLOR);
}

if (Config.ESPMenu.Line) {
draw->AddLine({(float) glWidth / 2,90},headPosSC,ColorVisibel,1.0f);
}

if (Config.ESPMenu.Health) {
float MaxHP = Player->HealthMax;
float health = Player->Health;
float KnockHealth = Player->NearDeathBreath;
DrawFilledRectangle(draw, PlayerScreen.X - (PlayerScreen.Z / 4) - 4, (PlayerScreen.Y - 5) + (PlayerScreen.Z + 5), 3, (PlayerScreen.Z + 5), Black);
if (health > 70.0)
{
DrawFilledRectangle(draw, PlayerScreen.X - (PlayerScreen.Z / 4) - 4, (PlayerScreen.Y - 5) + (PlayerScreen.Z + 5), 3, (PlayerScreen.Z + 5) * health / MaxHP, Green);
}
if (health > 30.0 && health <= 70.0)
{
DrawFilledRectangle(draw, PlayerScreen.X - (PlayerScreen.Z / 4) - 4, (PlayerScreen.Y - 5) + (PlayerScreen.Z + 5), 3, (PlayerScreen.Z + 5) * health / MaxHP, Yellow);
}
if (health > 0.0 && health <= 30.0)
{
DrawFilledRectangle(draw, PlayerScreen.X - (PlayerScreen.Z / 4) - 4, (PlayerScreen.Y - 5) + (PlayerScreen.Z + 5), 3, (PlayerScreen.Z + 5) * health / MaxHP, Red);
}
if (health <= 0)
{
DrawFilledRectangle(draw, PlayerScreen.X - (PlayerScreen.Z / 4) - 4, (PlayerScreen.Y - 5) + (PlayerScreen.Z + 5), 3, (PlayerScreen.Z + 5) * KnockHealth / MaxHP, Red2);
}}

if (Config.ESPMenu.Name){
if (Player->bEnsure) {
std::wstring ws;
ws = L"Bot";
DrawBorderStringW(draw,tahoma, 16.0f, ws, headPosSC.x, headPosSC.y + -26, IM_COL32(0, 150, 255, 255), IM_COL32(0, 0, 0, 255), true);
} else {
std::wstring ws;
ws = Player->PlayerName.ToWString();
DrawBorderStringW(draw,tahoma, 16.0f, ws, headPosSC.x, headPosSC.y + -26, ImColor(255, 255, 0, 255), IM_COL32(0, 0, 0, 255), true);
}}

if (Config.ESPMenu.Distance)
{
std::wstring dist;
dist += std::to_wstring((int) Distance);
dist += L"M";
DrawBorderStringW(draw,tahoma, 16.0f, dist, PlayerScreen.X, (PlayerScreen.Y + PlayerScreen.Z + 4), IM_COL32(255, 255, 255, 255),IM_COL32(0, 0, 0, 255), true);
}
}

if (Config.ESPMenu.Warning){
bool shit = false;
FVector MyPosition, EntityPosition;
ASTExtraVehicleBase* CurrentVehicle = Player->CurrentVehicle;
if (CurrentVehicle) {MyPosition = CurrentVehicle->RootComponent->RelativeLocation; }else{ MyPosition = Player->RootComponent->RelativeLocation;}
ASTExtraVehicleBase* CurrentVehicleAI = localPlayer->CurrentVehicle;
if (CurrentVehicleAI) {EntityPosition = CurrentVehicleAI->RootComponent->RelativeLocation; }else{ EntityPosition = localPlayer->RootComponent->RelativeLocation;}
FVector EntityPos = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EntityPosition, NULL, NULL, Vector3(glWidth, glHeight, 0),shit);
FVector angle = FVector(); Vector3 toEntity = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f); VectorAnglesRadar(toEntity, angle);
const auto angle_yaw_rad = MRB(angle.Y + 180.f);
const auto new_point_x = (glWidth / 2) +(30) / 2 * 8 * cosf(angle_yaw_rad);
const auto new_point_y = (glHeight / 2) + (30) / 2 * 8 * sinf(angle_yaw_rad);
const float sphereRadius = 6.0f;
draw->AddCircleFilled(ImVec2(new_point_x, new_point_y), sphereRadius, SCOLOR);
}}

if (Config.ESPMenu.Vehicle) {
if (i->IsA(ASTExtraVehicleBase::StaticClass())){
auto Vehicle = (ASTExtraVehicleBase *) i;
if (!Vehicle->Mesh) continue;
int CurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->HP, (int) Vehicle->VehicleCommon->HPMax));
int MaxHP = (int) Vehicle->VehicleCommon->HPMax;
long curHP_Color = IM_COL32(std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255), std::min(((510 * CurHP) / MaxHP), 240), 0, 155);
float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f; if (Distance <= 400.0f) {
FVector2D vehiclePos;
if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos)) {
auto mWidthScale = std::min(0.10f * Distance, 40.f);
auto mWidth = 70.f - mWidthScale; auto mHeight = 6.15f;
bool IsVisible = localController->LineOfSightTo(Vehicle, ViewPosY, true);
std::string s = GetVehicleName(Vehicle);
s += " ["; s += std::to_string((int)Distance); s += "]";
draw->AddText(NULL, ((float)density / 30.0f), {vehiclePos.X - (mWidth / 2), vehiclePos.Y}, IM_COL32(255,255,255,255), s.c_str());

if (Config.ESPMenu.Vehiclehp){
ImVec2 vStart = {vehiclePos.X - (mWidth / 2), vehiclePos.Y + 16.1f};
ImVec2 vEndFilled = {vStart.x + (CurHP * mWidth / MaxHP), vStart.y + mHeight};
ImVec2 vEndRect = {vStart.x + mWidth, vStart.y + mHeight};
draw->AddRectFilled(vStart, vEndFilled, curHP_Color, 0.2f, 0);
draw->AddRect(vStart, vEndRect, IM_COL32(000,000,000,255), 0.2f, 0); }
if (Config.ESPMenu.VehicleFuel){
int CurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->Fuel, (int) Vehicle->VehicleCommon->FuelMax));
int MaxHP = (int) Vehicle->VehicleCommon->FuelMax;
long curHP_Color = IM_COL32(std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255),std::min((510 * CurHP) / MaxHP, 255), 0, 155);
auto mWidthScale = std::min(0.10f * Distance, 40.f);
auto mWidth = 70.f - mWidthScale; auto mHeight = 4.30f;
ImVec2 vStart = {vehiclePos.X - (mWidth / 2), vehiclePos.Y + 23.f};
ImVec2 vEndFilled = {vStart.x + (CurHP * mWidth / MaxHP), vStart.y + mHeight};
ImVec2 vEndRect = {vStart.x + mWidth, vStart.y + mHeight};
draw->AddRectFilled(vStart, vEndFilled, IM_COL32(255, 255, 255, 210));
draw->AddRect(vStart, vEndRect, IM_COL32(000,000,000,255), 0.2f, 0);
}}}}}}}

if (Config.ESPMenu.GameInfo) {
if (Actor->IsA(ASTExtraGameStateBase::StaticClass())) {
auto InGame = (ASTExtraGameStateBase *) Actor;
std::string Info;
std::string s;
std::string devText = "Dev :- SONICxVIP";
Info += "Game Information";
s += "\nTotal Alive Players: ";
s += std::to_string((int) InGame->AlivePlayerNum);
s += "\nReal Players: ";
s += std::to_string((int) InGame->PlayerNum);
s += "\nTeam Remaining: ";
s += std::to_string((int) InGame->AliveTeamNum);
s += "\nMatch Time: ";
s += std::to_string((int) InGame->ElapsedTime);
s += "s | ";
s += std::to_string((int) InGame->ElapsedTime / 60);
s += "m";

 
float boxWidth = 290.0f;  
float boxHeight = 200.0f;
float boxPosX = 50.0f; 
float boxPosY = 400.0f;

 
draw->AddRectFilled(ImVec2(boxPosX, boxPosY), ImVec2(boxPosX + boxWidth, boxPosY + boxHeight), IM_COL32(10, 10, 10, 220), 12.0f);
float titleX = boxPosX + (boxWidth / 2.0f) - (ImGui::CalcTextSize(Info.c_str()).x / 2.0f);
draw->AddText(NULL, ((float) density / 25.f), ImVec2(titleX, boxPosY + 10.0f), IM_COL32(255, 255, 255, 255), Info.c_str());
float lineStartX = boxPosX + 10.0f;
float lineEndX = boxPosX + boxWidth - 10.0f;
float lineY = boxPosY + 35.0f;  
draw->AddLine(ImVec2(lineStartX, lineY), ImVec2(lineEndX, lineY), IM_COL32(192, 192, 192, 255), 1.0f);  
draw->AddText(NULL, ((float) density / 25.f), ImVec2(boxPosX + 10.0f, boxPosY + 45.0f), IM_COL32(255, 255, 255, 255), s.c_str());
float secondLineY = boxPosY + 145.0f;  
draw->AddLine(ImVec2(lineStartX, secondLineY), ImVec2(lineEndX, secondLineY), IM_COL32(192, 192, 192, 255), 1.0f);  
draw->AddText(NULL, ((float) density / 25.f), ImVec2(boxPosX + 10.0f, secondLineY + 10.0f), IM_COL32(255, 255, 255, 255), devText.c_str());
}}
if (Config.ESPMenu.GrenadeWarn) {
if (i->IsA(ASTExtraGrenadeBase::StaticClass())) {
auto Grenade = (ASTExtraGrenadeBase *) i;
auto RootComponent = Grenade->RootComponent;
if (!RootComponent)
continue;
float Distance = Grenade->GetDistanceTo(localPlayer) / 70.0f;
FVector2D grenadePos;
if (W2S(Grenade->K2_GetActorLocation(), & grenadePos)) {
std::string s = " ";
s += std::to_string((int) Distance);
s += "M";
std::string t;
t += " Nade Nade Nade.......!";
auto textSize = ImGui::CalcTextSize2(t.c_str(), 0, ((float) density / 15.5f));
draw->AddText(font_8, ((float) density / 13.0f), ImVec2(glWidth / 2 - (textSize.x / 2), 110), IM_COL32(255, 0, 0, 90), t.c_str());
draw->AddText(font_8, ((float) density / 25.0f), {grenadePos.X - 10, grenadePos.Y - 10}, IM_COL32(255, 0, 0, 90), s.c_str());
}}}
if (Config.ESPMenu.LootBox) {
if (i->IsA(APickUpListWrapperActor::StaticClass())) {
auto Pick = (APickUpListWrapperActor *)i;
if (!Pick->RootComponent)continue;
auto PickUpDataList = (TArray<FPickUpItemData>)Pick->GetDataList();
float Distance = Pick->GetDistanceTo(localPlayer) / 100.f;
FVector2D lootPos; FVector origin, extends; std::string s;
if (W2S(Pick->K2_GetActorLocation(), & lootPos)) {
std::string s = ""; s += "[ "; s += std::to_string((int) Distance); s += " M ]";
draw->AddText(NULL, ((float) density / 15.0f), {lootPos.X, lootPos.Y}, IM_COL32(0, 255, 0, 255), s.c_str());
DrawImage((int) (lootPos.X - 20), (int) (lootPos.Y - ((float) density / 15.0f)), 40, 40, LOOTBOX.textureId); 
}}} if (Config.ESPMenu.AirDrop) {
if (i->IsA(AAirDropBoxActor::StaticClass())) {
auto DropBox = (AAirDropBoxActor *)i;
auto RootComponent = DropBox->RootComponent;
if (!RootComponent) continue;
float Distance = DropBox->GetDistanceTo(localPlayer) / 100.f;
FVector2D DropBoxPos; std::string s;
if (W2S(DropBox->K2_GetActorLocation(),&DropBoxPos)) {
std::string s = " DROP ";
draw->AddText(NULL, ((float) density / 14.0f), {DropBoxPos.X, DropBoxPos.Y},IM_COL32(255,0,0,255),s.c_str());
}}} if (Config.ESPMenu.AirDrop) {
if (i->IsA(AAirDropPlane::StaticClass())) {
auto AirDropPlane = (AAirDropPlane *)i;
auto RootComponent = AirDropPlane->RootComponent;
if (!RootComponent)continue;
float Distance = AirDropPlane->GetDistanceTo(localPlayer) / 100.f;
FVector2D AirDropPlanePos; std::string s;
if (W2S(AirDropPlane->K2_GetActorLocation(), &AirDropPlanePos)) {
std::string s = " AIR-PLANE ";
draw->AddText(NULL, ((float) density / 14.0f), {AirDropPlanePos.X, AirDropPlanePos.Y},IM_COL32(255,255,255,255),s.c_str());
}}}
if (i->IsA(APickUpWrapperActor::StaticClass())) {
auto PickUp = (APickUpWrapperActor *) i;
if (Items[PickUp->DefineID.TypeSpecificID]) {
auto RootComponent = PickUp->RootComponent;
if (!RootComponent) continue;
float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;
FVector2D itemPos;
if (W2S(PickUp->K2_GetActorLocation(), &itemPos)) {
std::string s;
uint32_t tc = 0xFF000000;
for (auto &category: items_data) {
for (auto &item: category["Items"]) {
if (item["itemId"] == PickUp->DefineID.TypeSpecificID) {
s = item["itemName"].get<std::string>();
tc = strtoul(item["itemTextColor"].get<std::string>().c_str(), 0, 16);
break; }}}
s += " - ";
s += std::to_string((int) Distance);
s += "m";
draw->AddText(NULL, ((float) density / 15.0f), {itemPos.X, itemPos.Y},IM_COL32(255,255,255,255),s.c_str());
}}}


}}}

ImGui::PopFont();
g_LocalController = localController;
g_LocalPlayer = localPlayer;
std::string s;
if (g_LocalController == 0) {
LOBBY = true;
GAME = false;
} else {
GAME = true;
LOBBY = false;
}
if (GAME || LOBBY) {
auto Flags69 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
ImVec2 center = ImGui::GetMainViewport()->GetCenter();
ImGui::SetNextWindowPos(ImVec2(center.x, 100), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
ImGui::SetNextWindowSize(ImVec2(210.0f, 35.0f));
ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0,255,0,255));
ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(0,0,0,180));
ImGui::Begin("ene", 0, Flags69);
ImGui::PopStyleColor(2);
if (GAME) {
ImGui::Text(("Total Player : %d Bots : %d"),totalEnemies,totalBots);
}
if (LOBBY) {
ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0,255,0,255));
ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 0, 255, 180));
ImGui::Text("   In Lobby");
ImGui::PopStyleColor(2);
}
ImGui::End();
}
}}
//===========================
void loadConfig() {
int fd = open("/data/data/com.tencent.ig/files/sc.ini", O_RDONLY);
read(fd, &Config, sizeof(Config));
close(fd);
}

void saveConfig() {
int fd = open("/data/data/com.tencent.ig/files/sc.ini", O_WRONLY | O_CREAT);
system("chmod 777 /data/data/com.tencent.ig/files/sc.ini");
write(fd, &Config , sizeof(Config));
close(fd);
}
void loadCFG() {
loadConfig();
}
void saveCFG() {
saveConfig();
}
//===========================
int OpenURL(const char* url) {
JavaVM* java_vm = g_App->activity->vm; JNIEnv* java_env = NULL;
jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
if (jni_return == JNI_ERR) return -1;
jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
if (jni_return != JNI_OK) return -2;
jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
if (native_activity_clazz == NULL) return -3;
jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "AndroidThunkJava_LaunchURL", "(Ljava/lang/String;)V");
if (method_id == NULL) return -4;
jstring retStr = java_env->NewStringUTF(url); java_env->CallVoidMethod(g_App->activity->clazz, method_id, retStr);
jni_return = java_vm->DetachCurrentThread();
if (jni_return != JNI_OK) return -5; return 0; }
std::string getClipboardText() {
if (!g_App)
return "";

auto activity = g_App->activity;
if (!activity)
return "";

auto vm = activity->vm;
if (!vm)
return "";

auto object = activity->clazz;
if (!object)
return "";

std::string result;

JNIEnv *env;
vm->AttachCurrentThread(&env, 0);
{
auto ContextClass = env->FindClass("android/content/Context");
auto getSystemServiceMethod = env->GetMethodID(ContextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");

auto str = env->NewStringUTF("clipboard");
auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
env->DeleteLocalRef(str);

auto ClipboardManagerClass = env->FindClass("android/content/ClipboardManager");
auto getText = env->GetMethodID(ClipboardManagerClass, "getText", "()Ljava/lang/CharSequence;");

auto CharSequenceClass = env->FindClass("java/lang/CharSequence");
auto toStringMethod = env->GetMethodID(CharSequenceClass, "toString", "()Ljava/lang/String;");

auto text = env->CallObjectMethod(clipboardManager, getText);
if (text) {
str = (jstring) env->CallObjectMethod(text, toStringMethod);
result = env->GetStringUTFChars(str, 0);
env->DeleteLocalRef(str);
env->DeleteLocalRef(text);
}

env->DeleteLocalRef(CharSequenceClass);
env->DeleteLocalRef(ClipboardManagerClass);
env->DeleteLocalRef(clipboardManager);
env->DeleteLocalRef(ContextClass);
}
vm->DetachCurrentThread();

return result;
}


const char *GetAndroidID(JNIEnv *env, jobject context) {
jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());
auto obj = env->CallObjectMethod(context, getContentResolverMethod);
auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceModel(JNIEnv *env) {
jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());
auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
return env->GetStringUTFChars(str, 0);
}
const char *GetDeviceBrand(JNIEnv *env) {
jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());
auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/ StrEnc("YN4DaP)!{wRGN}", "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18", 14).c_str(), /*()Ljava/lang/String;*/ StrEnc("VnpibEspM(b]<s#[9cQD", "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F", 20).c_str());
auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
return env->GetStringUTFChars(str, 0);
}
const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());
auto len = strlen(uuid);
jbyteArray myJByteArray = env->NewByteArray(len);
env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);
jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());
auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
return env->GetStringUTFChars(str, 0);
}
struct MemoryStruct {
char *memory;
size_t size;
};
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
size_t realsize = size * nmemb;
struct MemoryStruct *mem = (struct MemoryStruct *) userp;
mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
if (mem->memory == NULL) {
return 0;
}
memcpy(&(mem->memory[mem->size]), contents, realsize);
mem->size += realsize;
mem->memory[mem->size] = 0;
return realsize;
}


std::string Login(const char *user_key) {
if (!g_App)
return "Internal Error";
auto activity = g_App->activity;
if (!activity)
return "Internal Error";
auto vm = activity->vm;
if (!vm)
return "Internal Error";
auto object = activity->clazz;
if (!object)
return "Internal Error";
JNIEnv *env;
vm->AttachCurrentThread(&env, 0);
std::string hwid = user_key;
hwid += GetAndroidID(env, object);
hwid += GetDeviceModel(env);
hwid += GetDeviceBrand(env);
std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
vm->DetachCurrentThread();
std::string errMsg;
struct MemoryStruct chunk{};
chunk.memory = (char *) malloc(1);
chunk.size = 0;
CURL *curl;
CURLcode res;
curl = curl_easy_init();


if(curl) {
curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, /*POST*/ StrEnc(",IL=", "\x7C\x06\x1F\x69", 4).c_str());
std::string api_key = OBFUSCATE("https://venomkey.com/connect");
curl_easy_setopt(curl, CURLOPT_URL, (api_key.c_str()));
curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, /*https*/ StrEnc("!mLBO", "\x49\x19\x38\x32\x3C", 5).c_str());
struct curl_slist *headers = NULL;
headers = curl_slist_append(headers, /*Content-Type: application/x-www-form-urlencoded*/ StrEnc("@;Ls\\(KP4Qrop`b#d3094/r1cf<c<=H)AiiBG6i|Ta66s2[", "\x03\x54\x22\x07\x39\x46\x3F\x7D\x60\x28\x02\x0A\x4A\x40\x03\x53\x14\x5F\x59\x5A\x55\x5B\x1B\x5E\x0D\x49\x44\x4E\x4B\x4A\x3F\x04\x27\x06\x1B\x2F\x6A\x43\x1B\x10\x31\x0F\x55\x59\x17\x57\x3F", 47).c_str());
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

char data[4096];
sprintf(data, /*game=PUBG&user_key=%s&serial=%s*/ StrEnc("qu2yXK,YkJyGD@ut0.u~Nb'5(:.:chK", "\x16\x14\x5F\x1C\x65\x1B\x79\x1B\x2C\x6C\x0C\x34\x21\x32\x2A\x1F\x55\x57\x48\x5B\x3D\x44\x54\x50\x5A\x53\x4F\x56\x5E\x4D\x38", 31).c_str(), user_key, UUID.c_str());
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

res = curl_easy_perform(curl);
if (res == CURLE_OK) {
try {
json result = json::parse(chunk.memory);
if (result[/*status*/ StrEnc("(>_LBm", "\x5B\x4A\x3E\x38\x37\x1E", 6).c_str()] == true) {
std::string token = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*token*/ StrEnc("{>3Lr", "\x0F\x51\x58\x29\x1C", 5).c_str()].get<std::string>();
time_t rng = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();

if (rng + 30 > time(0)) {
std::string auth = /*PUBG*/ StrEnc("Q*) ", "\x01\x7F\x6B\x67", 4).c_str();;
auth += "-";
auth += user_key;
auth += "-";
auth += UUID;
auth += "-";
auth += /*Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E*/ StrEnc("-2:uwZdV^%]?{{wHs2V,+(^NJU;kC*_{", "\x7B\x5F\x02\x39\x1C\x6D\x31\x3C\x6C\x6F\x30\x4C\x11\x38\x27\x1E\x23\x64\x3C\x5E\x67\x49\x69\x34\x2D\x33\x43\x58\x36\x50\x66\x3E", 32).c_str();
std::string outputAuth = Tools::CalcMD5(auth);

g_Token = token;
g_Auth = outputAuth;
bValid = g_Token == g_Auth;
EXP = result["data"]["EXP"].get<std::string>();
status = result ["data"]["mod_status"];
device = result ["data"]["device"];
floating = result ["data"]["credit"];
name = result ["data"]["modname"];
}} else {
errMsg = result[/*reason*/ StrEnc("LW(3(c", "\x3E\x32\x49\x40\x47\x0D", 6).c_str()].get<std::string>();
}} catch (json::exception &e) {
errMsg = "{";
errMsg += e.what();
errMsg += "}\n{";
errMsg += chunk.memory;
errMsg += "}";}} else {
errMsg = curl_easy_strerror(res);
}}
curl_easy_cleanup(curl);
return bValid ? "OK" : errMsg;
}
//========================================================================= //
#include "Mod/Draw.h"
#define IM_CLAMP(V,MN,MX) ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))


EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
if (glWidth <= 0 || glHeight <= 0)
return orig_eglSwapBuffers(dpy, surface);
if (!g_App)
return orig_eglSwapBuffers(dpy, surface);
screenWidth = ANativeWindow_getWidth(g_App->window);
screenHeight = ANativeWindow_getHeight(g_App->window);
density = AConfiguration_getDensity(g_App->config);


//========================================================================= //
if (!initImGui) {
IMGUI_CHECKVERSION();
ImGui::CreateContext();
InitTexture();
ImGui::StyleColorsDark();
ImGuiStyle& s = ImGui::GetStyle();

s.Colors[ImGuiCol_WindowBg] = ImColor(22, 21, 26, 255);
s.Colors[ImGuiCol_ChildBg] = ImColor(22, 21, 26, 255);
s.Colors[ImGuiCol_PopupBg] = ImColor(17, 16, 21, 255);
s.Colors[ImGuiCol_TextDisabled] = ImColor(66, 65, 70, 255);
s.Colors[ImGuiCol_Border] = ImColor(14, 13, 19, 255);
s.Colors[ImGuiCol_TextSelectedBg] = ImColor(35, 32, 43, 160);
s.FrameRounding = 4.f;
s.ItemInnerSpacing = ImVec2(10, 0);
s.ItemSpacing = ImVec2(0, 10);

ImGui_ImplAndroid_Init();
ImGui_ImplOpenGL3_Init("#version 300 es");

ImGuiIO &io = ImGui::GetIO();

io.ConfigWindowsMoveFromTitleBarOnly = true;
io.IniFilename = nullptr;
static const ImWchar ranges[] = {
0x0020, 0x00FF,
0x2010, 0x205E,
0x0600, 0x06FF,
0xFE00, 0xFEFF,
0,
};

static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
ImFontConfig icons_config;
icons_config.MergeMode = true;
icons_config.PixelSnapH = true;
icons_config.OversampleH = 2.5;
icons_config.OversampleV = 2.5;

ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(Tahomabd_data, Tahomabd_size, 17.0f, NULL, &ranges[0]); 
io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 18.0f, &icons_config, icons_ranges);
tahoma = io.Fonts->AddFontFromMemoryTTF((void *)tahoma_data, tahoma_size, 25.0f, NULL, &ranges[0]); 

ImFontConfig CustomFont;
CustomFont.FontDataOwnedByAtlas = false;
io.MouseDrawCursor = true;
ImFontConfig cfg;
cfg.SizePixels = ((float)density / 100.0f);
io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 18.0f, &CustomFont);
memset(&Config, 0, sizeof(sConfig));
//===============================ESPCOLOR ================================== //
Config.ColorsESP.Fov1 = CREATE_COLOR(0, 0, 0, 255);
initImGui = true;
}
ImGuiIO &io = ImGui::GetIO();
ImGui_ImplOpenGL3_NewFrame();
ImGui_ImplAndroid_NewFrame(glWidth,glHeight);
ImGui::NewFrame();
io.MouseDrawCursor = true;
Config.AimBot.Meter = 250;
Config.AimBot.Recoil = true;
Config.AimBot.VisCheck = true;
        Config.ColorsESP.BotVisLine = CREATE_COLOR(0, 255, 0, 255);    // أخضر
Config.ColorsESP.BotHideLine = CREATE_COLOR(255, 0, 0, 255);   // أحمر
Config.ColorsESP.PlayerVisLine = CREATE_COLOR(0, 255, 0, 255); // أخضر
Config.ColorsESP.PlayerHideLine = CREATE_COLOR(255, 0, 0, 255);// أحمر

Config.ColorsESP.BotVisBox = CREATE_COLOR(0, 255, 0, 255);     // أخضر
Config.ColorsESP.BotHideBox = CREATE_COLOR(255, 0, 0, 255);    // أحمر
Config.ColorsESP.PlayerVisBox = CREATE_COLOR(0, 255, 0, 255);  // أخضر
Config.ColorsESP.PlayerHideBox = CREATE_COLOR(255, 0, 0, 255); // أحمر

Config.ColorsESP.BotVisSkeleton = CREATE_COLOR(0, 255, 0, 255);// أخضر
Config.ColorsESP.BotHideSkeleton = CREATE_COLOR(255, 0, 0, 255);// أحمر
Config.ColorsESP.PlayerVisSkeleton = CREATE_COLOR(0, 255, 0, 255);// أخضر
Config.ColorsESP.PlayerHideSkeleton = CREATE_COLOR(255, 0, 0, 255);// أحمر
DrawESP(ImGui::GetBackgroundDrawList(), glWidth, glHeight);
//========================================================================= //
static float W1, W2;
static float B1, B2, B3;
static float S1;
static bool ShowMainMenu;
// if (ImGui::Begin("EdIt Menu")) {
// ImGui::SliderFloat("W1", &W1, 0.f, 1000.f);
// ImGui::SliderFloat("W2", &W2, 0.f, 1000.f);

// ImGui::SliderFloat("B1", &B1, 0.f, 600.f);
// ImGui::SliderFloat("B2", &B2, 0.f, 600.f);
// ImGui::SliderFloat("B3", &B3, 0.f, 600.f);

// ImGui::SliderFloat("S1", &S1, 0.f, 600.f);
// }
// ImGui::End();

if (ImGui::Begin(" Menu", 0, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground )) {
ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding,11.0);
ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 0, 0, 255));
ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0,0,0,255));
if (ImGui::Button("</>", ImVec2(95, 30))) {
ShowMainMenu = true;
}

ImGui::SetNextWindowSize(ImVec2(W1, W2));
if(ShowMainMenu){
static int MenuTab = 1;
static int TabHome = 0;
static int EspTab = 0; 
static bool p_open = false;
char buf[128];
ImVec2 center = ImGui::GetMainViewport()->GetCenter();
ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
sprintf(buf, (OBFUSCATE("")),(io.Framerate), ImGui::GetFrameCount());
ImGui::Begin(buf, &ShowMainMenu, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse| ImGuiWindowFlags_AlwaysAutoResize);
ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
ImVec2 P1, P2;
ImDrawList* pDrawList;
const auto& p = ImGui::GetWindowPos();
const auto& pWindowDrawList = ImGui::GetWindowDrawList();
const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();
const ImVec2 pos = ImGui::GetWindowPos();
ImDrawList* draw = ImGui::GetWindowDrawList();
static bool isLogin = true;
if (!isLogin) {
W1 = 470;
W2 = 0;
ImGui::PushItemWidth(-1);
static char s[64];
ImGui::Text("Key");
ImGui::SameLine();
ImGui::InputText("##key", s, sizeof s);
ImGui::PopItemWidth();
static std::string err;
if (ImGui::Button("Paste Key", ImVec2(461,0))) {
auto key = getClipboardText();
strncpy(s, key.c_str(), sizeof s);
}
if (ImGui::Button("Check", ImVec2(461,0))) {
err = Login(s);
if (err == "OK") {
isLogin = bValid && g_Auth == g_Token;
}}
if (!err.empty() && err != "OK") {
ImGui::Text("Server Response: %s", err.c_str());
}} else {
W1 = 600;
W2 = 400;
ImGuiIO io = ImGui::GetIO();
ImGui::BeginGroup();

ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 1.0f);
ImGui::PushStyleColor(ImGuiCol_Border,        IM_COL32(40, 120, 200, 200)); // أزرق غامق هادي
ImGui::PushStyleColor(ImGuiCol_Separator,     IM_COL32(30, 90, 160, 180)); // أهدى شوية
ImGui::PushStyleColor(ImGuiCol_WindowBg,      IM_COL32(10, 10, 12, 255));  // أسود دب ناعم
ImGui::PushStyleColor(ImGuiCol_Button,        IM_COL32(20, 20, 25, 200));  // زرار أسود رمادي
ImGui::PushStyleColor(ImGuiCol_ButtonActive,  IM_COL32(35, 110, 190, 220)); // أزرق وقت الضغط

ImGui::BeginChild("##io", ImVec2(120, 0), true); {
ImGui::Text("• SONIC");
ImGui::Separator();
if (ImGui::Button("Home", ImVec2(110, 0))) MenuTab = 1;
ImGui::Separator();
if (ImGui::Button("Esp", ImVec2(110, 0))) MenuTab = 2;
ImGui::Separator();
if (ImGui::Button("Aim", ImVec2(110, 0))) MenuTab = 3;
ImGui::Separator();
if (ImGui::Button("More", ImVec2(110, 0))) MenuTab = 4;
ImGui::Separator();
if (ImGui::Button("Skin", ImVec2(110, 0))) MenuTab = 5;
ImGui::Separator();
ImGui::EndChild();

ImGui::EndGroup();
ImGui::SameLine();
ImGui::BeginGroup();
if (MenuTab == 1) {
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10.0f); // 10 = مدى الانحناء
ImGui::BeginChild("merox##", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
if (ImGui::Button("SONICxVIP Cheat", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Separator();
if (ImGui::Button("Save")) {
saveCFG();
}
ImGui::SameLine();
if (ImGui::Button("Load")) {
loadCFG();
}
ImGui::SameLine();
if (ImGui::Button("Clean Fale")) {
const char* report = "/storage/emulated/0/Android/data/com.tencent.ig/files/iMSDK";
system(OBFUSCATE("rm -rf /storage/emulated/0/.backups"));
system(OBFUSCATE("rm -rf /storage/emulated/0/Tencent"));
system(OBFUSCATE("rm -rf /storage/emulated/0/.sstmp"));
system(OBFUSCATE("rm -rf /storage/emulated/0/QTAudioEngine"));
system(OBFUSCATE("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/ca-bundle.pem"));
system(OBFUSCATE("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs"));
system(OBFUSCATE("rm -rf /data/data/com.tencent.ig/app"));
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileListAddtional.json");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/iMSDK");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/log");
system("rm -rf /storage/emulated/0/Android/data/com.tencent.ig/files/TGPA");
if (std::remove(report) == 0) {
ImGui::Text("Done");
} else {
ImGui::Text("Error");
}
return 0;
}  
ImGui::Separator();
ImGui::TextColored(ImVec4(224, 189, 255, 200), ICON_FA_USERS"Developers :");
ImGui::BeginChild("child_developers", ImVec2(0, 43.511), true); {
ImGui::Text("- @SN_IQQ");
}
ImGui::EndChild(); 
ImGui::Separator();
ImGui::TextColored(ImVec4(224, 189, 255, 200),ICON_FA_CALENDAR "How Play :");
ImGui::BeginChild("child_how_play", ImVec2(0, 75), true); {
ImGui::BulletText("Avoid Reports");
ImGui::BulletText("Don't kill enemies brutally");
ImGui::BulletText("Regular Update And Support");
}
ImGui::EndChild(); 
ImGui::Separator();
ImGui::TextColored(ImVec4(224, 0, 0, 200), "Send feedback photos so the Key is not stopped!!!");
ImGui::Separator();
ImGui::TextColored(ImVec4(255,0,0,200), "SONICxVIP - Version 1.4");
ImGui::TextColored(ImVec4(255,0,0,200), "Send Feedback @SN_IQQ");

ImGui::EndChild(); 
}}

if (MenuTab == 2) {
if (ImGui::Button("Enemy", ImVec2(0,0))) EspTab = 1;
ImGui::SameLine();
if (ImGui::Button("Itam", ImVec2(0,0))) EspTab = 2;
if (EspTab == 1) {
if (ImGui::Button(ICON_FA_USERS" Enemy", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Checkbox("Line", &Config.ESPMenu.Line);
ImGui::SameLine();
ImGui::Checkbox("Skeleton ", &Config.ESPMenu.Skeleton);
ImGui::SameLine();
ImGui::Checkbox("Health", &Config.ESPMenu.Health);
ImGui::Checkbox("Alert", &Config.ESPMenu.Warning);
ImGui::SameLine();
ImGui::Checkbox("Box", &Config.ESPMenu.Box);
ImGui::SameLine();
ImGui::Checkbox("Name", &Config.ESPMenu.Name);
ImGui::SameLine();
//ImGui::Checkbox("Team ID", &Config.ESPMenu.TeamID);
//ImGui::SameLine();
ImGui::Checkbox("Distance", &Config.ESPMenu.Distance);
//ImGui::SameLine();
//ImGui::Checkbox("Id Player", &Config.ESPMenu.ID);
if (ImGui::Button(ICON_FA_DROPBOX" World", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Checkbox("AirDrop", &Config.ESPMenu.AirDrop);
ImGui::SameLine();
ImGui::Checkbox("Vehicle", &Config.ESPMenu.Vehicle);
ImGui::SameLine();
ImGui::Checkbox("LootBox", &Config.ESPMenu.LootBox);
ImGui::SameLine();
ImGui::Checkbox("Grenade", &Config.ESPMenu.GrenadeWarn);
if (ImGui::Button(ICON_FA_COG" Settings Esp", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Checkbox("Hide Esp", &Config.OTHER.HIDEESP);
ImGui::SameLine();
ImGui::Checkbox("No Bot", &Config.ESPMenu.NoBot);
ImGui::SameLine();
ImGui::Checkbox("Info", &Config.ESPMenu.GameInfo);
ImGui::SliderFloat("Thickness Skeleton", &Config.Skeleton, 0.f, 10.f);
ImGui::SliderFloat("Thickness Line", &Config.Line, 0.f, 10.f);
/*ImGui::Text("Change ESP");
ImGui::SameLine();
ImGui::InputInt("##Esp", &EspStyle);*/
}
if (EspTab == 2) {
for (auto &i : items_data) {
if (ImGui::TreeNode(i["Category"].get<std::string>().c_str())) {
for (auto &item : i["Items"]) {
ImGui::Checkbox(item["itemName"].get<std::string>().c_str(),
(bool *) &Items[item["itemId"].get<int>()]);
}
ImGui::TreePop();
}}}
}
if (MenuTab == 3) {
static int Set = 1;

switch (Set) {
    case 1:
        Config.AimBot.Target = EAimTarget::Head;
        break;
    case 2:
        Config.AimBot.Target = EAimTarget::Chest;
        break;
}
ImGui::Separator();
if (ImGui::Button(ICON_FA_INFO_CIRCLE" Aim Menu", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Checkbox("AimBot", &Config.AimBot.Enable); 
ImGui::SameLine();
ImGui::Checkbox("SilentAim", &Config.SilentAim.Enable); 
ImGui::SameLine();
ImGui::Checkbox("TargetAim", &Config.ESPMenu.ShowTarget);
ImGui::Checkbox("Fix Fake Damage", &FakeDamage);
ImGui::Separator();

if (ImGui::Button(ICON_FA_COG" Settings Aim", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Separator();
ImGui::Checkbox("IgnoreKnock", &Config.AimBot.IgnoreKnocked);
ImGui::SameLine();
ImGui::Checkbox("IgnoreBot", &Config.AimBot.IgnoreBot);
ImGui::Text("Aim Meter • ");
ImGui::SameLine();
ImGui::TextColored(ImVec4(0, 255, 0, 255),"250");
ImGui::SameLine();
ImGui::Text(" VisCheck • ");
ImGui::SameLine();
ImGui::TextColored(ImVec4(0, 255, 0, 255),"Activated");
ImGui::Separator();
ImGui::Separator();
ImGui::TextColored(ImVec4(0, 255, 0, 255),"Aim Set");
//ImGui::SameLine();
//ImGui::RadioButton("Head",&Set,1);
ImGui::SameLine();
ImGui::RadioButton("Body",&Set,2);
static const char *triggers[] = {"ANY(Scope/Fire)", "Shooting(Fire)", "Scoping(Scope)", "Both(Scope+Fire)", "NONE(All Time)"};
ImGui::Combo("Trigger", (int *) &Config.AimBot.Trigger, triggers, 5, -1);
ImGui::Separator();
ImGui::Separator();
ImGui::SliderFloat("Recoil", &Config.AimBot.Recc, 0.0f, 1.500f,"%.3f" );
ImGui::SliderInt("FOV SIZE", &Config.AimBot.Cross, 0.0f, 200.0f);
ImGui::Separator();
}
if (MenuTab == 4) {

if (ImGui::Button("Memory", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)));
ImGui::Checkbox("Ipad",&Config.MEROX.wide_view);
ImGui::SameLine();
ImGui::Checkbox("Het-x",&Config.MEROX.hitef);
ImGui::SameLine();
//ImGui::Checkbox("Small Cross",&Config.MEROX.small);
//ImGui::SameLine();
ImGui::Checkbox("Rgb Cross",&Config.MEROX.RGbcro);
if (Config.MEROX.wide_view) {
ImGui::SliderFloat("Review Ipad", &Config.MEROX.set_field_of_view, 50.0, 140);
}
}

if (MenuTab == 5) {
static int PlayerMenu;
static int WeaponMenu;
static int CarsMenu;
static int z = 0;
switch (z) {
case 0:
PlayerMenu = false;
WeaponMenu = false;
CarsMenu = false;
 break;
case 1:
PlayerMenu = true;
WeaponMenu = false;
CarsMenu = false;
break;
case 2:
PlayerMenu = false;
WeaponMenu = true;
CarsMenu = false;
break;
case 3:
PlayerMenu = false;
WeaponMenu = false;
CarsMenu = true;
break;
}
ImGui::TableNextColumn();
ImGui::Separator();
ImGui::Checkbox("Mod Skin", &ModSkinn);
ImGui::SameLine();
ImGui::Checkbox("kill message", &KillMessage);
ImGui::SameLine();
ImGui::Checkbox("Deadbox", &DeasBoxSkin);
ImGui::SameLine();
ImGui::Checkbox("HideName", &HideName);
ImGui::Separator();
ImGui::RadioButton("Outfits",&z,1);
ImGui::SameLine();
ImGui::RadioButton("Guns",&z,2);
ImGui::SameLine();
ImGui::RadioButton("Cars",&z,3);
ImGui::Separator();
ImGui::TableNextColumn();

if(PlayerMenu){
ImGui::Checkbox("X-SUIT", &preferences.Outfit);
ImGui::SameLine();
const char* XSuitsList[] = {"Nothing"
,"Golden Pharaoh X-Suit"
,"Blood Raven X-Suit"
,"Poseidon X-Suit"
,"Avalanche X-Suit"
,"Silvanus X-Suit"
,"Iridescence X-Suit"
,"Arcane Jester X-Suit"
,"Stygian Liege X-Suit"
,"Marmoris X-Suit"
,"Fiore X-Suit"
,"Galadria X-Suit"
,"Golden Pharaoh X-Suit"
,"Arcane Jester X-Suit"
,"Wedding Dress"
,"Mummy Set"
,"Temperance's Virtue Set"
,"Serene Lumina Set"
,"Spectral Admiral Set"
,"Invader Set"
,"Glacier Set"
,"Modern Lord Set"
,"Black Shark Diving Suit"
,"Fireman Suit"
,"Lonzo Ball Jersey"
,"Andre Drummond Jersey"
,"Isaiah Thomas Jersey"
,"Ben Simmons Jersey"
,"Angel Wings Set"
,"Devil Wings Set"
,"Masked Psychic Robe"
,"Armed Maid Suit"
,"Ryan Set"};
ImGui::Combo("##XSuits", &preferences.Config.Skin.XSuits, XSuitsList, IM_ARRAYSIZE(XSuitsList));
start = std::chrono::high_resolution_clock::now();
prevXSuits = preferences.Config.Skin.XSuits;
ImGui::TableNextColumn();
const char* BagSkins[] = {"Normal"
,"Blood Raven Backpack"
,"The fool backpack"
,"Pharaoh's Regalia Backpack"
,"Mystique Splendor Backpack"
,"Frosty Snowglobe Backpack"
,"Illusion Judge Backpack"
,"Arctic Witch Backpack"
,"8-bit Unicorn Backpack"
,"Count Backpack"
,"Butterfly Wings Backpack"};
ImGui::Combo("##bag", &preferences.bag, BagSkins, IM_ARRAYSIZE(BagSkins));
start = std::chrono::high_resolution_clock::now();
prevXSuits = preferences.bag;
ImGui::TableNextColumn();
const char* helmetSkins[] = {"Normal"
,"Inferno Rider Helmet"
,"Masked Psychic Helmet"
,"PUBLING Helmet"
,"Angry Pumpkin Helmet"
,"Glacier Helmet"
,"Angry Pumpkin Helmet"
,"Techno Helmet"
,"Regal Overlord Helmet"
,"Adorable Mouse Helmet"};
ImGui::Combo("##XSuits", &preferences.helmet, helmetSkins, IM_ARRAYSIZE(helmetSkins));
ImGui::TableNextColumn();
}

if (WeaponMenu) {
const char* m416Skins[] = {"Normal"
,"Glacier - M416"
,"The Fool - M416"
,"Wanderer - M416"
,"Lizard Roar - M416"
,"Call of the Wild - M416"
,"TechnoCore - M416"
,"Imperial Splendor - M416"
,"Silver Guru - M416"
,"Tidal Embrace - M416"
,"Shinobi Kami - M416"
,"Sealed Nether - M416"
,"Roaring Immolation - M416"
};
ImGui::Combo("##m416", &preferences.Config.Skin.M416, m416Skins, IM_ARRAYSIZE(m416Skins));
ImGui::TableNextColumn();
const char* AkmSkins[] = {"None"
,"Glacier"
,"Sculpture"
,"The Seven Seas"
,"Roaring Tiger"
,"Desert Fossil"
,"Jack-o'-lantern"
,"Ghillie Dragon"
,"Gold Pirate"
,"Codebreaker"
,"Wandering Tyrant"
,"Starsea Admiral"
,"Bunny Munchkin"
,"Decisive Day"
,"Lightshift Temple (Divine Moon)"
,"Lightshift Temple (Gold Feather)"};
ImGui::Combo("##akm", &preferences.Config.Skin.AKM, AkmSkins, IM_ARRAYSIZE(AkmSkins));
ImGui::TableNextColumn();
const char* ScarSkins[] = {"Normal"
,"Water Blaster - SCAR-L"
,"Enchanted Pumpkin - SCAR-L"
,"Operation Tomorrow - SCAR-L"
,"Hextech Crystal - SCAR-L"
,"Thorn of Malice - SCAR-L"
,"Bloodstained Nemesis - SCAR-L"
,"Folly's Clasp - SCAR-L"
,"Serene Lumina - SCAR-L"
,"Drop the Bass - SCAR-L"};

ImGui::Combo("##scar", &preferences.Config.Skin.Scar, ScarSkins, IM_ARRAYSIZE(ScarSkins));
ImGui::TableNextColumn();

const char* M762Skins[] = {"Normal"
,"8-bit Unicorn - M762"
,"Concerto of Love - M762"
,"Deadly Precision - M762"
,"Stray Rebellion - M762"
,"Starcore - M762"
,"Messi Football Icon - M762"
,"Noctum Sunder - M762"
,"Luminous Muse - M762"
,"Skeletal Carver - M762"
,"Platinum Skeleton - M762"
,"Soulspecter Shredder - M762"};
ImGui::Combo("##m76", &preferences.Config.Skin.M762, M762Skins, IM_ARRAYSIZE(M762Skins));
ImGui::TableNextColumn();
const char* P90Skins[] = {"Normal"
,"Angry Sheep - P90"
,"Evangelion-00 - P90"
,"Dancing Prints - P90 "
,"Fairytale Scarecrow - P90"
,"Polished Splendor - P90"
,"Devious Cybercat - P90"};
ImGui::Combo("##p90", &preferences.Config.Skin.P90, P90Skins, IM_ARRAYSIZE(P90Skins));
ImGui::TableNextColumn();
const char* M24Skins[] = {
    "Normal",
    "The Seven Seas - M24",
    "Pharaoh's Might - M24",
    "Lady Butterfly - M24",
    "Killer Tune - M24",
    "Circle of Life - M24",
    "Cadence Maestro - M24",
    "Industry Edge - M24"
};
ImGui::Combo("##m24", &preferences.Config.Skin.M24, M24Skins, IM_ARRAYSIZE(M24Skins));
ImGui::TableNextColumn();
const char* AWMSkins[] = {
    "Normal",
    "Mauve Avenger - AWM",
    "Field Commander - AWM",
    "Godzilla - AWM",
    "Rainbow Drake - AWM",
    "Flamewave - AWM",
    "Serpengleam - AWM"
};
ImGui::Combo("##awm", &preferences.Config.Skin.AWM, AWMSkins, IM_ARRAYSIZE(AWMSkins));
ImGui::TableNextColumn();
}
if (CarsMenu) {
if (ImGui::BeginTable("##ModCar", 3, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
ImGui::TableSetupColumn("Enable", 0, 50);
ImGui::TableSetupColumn("Name", 0, 60);
ImGui::TableSetupColumn("Skin", 0, 60);
ImGui::TableHeadersRow();
ImGui::TableNextRow();

ImGui::TableNextColumn();

ImGui::Checkbox("###0", &preferences.Dacia);
ImGui::TableNextColumn();
ImGui::Text("Dacia");
ImGui::TableNextColumn();
ImGui::InputInt("##card", &preferences.Config.Skin.Dacia);
ImGui::TableNextColumn();


ImGui::Checkbox("###1", &preferences.CoupeRB);
ImGui::TableNextColumn();
ImGui::Text("Coupe RB");
ImGui::TableNextColumn();
ImGui::InputInt("##carc", &preferences.Config.Skin.CoupeRP);
ImGui::TableNextColumn();


ImGui::Checkbox("###2", &preferences.UAZ);
ImGui::TableNextColumn();
ImGui::Text("UAZ");
ImGui::TableNextColumn();
ImGui::InputInt("##caru", &preferences.Config.Skin.UAZ);
ImGui::TableNextColumn();

ImGui::Checkbox("###23", &preferences.Moto);
ImGui::TableNextColumn();
ImGui::Text("MotoBike");
ImGui::TableNextColumn();
ImGui::InputInt("##moto", &preferences.Config.Skin.Moto);

ImGui::TableNextColumn();
ImGui::Checkbox("###235", &preferences.BigFoot);
ImGui::TableNextColumn();
ImGui::Text("BigFoot");
ImGui::TableNextColumn();
ImGui::InputInt("##Bigfoot", &preferences.Config.Skin.Bigfoot);

ImGui::TableNextColumn();
ImGui::Checkbox("###2345", &preferences.Mirado);
ImGui::TableNextColumn();
ImGui::Text("Mirado");
ImGui::TableNextColumn();
ImGui::InputInt("##OMirado", &preferences.Config.Skin.Mirado);

ImGui::TableNextColumn();
ImGui::Checkbox("###2365", &preferences.Buggy);
ImGui::TableNextColumn();
ImGui::Text("Buggy");
ImGui::TableNextColumn();
ImGui::InputInt("##carc", &preferences.Config.Skin.Buggy);

ImGui::TableNextColumn();
ImGui::Checkbox("###234995", &preferences.MiniBus);
ImGui::TableNextColumn();
ImGui::Text("MiniBus");
ImGui::TableNextColumn();
ImGui::InputInt("##miniB", &preferences.Config.Skin.MiniBus);

ImGui::TableNextColumn();
ImGui::Checkbox("###23650", &preferences.Boat);
ImGui::TableNextColumn();
ImGui::Text("PG-117");
ImGui::TableNextColumn();
ImGui::InputInt("##bg77", &preferences.Config.Skin.Boat);

ImGui::EndTable();
}}
}
ImGui::EndGroup();

}}}
ImGui::End(); 
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
return orig_eglSwapBuffers(dpy, surface);
}
void (*orig_onInputEvent)(void *inputEvent,void *ex_ab,void *ex_ac);
void _onInputEvent(void *inputEvent,void *ex_ab,void *ex_ac) {
orig_onInputEvent(inputEvent,ex_ab,ex_ac);
if (initImGui) {
ImGui_ImplAndroid_HandleInputEvent((AInputEvent*)inputEvent,{(float) screenWidth / (float) glWidth,(float) screenHeight / (float) glHeight}); }}
[[noreturn]] void* maps_thread(void*) {
while (true) {
auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(
std::chrono::system_clock::now().time_since_epoch()).count();

}}

void initOffset() {
Tools::Hook((void *) (UE4 + Broadcast_Offset), (void *) hk_Broadcast, (void **) &orig_Broadcast);
MtrEvent_Offset = (UE4 + MtrSkinEvent_Offset);
}


void EGL() {
Tools::Hook((void*)DobbySymbolResolver(OBFUSCATE("/system/lib/libEGL.so"), OBFUSCATE("eglSwapBuffers")), (void*)_eglSwapBuffers, (void**)&orig_eglSwapBuffers);
DobbyHook((void *) DobbySymbolResolver(OBFUSCATE("libinput.so"), OBFUSCATE("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE")), (void *) _onInputEvent, (void **) &orig_onInputEvent);
}


void *main_thread(void* parms) {
system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.tencent.ig");
system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.pubg.krmobile");
UE4 = Tools::GetBaseAddress("libUE4.so");
while (!UE4) {
UE4 = Tools::GetBaseAddress("libUE4.so");
sleep(1); }
anogs = Tools::GetBaseAddress("libanogs.so");
while (!anogs) {
anogs = Tools::GetBaseAddress("libanogs.so");
sleep(1); }
while (!g_App){
g_App = *(android_app **) (UE4 + GNativeAndroidApp_Offset);
sleep(1); }
FName::GNames = GetGNames();
while (!FName::GNames) {FName::GNames = GetGNames();
sleep(1); }
UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);
EGL();
initOffset();
items_data = json::parse(JSON_ITEMS);
pthread_t t;
pthread_create(&t, 0, maps_thread, 0);
return 0;
}
__attribute__((constructor)) void _iniit() {
pthread_t t;
pthread_create(&t,0,main_thread,0);
}

