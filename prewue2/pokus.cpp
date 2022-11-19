#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <iostream>
#include <windows.h>

int main() {
   char buffer[PATH_MAX];
   if (getcwd(buffer, sizeof(buffer)) != NULL) {
       printf("Current working directory : %s\n", buffer);
       std::cin.ignore();
   } else {
       perror("getcwd() error");
       return 1;
   }
   return 0;
}