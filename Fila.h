#define max 5

typedef struct
{

    char nome[25];
    int idade;
    int ID;
    char sexo[10];
    char  *priodadeVacinacao;
    char *resposta;

} Tdados;


typedef struct Fila
{

    int inicio ;
    int fim ;
    Tdados  vetor[max+1];


} Fila ;

int buscaSequencial(Fila  *fila, char Nome[]);

void imprimirFila ( Fila *fila);

void criarFilaVazia(Fila *fila);

int enfileira (Fila *fila, Tdados dados);

int desenfileira (Fila *fila, Tdados dados);

int verificaFilaVazia (Fila *fila);




