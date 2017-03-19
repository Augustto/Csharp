#include <stdio.h> 
#include <locale.h>
#include <string.h>

/*! \brief O programa � um question�rio de perguntas sobre Java realizado em C.
* \file Quiz.c
*
* Foi utilizada estrutura de dados e aloca��o din�mica de mem�ria
*
* Foi utilizada na estrutura de dados uma lista ligada com mem�ria din�mica
*
*\autor Felipe Augusto RA: 20417054
*\date 28-11-2016
*\version 1
*
*/

typedef struct prova{
		char perg[800];
		char resp;
		struct prova* prox;
}p;

void main(){

    FILE *prova; 
    FILE *arqPontuacao;
	setlocale(LC_ALL, "Portuguese");

	struct prova *primeiro;
	struct prova *atual;
	
	char nome[20];
	int pontuacao;
	
	primeiro = (p*) malloc(sizeof(p));
	
	atual = primeiro;
	
//Aqui � realizada a leitura das quest�es do arquivo

	char ch;
    int i;
    int j;
    
    prova = fopen ("questoes.txt", "r");
      
	for(i=0;i<30;i +=1){
    
    	for(j=0;j<700;j+=1){
    		atual->perg[j]= '\0';
		}
		atual->resp='\0';
		
   	j=0;
		while((ch=fgetc(prova))!= '*'){
				atual->perg[j] = ch;
				j++;
		}
		ch=fgetc(prova);
		atual->resp = ch;
		
		atual->prox = (p*) malloc(sizeof(p));
		atual = atual->prox;
	}
		
//Escolhendo o n�vel que o aluno pode jogar

    printf("Informe o seu RA: \n");
    scanf("%s", &nome);
    
    printf("\nOl� %s! Divirta-se!\n", &nome);
    
    arqPontuacao = fopen(strcat(nome,".txt"), "w");
    
    fflush(stdin);

	int nivel;
    printf("\nEscolha o n�vel de dificuldade:\n1 - F�cil\n2 - M�dio\n3 - Dif�cil\n\n");
    scanf("%d", &nivel);    
    
    if(nivel==1){
    	atual = primeiro;
	printf("\n");
	char alternativa;
	for(i =0;i<10;i +=1){
		j=0;
		while(atual->perg[j] != '\0'){
				printf("%c", atual->perg[j]);
				j++;
		}
		fflush(stdin); 
		scanf("%c", &alternativa);
		if(atual->resp == alternativa){
			printf("\nParab�ns, voc� acertou!");
			pontuacao++;
		}else{
			printf("\nVoc� errou!");
		}
		printf("\nAlternativa certa: %c \n", atual->resp);
		atual = atual->prox;
	}
	}
	
	else if(nivel == 2){
		atual = primeiro;
		
		int i;
		for(i=0;i<10;i++){
			atual = atual->prox;
		}
		
	printf("\n");
	char alternativa;
	for(i =10;i<20;i +=1){
			j=0;
		while(atual->perg[j]!= '\0'){
				printf("%c", atual->perg[j]);
				j++;
		}
		fflush(stdin); 
		scanf("%c", &alternativa);
		if(atual->resp== alternativa){
			printf("\nParab�ns, voc� acertou!");
			pontuacao++;
		}else{
			printf("\nVoc� errou!");
		}
		printf("\nAlternativa certa: %c \n", atual->resp);
		atual = atual->prox;
	}
	}
	
	else if(nivel == 3){
		
			atual = primeiro;
		
		int i;
		for(i=0;i<20;i++){
			atual = atual->prox;
		}
		
	printf("\n");
	char alternativa;
	for(i =20;i<30;i +=1){
		j=0;
		while(atual->perg[j] != '\0'){
				printf("%c", atual->perg[j]);
				j++;
		}
		fflush(stdin); 
		scanf("%c", &alternativa);
		if(atual->resp == alternativa){
			printf("\nParab�ns, voc� acertou!");
			pontuacao++;
		}else{
			printf("\nVoc� errou!");
		}
		printf("\nAlternativa certa: %c \n", atual->resp);
		atual = atual->prox;
	}
	}
		pontuacao += 48;
		fputc(pontuacao,arqPontuacao);
} 

