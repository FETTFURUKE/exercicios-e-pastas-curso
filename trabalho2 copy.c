#include <stdio.h>
#include <string.h>


typedef struct {
    int id;
    char titulo[100];
    char descricao[200];
    int prioridade;
    int status;

}tarefa;


int main(){

int opcao;

printarMenu();
 printf(" Escolha a opcao desejada: \n");
 scanf("%d" &opcao);


switch(opcao) {

case 1:
print(" ");
break;

case 2:
printf(" ");
break;

case 3:
printf("");
break;

case 4:
printf("");
break;





}


}



void printarMenu(){

printf("  SISTEMA DE PEDIDOS  \n");
printf("1 - Gerenciamento de ordens  \n");
printf("2 - Listar pedidos  \n");
printf("3 - Buscar pedido  \n");
printf("4 - Status dos pedidos  \n");
printf("5 - Maior prioridade  \n");
printf("6 - Remover pedido  \n");
printf("7 - Desligar  \n");

}


void cadastroOrden(){

printf("")



}














