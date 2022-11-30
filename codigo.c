/*
Integrantes:
Nome Completo: Enrique de Lima Carvalho Matrícula: UC22103250 Curso: Engenharia de Software
Nome Completo: Emanuelly de Souza Portela Matrícula: UC22200313 Curso: Análise e Desenvolvimento de Sistemas
Nome Completo: Gabrielly de Souza Portela Matrícula: UC22200274 Curso: Análise e Desenvolvimento de Sistemas
*/
#include <stdio.h> // inclusão de biblioteca padrao
#include <locale.h> // inclusão de biblioteca para tradução
#include <stdlib.h> // inclusão de biblioteca para o comando clear
#define SALA 90 // capacidade da sala - quantidade de ingressos para aquela sessao
#define SESSOES 2 // quantidade de sessões aceitas
#define INTEIRA 50.00 // valor do ingresso - inteira
#define MEIA 25.00 // valor do ingresso - meia

int main(){ // funcao main
    setlocale(LC_ALL, "Portuguese"); // comando para reconhecer acentuação

    int i = 1, j = 1, qntSessao, opcaoIngresso[SALA], qntPessoas, qntIngresso[SESSOES], idade[SALA], parar = 0; // declaração de variáveis - inteiros
    int qntMulheres[SESSOES], qntHomens[SESSOES], qntCriancas[SESSOES], qntAdolescentes[SESSOES], qntAdultos[SESSOES], qntIdosos[SESSOES]; // declaração de variáveis - inteiros
    int maioresHomens[SESSOES], maioresMulheres[SESSOES], qntInteiras[SESSOES], qntMeias[SESSOES];
    char sexo[SALA], recomecar, nomeFilme[2][30]; // declaração de variáveis - caracteres

    do{
        system("clear"); // comando para limpar o console
    printf("Digite a quantidade de sessões: ");
    scanf("%d", &qntSessao);

    if(qntSessao == SESSOES){
        do{
            fflush(stdin);
            
            recomecar = 'c';
            qntMulheres[i] = 0;
            qntHomens[i] = 0;
            qntCriancas[i] = 0;
            qntAdolescentes[i] = 0;
            qntAdultos[i] = 0;
            qntIdosos[i] = 0;
            maioresHomens[i] = 0;
            maioresMulheres[i] = 0;
            qntIngresso[i] = 0;
            qntInteiras[i] = 0;
            qntMeias[i] = 0;
               
                system("clear");
            printf("Sessão %d:\n", i);
            printf("Digite o nome do filme: ");
            fflush(stdin);
            scanf(" %[^\n]s", &nomeFilme[i]);
            
            do{
                system("clear");
            printf("Venda de ingresso:\n");
            
            do{ // SEXO
            printf("Informe o sexo(M ou F): ");
            fflush(stdin);
            scanf(" %c", &sexo[j]);
            
            if(sexo[j] == 'f' || sexo[j] == 'F'){
                qntMulheres[i]++;
            }else if(sexo[j] == 'm' || sexo[j] == 'M')
                qntHomens[i]++;
            
            if(!(sexo[j] == 'm' || sexo[j] == 'M' || sexo[j] == 'f' || sexo[j] == 'F'))
                printf("Sexo inválido, tente novamente\n");
            
            }while(!(sexo[j] == 'm' || sexo[j] == 'M' || sexo[j] == 'f' || sexo[j] == 'F'));

            do{ // IDADE
            printf("Digite a idade: ");
            scanf("%d", &idade[j]);
            
            if(idade[j] >= 3 && idade[j] <= 13)
                qntCriancas[i]++;
            else if(idade[j] >= 14 && idade[j] <= 17)
                qntAdolescentes[i]++;
            else if(idade[j] >= 18 && idade[j] <= 64)
                qntAdultos[i]++;
            else if(idade[j] >= 65 && idade[j] <= 100)
                qntIdosos[i]++;
            
            if(idade[j] < 3 || idade[j] > 100)
                printf("Idade inválida, tente novamente\n");
                
            }while(idade[j] < 3 || idade[j] > 100);

            do{ // TIPO DE INGRESSO
            printf("Ingresso:\n1. Meia(R$%.2f)\n2. Inteira(%.2f)\n", MEIA, INTEIRA);
            scanf("%d", &opcaoIngresso[j]);

            if(opcaoIngresso[j] == 1)
                qntMeias[i]++;
            else if(opcaoIngresso[j] == 2)
                qntInteiras[i]++;

            if(opcaoIngresso[j] != 1 && opcaoIngresso[j] != 2)
                printf("Opção inválida, tente novamente\n");
            }while(opcaoIngresso[j] != 1 && opcaoIngresso[j] != 2);

            if((sexo[j] == 'm' || sexo[j] == 'M') && idade[j] >= 18)
                maioresHomens[i]++;
            else if((sexo[j] == 'f' || sexo[j] == 'F') && idade[j] >= 18)
                maioresMulheres[i]++;

            qntIngresso[i]++;
            j++;
            parar = 0;

            if(qntIngresso[i] == SALA)
                printf("\nIngressos para a sessão esgotados!\n");
            else if(j == 11 || j > 20){
                printf("Digite 1 para parar ou 0 para continuar\n");
                scanf("%d", &parar);
            }
            }while(qntIngresso[i] == SALA || parar == 0);
            i++;;
        }while(qntSessao >= i);
    }else{
        printf("Erro: pressione R para recomeçar: ");
        scanf(" %c", &recomecar);
    }
    }while(recomecar == 'r' || recomecar == 'R');

    for(i = 1; i <= qntSessao; i++){
    printf("Sessão %d:\n", i);
    printf("Nome do filme: %s\n\n", nomeFilme[i]);
    printf("Quantidade de pessoas do sexo feminino: %d\n", qntMulheres[i]);
    printf("Quantidade de pessoas do sexo masculino: %d\n", qntHomens[i]);
    printf("Quantidade de ingressos vendidos: %d\n\n", qntIngresso[i]);

    printf("\tDados da Sessão\n");
    printf("Crianças: %d\n", qntCriancas[i]);
    printf("Adolescentes: %d\n", qntAdolescentes[i]);
    printf("Adultos: %d\n", qntAdultos[i]);
    printf("Idosos: %d\n\n", qntIdosos[i]);

    printf("Maiores de idade - Homens: %d\n", maioresHomens[i]);
    printf("Maiores de idade - Mulheres: %d\n\n", maioresMulheres[i]);

    printf("Ingressos - Inteiras(R$%.2f): %d\n", INTEIRA, qntInteiras[i]);
    printf("Ingressos - Meias(R$%.2f): %d\n", MEIA, qntMeias[i]);
    printf("Total arrecadado: R$%.2f\n\n", (qntInteiras[i] * INTEIRA) + (qntMeias[i] * MEIA));

    if(qntInteiras[i] > qntMeias[i])
        printf("Foram vendidos mais ingressos do tipo: inteira\n");
    else if(qntInteiras[i] < qntMeias[i])
        printf("Foram vendidos mais ingressos do tipo: meia\n");
    else if(qntInteiras[i] == qntMeias[i])
        printf("Foram vendidos a mesma quantidade de ingressos do tipo meia e inteira!\n\n");
    


    }

}