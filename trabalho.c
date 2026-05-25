#include <stdio.h>
#include <string.h>

#define MAX 10 // O teto máximo de produtos que cabem no nosso sistema

// ========================================================
// VALIDAÇÃO DE PREÇO: Para o usuário não digitar preço negativo
// ========================================================
float lerPreco()
{
    float preco;

    do
    {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &preco);

        if (preco < 0)
        {
            printf("Preco invalido! Nao existe preco menor que zero.\n");
        }

    } while (preco < 0); // Fica preso aqui até digitar um preço que faça sentido

    return preco;
}

// ========================================================
// VALIDAÇÃO DE ESTOQUE: Mesma lógica, estoque negativo não existe
// ========================================================
int lerEstoque()
{
    int estoque;

    do
    {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &estoque);

        if (estoque < 0)
        {
            printf("Quantidade invalida! O estoque nao pode ser negativo.\n");
        }

    } while (estoque < 0); // Só sai do looping quando digitarem zero ou mais

    return estoque;
}

// ========================================================
// O CADASTRO: Onde a gente joga os dados para dentro das gavetas
// ========================================================
int cadastrarProduto(char nomes[][50],
                     float precos[],
                     int estoques[],
                     int total)
{
    int i = total; // O 'i' vira a linha atual onde o produto vai ser salvo

    // Se o total chegou no MAX (10), o armário tá cheio e a gente para aqui
    if (total >= MAX)
    {
        printf("\nLimite maximo de produtos atingido! Nao cabe mais nada.\n");
        return total;
    }

    getchar(); // Limpa o 'Enter' perdido que fica mofando no teclado

    printf("\n===== CADASTRO DE PRODUTO =====\n");

    do
    {
        printf("Nome do produto: ");
        fgets(nomes[i], 50, stdin);

        // O fgets vem com um "\n" chato no final. Essa linha troca ele por um fim de texto '\0'
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        if (strlen(nomes[i]) == 0)
        {
            printf("Nome nao pode ser vazio! Digite alguma coisa.\n");
        }

    } while (strlen(nomes[i]) == 0);

    // Chama as funções de validação que criamos lá em cima e salva direto no vetor
    precos[i] = lerPreco();
    estoques[i] = lerEstoque();

    total++; // Avisa o sistema que agora temos mais um produto cadastrado

    printf("\nProduto cadastrado com sucesso!\n");

    return total; // Devolve o novo total atualizado para a função principal
}

