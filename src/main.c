/* Kosmos
Linux C shell by Potato Man
started on 18-11-2020
Author : Potato-git13
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Colors.h"
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

extern void help();
extern bool login();
extern void info();

int main(){
    bool accessAllowed = login();

    if (accessAllowed){
        printf("Access allowed!\n");
    }
    else{
        printf("Access denied!\n");
        exit(0);
    }
    char operation[50];
    char s[FILENAME_MAX];

    while(1){
        // Get the command
        colorGreenBold();
        printf("%s\n", getcwd(s, FILENAME_MAX));
        colorReset();
        printf("$ ");
        fgets(operation, 50, stdin);

        if (strcmp(operation, "exit\n") == 0){
            exit(0);
        }

        else if (strcmp(operation, "help\n") == 0){
            help();
        }

        char *checker = NULL;
        checker = strstr(operation, "mkfile");
        if (checker == operation){

          // MAKE A NEW FILE

          char final[999];
          int returned;
          FILE *fp;
          char filename[80];

          // copy the operation to final but remove the first tseven chars
          memcpy(final, operation+7, sizeof(operation)-1);
          // remove the last character aka the newline character
          char *p = final;
          p[strlen(p)-1] = 0;

          // asign the filename final
          memcpy(filename, final, sizeof(final));

          if( access( filename, F_OK ) != -1 ) {
            // file exists
              colorRed();
              printf("Error: File exists error\n");
              colorReset();
          } else {
              // file doesn't exist
              fp = fopen(filename, "w+");
          }
        }

        checker = strstr(operation, "cd");
        if (checker == operation){

            // CHANGE THE CURRENT DIRECTORY

            char final[999];
            int returned;

            // copy the operation to final but remove the first three chars
            memcpy(final, operation+3, sizeof(operation));
            // remove the last character aka the newline character
            char *p = final;
            p[strlen(p)-1] = 0;
            // Check if dir exists
            DIR* dir = opendir(final);
            if (dir) {
                // Directory exists
                closedir(dir);
                returned = chdir(final);
            }
            else if (ENOENT == errno) {
                // Directory does not exist
                colorRed();
                printf("Error: Directory does not exist\n");
                colorReset();
            }
        }
        checker = strstr(operation, "ls");
        if (checker == operation){

            // LIST THE CURRENT DIRECTORY

            char final[999];

            // copy the operation to final but remove the first three chars
            memcpy(final, operation+3, sizeof(operation));
            // remove the last character aka the newline character
            char *p = final;
            p[strlen(p)-1] = 0;

            //process id
            int pid;
            //create another process
            pid = fork();
            //child
            if ( pid == 0 ) {
                //execute cdfi
                execlp("cdfi", "cdfi", NULL);
            }
            //parent
            else {
                wait(NULL);
            }
        }
        if (strcmp(operation, "info\n") == 0){
            info();
        }
    }
    return 0;
}
