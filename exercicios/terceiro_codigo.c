#include <stdio.h>
#include <math.h>

int main() {

    
float salario_atual, novo_salario, fator_aumento;
int anos_empresa, periodos;

printf("                 ZEN.SA - FOLHA DE PAGAMENTO \n " );
printf(" digite o salario atual do coloborador: ");
scanf("%f", &salario_atual);

printf(" digite o tempo em que o colaborador trabalha na empresa: ");
 scanf("%d", &anos_empresa);


 periodos = anos_empresa / 5;
fator_aumento = pow(1.10, periodos);
novo_salario = salario_atual * fator_aumento;

printf("\n  FOLHA DE PAGAMENTO  ZEN \n " );
printf("\n quantidade de aumento aplicados : %d\n", periodos);
printf("\n novo salario: %.2f\n", novo_salario );

return 0;

  
  
}
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
