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
    int i;
    char pesquisaP;
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
            printf("\n===== LISTA DE PRODUTOS =====\n");
            i = 0;
            while (i < total) 
            {
                // %s exibe o texto do nome e o i++ no final faz o loop andar certo
                printf("Nome: %s | Preco: R$ %.2f | Estoque: %d \n", nomes[i], precos[i], estoques[i]);
                i++; 
            }
            break;

        case 3:
           
    char busca[50]; // Variável para o nome que queremos achar
    
    getchar(); // Limpa o buffer do teclado
    printf("Digite o nome do produto para buscar: ");
    fgets(busca, 50, stdin);
    busca[strcspn(busca, "\n")] = '\0'; // Remove o "Enter" do final
    for (i = 0; i < total; i++) {
        // Se strcmp retornar 0, significa que os nomes são iguais!
        if (strcmp(nomes[i], busca) == 0) {
            printf("\nProduto Encontrado!\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[i], precos[i], estoques[i]);
            
            // Se já achou o produto, não precisa continuar procurando os outros
            break; 
        }
    }
    
    // O break do switch case
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