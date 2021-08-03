/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int temaletra(char letra, char palavra1[]){ /*Para saber se tem ou não a letra digitada na palavra*/
	int i;
	for(i=0;i<strlen(palavra1);i++){
		if(letra == palavra1[i]){
			return 1;
		}
	}
	return 0;
}

int letrasim(char letra, char mostrador1[]){ /*Para saber se a letra já foi digitada*/
	int i;
	for(i=0;i<strlen(mostrador1);i++){
		if(letra == mostrador1[i]){
			return 2;
		}
	}
	return 0;
}

int forca(char palavra1[], char mostrador1[], char dica[]){
	int contador,cont=0,i,enforcamento=0;
	char letra;

	for(i=0;i<strlen(dica);i++){     /*Printa a dica na tela*/
	    printf("%c",dica[i]);
	}
	printf("\n");
  	printf("    __________      \n");
	printf("   |          |     \n");
	printf("   |                \n");
	printf("   |                \n");
	printf("   |                \n");
	printf("   |                \n");
	printf("   |                \n");
	printf("   |                \n");
	printf("___|");

	for(i=0;i<strlen(mostrador1);i++){
		printf("%c",mostrador1[i]);
	}
	printf("\n\n");

	do{
	  	do{
	  		printf("Digite uma letra: ");
	  		cont=0;
			scanf("%c",&letra);
	  		while(getchar()!='\n')
			cont++;
	    }while((letra<'A' || letra>'Z') && (letra<'a' || letra>'z') || (cont>0));
	  	letra = toupper(letra);

	  	system("clear");

		if(temaletra(letra,palavra1) != 1){
			printf("A palavra não possui essa letra!\n");
			enforcamento++;
		}
		if(letrasim(letra,mostrador1) == 2){	
			printf("Essa letra já foi digitada!\n");
		}
		for(i=0;i<strlen(palavra1);i++){
			if(letra == palavra1[i] && mostrador1[i] =='_'){
				mostrador1[i] = palavra1[i];
			}
		}
		contador=0;
	  	for(i=0;i<strlen(palavra1);i++){       /*Para saber se o jogador ganhou*/
	    	if(palavra1[i] == mostrador1[i]){
	     		contador++;
	    	}
	  	}
	  	for(i=0;i<strlen(dica);i++){     /*Printa a dica na tela*/
	    	printf("%c",dica[i]);
	  	}
	  	printf("\n");

	  	if(enforcamento == 0){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("___|");
		}
		if(enforcamento == 1){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |         ( )    \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("___|");
		}
		if(enforcamento == 2){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |         ( )    \n");
			printf("   |          |     \n");
			printf("   |          |     \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("___|");
		}
		if(enforcamento == 3){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |         ( )    \n");
			printf("   |        / |     \n");
			printf("   |          |     \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("___|");
		}
		if(enforcamento == 4){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |         ( )    \n");
			printf("   |        / | \\  \n");
			printf("   |          |     \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("   |                \n");
			printf("___|");
		}
		if(enforcamento == 5){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |         ( )    \n");
			printf("   |        / | \\  \n");
			printf("   |          |     \n");
			printf("   |         /      \n");
			printf("   |        /       \n");
			printf("   |                \n");
			printf("___|");
		}
		if(enforcamento == 6){
	  		printf("    __________      \n");
			printf("   |          |     \n");
			printf("   |         ( )    \n");
			printf("   |        / | \\  \n");
			printf("   |          |     \n");
			printf("   |         / \\   \n");
			printf("   |        /   \\  \n");
			printf("   |                \n");
			printf("___|");
		}
	  	for(i=0;i<strlen(mostrador1);i++){
			printf("%c",mostrador1[i]);
		}
		printf("\n\n");
	}while((contador < strlen(palavra1)) && (enforcamento < 6));
  	if(enforcamento >= 6){
  		return 0;
  	}
  	else{
  		return 1;
  	}
}

int main(){
	int Na;
	srand(time(NULL));
	Na = rand()%4;
	if(Na == 0){
		char palavra1[] = "RONALDO";
		char mostrador1[] = "_______";
		char dica[] = "Dica: É o maior artilheiro brasileiro em Copas do Mundo com 15 gols!";
		forca(palavra1,mostrador1,dica);
	}
	if(Na == 1){
		char palavra1[] = "MARADONA";
		char mostrador1[] = "________";
		char dica[] = "Dica: Fez gol de mão em uma Copa do Mundo e era cheirador(Combina com o Flamengo rsrs)!";
		forca(palavra1,mostrador1,dica);		
	}
	if(Na == 2){
		char palavra1[] = "PUSKAS";
		char mostrador1[] = "______";	
		char dica[] = "Dica: O nome do prêmio de gol mais bonito do ano tem o seu nome(Sem acento)!";
		forca(palavra1,mostrador1,dica);	
	}
	if(Na == 3){
		char palavra1[] = "CRUIJFF";
		char mostrador1[] = "_______";	
		char dica[] = "Dica: Maior jogador da história da Holanda e um dos maiores da história do Barcelona!";
		forca(palavra1,mostrador1,dica);	
	}
	if(Na == 4){
		char palavra1[] = "GARRINCHA";
		char mostrador1[] = "_________";	
		char dica[] = "Dica: Conhecido por seus grandes dribles e destaque da 1ª Copa do Mundo vencida pelo Brasil!";
		forca(palavra1,mostrador1,dica);	
	}
	return 0;
}