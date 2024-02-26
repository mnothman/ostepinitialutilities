#include <stdlib.h>
#include <stdio.h>

void writeCharacterRun(int runLength, char character) {
    fwrite(&runLength, sizeof(int), 1, stdout);
    fwrite(&character, sizeof(char), 1, stdout);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int runLength = 0; 
    char currentChar, lastChar = '\0'; 
    FILE *inputFile;

    for (int i = 1; i < argc; i++) {
        inputFile = fopen(argv[i], "r");
        if (inputFile == NULL) {
            printf("wzip: cannot open file\n");
            return 1;
        }

        while (fread(&currentChar, sizeof(char), 1, inputFile) == 1) {
            if (currentChar == lastChar || runLength == 0) {
                runLength++;
            } else {
                writeCharacterRun(runLength, lastChar);
                runLength = 1;
            }
            lastChar = currentChar;
        }
        fclose(inputFile);
    }
    if (runLength > 0) {
        writeCharacterRun(runLength, lastChar);
    }
    return 0;
}
