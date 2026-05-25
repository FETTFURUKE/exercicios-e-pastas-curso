#include <stdio.h>
#include <string.h>

#define MAX 10

// ==========================
// FUNÇÃO PARA VALIDAR PREÇO
// ==========================
float lerPreco()
{
    float preco;

    do
    {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &preco);

        if (preco < 0)
        {
            printf("Preco invalido!\n");
        }

    } while (preco < 0);

    return preco;
}

// =============================
// FUNÇÃO PARA VALIDAR ESTOQUE
// =============================
int lerEstoque()
{
    int estoque;

    do
    {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &estoque);

        if (estoque < 0)
        {
            printf("Quantidade invalida!\n");
        }

    } while (estoque < 0);

    return estoque;
}

// ==========================
// FUNÇÃO PARA CADASTRAR
// ==========================
int cadastrarProduto(char nomes[][50],
                     float precos[],
                     int estoques[],
                     int total)
{
    int i = total;

    // Verifica limite máximo
    if (total >= MAX)
    {
        printf("\nLimite maximo de produtos atingido!\n");
        return total;
    }

    getchar();

    printf("\n===== CADASTRO DE PRODUTO =====\n");

    // Cadastro do nome
    do
    {
        printf("Nome do produto: ");
        fgets(nomes[i], 50, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        if (strlen(nomes[i]) == 0)
        {
            printf("Nome nao pode ser vazio!\n");
        }

    } while (strlen(nomes[i]) == 0);

    // Cadastro do preço
    precos[i] = lerPreco();

    // Cadastro do estoque
    estoques[i] = lerEstoque();

    // Incrementa quantidade de produtos
    total++;

    printf("\nProduto cadastrado com sucesso!\n");

    return total;
}

// ==========================
// MENU
// ==========================
void menu()
{
    printf("\n=============================\n");
    printf(" SISTEMA DE PRODUTOS\n");
    printf("=============================\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Produto mais caro\n");
    printf("5 - Valor total em estoque\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

// ==========================
// FUNÇÃO PRINCIPAL
// ==========================
int main()
{
    char nomes[MAX][50];
    float precos[MAX];
    int estoques[MAX];

    int total = 0;
    int opcao;

    do
    {
        menu();

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            total = cadastrarProduto(
                nomes,
                precos,
                estoques,
                total);
            break;

        case 2:
            printf
            break;

        case 3:
            // IMPLEMENTAR
            break;

        case 4:
            // IMPLEMENTAR
            break;

        case 5:
            // IMPLEMENTAR
            break;

        case 0:
            printf("\nPrograma encerrado.\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}