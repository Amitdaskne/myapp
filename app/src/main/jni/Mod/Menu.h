#pragma once

int newUAZID = 0;
int lastUAZID = 0;
int newDaciaID = 0;
int lastDaciaID = 0;
int newCoupeID = 0;
int lastCoupeID = 0;
struct snew_Skin {
int XSuits = 403003;
int XSuits1 = 40604002;
int XSuits3 = 40604002;
int Hair = 40601002;
int Hair1= 401993;
int Set = 0;
int P90 = 102105;
int Pants = 404026;
int Shirt = 403003;
int Balo1 = 501001;
int Balo2 = 501002;
int Balo3 = 501003;
int Balo4 = 501004;
int Balo5 = 501005;
int Balo6 = 501006;
int Helmet1 = 502001;
int Helmet2 = 502002;
int Helmet3 = 502003;
int Helmet4 = 502004;
int Helmet5 = 502005;
int Helmet6 = 502114;
int Helmet7 = 502115;
int Helmet8 = 502116;
int Parachute = 703001;
int AKM = 101001;
int AKM_Mag = 291001;
int M16A4 = 101002;
int M16A4_Stock = 205007;
int M16A4_Mag = 291002;
int Scar = 101003;
int Scar_Mag = 291003;
int Pan = 108004;
int M416_1 = 101004;
int M416_2 = 291004;
int M416_3 = 203008;
int M416_4 = 205005;
int M416_flash = 201010;
int M416_compe = 201009;
int M416_silent = 201011;
int M416_reddot = 203001;
int M416_holo = 203001;
int M416_x2 = 203003;
int M416_x3 = 203014;
int M416_x4 = 203004;
int M416_x6 = 203015;
int M416_quickMag = 204012;
int M416_extendedMag = 204011;
int M416_quickNextended = 204013;
int M416_stock = 205002;
int M416_verical = 203015;
int M416_angle = 202001;
int M416_lightgrip = 202004;
int M416_pink = 202005;
int M416_lazer = 202007;
int M416_thumb = 202006;
int Groza = 101005;
int QBZ = 101007;
int AUG = 101006;
int M762 = 101008;
int M762_Mag = 291008;
int ACE32 = 101102;
int Honey = 101012;
int UZI = 102001;
int UMP = 102002;
int Vector = 102003;
int Thompson = 102004;
int Bizon = 102005;
int K98 = 103001;
int M24 = 103002;
int AWM = 103003;
int AMR = 103012;
int VSS = 103005;
int SKS = 103004;
int Mini14 = 103006;
int MK14 = 103007;
int SLR = 103009;
int S1897 = 104002;
int DP28 = 105002;
int M249 = 105001;
int MG3 = 105010;
int Skorpion = 106008;
int Moto = 1901001;
int CoupeRP = 1961001;
int Dacia = 1903001;
int UAZ = 1908001;
int Bigfoot = 1953001;
int Mirado = 1914004;
int OMirado = 1915001;
int Buggy = 1907001;
int MiniBus = 1904001;
int Boat = 1911001;
int M249s = 205009;
};

inline snew_Skin new_Skin;



