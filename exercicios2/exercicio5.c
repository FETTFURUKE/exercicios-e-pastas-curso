#include <stdio.h>
#include <windows.h>



float area, base, altura;
float areaR(float base, float altura) {
return base * altura;
}

int main(){

printf("Digite base: \n");
scanf("%f", &base);

printf("Digite altura: \n");
scanf("%f", &altura);



printf(" ----  %.2f  ----", areaR( base, altura));






}
