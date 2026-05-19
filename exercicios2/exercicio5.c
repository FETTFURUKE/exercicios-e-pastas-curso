#include <stdio.h>

float areaRetangulo(float base, float altura) {
    return base * altura;
}

int main() {
    float b, h;
    printf("Base: ");
    scanf("%f", &b);
    printf("Altura: ");
    scanf("%f", &h);
    printf("Área: %.2f\n", areaRetangulo(b, h));
    return 0;
}