#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <linux/limits.h>

bool login(){
    char *realpath(const char *path, char *resolved_path);

    FILE *fp;
    char password[80], c;
    int i = 0;
    char resolved_path[PATH_MAX];

    realpath("src/pass", resolved_path);

    fp = fopen(resolved_path, "r");
    while ((c = getc(fp)) != EOF && i != 80) password[i++] = c;

    fclose(fp);
    char passGuess[50];
    bool accessAllowed;

    printf("Your password: ");
    fgets(passGuess, 50, stdin);

    if (strcmp(password, passGuess) == 0){
        accessAllowed = true;
        return accessAllowed;
    }
    else{
        accessAllowed = false;
        return accessAllowed;
    }
}
