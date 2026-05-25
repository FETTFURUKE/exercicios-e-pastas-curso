#include <stdio.h>

float areaRetangulo(float base, float altura) {
    return base * altura;
}

float areaTriangulo(float base, float altura) {
    return (base * altura) / 2.0;
}

int main() {
    float b, h;
    printf("Digite a base e a altura: ");
    scanf("%f %f", &b, &h);
    
    float areaR = areaRetangulo(b, h);
    float areaT = areaTriangulo(b, h);
    
    printf("Retângulo: %.2f Triângulo: %.2f -> ", areaR, areaT);
    
    if (areaR > areaT) {
        printf("Retângulo é maior\n");
    } else if (areaT > areaR) {
        printf("Triângulo é maior\n");
    } else {
        printf("As áreas são iguais\n");
    }
    return 0;
}
