#include <list>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <dirent.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <libgen.h>
#include <memory>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <unwind.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>
#include <jni.h>
#include <cstddef>
// ============================ CONSTANTS ============================
uintptr_t NewBase = 0, libanogsBase = 0, libUE4Base = 0, libanogsAlloc = 0, libUE4Alloc = 0;
#define _BYTE uint8_t
#define _WORD uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
// ============================ Define constants ============================
#define libanogs "libanogs.so"
#define LibUE4 "libUE4.so"
#define PKG_GL "com.tencent.ig"
#define PKG_VNG "com.vng.pubgmobile"
#define PKG_KR "com.pubg.krmobile"
#define PKG_TW "com.rekoo.pubgm"
#define PKG_IN "com.pubg.imobile"
// ============================ MACROS ============================
#define SONIC(RET, NAME, ARGS) \
  RET(*o##NAME) ARGS; \
  RET h##NAME ARGS
  
  
#define SONIC_ZERO(RET, NAME, ARGS) \
RET(*o##NAME)   \
ARGS;   \
RET h##NAME ARGS\
{   \
asm volatile( \
"mov r0, #0\n"  \
); \
}

#define HOOK_LIB_OXORANY(lib, offset, ptr, orig) \
hook((void *)getAbsoluteAddress(oxorany(lib), string2Offset(oxorany(offset))), (void *)ptr, (void **)&orig)

#define PATCH_OXORANY(lib, offset, hex) \
patchOffset(oxorany(lib), string2Offset(oxorany(offset)), oxorany(hex), true)

// ============================ Helper Functions ============================
bool isAPKRunning(const char* packageName) {
DIR* dir = opendir("/proc/");
if (!dir) return false;
struct dirent* ptr;
char filepath[50], filetext[128];
while ((ptr = readdir(dir)) != nullptr) {
if (ptr->d_type != DT_DIR) continue;
snprintf(filepath, sizeof(filepath), "/proc/%s/cmdline", ptr->d_name);
FILE* fp = fopen(filepath, "r");
if (fp) {
fgets(filetext, sizeof(filetext), fp);
fclose(fp);
if (strcmp(filetext, packageName) == 0) {
closedir(dir);
return true;}}}
closedir(dir);
return false;}

const char* GetPackageNameA() {
if (isAPKRunning("com.tencent.ig")) return "com.tencent.ig";
if (isAPKRunning("com.vng.pubgmobile")) return "com.vng.pubgmobile";
if (isAPKRunning("com.pubg.krmobile")) return "com.pubg.krmobile";
if (isAPKRunning("com.rekoo.pubgm")) return "com.rekoo.pubgm";
if (isAPKRunning("com.pubg.imobile")) return "com.pubg.imobile";
return "unknown pkg";
}

bool checkFileForPlugin() {
std::ifstream file("/proc/self/cmdline");
std::string line;
while (file.is_open() && std::getline(file, line)) {
if (line.find(":plugin") != std::string::npos) {
file.close();
kill(getpid(), SIGSTOP);
pthread_exit(NULL);
return true;}}
return false;}
// ============================ HOOKS IMPLEMENTATIONS ============================

// ============================ MAIN THREAD ============================
//------ HOOKS









//--- END
// ============================ MAIN THREAD ============================
void* ANOGS_THREAD(void*)  {
std::string package = GetPackageNameA();
LOGI(OBFUSCATE("Detected Package: %s"), package.c_str());
do { sleep(1); } while (!isLibraryLoaded(OBFUSCATE("libanogs.so")));
libanogsBase = findLibrary(OBFUSCATE("libanogs.so"));
//======== Complete  ======== 
  
//=========== PATCH =================================    
     //--------- Complete ----------
LOGI("ANOGS thread LOADED successfully");
return nullptr;
}
void* UE4_THREAD(void*)  {
std::string package = GetPackageNameA();
LOGI(OBFUSCATE("Detected Package: %s"), package.c_str());
do { sleep(1); } while (!isLibraryLoaded(OBFUSCATE("libUE4.so")));
libUE4Base = findLibrary(OBFUSCATE("libUE4.so"));
     // ===================== START =====================
     

     // ===================== END =====================
LOGI("UE4 thread LOADED successfully");
return nullptr;
}

__attribute__((constructor)) void __int() {
pthread_t ptid;
pthread_create(&ptid, nullptr, ANOGS_THREAD, nullptr);
pthread_create(&ptid, nullptr, UE4_THREAD, nullptr);
}
