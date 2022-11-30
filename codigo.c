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
#include <stdio.h> // inclusao de biblioteca padrao
#include <locale.h> // inclusao de biblioteca para tradução

int main(){ // funcao main
    setlocale(LC_ALL, "Portuguese");
    
   	char nomeFilme1[30], nomeFilme2[30], opcaoIngresso;//"s" para salvar a qnt de pessoas
	int  i, qntsessao, qntpessoas, valorSessao=0, validacao = 1;//valor sessao inicial ser� 0, mas sempre q alguem entrar com o valor ele vai somando as entradas

do{
	printf("Digite a quantidade de sess�es: ");//quest�o 1
	scanf("%i", &qntsessao);
	
	if(qntsessao==2){
			validacao = 1;//
			printf("Sess�o 1:\n");
			printf("Digite o nome do filme: ");// enuciado
			scanf("%s", &nomeFilme1[30]);
			
			}else{
	printf("Sess�o inv�lida.\n");
	validacao = 0;
	}//fim else
}while(validacao != 1);//fim "do"
			
			do{	
			printf("Quantidade de pessoas: ");// enuciado
			scanf("%i", &qntpessoas);
			if(qntpessoas<10){
				printf("Quantidade inv�lida! (Min�mo 10) \n");
							}
		}while(qntpessoas < 10);
				
char sexo[qntpessoas];//declara��o da variavel nesse momento, pois � somente aqui que vamos declarar a qnt de pessoas
int idade[qntpessoas];		
		for(i=0;i<qntpessoas; i++){
		do{
			printf("Digite o sexo, F-Feminino ou M-Masculino:\n");// quest�o 3
			scanf(" %c", &sexo[i]);
			fflush(stdin);
				
				if(sexo[i]!='F'&& sexo[i]!='M'&&sexo[i]!='f'&& sexo[i]!='m'){
				printf("Sexo inv�lido!Digite novamente.\n");
			}		
		}while(sexo[i]!='F'&& sexo[i]!='M'&&sexo[i]!='f'&& sexo[i]!='m');	
		do{
			printf("Digite a idade (entre 03 e 100 anos):");
			scanf("%i", &idade[i]);
			fflush(stdin);
			
			if(idade[i]<3 || idade[i]>100){
			printf("Idade inv�lida! Digite novamente.");	
			}	
			
		}while(idade[i]<3 || idade[i]>100);//queset�o 4
		repeticao:
		printf("Digite a op��o deseja: (M) para meia entrada = R$25,00 ou (I) para inteira = R$50,00:");
		scanf("%c", &opcaoIngresso);
		fflush(stdin);
				
		switch (opcaoIngresso){
			case 'M':
				valorSessao=valorSessao+25;
				break;
			case 'I':
				valorSessao=valorSessao+50;
				break;
			default: 
			printf("Op��o inv�lida!Digite novamente.\n");
			goto repeticao;//fun��o utilizada para repeti��o, looping, n�o precisa q fale pra ele ate qnd deve repetir
		}//fim do switch case
		}//fim do for
		printf("Valor arrecadado na sess�o: %i\n", valorSessao);//somar os valores gravados das sessoes
		
		printf("Nome do filme:\n");
		scanf("%c", &nomeFilme1[30]);
		fflush(stdin);
		
		printf("A quantidade de pessoas do sexo F-feminino �: ");
		scanf("%c", &sexo[qntpessoas]);
		fflush(stdin);
		
		printf("A quantidade de pessoas do sexo M-masculino �: ");
		scanf("%c", &sexo[qntpessoas]);
		fflush(stdin);

		    
}//fim do main
