#include <stdio.h>
#include <windows.h>
int x, y;
int a, b;
 int  somar(int a, int b) {
    return a + b;   
 }



int main(){


    printf("Digite um numero inteiro:\n ");
    scanf("%d, %d", &x, &y);


    printf(" ----- %d ----- \n", somar(x, y)); 






return 0;




}