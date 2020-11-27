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
#include <errno.h>
#include <linux/limits.h>

extern void help();
extern bool login();
extern void info();

void sendError(char error_message[]);
char *realpath(const char *path, char *resolved_path);
void append(char filename[]);


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
    char final[999];
    char *p = final;

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
        checker = strstr(operation, "mkfile ");
        if (checker == operation){

            // MAKE A NEW FILE

            FILE *fp;
            char filename[80];

            // Copy the operation to final but remove the first seven chars
            memcpy(final, operation+7, sizeof(operation)-1);
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            // Asign the filename final
            memcpy(filename, final, sizeof(final));

            if( access( filename, F_OK ) != -1 ) {
                // File exists
                sendError("Error: File exists error\n");
            } else {
                // File doesn't exist
                fp = fopen(filename, "w+");
                fclose(fp);
            }
        }

        checker = strstr(operation, "cd ");
        if (checker == operation){

            // CHANGE THE CURRENT DIRECTORY

            // Copy the operation to final but remove the first three chars
            memcpy(final, operation+3, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;
            // Check if dir exists
            DIR* dir = opendir(final);
            if (dir) {
                // Directory exists
                closedir(dir);
                chdir(final);
            }
            else if (ENOENT == errno) {
                // Directory does not exist
                sendError("Error: Directory does not exist\n");
            }
        }
        checker = strstr(operation, "ls");
        if (checker == operation){

            // LIST THE CURRENT DIRECTORY

            // Copy the operation to final but remove the first three chars
            memcpy(final, operation+3, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            // Process id
            int pid;
            // Create another process
            pid = fork();
            // Child
            if ( pid == 0 ) {
                // Execute cdfi
                execlp("cdfi", "cdfi", NULL);
            }
            // Parent
            else {
                wait(NULL);
            }
        }

        if (strcmp(operation, "info\n") == 0){
            info();
        }

        checker = strstr(operation, "rm ");
        if (checker == operation){

            // REMOVE A FILE

            int returned;

            // Copy the operation to final but remove the first three chars
            memcpy(final, operation+3, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            // Remove the file
            returned = remove(final);

            if(returned == 0) {
                // File deleted successfuly
            } else {
                sendError("Error: unable to delete the file / dir\n");
            }
        }

        checker = strstr(operation, "rmdirr ");
        if (checker == operation) {

            // REMOVE A DIR WITH FILES


            // Copy the operation to final but remove the first seven chars
            memcpy(final, operation+7, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            // Process id
            int pid;
            // Create another process
            pid = fork();
            // Child
            if ( pid == 0 ) {
                // Execute rmdirr
                execlp("rmdirr", "rmdirr", final, NULL);
            }
            // Parent
            else {
                wait(NULL);
            }
        }
        if (strcmp(operation, "cngpass\n") == 0){

            // CHANGE THE PASSWORD

            char oldPass[80], oldPassGuess[80], newPass[80], newPassConf[80], c;
            FILE *fp;
            int i, returned;
            char resolved_path[PATH_MAX];
            realpath("src/pass", resolved_path);
            // Open file for reading and get the password
            fp = fopen(resolved_path, "r");
            while ((c = getc(fp)) != EOF && i != 80) oldPass[i++] = c;

            fclose(fp);
            // Get the current password from the user
            printf("Old password: ");
            fgets(oldPassGuess, 80, stdin);
            if (strcmp(oldPassGuess, oldPass) != 0){
                sendError("Old password incorrect\n");
                break;
            } else if (strcmp(oldPassGuess, oldPass) == 0){
                // If successful ask for a new password and the confiramtion
                printf("New password: ");
                fgets(newPass, 80, stdin);
                printf("New password confirm: ");
                fgets(newPassConf, 80, stdin);
                if (strcmp(newPass, newPassConf) != 0){
                    // Fail
                    sendError("The new password and the password confirmation are not the same\n");
                    break;
                } else if (strcmp(newPass, newPassConf) == 0){
                    // Open the same file for writing truntuating
                    fp = fopen(resolved_path, "w+");
                    // Write the new password to a file
                    returned = fputs(newPass, fp);
                    fclose(fp);
                    if (returned == 1){
                        printf("Password set\n");
                    } else {
                        // Fail
                        sendError("Password seting failed\n");
                    }

                }
            }
        }

        checker = strstr(operation, "read ");
        if (checker == operation){

            // READ A FILE

            // Copy the operation to final but remove the first five chars
            memcpy(final, operation+5, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            char ch;
            FILE *fp;
            // Read mode
            fp= fopen(final, "r");

            if (fp == NULL)
            {
                // Fail / Error
                sendError("Error: Could not open the file\n");
            } else {
                printf("%s:\n", final);

                while((ch = fgetc(fp)) != EOF)
                    // Print out all of the characters in a file
                    printf("%c", ch);

                fclose(fp);
                printf("\n");
            }
        }

        checker = strstr(operation, "echo ");
        if (checker == operation){

            // Copy the operation to final but remove the first five chars
            memcpy(final, operation+5, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            printf("%s\n", final);
        }

        checker = strstr(operation, "app");
        if (checker == operation){

            // APPEND TEXT TO A FILE

            // Copy the operation to final but remove the four chars
            memcpy(final, operation+4, sizeof(operation));
            // Remove the last character aka the newline character
            p = final;
            p[strlen(p)-1] = 0;

            append(final);
        }
    }
    return 0;
}


// sendError to reduce the amount of code
void sendError(char error_message[]){
    // Send the wanted error message in red and then reset the color
    colorRed();
    printf("%s", error_message);
    colorReset();
}

// Append to a file
void append(char filename[]){
    char text[200];
    int returned;
    FILE *fp;

    fp = fopen(filename, "a");
    // Get text input
    printf("> ");
    fgets(text, 200, stdin);

    returned = fputs(text, fp);
    if (returned == 1){
        // Success
    }
    else {
        // Fail / Error
        sendError("Error: Failed to write the text to the file");
    }
    fclose(fp);
}
