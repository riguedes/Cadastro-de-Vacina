#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void informacao();

int main()
{
    printf("              Programa Nacional de Imunizacao          \n\n");

    Fila f1;
    Tdados dados;
    int opcao ;
    int contIdoso =0 ;
    int contSaude = 0 ;
    int contgestante = 0;
    int contGeral =0 ;
    int participantes = max ;
    int contVacinas ;

    criarFilaVazia(&f1);


    printf("Numeros Pessoas na fila para vacinacao: %d \n \n", participantes);
    printf("Digite o numero de doses de vacina disponivel ?\n");
    scanf("%d",&contVacinas);

    printf("---------------------------------------------------------------------------\n");

    if(contVacinas == 0 || contVacinas < 0 || participantes > contVacinas)  // O número de pessoas na fila não poderá ultrapassar o número de doses disponíveis em nenhum momento
    {
        printf("Programa encerrado, numeros de pessoas maior que vacinas disponiveis \n");
    }
    else
    {

        int i = 0 ;

        for(i = 0 ; i < max ; i++)
        {
            printf("\n");
            printf("Numeros de vacinas disponiveis: %d \n\n",contVacinas);
            printf("Posicao na fila para vacinacao: %d \n \n", i+1);

            dados.ID = rand() % 100 ; // criando um ID aleatorio para cada paciente

            setbuf(stdin,NULL); // limpando o buffer do teclado
            printf("Digite seu nome porfavor: ");
            gets(dados.nome);

            printf("Digite sua idade: ");
            scanf("%d",&dados.idade);

            setbuf(stdin,NULL);
            printf("Digite seu sexo: ");
            gets(dados.sexo);

            informacao();

            printf("Sua escolha porfavor: ");
            scanf("%d",&opcao);

            int resposta ;

            switch (opcao)
            {
            case 1:
                printf("\n");

                dados.priodadeVacinacao = " Idoso ";

                printf("Faz uso de algum medicamento controlado ? \n");
                printf("1 = Nao faco uso de medicamento controlado \n2 = Faco uso de medicamento controlado\n ");
                printf("Sua escolha porvafor: ");
                scanf("%d",&resposta);

                if( resposta == 1)
                {
                    dados.resposta  = " Nao faz uso de medicamento controlado";
                }
                else if( resposta == 2)
                {
                    dados.resposta = " Faco uso de medicamento controlado" ;
                }

                contIdoso++;
                break;

            case 2:

                printf("\n");

                dados.priodadeVacinacao = " Gestante ";

                printf("Pre natal esta em dia ? \n");
                printf("1 = Pre natal esta em dia \n2 = Pre natal nao esta em dia \n");
                printf("Sua escolha porvafor: ");
                scanf("%d",&resposta);

                if( resposta == 1)
                {
                    dados.resposta  = " Pre natal esta em dia ";
                }
                else if( resposta == 2)
                {
                    dados.resposta = " Pre natal nao esta em dia" ;
                }

                contgestante++;
                break;

            case 3:
                printf("\n");

                dados.priodadeVacinacao = " Profissional da saude ";

                printf("Teve algum sintoma de febre nos ultimos 30 dias? \n");
                printf("1 = Nenhum sintomas de febre \n2 = tive sintomas de febre \n");
                printf("Sua escolha porvafor: ");
                scanf("%d",&resposta);

                if( resposta == 1)
                {
                    dados.resposta  = " Nenhum sintomas de febre";
                }
                else if( resposta == 2)
                {
                    dados.resposta = " tive sintomas de febre " ;
                }

                contSaude++;
                break;

            default:
                dados.priodadeVacinacao = " Nao possui " ;
                dados.resposta = "Nao possui " ;


            }

            enfileira(&f1,dados);
            printf("\n");

            contVacinas--;
            contGeral++;




        }

        printf("\n");
        printf("Relatorio dos Vacinados \n\n");
        printf("Numero de doses restantes: %d\n", contVacinas);
        printf("Total  geral de vacinados: %d\n", contGeral);
        printf("Numeros de gestantes vacinados: %d\n", contgestante);
        printf("Numeros de profissional da saude: %d\n", contSaude);
        printf("Numeros de idosos vacinados: %d\n", contIdoso);
        printf("\n");


        char nome[70];
        int comando;

         do{
         setbuf(stdin,NULL);
         printf("Porfavor, digite um nome para pesquisar na fila:  ");
         gets(nome);

         buscaSequencial(&f1,nome);

         printf("Digite 1 para pesquisar novamente e 2 para sair \n");
         scanf("%d",&comando);
         printf("\n");

         }while(comando == 1);


       // imprimirFila(&f1);

    }

    return 0;
}

void informacao()
{
    printf("\n");
    printf("Voce faz parte de algum desses grupos prioritarios ?  \n");
    printf("1 = idoso  \n2 = gestante \n3 = profissional da saude \n4 = nao possui \n ");

}
