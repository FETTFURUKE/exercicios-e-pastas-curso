#include    <stdio.h>
#include   <windows.h>
int main() {

     SetConsoleOutputCP(CP_UTF8);

    int quantidade;
    float preço, valor_total;

    printf(" digite o preço do produto: ");
    scanf("%f", &preço);

    printf(" digite a quantidade do produto: ");
    scanf("%d", &quantidade);

   
    if 
    (preço > 100)
    valor_total = (preço * quantidade) / 1.05;       
    

    else {
    (preço <= 100);
    valor_total = preço * quantidade;   
    }

    printf("O valor total a ser pago e: %.2f\n", valor_total);
    

    return 0;


}