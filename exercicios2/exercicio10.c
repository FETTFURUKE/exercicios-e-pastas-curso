#include <stdio.h>

float somar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) { return a / b; }

int main() {
    float n1, n2;
    char operador;
    
    printf("Digite a operação (Ex: 5.0 * 3.0): ");
    scanf("%f %c %f", &n1, &operador, &n2);
    
    switch(operador) {
        case '+':
            printf("%.1f + %.1f = %.2f\n", n1, n2, somar(n1, n2));
            break;
        case '-':
            printf("%.1f - %.1f = %.2f\n", n1, n2, subtrair(n1, n2));
            break;
        case '*':
            printf("%.1f * %.1f = %.2f\n", n1, n2, multiplicar(n1, n2));
            break;
        case '/':
            if (n2 == 0) {
                printf("Erro: Divisão por zero!\n");
            } else {
                printf("%.1f / %.1f = %.2f\n", n1, n2, dividir(n1, n2));
            }
            break;
        default:
            printf("Operador inválido!\n");
    }
    return 0;
}
