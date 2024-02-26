#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1024


int main(int argc, char *argv[]) {
  char *searchTerm = argv[1];
    
  if (argc == 2) {
        char buffer[MAX_LINE_SIZE];
        while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (strstr(buffer, searchTerm) != NULL) {
                printf("%s", buffer);
            }
        }
    } 
  if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    if (argc == 2) {
        char buffer[MAX_LINE_SIZE];
        while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (strstr(buffer, searchTerm) != NULL) {
                printf("%s", buffer);
            }
        }
    } 
    else {
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                return 1; 
            }
            char buffer[MAX_LINE_SIZE];
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                if (strstr(buffer, searchTerm) != NULL) {
                    printf("%s", buffer);
                }
            }
            fclose(fp);
        }
    }
    return 0;
}
