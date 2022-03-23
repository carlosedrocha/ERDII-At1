// A loja “Casa Bela” de artigos de decoração vende muito em prestação. E para isso deseja armazenara uma lista com os clientes pendentes.
// Como número de clientes varia constantemente, a lista deve ser implementada como usando os conceitos de lista ligada.
// As informações a serem armazenadas na lista são:

//DADOS{
// Nome do Cliente – string de no máximo 50 caracteres
// Data da Compra – uma estrutura com dia, mês e ano inteiros
// Valor da Dívida - valor real
// Número de Prestações – número inteiro
// Número de prestações já pagas – numero inteiro
//}

//FUNCOES{
// O programa deverá ter uma tela com as seguintes opções:
//
// Inserção de Novo Cliente (Se o Time conseguir, seria interessante que fosse em ordem alfabética) = NAO IMPLEMENTADO
// Remoção de um Cliente = NAO IMPLEMENTADO
// Buscar um Cliente para atualizar o número de prestações pagas. Caso seja a última prestação do Cliente, deve ser impresso um aviso e o nome dele retirado da lista = NAO IMPLEMENTADO
// Busca de um cliente – Impressão das informações com o valor do Saldo devedor, considerando que sempre serão parcelas iguais e que se houve uma entrada não foi considerada no Valor da Dívida = NAO IMPLEMENTADO
// Impressão do nome de todos os Clientes da Lista com o número de prestações que faltam pagar e o saldo devedor = NAO IMPLEMENTADO
//}


#include <stdio.h>
#include <stdlib.h>

//Definicao struct que armazena os dados dos clientes solicitados para o exercicio

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;
typedef struct dadosCliente
{
    char nomeCliente[50];
    float valorDivida;
    Data dataCompra;
    int numPrestacoes;
    int numPrestacoesPagas;
}DadosCliente;
//Definicao struct que armazena os dados do cliente junto com o encadeamento para o proximo no
typedef struct noDadosCliente
{
    DadosCliente dados;
    struct noDadosClientes* proximo;
}NoDadosCliente;

//Definicao struct que armazena o tamanho da lista formada por nos e tambem o primeiro no da lista
typedef struct lista
{
    int tam;
    NoDadosCliente* primeiroNoLista;
}Lista;


//FUNCOES//
// struct lista criarLista();
// void insereCliente(struct lista* lista);
// void solicitaDadosCliente(NoDadosCliente* no);



//Aloca e retorna ponteiro para lista
Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->tam = 0;
    lista->primeiroNoLista = NULL;

    return lista;
}

//Insere um novo no
void insereCliente(Lista* lista){
    NoDadosCliente* no = (NoDadosCliente*)malloc(sizeof(NoDadosCliente));

    solicitaDadosCliente(&no->dados);

    //Garante que o no inserido 
    no->proximo = lista->primeiroNoLista;
    lista->primeiroNoLista = no;
    lista->tam ++;
}

//Solicita e armazena os dados necessarios para satisfazer o no tipo DadosClientes 
void solicitaDadosCliente(DadosCliente* dados){
    //FAZER VERIFICACAO DE DADOS
    //scanf ("%[^\n]s",&nomeTemp);
    fflush(stdin);
    printf("\nDigite o nome do cliente: ");
    scanf ("%[^\n]%c", dados->nomeCliente);
    fflush(stdout);


    // fgets(dados->nomeCliente, 50, stdin);
    printf("%s",dados->nomeCliente);
    
    ////data
    printf("\nDigite o dia da compra: ");
    scanf("%d",&dados->dataCompra.dia);
    
    printf("\nDigite o mes da compra: ");
    scanf("%d",&dados->dataCompra.mes);
    fflush(stdin);

    
    printf("\nDigite o ano da compra: ");
    scanf("%d",&dados->dataCompra.ano);
    fflush(stdin);


    printf("\nDigite o numero de prestacoes: ");
    scanf("%d",&dados->dataCompra);
    fflush(stdin);

    printf("\nDigite o numero de prestacoes pagas: ");
    scanf("%d",&dados->numPrestacoes);
    fflush(stdin);

    printf("\nDigite o valor da divida: ");
    scanf("%f",&dados->valorDivida);
    fflush(stdin);


    printf("\n\n\tNOME: %s\n\n\tDATA: %d\n\n\tVALOR: %f",dados->nomeCliente, dados->dataCompra.dia, dados->valorDivida);

}

int main(){

    int finalizar = 0;
    int opcao;
    Lista* listaClientes = criarLista();


   do{
       printf("\n\n1 - Inserir cliente\n2 - imprimir\n3 - Inserir no fim\n3 - Imprimir tamanho da lista\n8 - Sair\n\nOpcao: ");
       scanf("%d", &opcao);
       switch(opcao){
           case 1:
                insereCliente(&listaClientes);
				break;
           case 2:
				//imprimir(&listaClientes);
				break;
           case 8:
               	printf("\nFinalizando...\n");
               	finalizar = 1;
               	break;
           default:
               	printf("Opcao invalida!\n");
       }
   } while (!finalizar);
}
    


