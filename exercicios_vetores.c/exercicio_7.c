#include <stdio.h>


int main() {


float notas[5];
char  nome_aluno[5][50];
int aprovados, reprovados;

for (int i=0;  i<5; i++) {


    printf("preencha o nome do aluno:");
    scanf("%s", nome_aluno[i]);
}
for (int i=0;  i<5; i++){
    printf("preencha o nota do aluno:");
    printf("%s: \n", &nome_aluno[i] );
    scanf("%f", &notas[i]);

}
 
for (int i = 0; i < 5; i++) {
    printf("Aluno: %s | Nota: %.1f -> ", nome_aluno[i], notas[i]);

    if (notas[i] >= 6.0) {
        printf("APROVADO\n");
        aprovados++; }
  
        else {
        printf("REPROVADO\n");
        reprovados++;
    }
}





}