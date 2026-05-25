#include <stdio.h>   
#include <string.h> 
#include <stdlib.h> 

#define MAX 10 // aqui eu defino um limite maximo de 10 

typedef struct { //struct seria aonde os dados sao reunidos e typedef seria trocar o nome struct para um nome selecionado como oque eu usei com o "PRODUTO"
    char nome[50];
    float preco;
    int estoque;
} Produto;

float lerPreco()
{
    float preco; // essa variavel serve para guardar as informaçoes sobre os preços

    do
    {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &preco); // aqui ele le o preço digitado e guarda

        if (preco < 0) // aqui seria uma segurança para nenhum numero negativo passar
        {
            printf("preço invalido, nao existe preco menor que zero.\n");
        }

    } while (preco < 0); // aqui ele verifica se o preço for negativo ele volta para o do
    
    return preco; // se o preço digitado for positivo ele volta para quem ela foi chamada
}

int lerEstoque() // seria uma função semelhante a anterios mais agora controlando o estoque
{
    int estoque; // aqui eu crio uma variavel na memoria chamada estoque

    do
    {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &estoque); // le um o numero inteiro digitado

        if (estoque < 0) // aqui ele barra se a quantidade for menor que zero
        {
            printf("Quantidade invalida! O estoque nao pode ser negativo.\n");
        }

    } while (estoque < 0); // aqui ele se repete ate que o numero digitado seja maior que 0

    return estoque; // aqui ele salva e devolve o resultado para a variavel
}

// aqui ele busca em PRODUTOS"struct" as variaveis armazenadas
int cadastrarProduto(Produto produtos[], int total)
{
    int i = total; // aqui eu defino o total de produtos

    if (total >= MAX) // aqui eu defino o limite maximo de produtos usando o MAX
    {
        printf("\nLimite maximo de produtos atingido\n");
        return total; // aqui ele "ignora" o que foi digitado e continua com os 10 produtos salvos sem mudar nada
    }

    getchar(); // ele remove os dados anterios para evitar enganos

    printf("\n===== CADASTRO DE PRODUTO =====\n");

    do
    {
        printf("Nome do produto: ");
        // Usamos o ponto (.) para entrar na ficha do produto e acessar o nome
        fgets(produtos[i].nome, 50, stdin); 

        // aqui ele acha o enter que foi digitado e corta para o texto nao quebrar a linha
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        if (strlen(produtos[i].nome) == 0) // aqui ele confere se eu apertei enter sem digitar nada
        {
            printf("Nome nao pode ser vazio! Digite alguma coisa.\n");
        }

    } while (strlen(produtos[i].nome) == 0); // aqui ele se repete se o nome estiver em branco

    // aqui ele chama as funções la de cima para validar e salvar usando o ponto  .
    produtos[i].preco = lerPreco();
    produtos[i].estoque = lerEstoque();

    total++; // aqui eu somo mais um no total de produtos salvos no sistema

    printf("\nProduto cadastrado com sucesso!\n");

    return total; // aqui ele devolve o total atualizado para a funcao principal
}

void menu() // essa funcao serve para mostrar as opcoes na tela
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
    printf("0 - Sair\n");
    printf("Opcao: ");
}

