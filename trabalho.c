#include <stdio.h>   
#include <string.h> 

#define MAX 10 //aqui eu defino um limite maximo de 10 


float lerPreco()
{
    float preco; // essa variavel serve para guardar as informaçoes sobre os preços

    do
    {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &preco); //aqui ele le o preço digitado e guarda

        if (preco < 0) // aqui seria uma segurança para nenhum numero negativo passar
        {
            printf("preço invalido, nao existe preco menor que zero.\n");
        }

    } while (preco < 0); // aqui ele verifica se o preço for negativo ele volta para o do
    return preco; // Se o preço for válido, a função termina e "devolve" esse valor para quem a chamou
}

// ====================================================================================
// FUNÇÃO: VALIDAÇÃO DE ESTOQUE
// Mesma lógica da função anterior, mas trabalha com números inteiros (int).
// ====================================================================================
int lerEstoque()
{
    int estoque; // Cria um espaço na memória para guardar a quantidade inteira

    do
    {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &estoque); // O '%d' avisa ao computador que ele vai ler um número inteiro

        if (estoque < 0)
        {
            printf("Quantidade invalida! O estoque nao pode ser negativo.\n");
        }

    } while (estoque < 0); // Fica preso aqui até que a quantidade seja 0 ou maior

    return estoque; // Devolve o número inteiro validado para o programa principal
}

// ====================================================================================
// FUNÇÃO: CADASTRO DE PRODUTOS
// Recebe as listas por referência (ponteiros implícitos) e a quantidade atual de cadastrados.
// ====================================================================================
int cadastrarProduto(char nomes[][50], float precos[], int estoques[], int total)
{
    int i = total; // O índice 'i' recebe o valor de 'total'. Se temos 0 produtos, o novo vai para a linha 0.

    // BARREIRA DE SEGURANÇA: Se o total for 10, significa que usamos as linhas de 0 a 9. Não há mais espaço.
    if (total >= MAX)
    {
        printf("\nLimite maximo de produtos atingido! Nao cabe mais nada.\n");
        return total; // Retorna o mesmo total, sem cadastrar nada, cancelando a execução da função
    }

    getchar(); // LIMPEZA DE BUFFER: Remove o 'Enter' (\n) que sobrou do último scanf no menu, evitando que o fgets seja pulado.

    printf("\n===== CADASTRO DE PRODUTO =====\n");

    do
    {
        printf("Nome do produto: ");
        // fgets(onde_salvar, tamanho_maximo, de_onde_ler)
        // stdin significa Standard Input (Teclado). Ele lê a linha inteira, incluindo espaços.
        fgets(nomes[i], 50, stdin);

        // REMOÇÃO DO ENTER: O fgets salva o texto junto com o "Enter" (\n) no final.
        // strcspn procura onde está o "\n" no texto e retorna a posição dele.
        // Nós vamos nessa posição exata e trocamos o "\n" por '\0' (Null character), que avisa o C onde o texto realmente termina.
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        // VALIDAÇÃO: Se o usuário só apertou Enter, o tamanho do texto (strlen) será 0.
        if (strlen(nomes[i]) == 0)
        {
            printf("Nome nao pode ser vazio! Digite alguma coisa.\n");
        }

    } while (strlen(nomes[i]) == 0); // Repete o pedido se o nome estiver completamente vazio

    // Agora chamamos as funções de leitura e validação que criamos lá em cima.
    // O valor retornado por elas é jogado direto na prateleira 'i' dos nossos vetores.
    precos[i] = lerPreco();
    estoques[i] = lerEstoque();

    total++; // INCREMENTO: Adiciona 1 ao contador de produtos cadastrados no sistema

    printf("\nProduto cadastrado com sucesso!\n");

    return total; // Retorna o novo total atualizado (ex: se era 0, agora retorna 1) para atualizar a main
}

// ====================================================================================
// FUNÇÃO: APENAS EXIBIÇÃO DO MENU
// Não processa dados, apenas joga o texto visual na tela.
// ====================================================================================
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

