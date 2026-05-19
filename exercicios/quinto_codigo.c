#include <stdio.h>

int main() {

    int numero;

    printf(" Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {

        printf(" o numero %d e par", numero);
    } else {
        printf(" o numero %d e impar", numero);

    }
    if (numero > 0) {
        printf(" o numero %d e positivo", numero);
    } else if (numero < 0) {
        printf(" o numero %d e negativo", numero);

    }
    else {
        printf(" o numero e zero(neutro)");

    }
    return 0;
    }