// ========================================================
// O MENU: Expandido com todas as novas ferramentas
// ========================================================
void menu()
{
    printf("\n=====================================\n");
    printf("        SISTEMA DE PRODUTOS\n");
    printf("=====================================\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Produto mais caro\n");
    printf("5 - Valor total em estoque\n");
    printf("6 - Alterar Preco e Estoque\n");
    printf("7 - Remover produto\n");
    printf("8 - Produto mais barato\n");
    printf("9 - Media de precos dos produtos\n");
    printf("10 - Alerta de estoque baixo (< 2 unidades)\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

// ========================================================
// FUNÇÃO PRINCIPAL: O cérebro do programa
// ========================================================
int main()
{
    // Criando as nossas 3 listas paralelas (gaveteiros)
    char nomes[MAX][50];
    float precos[MAX];
    int estoques[MAX];

    int total = 0; // Começamos do zero, nenhum produto cadastrado ainda
    int opcao;
    int i; // Nossa variável de controle para usar nos loops
    
    do
    {
        menu(); // Mostra as opções

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            total = cadastrarProduto(nomes, precos, estoques, total);
            break;

        case 2:
            if (total == 0) {
                printf("\nNenhum produto cadastrado ainda!\n");
                break;
            }
            printf("\n===== LISTA DE PRODUTOS =====\n");
            
            i = 0; 
            while (i < total) 
            {
                printf("Nome: %s | Preco: R$ %.2f | Estoque: %d \n", nomes[i], precos[i], estoques[i]);
                i++; 
            }
            break;

        case 3: {
            if (total == 0) {
                printf("\nNenhum produto cadastrado para buscar!\n");
                break;
            }
            
            char busca[50];
            int achou = 0;

            getchar(); 
            printf("\nDigite o nome do produto para buscar: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for (i = 0; i < total; i++) {
                if (strcmp(nomes[i], busca) == 0) {
                    printf("\nProduto Encontrado!\n");
                    printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[i], precos[i], estoques[i]);
                    achou = 1; 
                    break; 
                }
            }

            if (achou == 0) {
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 4: {
            if (total == 0) {
                printf("\nNenhum produto cadastrado ainda!\n");
                break;
            }

            int indiceMaior = 0; 

            for (i = 1; i < total; i++) {
                if (precos[i] > precos[indiceMaior]) {
                    indiceMaior = i; 
                }
            }

            printf("\n===== PRODUTO MAIS CARO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[indiceMaior], precos[indiceMaior], estoques[indiceMaior]);
            break;
        }

        case 5: {
            if (total == 0) {
                printf("\nNenhum produto em estoque para calcular!\n");
                break;
            }

            float valorTotalGeral = 0;

            for (i = 0; i < total; i++) {
                valorTotalGeral += (precos[i] * estoques[i]);
            }

            printf("\n===== VALOR TOTAL EM ESTOQUE =====\n");
            printf("O valor total acumulado de todos os produtos e: R$ %.2f\n", valorTotalGeral);
            break;
        }

        case 6: { // ALTERAR PREÇO E ESTOQUE
            if (total == 0) {
                printf("\nNenhum produto cadastrado para alterar!\n");
                break;
            }
            char busca[50];
            int achou = 0;

            getchar();
            printf("\nDigite o nome do produto que deseja alterar: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            // Procura o cara na lista para saber a linha dele
            for (i = 0; i < total; i++) {
                if (strcmp(nomes[i], busca) == 0) {
                    printf("\nProduto encontrado! Vamos atualizar os valores de \"%s\":\n", nomes[i]);
                    
                    // Reaproveita as funções de ler preço e estoque que já validam as entradas
                    precos[i] = lerPreco();
                    estoques[i] = lerEstoque();
                    
                    printf("\nValores atualizados com sucesso!\n");
                    achou = 1;
                    break;
                }
            }
            if (achou == 0) {
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 7: { // REMOVER PRODUTO
            if (total == 0) {
                printf("\nNenhum produto cadastrado para remover!\n");
                break;
            }
            char busca[50];
            int achou = 0;
            int j; // Variável extra para reorganizar a fila

            getchar();
            printf("\nDigite o nome do produto que deseja remover: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for (i = 0; i < total; i++) {
                if (strcmp(nomes[i], busca) == 0) {
                    achou = 1;
                    
                    // LÓGICA DO PUXA-FILA: Para nao deixar um buraco vazio na memória, 
                    // o produto da frente assume o lugar do que foi deletado, sucessivamente.
                    for (j = i; j < total - 1; j++) {
                        strcpy(nomes[j], nomes[j + 1]);
                        precos[j] = precos[j + 1];
                        estoques[j] = estoques[j + 1];
                    }
                    
                    total--; // Diminui o contador geral do sistema
                    printf("\nProduto removido com sucesso!\n");
                    break;
                }
            }
            if (achou == 0) {
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 8: { // PRODUTO MAIS BARATO
            if (total == 0) {
                printf("\nNenhum produto cadastrado ainda!\n");
                break;
            }

            int indiceMenor = 0; // Chuta que o primeiro é o menor

            // Compara com o resto dos produtos cadastrados
            for (i = 1; i < total; i++) {
                if (precos[i] < precos[indiceMenor]) {
                    indiceMenor = i; // Encontrou um menor preço, atualiza a posição
                }
            }

            printf("\n===== PRODUTO MAIS BARATO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[indiceMenor], precos[indiceMenor], estoques[indiceMenor]);
            break;
        }

        case 9: { // MÉDIA DE PREÇOS
            if (total == 0) {
                printf("\nNenhum produto cadastrado para calcular a media!\n");
                break;
            }

            float somaPrecos = 0;

            // Passa somando o preço de cada produto puro (sem multiplicar por estoque)
            for (i = 0; i < total; i++) {
                somaPrecos += precos[i];
            }

            // Calcula dividindo a soma pelo total de tipos cadastrados
            float media = somaPrecos / total;

            printf("\n===== MEDIA DE PRECOS =====\n");
            printf("A media de preco dos produtos cadastrados e: R$ %.2f\n", media);
            break;
        }

        case 10: { // ESTOQUE BAIXO (< 2)
            if (total == 0) {
                printf("\nNenhum produto cadastrado para verificar!\n");
                break;
            }

            int temEstoqueBaixo = 0; // Flag para saber se achamos algum crítico

            printf("\n===== ALERTA: ESTOQUE CRITICO (< 2 UNIDADES) =====\n");
            
            for (i = 0; i < total; i++) {
                // Aqui está o filtro que você pediu: menor que 2
                if (estoques[i] < 2) {
                    printf("AVISO! -> Produto: %s | Estoque atual: %d\n", nomes[i], estoques[i]);
                    temEstoqueBaixo = 1; // Opa, achamos pelo menos um
                }
            }

            // Se rodou o armário todo e não achou ninguém abaixo de 2 unidades
            if (temEstoqueBaixo == 0) {
                printf("Tudo seguro! Nenhum produto com estoque abaixo de 2 unidades.\n");
            }
            break;
        }

        case 0:
            printf("\nPrograma encerrado.\n");
            break;

        default:
            printf("\nOpcao invalida! Escolha um numero do menu.\n");
        }

    } while (opcao != 0); 

    return 0;
}