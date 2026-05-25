#include <stdio.h>   
#include <string.h> 

#define MAX 10 // aqui eu defino um limite maximo de 10 

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

int cadastrarProduto(char nomes[][50], float precos[], int estoques[], int total)
{
    int i = total; // aqui eu defino o total de produtos

    if (total >= MAX) // aqui eu defino o limite maximo de produtos usando o MAX
    {
        printf("\nLimite maximo de produtos atingido! Nao cabe mais nada.\n");
        return total; // aqui ele "ignora" o que foi digitado e continua com os 10 produtos salvos sem mudar nada
    }

    getchar(); // ele remove os dados anterios para evitar enganos

    printf("\n===== CADASTRO DE PRODUTO =====\n");

    do
    {
        printf("Nome do produto: ");
        fgets(nomes[i], 50, stdin); // aqui ele pega o nome do produto direto do teclado

        // aqui ele acha o enter que foi digitado e corta para o texto nao quebrar a linha
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        if (strlen(nomes[i]) == 0) // aqui ele confere se eu apertei enter sem digitar nada
        {
            printf("Nome nao pode ser vazio! Digite alguma coisa.\n");
        }

    } while (strlen(nomes[i]) == 0); // aqui ele se repete se o nome estiver em branco

    // aqui ele chama as funções la de cima para validar e salvar direto nas listas
    precos[i] = lerPreco();
    estoques[i] = lerEstoque();

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
    printf("10 - Alerta de estoque baixo (< 2 unidades)\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

int main()
{
    // aqui eu crio as 3 listas que vao guardar as informacoes juntas na memoria
    char nomes[MAX][50]; 
    float precos[MAX];   
    int estoques[MAX];   
    int total = 0; 
    int opcao;    
    int i;        
    
    do
    {
        menu(); // aqui ele mostra o menu na tela

        scanf("%d", &opcao); // aqui ele le a opcao que eu digitei

        switch (opcao) // aqui ele joga para o caso que eu escolhi no menu
        {
        case 1:
            // aqui eu chamo o cadastro e atualizo o total da main adicionando 1 produto e suas informaçoes
            total = cadastrarProduto(nomes, precos, estoques, total);
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
                // aqui ele printa  em forma de tabela os produtos e suas infromaçoes
                printf("Nome: %s | Preco: R$ %.2f | Estoque: %d \n", nomes[i], precos[i], estoques[i]);
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
                if (strcmp(nomes[i], busca) == 0) { // aqui ele compara se os dois nomes sao iguais
                    printf("\nProduto Encontrado!\n");
                    printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[i], precos[i], estoques[i]);
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
                if (precos[i] > precos[indiceMaior]) { // se o preco desse for maior do que o que eu ja tinha salvo
                    indiceMaior = i; // a posicao do mais caro passa a ser essa nova linha i
                }
            }

            printf("\n===== PRODUTO MAIS CARO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[indiceMaior], precos[indiceMaior], estoques[indiceMaior]);
            break;
        }

        case 5: {
            if (total == 0) { // confere se tem produtos para calcular
                printf("\nNenhum produto em estoque para calcular\n");
                break;
            }

            float valorTotalGeral = 0; // aqui e como se fosse a calculadora sem infromaçoes zerada

            for (i = 0; i < total; i++) { // loop para passar por todos os produtos
                // aqui ele calcula o preco vezes o estoque e vai guardando tudo na calcualdora
                valorTotalGeral += (precos[i] * estoques[i]);
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
                if (strcmp(nomes[i], busca) == 0) { // se achar o nome igual
                    printf("\nProduto encontrado, Vamos atualizar os valores de \"%s\":\n", nomes[i]);
                    
                    // aqui eu chamo as funcoes la de cima para colocar os novos valores por cima dos antigos
                    precos[i] = lerPreco();
                    estoques[i] = lerEstoque();
                    
                    printf("\nValores atualizados com sucesso!\n");
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
                if (strcmp(nomes[i], busca) == 0) {
                    achou = 1; 
                    
                    // aqui eu crio um loop que puxa todos os produtos da frente para tras para nao deixar buraco
                    for (j = i; j < total - 1; j++) {
                        strcpy(nomes[j], nomes[j + 1]); // puxa o nome da frente para tras
                        precos[j] = precos[j + 1];       // puxa o preco da frente para tras
                        estoques[j] = estoques[j + 1];   // puxa o estoque da frente para tras
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
                if (precos[i] < precos[indiceMenor]) { // se o preco desse for menor do que o menor que eu tinha
                    indiceMenor = i; // a posicao do mais barato passa a ser essa linha i
                }
            }

            printf("\n===== PRODUTO MAIS BARATO =====\n");
            printf("Nome: %s | Preco: R$ %.2f | Estoque: %d\n", nomes[indiceMenor], precos[indiceMenor], estoques[indiceMenor]);
            break;
        }

        case 9: { 
            if (total == 0) { // confere se tem itens para fazer calculo de media
                printf("\nNenhum produto cadastrado para calcular a media
                    \n");
                break;
            }

            float somaPrecos = 0; // como se fosse uma calculadora que soma  quantos produtos"preços" estao cadastrados

            for (i = 0; i < total; i++) {
                somaPrecos += precos[i]; // aqui ele vai somando o preco de cada produto
            }

            // aqui ele pega o resultado de todas as somas e divide pela quantidade de produtos salvos
            float media = somaPrecos / total;

            printf("\n===== MEDIA DE PRECOS =====\n");
            printf("a media de preco dos produtos cadastrados e: R$ %.2f\n", media);
            break;
        }

        case 10: { 
            if (total == 0) { // confere se tem produtos na lista para checar o estoque
                printf("\nNenhum produto cadastrado para verificar!\n");
                break;
            }

            int temEstoqueBaixo = 0; // serve para eu saber se achei alguem na condicao critica

            printf("\n===== ALERTA: ESTOQUE CRITICO (< 2 UNIDADES) =====\n");
            
            for (i = 0; i < total; i++) { // passa olhando o estoque de todo mundo
                if (estoques[i] < 2) { // aqui ele confere se a quantidade do produto i e menor do que 2
                    printf("AVISO! -> Produto: %s | Estoque atual: %d\n", nomes[i], estoques[i]);
                    temEstoqueBaixo = 1; // muda para 1 para avisar que encontrou estoque baixo
                }
            }

            if (temEstoqueBaixo == 0) { // se passou por tudo e continuou zero significa que ta tudo certo
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

    } while (opcao != 0); // aqui ele mantem o menu rodando ate que a opcao digitada seja zero

    return 0; // avisa o computador que o programa terminou sem erros
}