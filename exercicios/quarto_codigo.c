#include <stdio.h>


int main () {

    int nota1, nota2, nota3, media;

    printf(" Digite a primeira nota: ");
    scanf("%d", &nota1);

    printf(" digite a segunda nota: ");
    scanf("%d", &nota2);

    printf(" digite a terceira nota: ");
    scanf("%d", &nota3);

   media = (nota1 + nota2 + nota3)  / 3;

   printf(" a media do aluno e: %d", media);

   return 0;

}