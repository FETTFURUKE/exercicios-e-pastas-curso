#include <stdio.h>

void lerNotas(float notas[], int tamanho) {
    printf("Digite as notas dos %d alunos:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

float calcularMedia(float notas[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    return soma / tamanho;
}

int contarAprovados(float notas[], int tamanho) {
    int aprovados = 0;
    for (int i = 0; i < tamanho; i++) {
        if (notas[i] >= 6.0) aprovados++;
    }
    return aprovados;
}

void imprimirRelatorio(float notas[], int tamanho) {
    printf("\n--- RELATÓRIO DA TURMA ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Aluno %d: %.1f [%s]\n", i + 1, notas[i], (notas[i] >= 6.0) ? "AP" : "RE");
    }
    printf("Média: %.2f\n", calcularMedia(notas, tamanho));
    printf("Aprovados: %d de %d\n", contarAprovados(notas, tamanho), tamanho);
}

int main() {
    float notas[5];
    lerNotas(notas, 5);
    imprimirRelatorio(notas, 5);
    return 0;
}