std::chrono::steady_clock::time_point lastWeaponChangeTimei;
std::chrono::steady_clock::time_point lastWeaponChangeTime;
std::map<int, std::map<int, int>> weaponDefinitions = {
{101004,{{101004,1101004046}}},
{101102,{{101102,1101102007}}},
{101001,{{101001,1101001213}}},
{101006,{{101006,1101006062}}},
{101005,{{101005,1101005052}}},
{101002,{{101002,1101002081}}},
{101008,{{101008,1101008126}}},
{103001,{{103001,1103001179}}},
{103003,{{103003,1103003022}}},
{103009,{{103009,1103009022}}},
{103007,{{103007,1103007020}}},
{103007,{{103007,1103007028}}},
{103012,{{103012,1103012010}}},
{103005,{{103005,1103005024}}},
{103006,{{103006,1103006030}}},
{105001,{{105001,1105001048}}},
{105002,{{105002,1105002035}}},
{103002,{{103002,1103002059}}},
{102005,{{102005,1102005020}}},
{101007,{{101007,1101007046}}},
{101003,{{101003,1101003188}}},
{102004,{{102004,1102004018}}},
{102002,{{102002,1102002043}}},
{102001,{{102001,1102001024}}},
{102003,{{102003,1102003020}}},
{103010,{{103010,1103010012}}},
{101012,{{101012,1101012009}}},
{101100,{{101100,1101100004}}},
{101010,{{101010,1101010018}}},
{103008,{{103008,1103008014}}},
{103011,{{103011,1103011009}}},
{103100,{{103100,1103100007}}},
{102105,{{102105,1102105003}}},
{104001,{{104001,1104001028}}},
{104002,{{104002,1104002033}}},
{104003,{{104003,1104003027}}},
{104004,{{104004,1104004021}}},
{104101,{{104101,1104101001}}},
{104102,{{104102,1104102001}}},
{106001,{{106001,1106001020}}},
{106002,{{106002,1106002016}}},
{106003,{{106003,1106003011}}},
{106004,{{106004,1106004002}}},
{106005,{{106005,1106005002}}},
{106006,{{106006,1106006013}}},
{106008,{{106008,1106008014}}},
{106010,{{106010,1106010001}}},
{108004,{{108004,1108004062}}},
{203008,{{101004,1010040462}}},
{205005,{{101004,1010040463}}},
{291004,{{101004,1010040461}}},
{205102,{{101102,1011020062}}},
{291102,{{101102,1011020071}}},
{291003,{{101003,1010031811}}},
{292002,{{102002,1020020431}}},
{292003,{{102003,1020030191}}},
{205006,{{102003,1020030193}}},
{291001,{{101001,1010012131}}},
{291006,{{101006,1010060564}}},
{291008,{{101008,1010081261}}},
{291005,{{101005,1010050521}}},
{205007,{{101002,1010020814}}},
{291002,{{101002,1010020811}}},
{293009,{{103009,1030090221}}},
{204014,{{103001,1030011744}}},
{293003,{{103003,1030030211}}},
{293006,{{103006,1030060291}}},
{295001,{{105001,1050010481}}},
{205009,{{105001,1050010482}}},
{295002,{{105002,1050020351}}},
{201007,{{103003,1030030167}}},
{205002,{
{101004,1010040480},
{101102,1011020037},
{101002,1010020794}}},
{205003,{
{103002,1030020547},
{103003,1030030168},
{103001,1030011742}}},
{203005,{
{103002,1030020532},
{103003,1030030162},
{103001,1030011731}}},
{203015,{
{101003,1010031752},
{103002,1030020533},
{103006,1030060243},
{103003,1030030163},
{103001,1030011732}}},
{201005,{
{103002,1030020544},
{103003,1030030165}}},
{201003,{
{103002,1030020545},
{103003,1030030166}}},
{293005,{
{103006,1030060242},
{103005,1030050231}}},
{204007,{
{103002,1030020539},
{103006,1030060248},
{103003,1030030169}}},
{204008,{
{103002,1030020542},
{103003,1030030172}}},
{204009,{
{103002,1030020543},
{103006,1030060249},
{103003,1030030173}}},
{291007,{
{101007,1010070461},
{103002,1030020546}}},
{203004,{
{101004,1010040466},
{101008,1010081202},//4X
{102002,1020020375},
{101003,1010031753},
{101007,1010070402},
{103002,1030020534},
{105001,1050010423},
{103006,1030060244},
{103003,1030030164},
{103001,1030011733},
{101102,1011020015},
{101002,1010020755},
{101005,1010050462},
{101006,1010060552},
{101001,1010012062}}},
{203014,{
{101004,1010040467},
{101008,1010081203},//3X
{102002,1020020376},
{101003,1010031754},
{101007,1010070403},
{103002,1030020535},
{105001,1050010424},
{103001,1030011734},
{101102,1011020016},
{101002,1010020756},
{101005,1010050463},
{101006,1010060553},
{101001,1010012063}}},
{203003,{
{101004,1010040468},
{101008,1010081204},//2X
{102002,1020020377},
{101003,1010031755},
{101007,1010070404},
{103002,1030020536},
{105001,1050010425},
{103001,1030011735},
{101102,1011020017},
{101002,1010020757},
{101005,1010050464},
{101006,1010060554},
{101001,1010012064}}},
{203002,{
{101004,1010040469},
{101008,1010081205},//Holo
{102002,1020020378},
{101003,1010031756},
{101007,1010070405},
{103002,1030020537},
{105001,1050010426},
{103001,1030011736},
{101102,1011020018},
{101002,1010020758},
{101005,1010050465},
{101006,1010060561},
{101001,1010012065}}},
{203001,{
{101004,1010040470},
{101008,1010081206},//RedDot
{102002,1020020379},
{101003,1010031757},
{101007,1010070406},
{103002,1030020538},
{105001,1050010427},
{103001,1030011737},
{101102,1011020019},
{101002,1010020759},
{101005,1010050466},
{101006,1010060562},
{101001,1010012066}}},
{204011,{
{101004,1010040471},
{101008,1010081207},//ExpandedMagazine
{102002,1020020380},
{101003,1010031758},
{101007,1010070407},
{105001,1050010428},
{103006,1030060252},
{101102,1011020024},
{101002,1010020760},
{101005,1010050467},
{101006,1010060563},
{101001,1010012070}}},
{204012,{
{101004,1010040472},
{101008,1010081208},//QuickMagazine
{102002,1020020383},
{101003,1010031759},
{101007,1010070408},
{105001,1050010429},
{101102,1011020025},
{101002,1010020766},
{101005,1010050468},
{101006,1010060564},
{101001,1010012072}}},
{204013,{
{101004,1010040473},
{101008,1010081209},//ExpandedQuickMagazine
{102002,1020020384},
{101003,1010031763},
{101007,1010070409},
{105001,1050010434},
{103006,1030060253},
{101102,1011020026},
{101002,1010020767},
{101005,1010050469},
{101006,1010060571},
{101001,1010012073}}},
{201010,{
{101004,1010040474},
{101008,1010081210},//FlashHider
{102002,1020020372},
{101003,1010031765},
{101007,1010070410},
{103006,1030060245},
{103001,1030011738},
{101102,1011020027},
{101002,1010020768},
{101006,1010060573},
{101001,1010012067}}},
{201009,{
{101004,1010040475},
{101008,1010081213},//Compensator
{102002,1020020374},
{101003,1010031764},
{101007,1010070413},
{103006,1030060246},
{103001,1030011739},
{101102,1011020028},
{101002,1010020769},
{101006,1010060572},
{101001,1010012068}}},
{201011,{
{101004,1010040476},
{101008,1010081215},//Supressor
{102002,1020020373},
{101003,1010031766},
{101007,1010070414},
{103006,1030060247},
{103001,1030011741},
{101102,1011020029},
{101002,1010020770},
{101006,1010060574},
{101001,1010012069}}},
{202001,{
{101004,1010040477},
{101008,1010081216},//Foregrip
{102002,1020020387},
{101003,1010031767},
{101007,1010070415},
{101102,1011020034},
{101006,1010060581}}},
{202006,{
{101004,1010040478},
{102002,1020020386},
{101003,1010031768},
{101007,1010070416},
{101102,1011020035},
{101006,1010060582}}},
{202002,{
{101004,1010040479},
{101008,1010081217},//VerticalGrip
{102002,1020020385},
{101003,1010031769},
{101007,1010070417},
{101102,1011020036},
{101006,1010060583}}},
};

 void updateSkin() {
 if (preferences.bag == 1) {
bag3 = 1501000220; //Blood Raven Backpack
bag3 = 1501001220; //Lev 1 Blood Raven Backpack
bag3 = 1501002220; //Lev 2 Blood Raven Backpack
bag3 = 1501003220; //Lev 3 Blood Raven Backpack
}
if (preferences.bag == 2) {
bag3 = 1501000051; //The fool backpack
bag3 = 1501001051; //Lev 1 The fool backpack
bag3 = 1501002051; //Lev 2 The fool backpack
bag3 = 1501003051; //Lev 3 The fool backpack
}
if (preferences.bag == 3) {
bag3 = 1501000174; //Pharaoh's Regalia Backpack
bag3 = 1501001174; //Lev 1 Pharaoh's Regalia Backpack
bag3 = 1501002174; //Lev 2 Pharaoh's Regalia Backpack
bag3 = 1501003174; //Lev 3 Pharaoh's Regalia Backpack
}
if (preferences.bag == 4) {
bag3 = 1501000466; //Mystique Splendor Backpack
bag3 = 1501001466; //Lev 1 Mystique Splendor Backpack
bag3 = 1501002466; //Lev 2 Mystique Splendor Backpack
bag3 = 1501003466; //Lev 3 Mystique Splendor Backpack
}
if (preferences.bag == 5) {
bag3 = 1501000550; //Frosty Snowglobe Backpack
bag3 = 1501001550; //Lev 1 Frosty Snowglobe Backpack
bag3 = 1501002550; //Lev 2 Frosty Snowglobe Backpack
bag3 = 1501003550; //Lev 3 Frosty Snowglobe Backpack
}
if (preferences.bag == 6) {
bag3 = 1501000043; //Illusion Judge Backpack
bag3 = 1501001043; //Lev 1 Illusion Judge Backpack
bag3 = 1501002043; //Lev 2 Illusion Judge Backpack
bag3 = 1501003043; //Lev 3 Illusion Judge Backpack
}
if (preferences.bag == 7) {
bag3 = 1501000093; //Arctic Witch Backpack
bag3 = 1501001093; //Lev 1 Arctic Witch Backpack
bag3 = 1501002093; //Lev 2 Arctic Witch Backpack
bag3 = 1501003093; //Lev 3 Arctic Witch Backpack
}
if (preferences.bag == 8) {
bag3 = 1501000118; //8-bit Unicorn Backpack
bag3 = 1501001118; //Lev. 1 8-bit Unicorn Backpack
bag3 = 1501002118; //Lev. 2 8-bit Unicorn Backpack
bag3 = 1501003118; //Lev. 3 8-bit Unicorn Backpack
}
if (preferences.bag == 8) {
bag3 = 1501003024; //Count Backpack
bag3 = 1501003024; //Lev. 3 Count Backpack
}

//Helmet
if (preferences.helmet == 1) {
helmett3 = 1505000014; // photo Inferno Rider Helmet
helmett3 = 1502001014; // Lev1 Inferno Rider Helmet
helmett3 = 1502002014; // Lev2 lnferno Rider Helmet
helmett3 = 1502003014; // Lev3 lnferno Rider Helmet
}

if (preferences.helmet == 2) {
helmett3 = 1502000069; //Masked Psychic Helmet
helmett3 = 1502001069; //Lev 1 Masked Psychic Helmet
helmett3 = 1502002069; //Lev 2 Masked Psychic Helmet
helmett3 = 1502003069; //Lev 3 Masked Psychic Helmet
}

if (preferences.helmet == 3) {
helmett3 = 1505000009; //PUBLING Helmet
helmett3 = 1502001009; //Lev 1 PUBLING Helmet
helmett3 = 1502002009; //Lev 2 PUBLING Helmet
helmett3 = 1502003009; //Lev 3 PUBLING Helmet
}
if (preferences.helmet == 4) {
helmett3 = 1502000023; //Glacier Helmet
helmett3 = 1502001023; //Lev 1 Glacier Helmet
helmett3 = 1502002023; //Lev 2 Glacier Helmet
helmett3 = 1502003023; //Lev 3 Glacier Helmet
}

if (preferences.helmet == 5) {
helmett3 = 1505000018; //Angry Pumpkin Helmet
helmett3 = 1502001018; // Lev 1 Angry Pumpkin Helmet
helmett3 = 1502002018; // Lev 2 Angry Pumpkin Helmet
helmett3 = 1502003018; // Lev 2 Angry Pumpkin Helmet
 }

if (preferences.helmet == 6) {
helmett3 = 1502000047; //Techno Helmet
helmett3 = 1502001047; //Lev 1 Techno Helmet
helmett3 = 1502002047; //Lev 2 Techno Helmet
helmett3 = 1502003047; //Lev 2 Techno Helmet
}

if (preferences.helmet == 7) {
helmett3 = 1502000151; //Regal Overlord Helmet
helmett3 = 1502001151; // Lev 1 Regal Overlord Helmet
helmett3 = 1502002151; // Lev 2 Regal Overlord Helmet
helmett3 = 1502003151; // Lev 3 Regal Overlord Helmet
}

if (preferences.helmet == 8) {
helmett3 = 1502000086; // Adorable Mouse Helmet
helmett3 = 1502001086; // Lev 1 Adorable Mouse Helmet
helmett3 = 1502002086; // Lev 2 Adorable Mouse Helmet
helmett3 = 1502003086; // Lev 3 Adorable Mouse Helmet
}

if (ModEmote1 == 0)
sEmote1 = 2200101;
if (ModEmote1 == 1)
sEmote1 = 12220023;
if (ModEmote1 == 2)
sEmote1 = 12219677;
if (ModEmote1 == 3)
sEmote1 = 12219716;
if (ModEmote1 == 4)
sEmote1 = 12209401;
if (ModEmote1 == 5)
sEmote1 = 12209501;
if (ModEmote1 == 6)
sEmote1 = 12209701;
if (ModEmote1 == 7)
sEmote1 = 12209801;
if (ModEmote1 == 8)
sEmote1 = 12209901;

if (ModEmote1 == 0)
sEmote2 = 2200201;
if (ModEmote1 == 1)
sEmote2 = 12210201;
if (ModEmote1 == 2)
sEmote2 = 12210601;
if (ModEmote1 == 3)
sEmote2 = 12220028;
if (ModEmote1 == 4)
sEmote2 = 12219819;
if (ModEmote1 == 5)
sEmote2 = 12211801;
if (ModEmote1 == 6)
sEmote2 = 12212001;
if (ModEmote1 == 7)
sEmote2 = 12212201;
if (ModEmote1 == 8)
sEmote2 = 12212401;
if (ModEmote1 == 9)
sEmote2 = 1407277;


if (ModEmote1 == 0)
sEmote3 = 2200301;
if (ModEmote1 == 1)
sEmote3 = 12212601;
if (ModEmote1 == 2)
sEmote3 = 12213201;
if (ModEmote1 == 3)
sEmote3 = 12219715;
if (ModEmote1 == 4)
sEmote3 = 12219814;
if (ModEmote1 == 5)
sEmote3 = 12213601;
if (ModEmote1 == 6)
sEmote3 = 12213801;
if (ModEmote1 == 7)
sEmote3 = 12214001;
if (ModEmote1 == 8)
sEmote3 = 12214201;
if (ModEmote1 == 9)
sEmote3 = 1407277;


if (preferences.Config.Skin.Pan == 0)
new_Skin.Pan = 108004; // 108004 - Pan
if (preferences.Config.Skin.Pan == 1)
new_Skin.Pan = 1108004125; // Honeypot - Pan
if (preferences.Config.Skin.Pan == 2)
new_Skin.Pan = 1108004145; // Night of Rock - Pan
if (preferences.Config.Skin.Pan == 3)
new_Skin.Pan = 1108004160; // Crocodile - Pan
if (preferences.Config.Skin.Pan == 4)
new_Skin.Pan = 1108004283; // Accolade - Pan
if (preferences.Config.Skin.Pan == 5)
new_Skin.Pan = 1108004337; // Break Pad - Pan
if (preferences.Config.Skin.Pan == 6)
new_Skin.Pan = 1108004356; // Chicken Hot - Pan
if (preferences.Config.Skin.Pan == 7)
new_Skin.Pan = 1108004365; // Faerie Luster - Pan
if (preferences.Config.Skin.Pan == 8)
new_Skin.Pan = 1108004054; // Chicken Hot - Pan
if (preferences.Config.Skin.Pan == 9)
new_Skin.Pan = 1108004008; 


if (preferences.Config.Skin.XSuits == 0) {
new_Skin.XSuits = 403003;
new_Skin.XSuits1 = 40604002;
}
if (preferences.Config.Skin.XSuits == 1) {
new_Skin.XSuits = 1405628;
new_Skin.XSuits1 = 1402578;
}
if (preferences.Config.Skin.XSuits == 2) {
new_Skin.XSuits = 1405870;
new_Skin.XSuits1 = 1403257;
}
if (preferences.Config.Skin.XSuits == 3) {
new_Skin.XSuits = 1405983;
new_Skin.XSuits1 = 1402874;
}
if (preferences.Config.Skin.XSuits == 4) {
new_Skin.XSuits = 1406152;
new_Skin.XSuits1 = 1403393;
}
if (preferences.Config.Skin.XSuits == 5) {
new_Skin.XSuits = 1406311;
new_Skin.XSuits1 = 1410011; //Mặt nạ 1.403.414
}
if (preferences.Config.Skin.XSuits == 6) {
new_Skin.XSuits = 1406475;
new_Skin.XSuits1 = 1410131;
}
if (preferences.Config.Skin.XSuits == 7) {
new_Skin.XSuits = 1406638;
new_Skin.XSuits1 = 1410242;
}
if (preferences.Config.Skin.XSuits == 8) {
new_Skin.XSuits = 1406872;
//new_Skin.XSuits1 = 1410346; // khung
new_Skin.XSuits1 = 402133;
}
if (preferences.Config.Skin.XSuits == 9) {
new_Skin.XSuits = 1406971;
new_Skin.XSuits1 = 402147;
}
if (preferences.Config.Skin.XSuits == 10) {
new_Skin.XSuits = 1407103;
new_Skin.XSuits1 = 40604002;
}
if (preferences.Config.Skin.XSuits == 11) {
new_Skin.XSuits = 1407366;
}
if (preferences.Config.Skin.XSuits == 12) {
new_Skin.XSuits = 1406469;
}
if (preferences.Config.Skin.XSuits == 13) {
new_Skin.XSuits = 1406641;
}
if (preferences.Config.Skin.XSuits == 14) {
new_Skin.XSuits = 1405174;
new_Skin.XSuits1 = 40604012;
}
if (preferences.Config.Skin.XSuits == 15) {
new_Skin.XSuits = 1400687;
}
else if (preferences.Config.Skin.XSuits == 16) {
new_Skin.XSuits = 1407275;
new_Skin.XSuits1 = 1410646;
}
else if (preferences.Config.Skin.XSuits == 17) {
new_Skin.XSuits = 1407329;
}
else if (preferences.Config.Skin.XSuits == 18) {
new_Skin.XSuits = 1407330;
new_Skin.XSuits1 = 1410686;
}
else if (preferences.Config.Skin.XSuits == 19) {
new_Skin.XSuits = 1405145;
new_Skin.XSuits1 = 1403010;
}
else if (preferences.Config.Skin.XSuits == 20) {
new_Skin.XSuits = 1400782;
}
else if (preferences.Config.Skin.XSuits == 21) {
new_Skin.XSuits = 1405860;
}
if (preferences.Config.Skin.XSuits == 22) {
new_Skin.XSuits = 1400324;
new_Skin.XSuits1 = 1404050;
}
if (preferences.Config.Skin.XSuits == 23) {
new_Skin.XSuits = 1400288;
new_Skin.XSuits1 = 1400287;
}


if (preferences.Config.Skin.XSuits == 24) {
new_Skin.XSuits = 1400117;
}
if (preferences.Config.Skin.XSuits == 25) {
new_Skin.XSuits = 1405436;
}
if (preferences.Config.Skin.XSuits == 26) {
new_Skin.XSuits = 1405433;
}
if (preferences.Config.Skin.XSuits == 27) {
new_Skin.XSuits = 1405434;
}
if (preferences.Config.Skin.XSuits == 28) {
new_Skin.XSuits = 1405435;
}
if (preferences.Config.Skin.XSuits == 29) {
new_Skin.XSuits = 1405340;
}
if (preferences.Config.Skin.XSuits == 30) {
new_Skin.XSuits = 1405341;
}
if (preferences.Config.Skin.XSuits == 31) {
new_Skin.XSuits = 1405334;
}
if (preferences.Config.Skin.XSuits == 32) {
new_Skin.XSuits = 1400106;
}
if (preferences.Config.Skin.AKM == 0) {
new_Skin.AKM = 101001;
new_Skin.AKM_Mag = 205005;
}
if (preferences.Config.Skin.AKM == 1) {
new_Skin.AKM = 1101001089;
new_Skin.AKM_Mag = 1010010891;
}
if (preferences.Config.Skin.AKM == 2) {
new_Skin.AKM = 1101001042;
new_Skin.AKM_Mag = 1101001042;
}
if (preferences.Config.Skin.AKM == 3) {
new_Skin.AKM = 1101001062;
new_Skin.AKM_Mag = 101001062;
}
if (preferences.Config.Skin.AKM == 4) {
new_Skin.AKM = 1101001068;
new_Skin.AKM_Mag = 101001068;
}
if (preferences.Config.Skin.AKM == 5) {
new_Skin.AKM = 1101001103;
new_Skin.AKM_Mag = 1010011031;
}
if (preferences.Config.Skin.AKM == 6) {
new_Skin.AKM = 1101001116;
new_Skin.AKM_Mag = 1010011161;
}
if (preferences.Config.Skin.AKM == 7) {
new_Skin.AKM = 1101001128;
new_Skin.AKM_Mag = 1010011281;
}
if (preferences.Config.Skin.AKM == 8) {
new_Skin.AKM = 1101001143;
new_Skin.AKM_Mag = 1010011431;
}
if (preferences.Config.Skin.AKM == 9) {
new_Skin.AKM = 1101001154;
new_Skin.AKM_Mag = 1010011541;
}
if (preferences.Config.Skin.AKM == 10) {
new_Skin.AKM = 1101001174;
new_Skin.AKM_Mag = 1010011741;
}
if (preferences.Config.Skin.AKM == 11) {
new_Skin.AKM = 1101001213;
new_Skin.AKM_Mag = 1010012131;
}
if (preferences.Config.Skin.AKM == 12) {
new_Skin.AKM = 1101001231;
new_Skin.AKM_Mag = 1010012311;
}
if (preferences.Config.Skin.AKM == 13) {
new_Skin.AKM = 1101001242;
new_Skin.AKM_Mag = 1010012421;
}
if (preferences.Config.Skin.AKM == 14) {
new_Skin.AKM = 1101001249;
new_Skin.AKM_Mag = 1101001249;
}
if (preferences.Config.Skin.AKM == 15) {
new_Skin.AKM = 1101001256;
new_Skin.AKM_Mag = 1101001256;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (preferences.Config.Skin.M16A4 == 0) {
new_Skin.M16A4 = 101002;
new_Skin.M16A4_Stock = 205007;
new_Skin.M16A4_Mag = 291002;
}
if (preferences.Config.Skin.M16A4 == 1) {
new_Skin.M16A4 = 1101002029;
new_Skin.M16A4_Stock = 1010020292;
new_Skin.M16A4_Mag = 1010020291;
}
if (preferences.Config.Skin.M16A4 == 2) {
new_Skin.M16A4 = 1101002056;
new_Skin.M16A4_Stock = 1010020562;
new_Skin.M16A4_Mag = 1010020561;
}
if (preferences.Config.Skin.M16A4 == 3) {
new_Skin.M16A4 = 1101002068;
new_Skin.M16A4_Stock = 1010020682;
new_Skin.M16A4_Mag = 1010020681;
}
if (preferences.Config.Skin.M16A4 == 4) {
new_Skin.M16A4 = 1101002081;
new_Skin.M16A4_Stock = 1010020812;
new_Skin.M16A4_Mag = 1010020811;
}
if (preferences.Config.Skin.M16A4 == 5) {
new_Skin.M16A4 = 1101002103;
new_Skin.M16A4_Stock = 1010021032;
new_Skin.M16A4_Mag = 1010021031;
}
if (preferences.Config.Skin.M16A4 == 6) {
new_Skin.M16A4 = 11010021103;
new_Skin.M16A4_Stock = 1010021102;
new_Skin.M16A4_Mag = 1010021101;
}
if (preferences.Config.Skin.M16A4 == 7) {
new_Skin.M16A4 = 1101002117;
new_Skin.M16A4_Stock = 1010021172;
new_Skin.M16A4_Mag = 1010021171;
new_Skin.M16A4_Mag = 1010021171;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (preferences.Config.Skin.Scar == 0) {
new_Skin.Scar = 101003;
new_Skin.Scar_Mag = 291003;
}
if (preferences.Config.Skin.Scar == 1) {
new_Skin.Scar = 1101003057;
new_Skin.Scar_Mag = 1010030571;
}
if (preferences.Config.Skin.Scar == 2) {
new_Skin.Scar = 1101003070;
new_Skin.Scar_Mag = 1010030701;
}
if (preferences.Config.Skin.Scar == 3) {
new_Skin.Scar = 1101003080;
new_Skin.Scar_Mag = 1010030801;
}
if (preferences.Config.Skin.Scar == 4) {
new_Skin.Scar = 1101003119;
new_Skin.Scar_Mag = 1010031191;
}
if (preferences.Config.Skin.Scar == 5) {
new_Skin.Scar = 1101003146;
new_Skin.Scar_Mag = 1010031461;
}
if (preferences.Config.Skin.Scar == 6) {
new_Skin.Scar = 1101003167;
new_Skin.Scar_Mag = 1010031671;
}
if (preferences.Config.Skin.Scar == 7) {
new_Skin.Scar = 1101003181;
new_Skin.Scar_Mag = 1010031811;
}
if (preferences.Config.Skin.Scar == 8) {
new_Skin.Scar = 1101003195;
new_Skin.Scar_Mag = 1010031951;
}
///////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.M416 == 0) {
new_Skin.M416_1 = 101004;
new_Skin.M416_2 = 291004;
new_Skin.M416_3 = 203008;
new_Skin.M416_4 = 205005;
new_Skin.M416_flash = 201010;
new_Skin.M416_compe = 201009;
new_Skin.M416_silent = 201011;
new_Skin.M416_reddot = 203001;
new_Skin.M416_holo = 203002;
new_Skin.M416_x2 = 203003;
new_Skin.M416_x3 = 203014;
new_Skin.M416_x4 = 203004;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 204012;
new_Skin.M416_extendedMag = 204011;
new_Skin.M416_quickNextended = 204013;
new_Skin.M416_stock = 205002;
new_Skin.M416_verical = 202002;
new_Skin.M416_angle = 202001;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 1) {
new_Skin.M416_1 = 1101004046;
new_Skin.M416_2 = 1010040461;
new_Skin.M416_3 = 1010040462;
new_Skin.M416_4 = 1010040463;
new_Skin.M416_flash = 1010040474;
new_Skin.M416_compe = 1010040475;
new_Skin.M416_silent = 1010040476;
new_Skin.M416_reddot = 1010040470;
new_Skin.M416_holo = 1010040469;
new_Skin.M416_x2 = 1010040468;
new_Skin.M416_x3 = 1010040467;
new_Skin.M416_x4 = 1010040466;
new_Skin.M416_x6 = 1010040481;
new_Skin.M416_quickMag = 1010040471;
new_Skin.M416_extendedMag = 1010040472;
new_Skin.M416_quickNextended = 1010040473;
new_Skin.M416_stock = 1010040480;
new_Skin.M416_verical = 1010040479;
new_Skin.M416_thumb = 1010040478;
new_Skin.M416_angle = 1010040477;
new_Skin.M416_lightgrip = 1010040482;
new_Skin.M416_pink = 1010040483;
new_Skin.M416_lazer = 1010040484;
}
if (preferences.Config.Skin.M416 == 2) {
new_Skin.M416_1 = 1101004062;
new_Skin.M416_2 = 1010040611;
new_Skin.M416_3 = 1010040612;
new_Skin.M416_4 = 1010040613;
new_Skin.M416_flash = 201010;
new_Skin.M416_compe = 201009;
new_Skin.M416_silent = 201011;
new_Skin.M416_reddot = 203001;
new_Skin.M416_holo = 203002;
new_Skin.M416_x2 = 203003;
new_Skin.M416_x3 = 203014;
new_Skin.M416_x4 = 203004;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 204012;
new_Skin.M416_extendedMag = 204011;
new_Skin.M416_quickNextended = 204013;
new_Skin.M416_stock = 205002;
new_Skin.M416_verical = 203015;
new_Skin.M416_angle = 202001;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 3) {
new_Skin.M416_1 = 1101004078;
new_Skin.M416_2 = 1010040781;
new_Skin.M416_3 = 1010040782;
new_Skin.M416_4 = 1010040783;
new_Skin.M416_flash = 201010;
new_Skin.M416_compe = 201009;
new_Skin.M416_silent = 201011;
new_Skin.M416_reddot = 203001;
new_Skin.M416_holo = 203002;
new_Skin.M416_x2 = 203003;
new_Skin.M416_x3 = 203014;
new_Skin.M416_x4 = 203004;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 204012;
new_Skin.M416_extendedMag = 204011;
new_Skin.M416_quickNextended = 204013;
new_Skin.M416_stock = 205002;
new_Skin.M416_verical = 203015;
new_Skin.M416_angle = 202001;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 4) {
new_Skin.M416_1 = 1101004086;
new_Skin.M416_2 = 1010040861;
new_Skin.M416_3 = 1010040862;
new_Skin.M416_4 = 1010040863;
new_Skin.M416_flash = 201010;
new_Skin.M416_compe = 201009;
new_Skin.M416_silent = 201011;
new_Skin.M416_reddot = 203001;
new_Skin.M416_holo = 203002;
new_Skin.M416_x2 = 203003;
new_Skin.M416_x3 = 203014;
new_Skin.M416_x4 = 203004;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 204012;
new_Skin.M416_extendedMag = 204011;
new_Skin.M416_quickNextended = 204013;
new_Skin.M416_stock = 205002;
new_Skin.M416_verical = 203015;
new_Skin.M416_angle = 202001;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 5) {
new_Skin.M416_1 = 1101004098;
new_Skin.M416_2 = 1010040981;
new_Skin.M416_3 = 1010040982;
new_Skin.M416_4 = 1010040983;
new_Skin.M416_flash = 201010;
new_Skin.M416_compe = 201009;
new_Skin.M416_silent = 201011;
new_Skin.M416_reddot = 203001;
new_Skin.M416_holo = 203002;
new_Skin.M416_x2 = 203003;
new_Skin.M416_x3 = 203014;
new_Skin.M416_x4 = 203004;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 204012;
new_Skin.M416_extendedMag = 204011;
new_Skin.M416_quickNextended = 204013;
new_Skin.M416_stock = 205002;
new_Skin.M416_verical = 203015;
new_Skin.M416_angle = 202001;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 6) {
new_Skin.M416_1 = 1101004138;
new_Skin.M416_2 = 1010041381;
new_Skin.M416_3 = 1010041382;
new_Skin.M416_4 = 1010041383;
new_Skin.M416_flash = 1010041136;
new_Skin.M416_compe = 1010041137;
new_Skin.M416_silent = 1010041138;
new_Skin.M416_reddot = 1010041128;
new_Skin.M416_holo = 1010041127;
new_Skin.M416_x2 = 1010041126;
new_Skin.M416_x3 = 1010041125;
new_Skin.M416_x4 = 1010041124;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 1010041134;
new_Skin.M416_extendedMag = 1010041129;
new_Skin.M416_quickNextended = 1010041135;
new_Skin.M416_stock = 1010041146;
new_Skin.M416_verical = 1010041145;
new_Skin.M416_angle = 1010041139;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 7) {
new_Skin.M416_1 = 1101004163;
new_Skin.M416_2 = 1010041631;
new_Skin.M416_3 = 1010041632;
new_Skin.M416_4 = 1010041633;
new_Skin.M416_flash = 201010;
new_Skin.M416_compe = 1010041574;
new_Skin.M416_silent = 1010041575;
new_Skin.M416_reddot = 1010041566;
new_Skin.M416_holo = 1010041565;
new_Skin.M416_x2 = 1010041564;
new_Skin.M416_x3 = 1010041560;
new_Skin.M416_x4 = 1010041554;
new_Skin.M416_x6 = 203015;
new_Skin.M416_quickMag = 1010041568;
new_Skin.M416_extendedMag = 1010041569;
new_Skin.M416_quickNextended = 1010041567;
new_Skin.M416_stock = 1010041579;
new_Skin.M416_verical = 1010041578;
new_Skin.M416_angle = 1010041576;
new_Skin.M416_lightgrip = 20200400;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 1010041577;
}
if (preferences.Config.Skin.M416 == 8) {
new_Skin.M416_1 = 1101004201;
new_Skin.M416_2 = 1010042011;
new_Skin.M416_3 = 1010042012;
new_Skin.M416_4 = 1010042013;
new_Skin.M416_flash = 1010041956;
new_Skin.M416_compe = 1010041957;
new_Skin.M416_silent = 1010041958;
new_Skin.M416_reddot = 1010041948;
new_Skin.M416_holo = 1010041947;
new_Skin.M416_x2 = 1010041946;
new_Skin.M416_x3 = 1010041945;
new_Skin.M416_x4 = 1010041944;
new_Skin.M416_x6 = 1010041967;
new_Skin.M416_quickMag = 1010041949;
new_Skin.M416_extendedMag = 1010041950;
new_Skin.M416_quickNextended = 1010041955;
new_Skin.M416_stock = 1010041966;
new_Skin.M416_verical = 1010041965;
new_Skin.M416_angle = 1010041959;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 1010041960;
}
if (preferences.Config.Skin.M416 == 9) {
new_Skin.M416_1 = 1101004209;
new_Skin.M416_2 = 1010042073;
new_Skin.M416_3 = 1010042083;
new_Skin.M416_4 = 1010042093;
new_Skin.M416_flash = 20101000;
new_Skin.M416_compe = 1010042037;
new_Skin.M416_silent = 1010042039;
new_Skin.M416_reddot = 1010042029;
new_Skin.M416_holo = 1010042028;
new_Skin.M416_x2 = 1010042027;
new_Skin.M416_x3 = 1010042026;
new_Skin.M416_x4 = 1010042025;
new_Skin.M416_x6 = 1010042024;
new_Skin.M416_quickMag = 1010042034;
new_Skin.M416_extendedMag = 1010042035;
new_Skin.M416_quickNextended = 1010042036;
new_Skin.M416_stock = 1010042047;
new_Skin.M416_verical = 1010042046;
new_Skin.M416_angle = 1010042044;
new_Skin.M416_lightgrip = 202004;
new_Skin.M416_pink = 202005;
new_Skin.M416_lazer = 203015;
new_Skin.M416_thumb = 202006;
}
if (preferences.Config.Skin.M416 == 10) {
new_Skin.M416_1 = 1101004236;
new_Skin.M416_2 = 1010042224;
new_Skin.M416_3 = 1010042225;
new_Skin.M416_4 = 1010042226;
new_Skin.M416_flash = 1010042238;
new_Skin.M416_compe = 1010042237;
new_Skin.M416_silent = 1010042239;
new_Skin.M416_reddot = 1010042233;
new_Skin.M416_holo = 1010042232;
new_Skin.M416_x2 = 1010042231;
new_Skin.M416_x3 = 1010042219;
new_Skin.M416_x4 = 1010042218;
new_Skin.M416_x6 = 1010042217;
new_Skin.M416_quickMag = 1010042235;
new_Skin.M416_extendedMag = 1010042234;
new_Skin.M416_quickNextended = 1010042236;
new_Skin.M416_stock = 1010042244;
new_Skin.M416_verical = 1010042243;
new_Skin.M416_angle = 1010042241;
new_Skin.M416_lightgrip = 1010042245;
new_Skin.M416_pink = 1010042246;
new_Skin.M416_lazer = 1010042247;
new_Skin.M416_thumb = 1010042242;
}

if (preferences.Config.Skin.M416 == 11) {
new_Skin.M416_1 = 1101004218;
new_Skin.M416_2 = 1010042181;
new_Skin.M416_3 = 1010042182;
new_Skin.M416_4 = 1010042183;
new_Skin.M416_flash = 1010042128;
new_Skin.M416_compe = 1010042127;
new_Skin.M416_silent = 1010042129;
new_Skin.M416_reddot = 1010042119;
new_Skin.M416_holo = 1010042118;
new_Skin.M416_x2 = 1010042117;
new_Skin.M416_x3 = 1010042116;
new_Skin.M416_x4 = 1010042115;
new_Skin.M416_x6 = 1010042114;
new_Skin.M416_quickMag = 1010042124;
new_Skin.M416_extendedMag = 1010042125;
new_Skin.M416_quickNextended = 1010042126;
new_Skin.M416_stock = 1010042137;
new_Skin.M416_verical = 1010042136;
new_Skin.M416_angle = 1010042134;
new_Skin.M416_lightgrip = 1010042138;
new_Skin.M416_pink = 1010042139;
new_Skin.M416_lazer = 1010042144;
new_Skin.M416_thumb = 1010042135;
}
if (preferences.Config.Skin.M416 == 12) {
new_Skin.M416_1 = 1101004226;
new_Skin.M416_2 = 1010042214;
new_Skin.M416_3 = 1010042215;
new_Skin.M416_4 = 1010042216;
new_Skin.M416_flash = 1010042238;
new_Skin.M416_compe = 1010042237;
new_Skin.M416_silent = 1010042239;
new_Skin.M416_reddot = 1010042233;
new_Skin.M416_holo = 1010042232;
new_Skin.M416_x2 = 1010042231;
new_Skin.M416_x3 = 1010042219;
new_Skin.M416_x4 = 1010042218;
new_Skin.M416_x6 = 1010042217;
new_Skin.M416_quickMag = 1010042235;
new_Skin.M416_extendedMag = 1010042234;
new_Skin.M416_quickNextended = 1010042236;
new_Skin.M416_stock = 1010042244;
new_Skin.M416_verical = 1010042243;
new_Skin.M416_angle = 1010042241;
new_Skin.M416_lightgrip = 1010042245;
new_Skin.M416_pink = 1010042246;
new_Skin.M416_lazer = 1010042247;
new_Skin.M416_thumb = 1010042242;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.Groza == 0) {
new_Skin.Groza = 101005;
}
if (preferences.Config.Skin.Groza == 1) {
new_Skin.Groza = 1101005019;
}
if (preferences.Config.Skin.Groza == 2) {
new_Skin.Groza = 1101005025;
}
if (preferences.Config.Skin.Groza == 3) {
new_Skin.Groza = 1101005038;
}
if (preferences.Config.Skin.Groza == 4) {
new_Skin.Groza = 1101005043;
}
if (preferences.Config.Skin.Groza == 5) {
new_Skin.Groza = 1101005052;
}
if (preferences.Config.Skin.Groza == 6) {
new_Skin.Groza = 1101005082;
}
if (preferences.Config.Skin.Groza == 7) {
new_Skin.Groza = 1101005090;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.AUG == 0)
new_Skin.AUG = 101006;
if (preferences.Config.Skin.AUG == 1)
new_Skin.AUG = 1101006033;
if (preferences.Config.Skin.AUG == 2)
new_Skin.AUG = 1101006044;
if (preferences.Config.Skin.AUG == 3)
new_Skin.AUG = 1101006062;
if (preferences.Config.Skin.AUG == 4)
new_Skin.AUG = 1101006067;
if (preferences.Config.Skin.AUG == 5)
new_Skin.AUG = 1101006075;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.QBZ == 0)
new_Skin.QBZ = 101007;
if (preferences.Config.Skin.QBZ == 1)
new_Skin.QBZ = 1101007025;
if (preferences.Config.Skin.QBZ == 2)
new_Skin.QBZ = 1101007036;
if (preferences.Config.Skin.QBZ == 3)
new_Skin.QBZ = 1101007046;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 if (preferences.Config.Skin.MK14 == 0) {
new_Skin.MK14 = 103007;
}
if (preferences.Config.Skin.MK14 == 1) {
new_Skin.MK14 = 1103007020; //NEBULA POWER
}
if (preferences.Config.Skin.MK14 == 2) {
new_Skin.MK14 = 1103007028; //MK NEW
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.M762 == 0) {
new_Skin.M762 = 101008;
new_Skin.M762_Mag = 291008;
}
if (preferences.Config.Skin.M762 == 1) {
new_Skin.M762 = 1101008026;
new_Skin.M762_Mag = 1010080261;
}
if (preferences.Config.Skin.M762 == 2) {
new_Skin.M762 = 1101008051;
new_Skin.M762_Mag = 1010080511;
}
if (preferences.Config.Skin.M762 == 3) {
new_Skin.M762 = 1101008061;
new_Skin.M762_Mag = 1010080611;
}
if (preferences.Config.Skin.M762 == 4) {
new_Skin.M762 = 1101008081;
new_Skin.M762_Mag = 1010080811;
}
if (preferences.Config.Skin.M762 == 5) {
new_Skin.M762 = 1101008104;
new_Skin.M762_Mag = 1010081041;
}
if (preferences.Config.Skin.M762 == 6) {
new_Skin.M762 = 1101008116;
new_Skin.M762_Mag = 1010081161;
}
if (preferences.Config.Skin.M762 == 7) {
new_Skin.M762 = 1101008126;
new_Skin.M762_Mag = 1010081261;
}
if (preferences.Config.Skin.M762 == 8) {
new_Skin.M762 = 1101008136;
new_Skin.M762_Mag = 1101008136;
}
if (preferences.Config.Skin.M762 == 9) {
new_Skin.M762 = 1101008146;
new_Skin.M762_Mag = 1101008146;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.ACE32 == 0)
new_Skin.ACE32 = 101102;
if (preferences.Config.Skin.ACE32 == 1)
new_Skin.ACE32 = 1101102007;
if (preferences.Config.Skin.ACE32 == 2)
new_Skin.ACE32 = 1101102017;
if (preferences.Config.Skin.ACE32 == 3)
new_Skin.ACE32 = 1101102025;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.UZI == 0)
new_Skin.UZI = 102001;
if (preferences.Config.Skin.UZI == 1)
new_Skin.UZI = 1102001024;
if (preferences.Config.Skin.UZI == 2)
new_Skin.UZI = 1102001036;
if (preferences.Config.Skin.UZI == 3)
new_Skin.UZI = 1102001058;
if (preferences.Config.Skin.UZI == 4)
new_Skin.UZI = 1102001069;
if (preferences.Config.Skin.UZI == 5)
new_Skin.UZI = 1102001089; 
if (preferences.Config.Skin.UZI == 6)
new_Skin.UZI = 1102001103; 
if (preferences.Config.Skin.UZI == 7)
new_Skin.UZI = 1102001102;
if (preferences.Config.Skin.UZI == 8)
new_Skin.UZI = 1102001112;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.UMP == 0)
new_Skin.UMP = 102002;
if (preferences.Config.Skin.UMP == 1)
new_Skin.UMP = 1102002043;
if (preferences.Config.Skin.UMP == 2)
new_Skin.UMP = 1102002053;
if (preferences.Config.Skin.UMP == 3)
new_Skin.UMP = 1102002061;
if (preferences.Config.Skin.UMP == 4)
new_Skin.UMP = 1102002066;
if (preferences.Config.Skin.UMP == 5)
new_Skin.UMP = 1102002090;
if (preferences.Config.Skin.UMP == 6)
new_Skin.UMP = 1102002112;
if (preferences.Config.Skin.UMP == 7)
new_Skin.UMP = 1102002119;
if (preferences.Config.Skin.UMP == 8)
new_Skin.UMP = 1102002124;
if (preferences.Config.Skin.UMP == 9)
new_Skin.UMP = 1102002129;
if (preferences.Config.Skin.UMP == 10)
new_Skin.UMP = 1102002136;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.P90 == 0)
new_Skin.P90 = 102105;
if (preferences.Config.Skin.P90 == 1)
new_Skin.P90 = 1102105012; //Angry Sheep - P90 
if (preferences.Config.Skin.P90 == 2)
new_Skin.P90 = 1102105002; //Evangelion-00 - P90 
if (preferences.Config.Skin.P90 == 3)
new_Skin.P90 = 1102105003; //Dancing Prints - P90 
if (preferences.Config.Skin.P90 == 4)
new_Skin.P90 = 1102105004; //Fairytale Scarecrow - P90 
if (preferences.Config.Skin.P90 == 5)
new_Skin.P90 =1102105005; //Polished Splendor - P90 
if (preferences.Config.Skin.P90 == 6)
new_Skin.P90 = 1102105001; //Devious Cybercat - P90 (Lv. 7) 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.Vector == 0)
new_Skin.Vector = 102003;
if (preferences.Config.Skin.Vector == 1)
new_Skin.Vector = 1102003020;
if (preferences.Config.Skin.Vector == 2)
new_Skin.Vector = 1102003031;
if (preferences.Config.Skin.Vector == 3)
new_Skin.Vector = 1102003049;
if (preferences.Config.Skin.Vector == 4)
new_Skin.Vector = 1102003048;
if (preferences.Config.Skin.Vector == 5)
new_Skin.Vector = 1102003065;
if (preferences.Config.Skin.Vector == 6)
new_Skin.Vector = 1102003072;
if (preferences.Config.Skin.Vector == 7)
new_Skin.Vector = 1102003080;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.Thompson == 0)
new_Skin.Thompson = 102004;
if (preferences.Config.Skin.Thompson == 1)
new_Skin.Thompson = 1102004018;
if (preferences.Config.Skin.Thompson == 2)
new_Skin.Thompson = 1102004034;
if (preferences.Config.Skin.Thompson == 3)
new_Skin.Thompson = 1102004049;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.Bizon == 0)
new_Skin.Bizon = 102005;
if (preferences.Config.Skin.Bizon == 1)
new_Skin.Bizon = 1102005007;
if (preferences.Config.Skin.Bizon == 2)
new_Skin.Bizon = 1102005020;
if (preferences.Config.Skin.Bizon == 3)
new_Skin.Bizon = 1102005041;
if (preferences.Config.Skin.Bizon == 4)
new_Skin.Bizon = 1102005046;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.K98 == 0)
new_Skin.K98 = 103001;
if (preferences.Config.Skin.K98 == 1)
new_Skin.K98 = 1103001060;
if (preferences.Config.Skin.K98 == 2)
new_Skin.K98 = 1103001079;
if (preferences.Config.Skin.K98 == 3)
new_Skin.K98 = 1103001101;
if (preferences.Config.Skin.K98 == 4)
new_Skin.K98 = 1103001145;
if (preferences.Config.Skin.K98 == 5)
new_Skin.K98 = 1103001160;
if (preferences.Config.Skin.K98 == 6)
new_Skin.K98 = 1103001179;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (new_Skin.M24 == 0)
new_Skin.M24 = 103002;
if (preferences.Config.Skin.M24 == 1)
new_Skin.M24 = 1103002018;
if (preferences.Config.Skin.M24 == 2)
new_Skin.M24 = 1103002030;
if (preferences.Config.Skin.M24 == 3)
new_Skin.M24 = 1103002048;
if (preferences.Config.Skin.M24 == 4)
new_Skin.M24 = 1103002047;
if (preferences.Config.Skin.M24 == 5)
new_Skin.M24 = 1103002059;
if (preferences.Config.Skin.M24 == 6)
new_Skin.M24 = 1103002087;
if (preferences.Config.Skin.M24 == 7)
new_Skin.M24 = 1103002094;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.AWM == 0)
new_Skin.AWM = 103003;
if (preferences.Config.Skin.AWM == 1)
new_Skin.AWM = 1103003022;
if (preferences.Config.Skin.AWM == 2)
new_Skin.AWM = 1103003030;
if (preferences.Config.Skin.AWM == 3)
new_Skin.AWM = 1103003042;
if (preferences.Config.Skin.AWM == 4)
new_Skin.AWM = 1103003051;
if (preferences.Config.Skin.AWM == 5)
new_Skin.AWM = 1103003062;
if (preferences.Config.Skin.AWM == 6)
new_Skin.AWM = 1103003087;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.MG3 == 0)
new_Skin.MG3 = 105010;
if (preferences.Config.Skin.MG3 == 1)
new_Skin.MG3 = 1105010019;// Sky Huntress - MG3 (Lv. 7) 
if (preferences.Config.Skin.MG3 == 2)
new_Skin.MG3 = 1105010008;// Soaring Dragon - MG3 (Lv. 5) 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (preferences.Config.Skin.DP28 == 0)
new_Skin.DP28 = 105002;
if (preferences.Config.Skin.DP28 == 1)
new_Skin.DP28 = 1105002018;
if (preferences.Config.Skin.DP28 == 2)
new_Skin.DP28 = 1105002035;
if (preferences.Config.Skin.DP28 == 3)
new_Skin.DP28 = 1105002058;
if (preferences.Config.Skin.DP28 == 4)
new_Skin.DP28 = 1105002063;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (new_Skin.M249 == 0)
new_Skin.M249 = 105001;
new_Skin.M249s = 205009;
if (preferences.Config.Skin.M249 == 1)
new_Skin.M249 = 1105001020;
new_Skin.M249s = 1050010351;
if (preferences.Config.Skin.M249 == 2)
new_Skin.M249 = 1105001034;
new_Skin.M249s = 1050010412;
if (preferences.Config.Skin.M249 == 3)
new_Skin.M249 = 1105001048;
new_Skin.M249s = 1050010482;
if (preferences.Config.Skin.M249 == 4)
new_Skin.M249 = 1105001054;
new_Skin.M249s = 1050010542;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 if (preferences.Config.Skin.Bigfoot == 0)
new_Skin.Bigfoot = 1953001;
if (preferences.Config.Skin.Bigfoot == 1)
new_Skin.Bigfoot = 1953004;

