#include <stdio.h>
#include <windows.h>


int main(){

int notas[] = {7, -1, 5, -1, 9, 6};
int soma = 0, count = 0;
 
for (int i = 0; i < 6; i++) {
    if (notas[i] < 0) {
        continue; 
    }
    soma += notas[i];
    count++;
}
break;
}
 
printf("Média: %.1f\n", (float)soma / count);
