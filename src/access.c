#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool login(){
  char password[] = "Password\n";
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
