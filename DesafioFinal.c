/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
	int i,j,suecia=0;
	char chute[11];
	system("clear");
			printf("ENIGMA MORTAL:\n");
			printf("Esse é o último desafio, se você chegou até aqui, PARABÉNS!\n");
			printf("Para passar e encontrar a tumba, você deve juntar as letras expostas nas dicas do mapa para formar uma palavra!\n");
			printf("Essas letras formam o nome do jogador, que fez o gol mais bonito que o Pajé viu!\n\n");
			printf("Qual o nome encontrado:\n");
			scanf("%s", chute);
			getchar();
			for(i=0;i<11;i++){
	    		chute[i] = toupper(chute[i]);
			}
			char enigma[] = "IBRAHIMOVIC";
			for(j=0;j<11;j++){
	    		if(enigma[j] == chute[j]){
	       			suecia++;
	    		}
			}
			if(suecia == 11){
				printf("\nParabéns Laryssa Crossfit!\n");
				printf("Você completou todos os desafios e conseguiu concluir o enigma!\n");
				printf("Agora só seguir até a tumba!\n");
			}
			else{
				printf("\nPoxa exploradora!\n");
				printf("Tão perto da tumba você errou!\n");
				printf("Para chegar na tumba você precisa ganhar essa disputa!\n");
			}
			printf("\nPressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

	return 0;
}