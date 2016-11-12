#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 128
#define TOT 128

void compare(char* vi){
        FILE *f = fopen("data.txt", "rb");
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);

        char *string = malloc(fsize + 1);
        fread(string, fsize, 1, f);
        //printf("\n %s", string);
        char *ret;
        ret = strstr(string, vi);
        fclose(f);

        string[fsize] = 0;
        if(ret!=NULL){
                printf("\n Virus detected- %s\n", vi);
                exit(EXIT_SUCCESS);
        }

}

int main(void) {
    char line[TOT][BUF];
    FILE *plist = NULL;
    int i = 0;
    int total = 0;
	
	plist = fopen("virus.txt", "r");
    while(fgets(line[i], BUF, plist)) {
        /* get rid of ending \n from fgets */
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    total = i;

    for(i = 0; i < total; ++i){
        //printf("%s\n", line[i]);
        compare(line[i]);
    }
    return 0;
}