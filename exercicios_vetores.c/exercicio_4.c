#include <stdio.h>
#include <math.h>

float numero;
int positivo, negativo, zero;

int main() {
    positivo = 0;
    negativo = 0;
    zero = 0;

    for (int i = 0; i < 10; i++) {
        printf("digite um numero:");
        scanf("%f", &numero);
    
    if (numero > 0) {
        positivo++;
    } else if (numero < 0) {
        negativo++;
    } else {
        zero++;
    }
    }
    printf("numeros positivos: %d\n", positivo);
   printf("numeros negativos: %d\n", negativo);
   printf("numeros zeros: %d\n", zero);



}


