#include <stdio.h>

float lerNota() {
    float nota;
    printf("Nota: ");
    scanf("%f", &nota);
    return nota;
}

int estaAprovado(float nota) {
    return (nota >= 6.0);
}

void imprimirResultado(float nota, int ap) {
    printf("Status: %s\n", ap ? "APROVADO" : "REPROVADO");
}

int main() {
    float n = lerNota();
    imprimirResultado(n, estaAprovado(n));
    return 0;
}