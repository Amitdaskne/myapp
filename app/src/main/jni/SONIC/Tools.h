#pragma once

#include <map>
#include <jni.h>
#include "Dobby/dobby.h"
#include "Includes.h"

uintptr_t getBaseAddress(std::string_view name);
uintptr_t getEndAddress(std::string_view name);
uintptr_t findPattern(const char *lib, const char *bMask, const char *szMask);
int setPageProtection(void *target, int protection);
void writeMem(void *dst, void *src, int len);

namespace Tools {
	void Hook(void *target, void *replace, void **backup);
	
	bool Read(void *addr, void *buffer, size_t length);
	bool Write(void *addr, void *buffer, size_t length);
	bool ReadAddr(void *addr, void *buffer, size_t length);
	bool WriteAddr(void *addr, void *buffer, size_t length);
	bool SetWriteable(void *addr);
	bool PVM_ReadAddr(void *addr, void *buffer, size_t length);
	bool PVM_WriteAddr(void *addr, void *buffer, size_t length);
	bool IsPtrValid(void *addr);
	
	uintptr_t GetBaseAddress(const char *name);
	uintptr_t GetEndAddress(const char *name);
	uintptr_t FindPattern(const char *lib, const char* pattern);
	uintptr_t GetRealOffsets(const char *libraryName, uintptr_t relativeAddr);
	uintptr_t String2Offset(const char *c);
	
	const char *GetAndroidID(JNIEnv *env, jobject context);
	const char *GetDeviceModel(JNIEnv *env);
	const char *GetDeviceBrand(JNIEnv *env);
	const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid);
	std::string CalcMD5(std::string s);
}
typedef signed char mbyte;
typedef long long mlong;       //long 8
typedef unsigned long ulong;  //unsig long 4/8
typedef ulong Addr;  //unsig long 4/8
typedef long Offset;  //unsig long 4/8
typedef double mdouble;       //double 8
typedef float mfloat;         //float 4
typedef unsigned int uint;
typedef int TYPE;
typedef unsigned char boolean;
typedef unsigned char uchar;
typedef unsigned int CharType;
typedef unsigned char UTF8;
typedef unsigned short UTF16;
typedef unsigned int UTF32;

// 3D结构体
struct C3D {
    float x;
    float y;
    float z;
};

// 2D结构体
struct C2D {
    float x;
    float y;
    float w;
    float h;
};

struct RADDR {
    Addr addr;                    // 起始地址
    Addr taddr;                   // 结束地址
};



