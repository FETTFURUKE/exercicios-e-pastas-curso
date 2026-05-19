#include <stdio.h>

int main()
{

    char nome[50];
    int idade;
    float altura;


printf("digite seu nome");
scanf("%s", nome);

printf("digite sua idade:");
scanf("%d", &idade);

printf("digite sua altura:");
scanf("%f", altura);

printf("\n ---dados ---- \n");
printf("nome: %s\n", nome) ;
printf("idade: %d\n", &idade);
printf("altura: %f\n", &altura);

if(idade >= 18)
{
    printf("maior de idade\n");
}
else
{
    printf("menor de idade\n");
}

    return 0;


}


