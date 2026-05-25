#include <stdio.h>
#include <windows.h>



int main() {


    float notas[5];
    char nome_aluno[5][50];
    int aprovados, reprovados;


printf("\033[1;31m INICIALIZANDO BIOS v2.0.26\033[0m\n");

    printf("Carregando Servidor: ");
for (int i = 0; i < 20; i++) {
    printf("%c", 176); // Caractere de bloco cheio (pode variar conforme o terminal)
    Sleep(150);
}
system("cls"); // Limpa tudo para começar o programa limpo

    char msg[] = "INICIALIZANDO SISTEMA DE NOTAS...";
for (int i = 0; msg[i] != '\0'; i++) {
    printf("%c", msg[i]);
    fflush(stdout); // Garante que a letra saia na hora
    Sleep(100);     // Espera 100 milissegundos entre cada letra
}
printf("\n");

for (int i = 0; i < 5; i++) {
    printf(" preencha o nome do aluno: ");
    scanf("%s", nome_aluno[i]);

}

for (int i = 0; i < 5; i++) {
    printf(" digite a nota do aluno ");
    printf("%s: ", nome_aluno[i]);
    scanf("%f", &notas[i]);
}

for (int i = 0; i<5; i++) {
    printf("aluno: %s \n nota: %.2f -> ", nome_aluno[i], notas[i]);

    if ( notas[i] >= 6.0) {
        printf("\n aprovado\n");
        aprovados++;
    } else {
        printf("\n reprovado\n");
        reprovados++;
    }
}
   













































}