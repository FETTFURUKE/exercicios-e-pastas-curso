#include <stdio.h>

int quadrado(int n) {
    return n * n;
}

int cubo(int n) {
    return quadrado(n) * n;
}

int main() {
    int numero;
    printf("Número: ");
    scanf("%d", &numero);
    printf("%d² = %d\n", numero, quadrado(numero));
    printf("%d³ = %d\n", numero, cubo(numero));
    return 0;
}
