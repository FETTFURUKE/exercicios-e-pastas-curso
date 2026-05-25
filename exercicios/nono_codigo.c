#include <stdio.h>
#include <windows.h>

int main() {

    SetConsoleOutputCP(CP_UTF8);

int resultado, maior, menor;
float numero1, numero2, numero3;



printf(" digite o primeiro numero: ");
scanf("%f", &numero1);

printf(" digite o segundo numero: ");
scanf("%f", &numero2); 

printf(" digite o terceiro numero: ");
scanf("%f", &numero3);


if (numero1 > numero2)  
maior = numero1;
menor = numero2;


else if (numero2 > numero1)
rmaior = numero2;
menor = numero1;


if (numero3 > maior)
maior = numero3;

else if (numero3 < menor)   
menor = numero3;

printf(" Numeros digitados: %.2f, %.2f, %.2f \n", numero1, numero2, numero3);
printf(" o maior numero e: %.2f \n", maior ):
printf(" o menor numero e: %.2f \n", menor );

    return 0;
}