// ====================================================================================
// FUNÇÃO PRINCIPAL: O ponto de partida de toda a execução do programa
// ====================================================================================
int main()
{
    // DECLARAÇÃO DOS VETORES PARALELOS:
    // nomes[10][50] -> Uma matriz (tabela). Tem 10 linhas, e cada linha pode ter um texto de até 50 letras.
    char nomes[MAX][50];
    // precos[10] -> Um vetor de 10 posições para guardar números decimais (preços).
    float precos[MAX];
    // estoques[10] -> Um vetor de 10 posições para guardar números inteiros (quantidades).
    int estoques[MAX];

    int total = 0; // Controla quantos produtos reais existem no sistema. Começa em zero.
    int opcao;     // Guarda o número do menu escolhido pelo usuário.
    int i;         // Variável universal que usaremos como contador dentro dos nossos loops (for/while).
    
    do
    {
        menu(); // Desenha o menu na tela

        scanf("%d", &opcao); // Aguarda o usuário escolher uma opção e digita o valor nela

        // O switch funciona como um roteador: ele olha o número em 'opcao' e pula direto para o 'case' correspondente
        switch (opcao)
        {
        case 1:
            // Executa o cadastro enviando as listas e o total atual.
            // O resultado retornado pela função atualiza a nossa variável 'total' da main.
            total = cadastrarProduto(nomes, precos, estoques, total);
            break;

        case 2:
            // VALIDAÇÃO: Se o total for 0, o sistema avisa e o 'break' impede o programa de tentar ler memória vazia.
            if (total == 0) {
                printf("\nNenhum produto cadastrado ainda!\n");
                break;
            }
            printf("\n===== LISTA DE PRODUTOS =====\n");
            
            i = 0; // Reseta o contador. Vamos começar a olhar a partir do primeiro item (posição 0).
            while (i < total) // O looping vai rodar enquanto o 'i' for menor que a quantidade total de cadastrados.
            {
                // Como os vetores são paralelos, a posição 'i' acessa o Nome, Preço e Estoque do MESMO produto.
                printf("Nome: %s | Preco: R$ %.2f | Estoque: %d \n", nomes[i], precos[i], estoques[i]);
                i++; // Soma 1 ao 'i' para passar para a próxima linha da memória na próxima rodada do while.
            }
            break;

        case 3: { // Chaves '{ }' são usadas aqui para isolar e permitir a criação de variáveis locais protegidas dentro deste case.
            if (total == 0) {
                printf("\nNenhum produto cadastrado para buscar!\n");
                break;
            }
            
            char busca[50]; // Variável para guardar temporariamente o texto que o usuário quer procurar.
            int achou = 0;  // FLAG (Sinalizador): Começa em 0 (falso). Se encontrarmos o produto, vira 1 (verdadeiro).

            getchar(); // Limpa o buffer para o fgets funcionar sem bugs.
            printf("\nDigite o nome do produto para buscar: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0'; // Remove o caractere de quebra de linha.

            // LOOP DE VARREDURA: O 'for' inicia 'i=0', checa se 'i < total' e adiciona 'i++' a cada ciclo.
            for (i = 0; i < total; i++) {
                // strcmp(texto1, texto2) compara caractere por caractere. Se forem 100% idênticos, ela retorna exatamente 0.
                if (strcmp(nomes[i], busca) == 0) {
                    printf("\nProduto Encontrado!\n");
                    printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[i], precos[i], estoques[i]);
                    achou = 1; // Ativa a nossa flag indicando sucesso na busca.
                    break; // ABORTO: Se já encontramos o que queríamos, quebramos o loop 'for' imediatamente para economizar processamento.
                }
            }

            // Se o loop acima procurou em todas as linhas e a flag 'achou' continuou valendo 0...
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

            // TÉCNICA DE COMPARAÇÃO: Nós não guardamos o preço mais alto, guardamos APENAS a LINHA (índice) dele.
            int indiceMaior = 0; // Chutamos inicialmente que o produto da primeira linha (0) é o mais caro de todos.

            // O loop começa a varrer a partir da segunda linha (índice 1), já que comparar a linha 0 com ela mesma é inútil.
            for (i = 1; i < total; i++) {
                // Se o preço do produto da linha 'i' atual for maior do que o preço do nosso atual campeão...
                if (precos[i] > precos[indiceMaior]) {
                    indiceMaior = i; // O trono muda de dono! Guardamos o novo índice 'i' como o mais caro encontrado até agora.
                }
            }

            // Impressão final usando a linha que venceu a competição de maior preço
            printf("\n===== PRODUTO MAIS CARO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[indiceMaior], precos[indiceMaior], estoques[indiceMaior]);
            break;
        }

        case 5: {
            if (total == 0) {
                printf("\nNenhum produto em estoque para calcular!\n");
                break;
            }

            float valorTotalGeral = 0; // ACUMULADOR: Variável que servirá como um "cofrinho" de somas. Deve começar obrigatoriamente em 0.

            // Varre todos os produtos cadastrados do primeiro ao último
            for (i = 0; i < total; i++) {
                // Multiplica o preço da linha 'i' pela quantidade em estoque da linha 'i'.
                // O operador '+=' pega o resultado dessa multiplicação e soma ao valor que já estava guardado no cofrinho.
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

            // Primeiro passo: Localizar em qual linha ('i') o produto está escondido na memória
            for (i = 0; i < total; i++) {
                if (strcmp(nomes[i], busca) == 0) {
                    printf("\nProduto encontrado! Vamos atualizar os valores de \"%s\":\n", nomes[i]);
                    
                    // Sobrescreve os dados antigos daquela linha 'i' chamando as nossas funções de leitura já validadas
                    precos[i] = lerPreco();
                    estoques[i] = lerEstoque();
                    
                    printf("\nValores atualizados com sucesso!\n");
                    achou = 1;
                    break; // Interrompe o loop de busca
                }
            }
            if (achou == 0) {
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 7: { // REMOVER PRODUTO (TÉCNICA DE SHIFT LEFT / PUXA-FILA)
            if (total == 0) {
                printf("\nNenhum produto cadastrado para remover!\n");
                break;
            }
            char busca[50];
            int achou = 0;
            int j; // Variável de controle secundária para o segundo loop interno

            getchar();
            printf("\nDigite o nome do produto que deseja remover: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            // Loop para achar a linha do produto a ser deletado
            for (i = 0; i < total; i++) {
                if (strcmp(nomes[i], busca) == 0) {
                    achou = 1; // Encontrou!
                    
                    // LÓGICA DO REMANEJAMENTO: Em C, vetores estáticos não apagam dados deixando buracos. 
                    // Se apagarmos o item da linha 2, precisamos pegar o item da linha 3 e colar na linha 2, 
                    // o da linha 4 colar na linha 3, e assim por diante.
                    // O loop começa na posição do item deletado ('j = i') e vai até a penúltima posição utilizada ('total - 1')
                    for (j = i; j < total - 1; j++) {
                        strcpy(nomes[j], nomes[j + 1]); // Copia o string da linha da frente (j+1) para a linha de trás (j)
                        precos[j] = precos[j + 1];       // Puxa o preço da frente para trás
                        estoques[j] = estoques[j + 1];   // Puxa o estoque da frente para trás
                    }
                    
                    total--; // Reduz o número total de produtos cadastrados ativos. A última linha duplicada agora fica invisível para o sistema.
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

            int indiceMenor = 0; // Chuta que o menor preço está na linha inicial (0)

            // Varre o restante das linhas comparando os valores reais
            for (i = 1; i < total; i++) {
                if (precos[i] < precos[indiceMenor]) {
                    indiceMenor = i; // Encontrou um preço menor ainda, registra a nova linha vencedora
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

            float somaPrecos = 0; // Acumulador para somar todos os preços unitários puros

            for (i = 0; i < total; i++) {
                somaPrecos += precos[i]; // Vai adicionando o valor de cada etiqueta de preço no montante
            }

            // Faz o cálculo matemático básico: a soma de tudo dividido pela quantidade de itens somados
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

            int temEstoqueBaixo = 0; // Flag de segurança para o caso de o estoque de todo mundo estar em níveis normais

            printf("\n===== ALERTA: ESTOQUE CRITICO (< 2 UNIDADES) =====\n");
            
            for (i = 0; i < total; i++) {
                // REGRA SOLICITADA: Verifica se o número armazenado no índice atual é estritamente menor que 2 (ou seja, 0 ou 1 item)
                if (estoques[i] < 2) {
                    printf("AVISO! -> Produto: %s | Estoque atual: %d\n", nomes[i], estoques[i]);
                    temEstoqueBaixo = 1; // Ativa a flag indicando que achamos pelo menos um caso crítico
                }
            }

            // Se o loop varreu toda a memória e a nossa flag continuou intacta em zero...
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

    } while (opcao != 0); // O loop principal do menu continua rodando enquanto a opção digitada não for zero

    return 0; // Indica ao sistema operacional que o programa rodou perfeitamente e chegou ao fim sem travamentos
}