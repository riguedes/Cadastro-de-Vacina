
#include "Fila.h"


void criarFilaVazia(Fila *fila)
{

    fila->inicio = 0 ;
    fila->fim = fila->inicio;

}

int enfileira (Fila *fila, Tdados dados)
{

    if(((fila->fim +1 ) % (max+1)) == fila->inicio)
    {
        printf("Fila cheia \n");
        return 0 ;
    }
    else
    {
        fila->vetor[fila->fim] = dados;
        fila->fim = (fila->fim+1) % (max+1);
        return 1 ;

    }

}

int desenfileira (Fila *fila, Tdados dados)
{
    int i ;

    if(verificaFilaVazia == 0)
    {
        printf("Erro, Pilha vazia !\n");
        return 0 ;
    }
    else
    {

        dados = fila->vetor[fila->inicio];
        fila->inicio = ( fila->inicio+1) % (max+1);

        return 1;
    }

}
void imprimirFila ( Fila *fila)
{
    printf("\n");
    int i ;

    for(i = fila->inicio ; i < fila->fim; i = ( i+1) % (max+1) )
    {
        printf("ID: %d \n", fila->vetor[i].ID );
        printf("Nome: %s \n", fila->vetor[i].nome);
        printf("Sexo: %s \n", fila->vetor[i].sexo);
        printf("Idade: %d \n", fila->vetor[i].idade);
        printf("Grupo prioritario: %s \n ",fila->vetor[i].priodadeVacinacao);
        printf("Resposta do grupo prioritario: %s \n ", fila->vetor[i].resposta);

        printf("\n");

    }

}

int verificaFilaVazia (Fila *fila)
{
    if( fila->fim == fila->inicio)
    {
        return 0;
    }
    else
    {
        return 1 ;
    }
}



int buscaSequencial(Fila *fila, char Nome[])
{
    int i ;
    int posicao ;
    int naoAchei = 0 ;


    for(i = fila->inicio ; i < fila->fim; i = ( i+1) % (max+1) )
    {
        if(strcmp (Nome, fila->vetor[i].nome) == 0)
        {
            posicao = i ;
            printf("Usuario encontrado \n");
            printf("Dados do %s \n",Nome);
            printf("ID: %d \n", fila->vetor[i].ID );
            printf("Sexo: %s \n", fila->vetor[i].sexo);
            printf("Idade: %d \n", fila->vetor[i].idade);
            printf("Grupo prioritario: %s \n ",fila->vetor[i].priodadeVacinacao);
            printf("Resposta do grupo prioritario: %s \n ", fila->vetor[i].resposta);
            printf("Posicao na Fila no quando tomou a vacina: %d \n", posicao+1);
            printf("\n");
            return posicao ;
            break ;

        }else{
            naoAchei++;
        }

    }
    if( naoAchei > 0){
        printf("%s nao encontrado \n", Nome);
        printf("\n");
    }


}
