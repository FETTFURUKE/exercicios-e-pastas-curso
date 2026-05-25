#include <stdio.h>
#include <windows.h>



void saudações (char nome[]); {
 
    printf("Olá, %s!\n", nome);
 
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    
    
saudações("Ana");
saudações("vitor");
saudações("bia");



return 0;


}