if (preferences.Config.Skin.OMirado == 0)
new_Skin.OMirado = 1915001;
if (preferences.Config.Skin.OMirado == 1)
new_Skin.OMirado = 1915011;
if (preferences.Config.Skin.OMirado == 2)
new_Skin.OMirado = 1915099;

if (preferences.Config.Skin.Mirado == 0)
new_Skin.Mirado = 1914001;
if (preferences.Config.Skin.Mirado == 1)
new_Skin.Mirado = 1914011;

if (preferences.Config.Skin.Moto == 0)
new_Skin.Moto = 1901001;
if (preferences.Config.Skin.Moto == 1)
new_Skin.Moto = 1901073;
if (preferences.Config.Skin.Moto == 2)
new_Skin.Moto = 1901074;
if (preferences.Config.Skin.Moto == 3)
new_Skin.Moto = 1901075;
if (preferences.Config.Skin.Moto == 4)
new_Skin.Moto = 1901047;
if (preferences.Config.Skin.Moto == 5)
new_Skin.Moto = 1901085;
if (preferences.Config.Skin.Moto == 6)
new_Skin.Moto = 1901076;
if (preferences.Config.Skin.Moto == 7)
new_Skin.Moto = 1901027;
if (preferences.Config.Skin.Moto == 8)
new_Skin.Moto = 1901018;
if (preferences.Config.Skin.Moto == 9)
new_Skin.Moto = 1901085;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (preferences.Config.Skin.Buggy == 0)
new_Skin.Buggy = 1907001;
if (preferences.Config.Skin.Buggy == 1)
new_Skin.Buggy = 1907047;
if (preferences.Config.Skin.Buggy == 2)
new_Skin.Buggy = 1907009;
if (preferences.Config.Skin.Buggy == 3)
new_Skin.Buggy = 1907010;
if (preferences.Config.Skin.Buggy == 4)
new_Skin.Buggy = 1907011;
if (preferences.Config.Skin.Buggy == 5)
new_Skin.Buggy = 1907012;
if (preferences.Config.Skin.Buggy == 6)
new_Skin.Buggy = 1907013;
if (preferences.Config.Skin.Buggy == 7)
new_Skin.Buggy = 1907014;
if (preferences.Config.Skin.Buggy == 8)
new_Skin.Buggy = 1907015;
if (preferences.Config.Skin.Buggy == 9)
new_Skin.Buggy = 1907016;
if (preferences.Config.Skin.Buggy == 10)
new_Skin.Buggy = 1907017;
if (preferences.Config.Skin.Buggy == 11)
new_Skin.Buggy = 1907018;
if (preferences.Config.Skin.Buggy == 12)
new_Skin.Buggy = 1907019;
if (preferences.Config.Skin.Buggy == 13)
new_Skin.Buggy = 1907020;
if (preferences.Config.Skin.Buggy == 14)
new_Skin.Buggy = 1907021;
if (preferences.Config.Skin.Buggy == 15)
new_Skin.Buggy = 1907022;
if (preferences.Config.Skin.Buggy == 16)
new_Skin.Buggy = 1907023;
if (preferences.Config.Skin.Buggy == 17)
new_Skin.Buggy = 1907024;
if (preferences.Config.Skin.Buggy == 18)
new_Skin.Buggy = 1907025;
if (preferences.Config.Skin.Buggy == 19)
new_Skin.Buggy = 1907026;
if (preferences.Config.Skin.Buggy == 20)
new_Skin.Buggy = 1907027;
if (preferences.Config.Skin.Buggy == 21)
new_Skin.Buggy = 1907028;
if (preferences.Config.Skin.Buggy == 22)
new_Skin.Buggy = 1907029;
if (preferences.Config.Skin.Buggy == 23)
new_Skin.Buggy = 1907030;
if (preferences.Config.Skin.Buggy == 24)
new_Skin.Buggy = 1907031;
if (preferences.Config.Skin.Buggy == 25)
new_Skin.Buggy = 1907032;
if (preferences.Config.Skin.Buggy == 26)
new_Skin.Buggy = 1907033;
if (preferences.Config.Skin.Buggy == 27)
new_Skin.Buggy = 1907034;
if (preferences.Config.Skin.Buggy == 28)
new_Skin.Buggy = 1907035;
if (preferences.Config.Skin.Buggy == 29)
new_Skin.Buggy = 1907036;
if (preferences.Config.Skin.Buggy == 30)
new_Skin.Buggy = 1907037;
if (preferences.Config.Skin.Buggy == 31)
new_Skin.Buggy = 1907038;
if (preferences.Config.Skin.Buggy == 32)
new_Skin.Buggy = 1907039;
if (preferences.Config.Skin.Buggy == 33)
new_Skin.Buggy = 1907040;

