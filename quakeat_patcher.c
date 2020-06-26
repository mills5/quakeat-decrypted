//
//	https://github.com/mills5/quakeat-decrypted/
//	Patches a Quake Arcade Tournament Edition 'glquake.exe' to remove the dongle protection.
//

#include <stdio.h>

#define TARGET_FILENAME "glquake.exe"
#define OUTPUT_FILENAME "glquake_at_patched.exe"

const unsigned long file_shell_oep = 0x80010;
const unsigned char newCode[104] = { 0xBB, 0x30, 0x4B, 0xD8, 0x00, 0xBE, 0x50, 0x41, 0xD8, 0x00, 0x68, 0x22, 0x7D, 0x51, 0x6B, 0x68, 0x70, 0x02, 0x00, 0x00, 0x68, 0x04, 0x10, 0xD8, 0x00, 0xFF, 0xD3, 0x68, 0xB1, 0xC5, 0x0F, 0xC6, 0x68, 0xA6, 0xDE, 0x05, 0x00, 0x68, 0x00, 0x10, 0x40, 0x00, 0xFF, 0xD3, 0x68, 0xB5, 0xA5, 0xE2, 0x13, 0x68, 0x00, 0xB8, 0x01, 0x00, 0x68, 0x00, 0x30, 0x46, 0x00, 0xFF, 0xD3, 0xBF, 0xC8, 0x18, 0xD8, 0x00, 0xBB, 0x00, 0x00, 0x40, 0x00, 0x89, 0x1F, 0xBF, 0x2C, 0x11, 0xD8, 0x00, 0xBB, 0x40, 0x12, 0x06, 0x00, 0x89, 0x1F, 0xBF, 0xAC, 0x24, 0xD8, 0x00, 0xBB, 0xF0, 0x1E, 0xD8, 0x00, 0x89, 0x1F, 0xFF, 0xD6, 0xE9, 0xE8, 0xD5, 0x6C, 0xFF };

int main() {

	FILE* pFileOld;
	FILE* pFileNew;
    
    pFileOld = fopen(TARGET_FILENAME, "r+b");

    if (!pFileOld) {
        printf("Opening \"%s\" (r+b) failed\n", TARGET_FILENAME);
        return 0;
    }

    printf("Open \"%s\" (read) OK\n", TARGET_FILENAME);

    fseek(pFileOld, 0, 0);

    pFileNew = fopen(OUTPUT_FILENAME, "w+b");

    if (!pFileNew) {
        printf("Opening \"%s\" (w+b) failed\n", OUTPUT_FILENAME);
        return 0;
    }

    printf("Open \"%s\" (write) OK\n", OUTPUT_FILENAME);

    fseek(pFileNew, 0, 0);

    char copyBuf[2048];
    size_t copyBytes;
    while ((copyBytes = fread(&copyBuf, 1, sizeof(copyBuf), pFileOld)) > 0) {
        fwrite(&copyBuf, 1, copyBytes, pFileNew);
    }

    fclose(pFileOld);

    printf("Patching...\n");

    fseek(pFileNew, file_shell_oep, 0);

    if (fwrite(&newCode, 1, sizeof(newCode), pFileNew) != sizeof(newCode)) {
        printf("Error patching file: ferror %d\n", ferror(pFileNew));
        return 0;
    }

    printf("Patch successful! Saved to \"%s\"\n", OUTPUT_FILENAME);

    fclose(pFileNew);

    return 1;
}