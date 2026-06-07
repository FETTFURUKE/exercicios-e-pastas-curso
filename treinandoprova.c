#include <stdio.h>


float temperatura;
int hora, opcao;


float Lertemperatura() {
printf("Digite a temperatura:  \n");
scanf("%f", &temperatura);

}

int Lerhora() {
printf("digite a hora do registro: 00:00  \n");
scanf("%d", &hora);


}

int main(){

float temperatura;
int hora, opcao;

switch( opcao){

case 1:

temperatura = Lertemperatura;
break;



case 2:

hora = Lerhora;
break;



}

























}