if (preferences.Config.Skin.Dacia == 0)
new_Skin.Dacia = 1903001;
if (preferences.Config.Skin.Dacia == 1)
new_Skin.Dacia = 1903076;
if (preferences.Config.Skin.Dacia == 2)
new_Skin.Dacia = 1903079;
if (preferences.Config.Skin.Dacia == 3)
new_Skin.Dacia = 1903071;
if (preferences.Config.Skin.Dacia == 4)
new_Skin.Dacia = 1903014;
if (preferences.Config.Skin.Dacia == 5)
new_Skin.Dacia = 1903017;
if (preferences.Config.Skin.Dacia == 6)
new_Skin.Dacia = 1903035;
if (preferences.Config.Skin.Dacia == 7)
new_Skin.Dacia = 1903087;
if (preferences.Config.Skin.Dacia == 8)
new_Skin.Dacia = 1903088;
if (preferences.Config.Skin.Dacia == 9)
new_Skin.Dacia = 1903089;
if (preferences.Config.Skin.Dacia == 10)
new_Skin.Dacia = 1903090;
if (preferences.Config.Skin.Dacia == 11)
new_Skin.Dacia = 1903074;
if (preferences.Config.Skin.Dacia == 12)
new_Skin.Dacia = 1903075;
if (preferences.Config.Skin.Dacia == 13)
new_Skin.Dacia = 1903072;
if (preferences.Config.Skin.Dacia == 14)
new_Skin.Dacia = 1903073;
if (preferences.Config.Skin.Dacia == 15)
new_Skin.Dacia = 1903080;
if (preferences.Config.Skin.Dacia == 16)
new_Skin.Dacia = 1903189;
if (preferences.Config.Skin.Dacia == 17)
new_Skin.Dacia = 1903190;
if (preferences.Config.Skin.Dacia == 18)
new_Skin.Dacia = 1903191;
if (preferences.Config.Skin.Dacia == 19)
new_Skin.Dacia = 1903192;
if (preferences.Config.Skin.Dacia == 20)
new_Skin.Dacia = 1903193;
if (preferences.Config.Skin.Dacia == 21)
new_Skin.Dacia = 1903197;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


