/*
Integrantes:
Nome Completo: Enrique de Lima Carvalho Matrícula: UC22103250 Curso: Engenharia de Software
Nome Completo: Emanuelly de Souza Portela Matrícula: UC22200313 Curso: Análise e Desenvolvimento de Sistemas
Nome Completo: Gabrielly de Souza Portela Matrícula: UC22200274 Curso: Análise e Desenvolvimento de Sistemas

Um cinema de Brasília está interessado em descobrir o perfil das pessoas
que frequentam suas sessões de filmes e, para isso, necessita analisar as informações
prestadas. Devem ser solicitados a quantidade de sessões que serão realizadas e, para cada
sessão, o nome do filme, a quantidade de pessoas que assistiram o filme, assim como, o sexo, a
idade e se foi pago inteira ou meia entrada. Para isso, algumas validações devem ser realizadas:
1. Solicite a quantidade de sessões, aceitando exatamente 2 (duas) sessões. (0,4 ponto)
2. Solicite a quantidade de pessoas que assistiram ao filme, não aceitando valor inferior
a 10 (dez). (0,4 ponto)
3. Para cada pessoa que assistiu ao filme deverá ser solicitado e validado o sexo (M -
masculino, F - Feminino) e a idade (de 3 a 100 anos) (0,4 ponto).
4. Apresentar ao usuário apenas as opções Inteira e Meia (0,4 ponto), e somar o valor
arrecadado na sessão, considerando que a inteira custa R$50,00 e a meia R$25,00 (0,4
ponto).
Após a leitura dos dados do filme, deverá ser apresentado:
5. o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de
pessoas do sexo masculino que assistiram ao filme (0,4 ponto).
6. a quantidade de pessoas, seguindo a classificação por idade indicada abaixo. (0,4 ponto).
Idade Classificação
|de 3 até 13 anos - Crianças|
|de 14 até 17 anos - Adolescentes|
|de 18 até 64 anos - Adultos|
|de 65 até 100 anos - Idosos|
7. Depois da leitura dos dados de cada sessão, deverá ser mostrada a quantidade de
pessoas maiores de idade (idade maior ou igual a 18 anos) do sexo masculino e a
quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes. (0,4
ponto).
8. Informar o valor total arrecadado em cada sessão e informar se houve mais pagamento
de inteira que de meia entrada. (0,4 ponto).
9. Dentro do contexto da atividade, pense em uma nova funcionalidade e implemente. (0,4
ponto).
*/
#include <stdio.h> // inclusão de biblioteca padrao
#include <locale.h> // inclusão de biblioteca para tradução
#include <stdlib.h> // inclusão de biblioteca para o comando clear
#define SALA 90 // capacidade da sala - quantidade de ingressos para aquela sessao
#define SESSOES 2 // quantidade de sessões aceitas
#define INTEIRA 50.00 // valor do ingresso - inteira
#define MEIA 25.00 // valor do ingresso - meia
#define PREMIUM 120.00 // valor do ingresso - Premium

int main(){ // funcao main

    setlocale(LC_ALL, "Portuguese");// comando para reconhecer acentuação

    int i = 1, j = 1, qntSessao, opcaoIngresso[SALA], qntPessoas, qntIngresso[SESSOES], idade[SALA], parar = 0; // declaração de variáveis - inteiros
    int qntMulheres[SESSOES], qntHomens[SESSOES], qntCriancas[SESSOES], qntAdolescentes[SESSOES], qntAdultos[SESSOES], qntIdosos[SESSOES]; // declaração de variáveis - inteiros
    int maioresHomens[SESSOES], maioresMulheres[SESSOES], qntInteiras[SESSOES], qntMeias[SESSOES], qntPremium[SESSOES];
    char sexo[SALA], recomecar, nomeFilme[2][30]; // declaração de variáveis - caracteres

    do{
        system("cls"); // comando para limpar o console
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
            qntPremium[i] = 0;

                system("cls");
            printf("Sessão %d:\n", i);
            printf("Digite o nome do filme: ");
            fflush(stdin);
            scanf(" %[^\n]s", &nomeFilme[i]);

            do{
                system("cls");
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
            printf("\n\t-----ATENÇÃO-----\n");
            printf("\nA OPÇÃO PREMIUM INCLUI: ENTRADA + PIPOCA MEGA + 2 REFRIGERANTES + CHOCOLATE! \n");
            printf("\n\t-------------------\n\n");
            printf("Ingresso:\n1. Meia(R$%.2f)\n2. Inteira(R$%.2f)\n3. Premium(R$%.2f) \n", MEIA, INTEIRA, PREMIUM);
            scanf("%d", &opcaoIngresso[j]);

            if(opcaoIngresso[j] == 1)
                qntMeias[i]++;
            else if(opcaoIngresso[j] == 2)
                qntInteiras[i]++;
            else if(opcaoIngresso[j] == 3)
                qntPremium[i]++;

            if(opcaoIngresso[j] != 1 && opcaoIngresso[j] != 2 && opcaoIngresso[j] != 3)
                printf("Opção inválida, tente novamente\n");
            }while(opcaoIngresso[j] != 1 && opcaoIngresso[j] != 2 && opcaoIngresso[j] != 3);

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
    printf("Ingressos - Premuum (R%.2f) : %d\n", PREMIUM, qntPremium[i]);
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
