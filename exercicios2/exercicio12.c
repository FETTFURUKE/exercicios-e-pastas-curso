#include <stdio.h>

int maiorVetor(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) maior = v[i];
    }
    return maior;
}

int menorVetor(int v[], int n) {
    int menor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor) menor = v[i];
    }
    return menor;
}

int main() {
    int valores[6];
    printf("Digite 6 valores: ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &valores[i]);
    }
    printf("Maior: %d\n", maiorVetor(valores, 6));
    printf("Menor: %d\n", menorVetor(valores, 6));
    return 0;
}