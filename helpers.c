#include <stdint.h>
#include "checksum.h"
#include "apply_patch.h"
#include "helpers.h"

#define FILE_BEGIN SEEK_SET
#define FILE_END SEEK_END
#define FILE_CURRENT SEEK_CUR
#define min(a, b) (a <= b ? a : b)

void SetFilePointer(FILE* file, DWORD offset, void * reserved, int set)
{
    fseek(file, offset, set);
}

int ReadFile(FILE* file, void *dest, DWORD len, DWORD *read, void *reserved)
{
    *read = fread(dest, 1, len, file);

    return TRUE;
}

int WriteFile(FILE* file, void* block, DWORD len, DWORD* written, void *reserved)
{
    *written = fwrite(block, 1, len, file);

    return TRUE;
}