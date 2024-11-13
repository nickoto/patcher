#ifndef PATCHER_HELPERS_H
#define PATCHER_HELPERS_H

#include <stdio.h>

#define FALSE 0
#define TRUE 1
typedef unsigned int DWORD;
typedef unsigned int UINT;
typedef unsigned char BYTE;
typedef unsigned char BOOL;
typedef FILE* HANDLE;
#define FILE_BEGIN SEEK_SET
#define FILE_END SEEK_END
#define FILE_CURRENT SEEK_CUR
#define min(a, b) (a <= b ? a : b)

void SetFilePointer(FILE* file, DWORD offset, void* reserved, int set);
int ReadFile(FILE* file, void *dest, DWORD len, DWORD *read, void *reserved);
int WriteFile(FILE* file, void* block, DWORD len, DWORD* written, void *reserved);
#endif //PATCHER_HELPERS_H
