#include <stdio.h>
#include <windows.h>
#include <math.h>

int vet[5];
int i;

int main() {
 
    SetConsoleOutputCP(CP_UTF8);


    for (i=0; i<6; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &vet[i]);
    }

    printf("os numeros digitados sao:  %d\n");
    for (i=0; i<6; i++) {
        printf("%d\n", vet[i]);
    }
       

        
    printf("os numeros inversos sao:  %d\n" );
    for (i=5; i<-1; i--) {
        printf("%d\n", vet[i]);
    
        
        
    }
    
}