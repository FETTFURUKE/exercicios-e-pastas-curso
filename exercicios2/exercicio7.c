#include <stdio.h>

float celsiusParaFahrenheit(float c) {
    return c * 9.0 / 5.0 + 32.0;
}

float fahrenheitParaKelvin(float f) {
    return f + 273.15;
}

float celsiusParaKelvin(float c) {
    return fahrenheitParaKelvin(celsiusParaFahrenheit(c));
}

int main() {
    float celsius;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    printf("%.2f°C -> %.1f°F -> %.2fK\n", celsius, celsiusParaFahrenheit(celsius), celsiusParaKelvin(celsius));
    return 0;
}