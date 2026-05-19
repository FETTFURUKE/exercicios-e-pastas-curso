#include <stdio.h>

char* nomeDoDia(int dia) {
    switch(dia) {
        case 1: return "Segunda";
        case 2: return "Terça";
        case 3: return "Quarta";
        case 4: return "Quinta";
        case 5: return "Sexta";
        case 6: return "Sábado";
        case 7: return "Domingo";
        default: return "Inválido";
    }
}

int main() {
    for (int i = 1; i <= 7; i++) {
        printf("Dia %d: %s\n", i, nomeDoDia(i));
    }
    return 0;
}