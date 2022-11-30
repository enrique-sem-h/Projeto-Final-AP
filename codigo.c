/*
Integrantes:
Nome Completo: Enrique de Lima Carvalho Matr�cula: UC22103250 Curso: Engenharia de Software
Nome Completo: Emanuelly de Souza Portela Matr�cula: UC22200313 Curso: An�lise e Desenvolvimento de Sistemas
Nome Completo: Gabrielly de Souza Portela Matr�cula: UC22200274 Curso: An�lise e Desenvolvimento de Sistemas

Questao 9 - implementar nova funcionalidade: Implementamos o ingresso PREMIUM com valor diferenciado e combo de comida/bebida

Citacao de 2 conceitos aplicadas baseda no Livro C�digo Limpo:
1� Regra apliacada:
Capitulo 2 - regra - USE NOMES QUE REVELEM SEU PR�POSITO
Especificar o nome de uma varivavel e/ou funcao, ficando claro para outras pessoas saberem ao que se refere e sua importancia no c�digo 

2� Regra aplicada:
Capitulo 4 - regra - EXPLIQUE-SE NO C�DIGO
Quando um c�digo n�o da para ser claro e for preciso fazer um comentario, de preferencia em explicar o mesmo na declaracao do nome da funcao
 escreva exatamente como vc gostaria que tivesse no comentario, assim o codigo fica mais limpo e compreens�vel  */
 
 
#include <stdio.h> // inclus�o de biblioteca padrao
#include <locale.h> // inclus�o de biblioteca para tradu��o
#include <stdlib.h> // inclus�o de biblioteca para o comando clear
#define SALA 90 // Definir capacidade da sala - quantidade de ingressos para aquela sessao
#define SESSOES 2 // Definir quantidade de sess�es aceitas
#define INTEIRA 50.00 // Definir valor do ingresso - inteira
#define MEIA 25.00 // Definir valor do ingresso - meia
#define PREMIUM 120.00 // Definir valor do ingresso - Premium

