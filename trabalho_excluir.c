#include <stdio.h>  // Entrada e saída padrão [12, 13]
#include <string.h> // Manipulação de strings como strcmp [14, 15]

// Definição do limite máximo de produtos [16, 17]
#define MAX_PRODUTOS 10

// 1. A Ficha do Produto (Estrutura) [18-20]
typedef struct {
    char nome[21];
    float preco;
    int estoque;
} Produto;

// Protótipos das funções (Especialistas) [22, 23]
void cadastrar(Produto lista[], int *total);
void listar(Produto lista[], int total);
void buscar(Produto lista[], int total);
void mostrarMaisCaro(Produto lista[], int total);
void calcularValorEstoque(Produto lista[], int total);

int main() {
    // 2. A Prateleira (Vetor de Estruturas) [24-26]
    Produto estoque[MAX_PRODUTOS];
    int totalProdutos = 0; // Contador de produtos cadastrados
    int opcao;

    // 3. O Painel de Escolhas (Menu Interativo) [5, 6, 8]
    do {
        printf("\n--- SISTEMA DE GESTAO DE PRODUTOS ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Produto mais caro\n");
        printf("5 - Valor total em estoque\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        
        // Validação de entrada para evitar erros de tipos não numéricos [27, 28]
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite um numero valido!\n");
            while(getchar() != '\n'); // Limpa o "lixo" do buffer [29]
            opcao = -1; // Força uma opção inválida para repetir o menu
            continue;
        }

        switch(opcao) {
            case 1: cadastrar(estoque, &totalProdutos); break;
            case 2: listar(estoque, totalProdutos); break;
            case 3: buscar(estoque, totalProdutos); break;
            case 4: mostrarMaisCaro(estoque, totalProdutos); break;
            case 5: calcularValorEstoque(estoque, totalProdutos); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); // Validação de menu [30, 31]
        }
    } while (opcao != 0);

    return 0;
}

// 4. Implementação das Funcionalidades (Funções)

// Função para Cadastrar com Validações
void cadastrar(Produto lista[], int *total) {
    if (*total >= MAX_PRODUTOS) { // Validação de limite [32]
        printf("Erro: Limite de %d produtos atingido!\n", MAX_PRODUTOS);
        return;
    }

    Produto p;
    printf("Digite o nome do produto: ");
    scanf("%s", p.nome); // Lê uma palavra simples [33, 34]

    // Validação de Preço Negativo [35, 36]
    do {
        printf("Digite o preco: ");
        scanf("%f", &p.preco);
        if (p.preco < 0) printf("Erro: O preco nao pode ser negativo!\n");
    } while (p.preco < 0);

    // Validação de Estoque Negativo [37]
    do {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &p.estoque);
        if (p.estoque < 0) printf("Erro: O estoque nao pode ser negativo!\n");
    } while (p.estoque < 0);

    lista[*total] = p; // Guarda na "gaveta" correta [38, 39]
    (*total)++; // Incrementa o total usando ponteiro [40-42]
    printf("Produto cadastrado com sucesso!\n");
}

// Função para Listar Produtos [43, 44]
void listar(Produto lista[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("\n--- LISTAGEM DE PRODUTOS ---\n");
    for (int i = 0; i < total; i++) {
        printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", 
               lista[i].nome, lista[i].preco, lista[i].estoque);
    }
}

// Função para Buscar por Nome [45-47]
void buscar(Produto lista[], int total) {
    char termo[21];
    int achou = 0;
    printf("Digite o nome do produto para busca: ");
    scanf("%s", termo);

    for (int i = 0; i < total; i++) {
        // Comparação de strings usando strcmp [45, 47]
        if (strcmp(lista[i].nome, termo) == 0) {
            printf("Produto Encontrado: %s | Preco: R$ %.2f | Estoque: %d\n", 
                   lista[i].nome, lista[i].preco, lista[i].estoque);
            achou = 1;
        }
    }
    if (!achou) printf("Produto nao encontrado.\n");
}

// Função para Identificar o Mais Caro [48, 49]
void mostrarMaisCaro(Produto lista[], int total) {
    if (total == 0) {
        printf("Estoque vazio.\n");
        return;
    }
    int m = 0; // Índice do mais caro
    for (int i = 1; i < total; i++) {
        if (lista[i].preco > lista[m].preco) {
            m = i;
        }
    }
    printf("O produto mais caro e: %s (R$ %.2f)\n", lista[m].nome, lista[m].preco);
}

// Função para Calcular Valor Total [50, 51]
void calcularValorEstoque(Produto lista[], int total) {
    float totalGeral = 0;
    for (int i = 0; i < total; i++) {
        totalGeral += (lista[i].preco * lista[i].estoque); // Acumulador [50, 52]
    }
    printf("Valor total armazenado na loja: R$ %.2f\n", totalGeral);
}