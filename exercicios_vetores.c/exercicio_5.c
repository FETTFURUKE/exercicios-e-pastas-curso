#include <stdio.h>
#include <windows.h>




int main() {
   
    int numeros[5];
    SetConsoleOutputCP(CP_UTF8);

for (int i = 0; i < 6; i++)
{
    printf("digite um numero:");
    scanf("%d", &numeros[i]);
}
    printf("numeros digitados são: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  \n", numeros[i]);
    }
printf("\n numeros inversos são: \n");
for(int i=4; i>-1; i--){
    printf("%d  \n", numeros[i]);


}
}






