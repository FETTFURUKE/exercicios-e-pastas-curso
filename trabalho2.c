#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100

typedef struct {
    int id;
    char titulo[100];
    char descricao[200];
    int prioridade;
    int status; 
} Tarefa;


void limparString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void cadastrarTarefa(Tarefa tarefas[], int *totalTarefas, int *proximoId) {
    if (*totalTarefas >= MAX_TAREFAS) {
        printf("\n[ERRO] Limite de tarefas atingido!\n");
        return;
    }

    Tarefa novaTarefa;
    novaTarefa.id = *proximoId;

    printf("\n--- Cadastrar Tarefa (ID: %d) ---\n", novaTarefa.id);
    
    
    getchar(); 

    printf("Título: ");
    fgets(novaTarefa.titulo, sizeof(novaTarefa.titulo), stdin);
    limparString(novaTarefa.titulo);

    printf("Descrição: ");
    fgets(novaTarefa.descricao, sizeof(novaTarefa.descricao), stdin);
    limparString(novaTarefa.descricao);

    
    do {
        printf("Prioridade (1 - Baixa, 2 - Média, 3 - Alta): ");
        scanf("%d", &novaTarefa.prioridade);
        if (novaTarefa.prioridade < 1 || novaTarefa.prioridade > 3) {
            printf("Prioridade inválida! Tente novamente.\n");
        }
    } while (novaTarefa.prioridade < 1 || novaTarefa.prioridade > 3);

    novaTarefa.status = 0; 

    
    tarefas[*totalTarefas] = novaTarefa;
    (*totalTarefas)++;
    (*proximoId)++;

    printf("\nTarefa cadastrada com sucesso!\n");
}

void exibirTarefa(Tarefa t) {
    printf("\nID: %d\n", t.id);
    printf("Título: %s\n", t.titulo);
    printf("Descrição: %s\n", t.descricao);
    printf("Prioridade: %s\n", (t.prioridade == 1) ? "Baixa" : (t.prioridade == 2) ? "Média" : "Alta");
    printf("Status: %s\n", (t.status == 0) ? "Pendente" : "Concluída");
    printf("-----------------------------------\n");



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

void buscarTarefa(Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada para busca.\n");
        return;
    }

    char termoBusca[100];
    printf("\nDigite o título da tarefa que deseja buscar: ");
    getchar(); 
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

void mostrarMaiorPrioridade(Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    int maiorPrioridade = 0;

    
    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].prioridade > maiorPrioridade) {
            maiorPrioridade = tarefas[i].prioridade;
        }
    }

    printf("\n=== TAREFA(S) DE MAIOR PRIORIDADE ===\n");
    
    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].prioridade == maiorPrioridade) {
            exibirTarefa(tarefas[i]);
        }
    }
}


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
            
      
            for (int j = i; j < (*totalTarefas) - 1; j++) {
                tarefas[j] = tarefas[j + 1];
            }
            
            (*totalTarefas)--; 
            printf("\nTarefa removida com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nTarefa com ID %d não encontrada.\n", idBusca);
    }
}


int main() {
    Tarefa listaTarefas[MAX_TAREFAS];
    int totalTarefas = 0;
    int proximoId = 1;
    int opcao;

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
                mostrarPorStatus(listaTarefas, totalTarefas, 0); 
                break;
            case 6:
                mostrarPorStatus(listaTarefas, totalTarefas, 1); 
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







