int main()
{
    Produto produtos[MAX]; 
    int total = 0; 
    int opcao;    
    int i;        
    char Pcadastro;

    do
    {
        menu(); // aqui ele mostra o menu na tela

        scanf("%d", &opcao); // aqui ele le a opcao que eu digitei

        switch (opcao) // aqui ele joga para o caso que eu escolhi no menu
        {
        case 1:
            do {
                total = cadastrarProduto(produtos, total);
                
                if (total >= MAX) {
                    break; // Se estourar o limite de 10, sai do laço de repetição automático
                }

                printf("\nDeseja realizar outro cadastro? (s/n): ");
                scanf(" %c", &Pcadastro);// coloquei isso tipo o usuario nao precisa ir ate o menu paara cadastrar outro produto
            } while (Pcadastro == 's' || Pcadastro == 'S');
              // talvez voce se pergunte mas aonde esta o n?
              /* nao usei o n por que nao a necessidade por que se o usuario digitar outra letra o numero ou se der
              so enter ele entendera como erro re voltara para o menu automaticamente anulando a necessidade de colocar N*/
          
            break;

        case 2:
            if (total == 0) { // aqui ele confere se nao tem nada cadastrado ainda
                printf("\nNenhum produto cadastrado ainda!\n");
                break;
            }
            printf("\n===== LISTA DE PRODUTOS =====\n");
            
            i = 0; // comeco a olhar a partir da primeira posicao
            while (i < total) // aqui ele roda ate chegar no limite de itens cadastrados
            {
                // usamos o .nome, .preco e .estoque para exibir os dados da struct
                printf("Nome: %s | Preco: R$ %.2f | Estoque: %d", produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                
                if (produtos[i].estoque < 5) { // AJUSTADO: Alerta para estoque menor que 5 baseado no desafio extra
                    printf(" -> [ALERTA: ESTOQUE BAIXO]");
                }
                
                printf("\n");
                i++; // aqui eu pulo para a proxima linha da lista
            }
            break;

        case 3: { 
            if (total == 0) { // verifica se tem produtos antes de comecar a busca
                printf("\nNenhum produto cadastrado para buscar!\n");
                break;
            }
            
            char busca[50]; // variavel para guardar o nome do produto que eu quero achar
            int achou = 0;  // essa variavel comeca em zero e serve para avisar se achei ou nao

            getchar(); // limpa a memoria do terminal
            printf("\nDigite o nome do produto: ");
            fgets(busca, 50, stdin); // le o nome que eu quero buscar
            busca[strcspn(busca, "\n")] = '\0'; // tira o enter do final do texto de busca

            for (i = 0; i < total; i++) { // aqui ele passa olhando linha por linha dos produtos
                if (strcmp(produtos[i].nome, busca) == 0) { // compara usando o .nome
                    printf("\nProduto Encontrado!\n");
                    printf("Nome: %s | Preco: R$ %.2f | Estoque: %d", produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                    
                    if (produtos[i].estoque < 3) { /* seria um codigo que verefica automaticamente 
                        pro usuario se o estoque do produto pesquisado ou listado esta correto*/
                        printf(" -> [ALERTA: ESTOQUE BAIXO]");
                    }
                    
                    printf("\n");
                    achou = 1; // muda para 1 para avisar que deu certo
                    break; // aqui ele para o loop porque ja achou o que queria
                }
            }

            if (achou == 0) { // se o loop terminou e continuou zero significa que nao achou
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 4: {
            if (total == 0) { // confere se a lista nao esta vazia
                printf("\nNenhum produto cadastrado ainda\n");
                break;
            }

            int indiceMaior = 0; // aqui eu "chuto" que o primeiro numero e o maior

            for (i = 1; i < total; i++) { // passa comparando com o resto dos produtos
                if (produtos[i].preco > produtos[indiceMaior].preco) { // compara os preços acessando com ponto (.)
                    indiceMaior = i; // a posicao do mais caro passa a ser essa nova linha i
                }
            }

            printf("\n===== PRODUTO MAIS CARO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", produtos[indiceMaior].nome, produtos[indiceMaior].preco, produtos[indiceMaior].estoque);
            break;
        }

        case 5: {
            if (total == 0) { // confere se tem produtos para calcular
                printf("\nNenhum produto em estoque para calcular\n");
                break;
            }

            float valorTotalGeral = 0; // aqui e como se fosse a calculadora sem infromaçoes zerada

            for (i = 0; i < total; i++) { // loop para passar por todos os produtos
                // calcula o preco vezes o estoque acessando directo da struct
                valorTotalGeral += (produtos[i].preco * produtos[i].estoque);
            }

            printf("\n ===== VALOR TOTAL EM ESTOQUE ===== \n");
            printf("O valor total acumulado de todos os produtos e: R$ %.2f\n", valorTotalGeral);
            break;
        }

        case 6: { 
            if (total == 0) { // verifica se tem o que alterar
                printf("\nNenhum produto cadastrado para alterar!\n");
                break;
            }
            char busca[50]; // guarda o nome do produto que eu quero mudar
            int achou = 0;

            getchar();
            printf("\ndigite o nome do produto que deseja alterar: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for (i = 0; i < total; i++) { // loop para achar em qual linha o produto esta salvo
                if (strcmp(produtos[i].nome, busca) == 0) { // se achar o nome igual
                    printf("\nProduto encontrado, Vamos atualizar os valores de \"%s\":\n", produtos[i].nome);
                    
                    // atualiza os campos específicos da struct do produto achado
                    produtos[i].preco = lerPreco();
                    produtos[i].estoque = lerEstoque();
                    
                    printf("\nValores updated com sucesso!\n");
                    achou = 1;
                    break; // para a busca porque ja alterou
                }
            }
            if (achou == 0) {
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 7: { 
            if (total == 0) { // confere se tem o que remover
                printf("\nNenhum produto cadastrado para remover!\n");
                break;
            }
            char busca[50]; // guarda o nome de quem eu quero apagar
            int achou = 0;
            int j; // variavel extra para ajudar a mexer na fila de produtos

            getchar();
            printf("\nDigite o nome do produto que deseja remover: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for (i = 0; i < total; i++) { // loop para achar o produto na lista
                if (strcmp(produtos[i].nome, busca) == 0) {
                    achou = 1; 
                    
                    /*aqui o struct auxilia tipo inves de eu digitar nome , preço e depois estoque, com
                      ele nao como ele tem tudo ja armazenado eu so chamo ele com o nome denominado e pronto*/
                    
                    for (j = i; j < total - 1; j++) {
                        produtos[j] = produtos[j + 1]; // Copia o produto da frente inteirinho para trás
                    }
                    
                    total--; // aqui eu tiro um do total de produtos porque deletei um item
                    printf("\nProduto removido com sucesso!\n");
                    break;
                }
            }
            if (achou == 0) {
                printf("\nProduto \"%s\" nao encontrado.\n", busca);
            }
            break;
        }

        case 8: { 
            if (total == 0) { // confere se tem produtos na lista
                printf("\nNenhum produto cadastrado ainda\n");
                break;
            }

            int indiceMenor = 0; // aqui eu "chuto de novo" que o primeiro produto da lista e o mais barato

            for (i = 1; i < total; i++) { // passa comparando com todos os outros itens
                if (produtos[i].preco < produtos[indiceMenor].preco) { // compara os preços com ponto .
                    indiceMenor = i; // a posicao do mais barato passa a ser essa linha i
                }
            }

            printf("\n===== PRODUTO MAIS BARATO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", produtos[indiceMenor].nome, produtos[indiceMenor].preco, produtos[indiceMenor].estoque);
            break;
        }

        case 9: { 
            if (total == 0) { // confere se tem itens para fazer calculo de media
                printf("\nNenhum produto cadastrado para calcular a media\n");
                break;
            }

            float somaPrecos = 0; // como se fosse uma calculadora que soma quantos produtos "preços" estao cadastrados

            for (i = 0; i < total; i++) {
                somaPrecos += produtos[i].preco; // vai somando o preco de cada informação guardada na struct
            }

            // divide o total de somas pela quantidade de produtos salvos
            float media = somaPrecos / total;

            printf("\n===== MEDIA DE PRECOS =====\n");
            printf("a media de preco dos produtos cadastrados e: R$ %.2f\n", media);
            break;
        }

        case 0:
            printf("\nPrograma encerrado.\n");
            break;

        default:
            printf("\nOpcao invalida! Escolha um numero do menu.\n");
        }

      
   
        if (opcao != 0) {
            printf("\n--------------------------------------------------\n");
            printf("Pressione [Enter] para voltar ao menu...");
            // coloquei isso por que o menu estava tampando o resultado
           
            while (getchar() != '\n'); 
            
            getchar();     // Trava o programa na tela para você ler o resultado com calma
            system("cls"); // limpa o terminal completamente antes de rodar o menu de novo
        }
        // =========================================================================

    } while (opcao != 0); // aqui ele mantem o menu rodando ate que a opcao digitada seja zero

    return 0; // avisa o computador que o programa terminou sem erros
}