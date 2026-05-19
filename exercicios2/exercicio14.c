#include <stdio.h>

int somaAteN(int n) {
    int acumulador = 0;
    int i = 1;
    while (i <= n) {
        acumulador += i;
        i++;
    }
    return acumulador;
}

int ePar(int n) {
    return (n % 2 == 0);
}

int main() {
    int n;
    printf("N: ");
    scanf("%d", &n);
    
    int soma = somaAteN(n);
    printf("A soma de 1 a %d é %d e é %s\n", n, soma, ePar(soma) ? "par" : "ímpar");
    return 0;
}