if (preferences.Config.Skin.MiniBus == 0)
new_Skin.MiniBus = 1904001;
if (preferences.Config.Skin.MiniBus == 1)
new_Skin.MiniBus = 1904005;
if (preferences.Config.Skin.MiniBus == 2)
new_Skin.MiniBus = 1904006;
if (preferences.Config.Skin.MiniBus == 3)
new_Skin.MiniBus = 1904007;
if (preferences.Config.Skin.MiniBus == 4)
new_Skin.MiniBus = 1904008;
if (preferences.Config.Skin.MiniBus == 5)
new_Skin.MiniBus = 1904009;
if (preferences.Config.Skin.MiniBus == 6)
new_Skin.MiniBus = 1904010;
if (preferences.Config.Skin.MiniBus == 7)
new_Skin.MiniBus = 1904011;
if (preferences.Config.Skin.MiniBus == 8)
new_Skin.MiniBus = 1904012;
if (preferences.Config.Skin.MiniBus == 9)
new_Skin.MiniBus = 1904013;
if (preferences.Config.Skin.MiniBus == 10)
new_Skin.MiniBus = 1904014;
if (preferences.Config.Skin.MiniBus == 11)
new_Skin.MiniBus = 1904015;
if (preferences.Config.Skin.MiniBus == 12)
new_Skin.MiniBus = 1904004;