int main(){ // funcao main

    setlocale(LC_ALL, "Portuguese");// comando para reconhecer acentua��o

    int i = 1, j = 1, qntSessao, opcaoIngresso[SALA], qntPessoas, qntIngresso[SESSOES], idade[SALA], parar = 0; // declara��o de vari�veis - inteiros
    int qntMulheres[SESSOES], qntHomens[SESSOES], qntCriancas[SESSOES], qntAdolescentes[SESSOES], qntAdultos[SESSOES], qntIdosos[SESSOES]; // declara��o de vari�veis - inteiros
    int maioresHomens[SESSOES], maioresMulheres[SESSOES], qntInteiras[SESSOES], qntMeias[SESSOES], qntPremium[SESSOES]; // declara��o de vari�veis - inteiros
    char sexo[SALA], recomecar, nomeFilme[2][30]; // declara��o de vari�veis - caracteres

    do{
        system("cls"); // comando para limpar o console
    printf("Digite a quantidade de sess�es: ");
    scanf("%d", &qntSessao);



    if(qntSessao == SESSOES){ //condicao primaria
        do{ // inicializacao do loop ref as condicoes declaradas a baixo
        
            fflush(stdin); //limpar o buffer de saida 

            recomecar = 'c'; // declara��o do caractere que ser� utilizado para reiniciar o loop
			//inicializacoes das variaveis
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
            qntPremium[i] = 0;

                system("cls"); // comando para limpar o console
            printf("Sess�o %d:\n", i);
            printf("Digite o nome do filme: ");
            fflush(stdin);
            scanf(" %[^\n]s", &nomeFilme[i]);

            do{
                system("cls"); //limpar o buffer de saida 
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
                printf("Sexo inv�lido, tente novamente\n");

            }while(!(sexo[j] == 'm' || sexo[j] == 'M' || sexo[j] == 'f' || sexo[j] == 'F'));  //verificacao para que o loop seja executado 

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
                printf("Idade inv�lida, tente novamente\n");

            }while(idade[j] < 3 || idade[j] > 100);

            do{ // TIPO DE INGRESSO
            printf("\n\t-----ATEN��O-----\n");
            printf("\nA OP��O PREMIUM INCLUI: ENTRADA + PIPOCA MEGA + 2 REFRIGERANTES + CHOCOLATE! \n"); // Questao 9 - nova funcionalidade implantada
            printf("\n\t-------------------\n\n");
            printf("Ingresso:\n1. Meia(R$%.2f)\n2. Inteira(R$%.2f)\n3. Premium(R$%.2f) \n", MEIA, INTEIRA, PREMIUM);
            scanf("%d", &opcaoIngresso[j]);

            if(opcaoIngresso[j] == 1)
                qntMeias[i]++;
            else if(opcaoIngresso[j] == 2)
                qntInteiras[i]++;
            else if(opcaoIngresso[j] == 3)
                qntPremium[i]++; // Questao 9 - nova funcionalidade implementada

            if(opcaoIngresso[j] != 1 && opcaoIngresso[j] != 2 && opcaoIngresso[j] != 3)
                printf("Op��o inv�lida, tente novamente\n");
            }while(opcaoIngresso[j] != 1 && opcaoIngresso[j] != 2 && opcaoIngresso[j] != 3);

            if((sexo[j] == 'm' || sexo[j] == 'M') && idade[j] >= 18)
                maioresHomens[i]++;
            else if((sexo[j] == 'f' || sexo[j] == 'F') && idade[j] >= 18)
                maioresMulheres[i]++;

            qntIngresso[i]++;
            j++;
            parar = 0;

            if(qntIngresso[i] == SALA)
                printf("\nIngressos para a sess�o esgotados!\n");
            else if(j == 11 || j > 20){
                printf("Digite 1 para parar ou 0 para continuar\n");
                scanf("%d", &parar);
            }
            }while(qntIngresso[i] == SALA || parar == 0);
            i++;
        }while(qntSessao >= i);
    }else{
        printf("Erro: pressione R para recome�ar: ");
        scanf(" %c", &recomecar);
    }
    }while(recomecar == 'r' || recomecar == 'R');

    for(i = 1; i <= qntSessao; i++){
    printf("Sess�o %d:\n", i);
    printf("Nome do filme: %s\n\n", nomeFilme[i]);
    printf("Quantidade de pessoas do sexo feminino: %d\n", qntMulheres[i]);
    printf("Quantidade de pessoas do sexo masculino: %d\n", qntHomens[i]);
    printf("Quantidade de ingressos vendidos: %d\n\n", qntIngresso[i]);

    printf("\tDados da Sess�o\n");
    printf("Crian�as: %d\n", qntCriancas[i]);
    printf("Adolescentes: %d\n", qntAdolescentes[i]);
    printf("Adultos: %d\n", qntAdultos[i]);
    printf("Idosos: %d\n\n", qntIdosos[i]);

    printf("Maiores de idade - Homens: %d\n", maioresHomens[i]);
    printf("Maiores de idade - Mulheres: %d\n\n", maioresMulheres[i]);

    printf("Ingressos - Inteiras(R$%.2f): %d\n", INTEIRA, qntInteiras[i]);
    printf("Ingressos - Meias(R$%.2f): %d\n", MEIA, qntMeias[i]);
    printf("Ingressos - Premuum (R%.2f) : %d\n", PREMIUM, qntPremium[i]); // Questao 9 - nova funcionalidade implantada
    printf("Total arrecadado: (R$%.2f)\n\n", (qntInteiras[i] * INTEIRA) + (qntMeias[i] * MEIA) + (qntPremium[i] * PREMIUM));

    if(qntInteiras[i] > qntMeias[i] && qntInteiras[i] > qntPremium[i]) 
        printf("Foram vendidos mais ingressos do tipo: inteira\n");
    else if(qntMeias[i] > qntInteiras[i] && qntMeias > qntPremium[i])
        printf("Foram vendidos mais ingressos do tipo: meia\n");
    else if(qntPremium[i] > qntInteiras[i] && qntPremium[i] > qntMeias)
        printf("Foram vendidos mais ingressos do tipo: Premium!\n\n");
    else{
        printf("Foram vendidos ingressos em quantidades iguais!");
    }
    }
    return 0;
}
