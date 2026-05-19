#include <stdio.h>
#include <windows.h>

int n;


int dobrar(int n ) {
return n * 2;
}

int main(){

printf("\n Digite o numero que deseja dobrar: \n");
scanf("%d", &n);

printf(" ----  %d  ----", dobrar(n));







return 0;




}