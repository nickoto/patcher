#include "apply_patch.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    printf("Patcher\n");
    if (argc != 3) {
        printf("USAGE: patch {in_file} {patch_file}\n");
        return 0;
    }

    int len = strlen(argv[1]);
    char *outfile_name = calloc(len+20, 1);
    char *bakfile_name = calloc(len+20, 1);

    snprintf(outfile_name, len+20, "%s.patched", argv[1]);
    snprintf(bakfile_name, len+20, "%s.bak", argv[1]);

    printf("Patching to: %s\n", outfile_name);

    FILE* infile = fopen(argv[1], "rb");
    FILE* patchfile = fopen(argv[2], "rb");

    if (!infile) {
        printf("Input file not found: %s\n", argv[1]);
        return -1;
    }
    if (!patchfile) {
        printf("Patch file not found: %s\n", argv[3]);
        return -1;
    }

    FILE* outfile = fopen(outfile_name, "w+b");
    if (!outfile) {
        printf("Could not create output file: %s\n", argv[2]);
        return -1;
    }

    int result = DoPatch(patchfile, infile, outfile);
    if (PATCH_SUCCESS != result) {
        printf("Failed to patch %s\n", argv[2]);
        printf("Error: %d\n", result);
        remove(outfile_name);
        return result;
    }

    fclose(infile);
    fclose(outfile);
    fclose(patchfile);

    rename(argv[1], bakfile_name);
    rename(outfile_name, argv[1]);

    printf("Patching success\n");
}
