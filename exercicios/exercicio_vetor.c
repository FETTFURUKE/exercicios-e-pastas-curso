#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>


int main() {
    
SetConsoleOutputCP(CP_UTF8);


float vet[5] = {0};
int i;
float total = 0;
float media = 0;

sleep(5);

printf(" \n                                                                      \n");
printf(" \n                                                                      \n");
printf(" \n                                                                      \n");
printf(" \n                                                                      \n");
printf(" \n                                                                      \n");
printf(" \n                        INICIALIZANDO SISTEMA                         \n");
printf(" \n                                                                      \n");
printf(" \n                                                                      \n");
printf(" \n                                                                      \n");
printf(" \n                                                                      \n");

sleep(5000);




for (i = 0; i < 5; i++) {
    printf("digite a nota %d:", i + 1);
    scanf("%f", &vet[i]);
   
}

  printf("\n ----- RESULTADO ------ \n");

  for (i = 0; i < 5; i++) {
  
    printf(" ---- nota %d: %.1f ---- \n", i + 1, vet[i]);
    
}

total = (vet[0] + vet[1] + vet[2] + vet[3] + vet[4]);
    
printf(" ---- total: %.2f ---- \n", total);

media = total / 5;
printf(" ---- Media Final: %.2f ---- \n", media);

return 0;


































}
















