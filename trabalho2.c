#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX_TAREFAS 100





typedef struct {
   
   
   

   
} T

// Função auxiliar para remover o '\n' gerado pelo fgets e limpar o buffer
void limparString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// 1 - Cadastrar tarefa
void cadastrarTarefa(Tarefa tarefas[], int *totalTarefas, int *proximoId) {
    if (*totalTarefas >= MAX_TAREFAS) {
        printf("\n[ERRO] Limite de tarefas atingido!\n");
        return;
    }

    Tarefa novaTarefa;
    novaTarefa.id = *proximoId;

    printf("\n--- Cadastrar Tarefa (ID: %d) ---\n", novaTarefa.id);
    
    // Limpar o buffer antes de ler strings com fgets
    getchar(); 

    printf("Título: ");
    fgets(novaTarefa.titulo, sizeof(novaTarefa.titulo), stdin);
    limparString(novaTarefa.titulo);

    printf("Descrição: ");
    fgets(novaTarefa.descricao, sizeof(novaTarefa.descricao), stdin);
    limparString(novaTarefa.descricao);

    // Validação da prioridade
    do {
        printf("Prioridade (1 - Baixa, 2 - Média, 3 - Alta): ");
        scanf("%d", &novaTarefa.prioridade);
        if (novaTarefa.prioridade < 1 || novaTarefa.prioridade > 3) {
            printf("Prioridade inválida! Tente novamente.\n");
        }
    } while (novaTarefa.prioridade < 1 || novaTarefa.prioridade > 3);

    novaTarefa.status = 0; // Toda tarefa inicia como Pendente

    // Salva no vetor
    tarefas[*totalTarefas] = novaTarefa;
    (*totalTarefas)++;
    (*proximoId)++;

    printf("\nTarefa cadastrada com sucesso!\n");
}

// Função auxiliar para exibir uma única tarefa formatada
void exibirTarefa(Tarefa t) {
    printf("\nID: %d\n", t.id);
    printf("Título: %s\n", t.titulo);
    printf("Descrição: %s\n", t.descricao);
    printf("Prioridade: %s\n", (t.prioridade == 1) ? "Baixa" : (t.prioridade == 2) ? "Média" : "Alta");
    printf("Status: %s\n", (t.status == 0) ? "Pendente" : "Concluída");
    printf("-----------------------------------\n");
}

// 2 - Listar todas as tarefas
void listarTarefas(Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\n=== LISTA DE TODAS AS TAREFAS ===\n");
    for (int i = 0; i < totalTarefas; i++) {
        exibirTarefa(tarefas[i]);
    }
}

// 3 - Buscar tarefa pelo título
void buscarTarefa(Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada para busca.\n");
        return;
    }

    char termoBusca[100];
    printf("\nDigite o título da tarefa que deseja buscar: ");
    getchar(); // Limpa o buffer
    fgets(termoBusca, sizeof(termoBusca), stdin);
    limparString(termoBusca);

    int encontrada = 0;
    for (int i = 0; i < totalTarefas; i++) {
        if (strcmp(tarefas[i].titulo, termoBusca) == 0) {
            printf("\n--- Tarefa Encontrada ---");
            exibirTarefa(tarefas[i]);
            encontrada = 1;
        }
    }

    if (!encontrada) {
        printf("\nTarefa não encontrada.\n");
    }
}

// 4 - Alterar status da tarefa
void alterarStatus(Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    int idBusca, encontrado = 0;
    printf("\nDigite o ID da tarefa para alterar o status: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].id == idBusca) {
            encontrado = 1;
            int novoStatus;
            printf("\nTarefa atual: %s\n", tarefas[i].titulo);
            printf("Status atual: %s\n", (tarefas[i].status == 0) ? "Pendente" : "Concluída");
            
            do {
                printf("Escolha o novo status (0 - Pendente, 1 - Concluída): ");
                scanf("%d", &novoStatus);
                if (novoStatus != 0 && novoStatus != 1) {
                    printf("Opção inválida!\n");
                }
            } while (novoStatus != 0 && novoStatus != 1);

            tarefas[i].status = novoStatus;
            printf("\nStatus alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nTarefa com ID %d não encontrada.\n", idBusca);
    }
}

// 5 e 6 - Mostrar por status (Filtro)
void mostrarPorStatus(Tarefa tarefas[], int totalTarefas, int statusFiltro) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    int contador = 0;
    printf("\n=== TAREFAS %s ===\n", (statusFiltro == 0) ? "PENDENTES" : "CONCLUÍDAS");

    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].status == statusFiltro) {
            exibirTarefa(tarefas[i]);
            contador++;
        }
    }

    if (contador == 0) {
        printf("Nenhuma tarefa encontrada neste status.\n");
    }
}

// 7 - Mostrar tarefa com maior prioridade
void mostrarMaiorPrioridade(Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    int maiorPrioridade = 0;

    // Primeiro descobre qual é o maior valor de prioridade presente no vetor
    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].prioridade > maiorPrioridade) {
            maiorPrioridade = tarefas[i].prioridade;
        }
    }

    printf("\n=== TAREFA(S) DE MAIOR PRIORIDADE ===\n");
    // Exibe todas as tarefas que possuem essa maior prioridade
    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].prioridade == maiorPrioridade) {
            exibirTarefa(tarefas[i]);
        }
    }
}

// 8 - Remover tarefa (Garante a reorganização do vetor)
void removerTarefa(Tarefa tarefas[], int *totalTarefas) {
    if (*totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada para remover.\n");
        return;
    }

    int idBusca, encontrado = 0;
    printf("\nDigite o ID da tarefa que deseja remover: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < *totalTarefas; i++) {
        if (tarefas[i].id == idBusca) {
            encontrado = 1;
            
            // Reorganização: move todos os elementos seguintes uma posição para trás
            for (int j = i; j < (*totalTarefas) - 1; j++) {
                tarefas[j] = tarefas[j + 1];
            }
            
            (*totalTarefas)--; // Reduz o contador global de tarefas
            printf("\nTarefa removida com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nTarefa com ID %d não encontrada.\n", idBusca);
    }
}

// Função Principal
int main() {
    Tarefa listaTarefas[MAX_TAREFAS];
    int totalTarefas = 0;
    int proximoId = 1; // ID auto-incrementável único
    int opcao;
SetConsoleCP(CP_UTF8);
    do {
        printf("\n=============================\n");
        printf(" SISTEMA DE TAREFAS\n");
        printf("=============================\n");
        printf("1 - Cadastrar tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Buscar tarefa\n");
        printf("4 - Alterar status\n");
        printf("5 - Mostrar pendentes\n");
        printf("6 - Mostrar concluídas\n");
        printf("7 - Maior prioridade\n");
        printf("8 - Remover tarefa\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(listaTarefas, &totalTarefas, &proximoId);
                break;
            case 2:
                listarTarefas(listaTarefas, totalTarefas);
                break;
            case 3:
                buscarTarefa(listaTarefas, totalTarefas);
                break;
            case 4:
                alterarStatus(listaTarefas, totalTarefas);
                break;
            case 5:
                mostrarPorStatus(listaTarefas, totalTarefas, 0); // 0 para Pendentes
                break;
            case 6:
                mostrarPorStatus(listaTarefas, totalTarefas, 1); // 1 para Concluídas
                break;
            case 7:
                mostrarMaiorPrioridade(listaTarefas, totalTarefas);
                break;
            case 8:
                removerTarefa(listaTarefas, &totalTarefas);
                break;
            case 0:
                printf("\nEncerrando o sistema... Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Escolha um número do menu.\n");
        }
    } while (opcao != 0);

    return 0;
}