#include <stdio.h>

int somarVetor(int v[], int n) {
    int acumulador = 0;
    for (int i = 0; i < n; i++) {
        acumulador += v[i];
    }
    return acumulador;
}

int main() {
    int v[5];
    printf("Digite 5 valores: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &v[i]);
    }
    printf("Soma: %d\n", somarVetor(v, 5));
    return 0;
}