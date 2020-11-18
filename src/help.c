#include <stdio.h>

void help(){
    printf("\nexit       exits the shell");
    printf("\nhelp       shows this screen");
    printf("\ncd         changes the current directory");
    printf("\nmkfile     makes a new file if it doesn't exist");
    printf("\nls         list all the files directories and their properties");
    printf("\ninfo       info about the shell\n\n");
}

void info(){
    printf("\t\tThe Kosmos Shell\n");
    printf("Started on 18-11-2020. Made by Potato-git13/Potato man.\n");
    printf("This is a Linux shell was made in C.\n");
}