if (preferences.Config.Skin.CoupeRP == 0)
new_Skin.CoupeRP = 1961001;
if (preferences.Config.Skin.CoupeRP == 1)
new_Skin.CoupeRP = 1961024;
if (preferences.Config.Skin.CoupeRP == 2)
new_Skin.CoupeRP = 1961047;
if (preferences.Config.Skin.CoupeRP == 3)
new_Skin.CoupeRP = 1961034;
if (preferences.Config.Skin.CoupeRP == 4)
new_Skin.CoupeRP = 1961018;
if (preferences.Config.Skin.CoupeRP == 5)
new_Skin.CoupeRP = 1961007;
if (preferences.Config.Skin.CoupeRP == 6)
new_Skin.CoupeRP = 1961010;
if (preferences.Config.Skin.CoupeRP == 7)
new_Skin.CoupeRP = 1961049;
if (preferences.Config.Skin.CoupeRP == 8)
new_Skin.CoupeRP = 1961048;
if (preferences.Config.Skin.CoupeRP == 9)
new_Skin.CoupeRP = 1961012;
if (preferences.Config.Skin.CoupeRP == 10)
new_Skin.CoupeRP = 1961013;
if (preferences.Config.Skin.CoupeRP == 11)
new_Skin.CoupeRP = 1961014;
if (preferences.Config.Skin.CoupeRP == 12)
new_Skin.CoupeRP = 1961015;
if (preferences.Config.Skin.CoupeRP == 13)
new_Skin.CoupeRP = 1961016;
if (preferences.Config.Skin.CoupeRP == 14)
new_Skin.CoupeRP = 1961017;
if (preferences.Config.Skin.CoupeRP == 15)
new_Skin.CoupeRP = 1961020;
if (preferences.Config.Skin.CoupeRP == 16)
new_Skin.CoupeRP = 1961021;
if (preferences.Config.Skin.CoupeRP == 17)
new_Skin.CoupeRP = 1961025;
if (preferences.Config.Skin.CoupeRP == 18)
new_Skin.CoupeRP = 1961029;
if (preferences.Config.Skin.CoupeRP == 19)
new_Skin.CoupeRP = 1961030;
if (preferences.Config.Skin.CoupeRP == 20)
new_Skin.CoupeRP = 1961031;
if (preferences.Config.Skin.CoupeRP == 21)
new_Skin.CoupeRP = 1961032;
if (preferences.Config.Skin.CoupeRP == 22)
new_Skin.CoupeRP = 1961033;
if (preferences.Config.Skin.CoupeRP == 23)
new_Skin.CoupeRP = 1961035;
if (preferences.Config.Skin.CoupeRP == 24)
new_Skin.CoupeRP = 1961036;
if (preferences.Config.Skin.CoupeRP == 22)
new_Skin.CoupeRP = 1961037;
if (preferences.Config.Skin.CoupeRP == 26)
new_Skin.CoupeRP = 1961038;
if (preferences.Config.Skin.CoupeRP == 27)
new_Skin.CoupeRP = 1961039;
if (preferences.Config.Skin.CoupeRP == 28)
new_Skin.CoupeRP = 1961040;
if (preferences.Config.Skin.CoupeRP == 29)
new_Skin.CoupeRP = 1961041;
if (preferences.Config.Skin.CoupeRP == 30)
new_Skin.CoupeRP = 1961042;
if (preferences.Config.Skin.CoupeRP == 31)
new_Skin.CoupeRP = 1961043;
if (preferences.Config.Skin.CoupeRP == 32)
new_Skin.CoupeRP = 1961044;
if (preferences.Config.Skin.CoupeRP == 33)
new_Skin.CoupeRP = 1961045;
if (preferences.Config.Skin.CoupeRP == 34)
new_Skin.CoupeRP = 1961046;
if (preferences.Config.Skin.CoupeRP == 35)
new_Skin.CoupeRP = 1961050;
if (preferences.Config.Skin.CoupeRP == 36)
new_Skin.CoupeRP = 1961051;
if (preferences.Config.Skin.CoupeRP == 37)
new_Skin.CoupeRP = 1961052;
if (preferences.Config.Skin.CoupeRP == 38)
new_Skin.CoupeRP = 1961053;
if (preferences.Config.Skin.CoupeRP == 39)
new_Skin.CoupeRP = 1961054;
if (preferences.Config.Skin.CoupeRP == 40)
new_Skin.CoupeRP = 1961055;
if (preferences.Config.Skin.CoupeRP == 41)
new_Skin.CoupeRP = 1961056;
if (preferences.Config.Skin.CoupeRP == 42)
new_Skin.CoupeRP = 1961057;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (preferences.Config.Skin.UAZ == 0)
new_Skin.UAZ = 1908001;
if (preferences.Config.Skin.UAZ == 1)
new_Skin.UAZ = 1908067;
if (preferences.Config.Skin.UAZ == 2)
new_Skin.UAZ = 1908061;
if (preferences.Config.Skin.UAZ == 3)
new_Skin.UAZ = 1908032;
if (preferences.Config.Skin.UAZ == 4)
new_Skin.UAZ = 1908068;
if (preferences.Config.Skin.UAZ == 5)
new_Skin.UAZ = 1908066;
if (preferences.Config.Skin.UAZ == 6)
new_Skin.UAZ = 1908075;
if (preferences.Config.Skin.UAZ == 7)
new_Skin.UAZ = 1908076;
if (preferences.Config.Skin.UAZ == 8)
new_Skin.UAZ = 1908077;
if (preferences.Config.Skin.UAZ == 9)
new_Skin.UAZ = 1908078;
if (preferences.Config.Skin.UAZ == 10)
new_Skin.UAZ = 1908084;
if (preferences.Config.Skin.UAZ == 11)
new_Skin.UAZ = 1908085;
if (preferences.Config.Skin.UAZ == 12)
new_Skin.UAZ = 1908086;
if (preferences.Config.Skin.UAZ == 13)
new_Skin.UAZ = 1908088;
if (preferences.Config.Skin.UAZ == 14)
new_Skin.UAZ = 1908089;
if (preferences.Config.Skin.UAZ == 15)
new_Skin.UAZ = 1908188;
if (preferences.Config.Skin.UAZ == 16)
new_Skin.UAZ = 1908189;
if (preferences.Config.Skin.UAZ == 17)
new_Skin.UAZ = 1957001;
 
 if (preferences.Config.Skin.Boat == 0)
