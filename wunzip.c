#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    
    int runLength;
    char character;
    FILE *filePtr;

    for (int i = 1; i < argc; i++) {
        filePtr = fopen(argv[i], "r");
        if (filePtr == NULL) { 
            printf("wunzip: cannot open file\n");
            return 1;
        }
        while (fread(&runLength, sizeof(int), 1, filePtr) == 1 && fread(&character, sizeof(char), 1, filePtr) == 1) {
            for (int j = 0; j < runLength; j++) {
                printf("%c", character);
            }
        }
        fclose(filePtr);
    }
    return 0;
}
