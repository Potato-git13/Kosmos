#include <stdio.h>

void help(){
    printf("\n\033[0;34mexit       exits the shell");
    printf("\nhelp       shows this screen");
    printf("\ncd         changes the current directory");
    printf("\ntouch     makes a new file if it doesn't exist");
    printf("\nls         list all the files directories and their properties");
    printf("\ninfo       info about the shell");
    printf("\nrm         remove a file or an empty directory");
    printf("\ncngpass    change the password");
    printf("\nread       reads the specified file");
    printf("\necho       echoes your message");
    printf("\napp        appends text to a file. If it doesn't exist it will make it.");
    printf("\n\n\033[0m");
}

void info(){
    printf("\t\tThe Kosmos Shell\n");
    printf("Started on 18-11-2020. Made by Potato-git13/Potato man.\n");
    printf("This is a Linux shell was made in C.\n");
}