new_Skin.Boat = 1911001;
if (preferences.Config.Skin.Boat == 1)
new_Skin.Boat = 1911013;
if (preferences.Config.Skin.Boat == 2)
new_Skin.Boat = 1911003;
if (preferences.Config.Skin.Boat == 3)
new_Skin.Boat = 1911004;
if (preferences.Config.Skin.Boat == 4)
new_Skin.Boat = 1911005;
if (preferences.Config.Skin.Boat == 5)
new_Skin.Boat = 1911006;
if (preferences.Config.Skin.Boat == 6)
new_Skin.Boat = 1911007;
if (preferences.Config.Skin.Boat == 7)
new_Skin.Boat = 1911008;
if (preferences.Config.Skin.Boat == 8)
new_Skin.Boat = 1911009;
if (preferences.Config.Skin.Boat == 9)
new_Skin.Boat = 1911010;
if (preferences.Config.Skin.Boat == 10)
new_Skin.Boat = 1911011;
if (preferences.Config.Skin.Boat == 11)
new_Skin.Boat = 1911012;
}

int scar[] = { 101003,1010031,1010032,1010033,1010034,1010035,1010036,1010037,1010039, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181};
int akmv[] = { 101001,1010011,1010012,1010013,1010014,1010015,1010016,1010017,1010019,1101001089, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001213,1101001231,1101001242,1010012561,1010012491};
int m7[] = { 101008,1010081,1010082,1010083,1010084,1010085,1010086,1010087,1010089, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126,1010081381};
int awm[] = { 103003,1030033,1030034,1030035,1030036,1030037,1030039, 1103003022, 1103003030, 1103003042, 1103003051, 1103003062};
int kar[] = { 103001, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179};
int m24[] = { 103002,1030021,1030022,1030023,1030024,1030025,1030026,1030027, 1103002018, 1103002030, 1103002048, 1103002056, 1103002087};
int dp[] = { 105002, 1105002018, 1105002035, 1105002058, 1105002063};
int m249[] = { 105001, 1105001020, 1105001034, 1105001048, 1105001054};
int groza[] = { 101005,1010051,1010052,1010053,1010054,1010055,1010056,1010057,1010059, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
int aug[] = { 101006, 1101006033, 1101006044, 1101006062};
int m16[] = { 101002, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103};
int uzi[] = { 102001, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102};
int ump[] = { 102002, 1102002043, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002136};
int vector[] = { 102003, 1102003020, 1102003031, 1102003065, 1102003080};
int tommy[] = { 102004, 1102004018, 1102004034};
int bizon[] = { 102005, 1102005007, 1102005020, 1102005041};
int ace32[] = { 101102, 1101102007, 1101102017,1011020228};
int pan[] = { 108004, 1108004125, 1108004145, 1108004160, 1108004283, 1108004337, 1108004356, 1108004365, 1108004054, 1108004008};
int m249s[] = { 205009, 1050010351, 1050010412, 1050010482, 1050010542};
int akmmag[] = { 291001,204013,204011,204012,1010010891, 1010011031, 1010011161, 1010011281, 1010011431, 1010011541, 1010011741,1010012131,1010012311,1010012421};
int m7mag[] = { 291008,204013,204011,204012,1010080261, 1010080511, 1010080611, 1010080811, 1010081041, 1010081161, 1010081261};
int scarmag[] = { 291003,204013,204011,204012,1010030571, 1010030701, 1010030801, 1010031191, 1010031461, 1010031671, 1010031811};

int m16s[] = { 205007, 1010020292, 1010020562, 1010020682, 1010020812, 1010021032};
int m16mag[] = { 291002,204013,204011,204012, 1010020291, 1010020561, 1010020681, 1010020811, 1010021031};
int mk14[] = {103007,1030071,1030072,1030073,1030074,1030075,1030076,1030077,1103007020,1103007028};
int P90[] = {102105,1102105001,1102105002,1102105003,1102105004};
int MG3[] = {105010,1105010019,1105010008,1105010009,1105010010,1105010011};
int SuitX[] = {403003,1405628, 1405870, 1405983, 1406152, 1406311, 1406475, 1406638,1406872,1406971,1407103,1407366,1406469, 1406641,1405174,1400687,1407275,1407329,1407330,1405145, 1400782, 1405860, 1400324, 1400288,1400117, 1405436, 1405433, 1405434, 1405435, 1405340, 1405341, 1405334,1400106};
int Bag[] = { 501006,501005,501004,501003,501002,501001,1501003550,1501003277,1501003321,1501003443,1501003265,1501003051,1501003220,1501003174,1501003466,1501003043,1501003093,1501003118,1501003024};
int Helmet[] = { 502001,502002,502003,1502003014,1502003028,1502003023,1501002443,1502003031,1502003033,1502003069,1502003261, 1502003009,1502003018,1502003047,1502003086,1502003151};


int m4mag[] = { 291004,204013,204011,204012,1010040461,1010040611,1010040781,1010040861,1010040981,1010041381,1010041631,1010042011,1010042073,1010042153};
int m4v[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163,1101004201,1101004209,1101004218 ,1101004226};
int m4sight[] = { 203008,1010040462,1010040612,1010040782,1010040862,1010040982,1010041382,1010041632,1010042012,1010042083,1010042163};
int m4stock[] = { 205005,1010040463,1010040613,1010040783,1010040863,1010040983,1010041383,1010041633,1010042013,1010042093,1010042173};
int m4stock1[] = { 205002,1010040480,205002,205002,205002,205002,1010041146,1010041579,1010041966,1010042137,1010042173};
int m4reddot[] = { 203001,1010040470,203001,203001,203001,203001,1010041128,1010041566,1010041948,1010042029,1010042119};
int m4x3[] = {203014, 1010040467, 203014, 203014, 203014, 1010041125, 1010041560, 1010041945, 1010042026, 1010042219, 1010042116, 1010042219};
int m4x4[] = { 203004, 1010040466, 203004, 203004, 203004, 1010041124, 1010041554, 1010041944, 1010042025, 1010042218, 1010042115, 1010042218 };
int m4x6[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 203015, 1010041967, 1010042024, 1010042217, 1010042114, 1010042217 };