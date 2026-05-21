
#include <stdio.h>
#include <string.h>

#define MAX 10

// --- FUNÇÕES DE AUXÍLIO PARA LEITURA E VALIDAÇÃO ---

float lerPreco() {
    float preco;
    do {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &preco);
        if (preco < 0) {
            printf("Preco invalido! O valor nao pode ser negativo.\n");
        }
    } while (preco < 0);
    return preco;
}

int lerEstoque() {
    int estoque;
    do {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &estoque);
        if (estoque < 0) {
            printf("Quantidade invalida! O estoque nao pode ser negativo.\n");
        }
    } while (estoque < 0);
    return estoque;
}

// --- FUNCIONALIDADES DO SISTEMA ---

int cadastrarProduto(char nomes[], float precos[], int estoques[], int total) {
    if (total >= MAX) {
        printf("\nErro: Limite maximo de %d produtos atingido!\n", MAX);
        return total;
    }

    int i = total;
    getchar(); // Limpa o buffer do \n deixado pelo scanf anterior

    printf("\n===== CADASTRO DE PRODUTO (%d/%d) =====\n", total + 1, MAX);
    do {
        printf("Nome do produto: ");
        fgets(nomes[i], 50, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove o \n do fgets

        if (strlen(nomes[i]) == 0) {
            printf("Nome nao pode ser vazio!\n");
        }
    } while (strlen(nomes[i]) == 0);

    precos[i] = lerPreco();
    estoques[i] = lerEstoque();

    printf("\nProduto \"%s\" cadastrado com sucesso!\n", nomes[i]);
    return total + 1;
}

void listarProdutos(char nomes[], float precos[], int estoques[], int total) {
    if (total == 0) {
        printf("\nNenhum produto cadastrado no momento.\n");
        return;
    }

    printf("\n===== LISTAGEM DE PRODUTOS =====\n");
    // Uso do laço 'for' para percorrer o vetor do índice 0 até total-1
    for (int i = 0; i < total; i++) {
        printf("%d. Nome: %-15s | Preco: R$ %7.2f | Estoque: %d\n",
               i + 1, nomes[i], precos[i], estoques[i]);
    }
}

void buscarProduto(char nomes[], float precos[], int estoques[], int total) {
    char termo;
    int achou = 0;

    if (total == 0) {
        printf("\nEstoque vazio. Nao ha o que buscar.\n");
        return;
    }

    getchar();
    printf("\nDigite o nome exato do produto para buscar: ");
    fgets(termo, 50, stdin);
    termo[strcspn(termo, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        // Comparação de strings usando strcmp: retorna 0 se forem iguais
        if (strcmp(nomes[i], termo) == 0) {
            printf("\nProduto encontrado na posicao %d:\n", i + 1);
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[i], precos[i], estoques[i]);
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("\nProduto \"%s\" nao encontrado no sistema.\n", termo);
    }
}

void mostrarMaisCaro(char nomes[], float precos[], int estoques[], int total) {
    if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int indiceMaisCaro = 0;
    // Algoritmo de busca de maior valor: comparamos o atual com o maior salvo
    for (int i = 1; i < total; i++) {
        if (precos[i] > precos[indiceMaisCaro]) {
            indiceMaisCaro = i;
        }
    }

    printf("\n===== PRODUTO MAIS CARO =====\n");
    printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
           nomes[indiceMaisCaro], precos[indiceMaisCaro], estoques[indiceMaisCaro]);
}

void calcularValorTotalEstoque(float precos[], int estoques[], int total) {
    float valorTotalGeral = 0;

    for (int i = 0; i < total; i++) {
        // Fórmula: valor acumulado += (preço * quantidade)
        valorTotalGeral += (precos[i] * (float)estoques[i]);
    }

    printf("\nVALOR TOTAL ARMAZENADO NA LOJA: R$ %.2f\n", valorTotalGeral);
}

void menu() {
    printf("\n=============================\n");
    printf("      SISTEMA DE PRODUTOS\n");
    printf("=============================\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Produto mais caro\n");
    printf("5 - Valor total em estoque\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

// --- FUNÇÃO PRINCIPAL ---

int main() {
    char nomes[MAX];
    float precos[MAX];
    int estoques[MAX];

    int total = 0;
    int opcao;

    // Laço do-while garante que o menu apareça pelo menos uma vez
    do {
        menu();

        // Validação básica para evitar erros de leitura
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite apenas numeros!\n");
            while(getchar() != '\n'); // Limpa buffer
            opcao = -1;
            continue;
        }

        // Estrutura switch para selecionar a tarefa desejada
        switch (opcao) {
            case 1:
                total = cadastrarProduto(nomes, precos, estoques, total);
                break;
            case 2:
                listarProdutos(nomes, precos, estoques, total);
                break;
            case 3:
                buscarProduto(nomes, precos, estoques, total);
                break;
            case 4:
                mostrarMaisCaro(nomes, precos, estoques, total);
                break;
            case 5:
                calcularValorTotalEstoque(precos, estoques, total);
                break;
            case 0:
                printf("\nSaindo... Programa encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}


