/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include <stdio.h>
#include<stdlib.h>

char ataque_do_jogador(){
 	char chute;
 	int cont=0;

	printf("* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("* A A                                         B B *\n");
	printf("* A A                                         B B *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("*                        C C                      *\n");
	printf("*                        C C                      *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("* D D                                         E E *\n");
	printf("* D D                                         E E *\n");
	printf("                                                   \n");
	printf("Escolha uma das letras acima para chutar: ");
	while((chute < 'A' || chute > 'E')){
		scanf("%c", &chute);
		while(getchar()!='\n'){
			cont++;
		}
		if((chute < 'A' || chute > 'E') || cont>0){
			printf("Resposta Inválida!!! Digite A,B,C,D OU E.(MAIÚSCULO)\n");
			chute='F';
			cont=0;
		}
	}		
	return chute;
}	

char defesa_da_maquina(){
	char x;
	srand(time(NULL));
	x='A' + rand()%5;
  	return x;
}

char batida1(){
	if (defesa_da_maquina() == ataque_do_jogador()){
		printf("\nDefesaaaaaa do goleeeeeirooooo\n\n");
		return 0;
	}
	else {
		printf("\nGoooooooooooooooolllllllll\n\n");
		return 1;	
	}
	return 0;
}		

char defesa_do_jogador(){
 	char pulo;
 	int cont=0;

	printf("* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("* A A                                         B B *\n");
	printf("* A A                                         B B *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("*                        C C                      *\n");
	printf("*                        C C                      *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("*                                                 *\n");
	printf("* D D                                         E E *\n");
	printf("* D D                                         E E *\n");
	printf("                                                   \n");
	printf("Escolha uma das letras acima para seu goleiro pular: ");
	while((pulo < 'A' || pulo > 'E')){
		scanf("%c", &pulo);
		while(getchar()!='\n'){
			cont++;
		}
		if((pulo < 'A' || pulo > 'E') || cont>0){
			printf("Resposta Inválida!!! Digite A,B,C,D OU E.(MAIÚSCULO)\n");
			pulo='F';
			cont=0;
		}
	}		
	return pulo;
}	

char ataque_da_maquina(){
	char y;
	srand(time(NULL));
	y='A' + rand()%5;
  	return y;
}

char batida2(){
	if (ataque_da_maquina() == defesa_do_jogador()){
		printf("\nDefesaaaaaa do goleeeeeirooooo\n\n");
		return 0; 
	}
	else {
		printf("\nGoooooooooooooooolllllllll\n\n");	
		return 1;
	}
	return 0;
}	

int cobranca(int tribo){
	int lugar1,lugar2;
  	lugar1 = batida1();
  	lugar2 = batida2();
  	if(tribo == 1){
		printf("  ___________________\n");
  		printf("  |        |        |\n");
  		printf("  |  REAL  |  BARÇA |\n");
  		printf("  |________|________|\n");
  		printf("  |        |        |\n");
  		printf("  |   %d    |   %d    |\n",lugar1,lugar2);
  		printf("  |________|________|\n");
    	printf("                     \n\n");
    }
    else{
    	printf("  ___________________\n");
  		printf("  |        |        |\n");
  		printf("  |  BARÇA |  REAL  |\n");
  		printf("  |________|________|\n");
  		printf("  |        |        |\n");
  		printf("  |   %d    |   %d    |\n",lugar1,lugar2);
  		printf("  |________|________|\n");
    	printf("                     \n\n");
    }	
	if(lugar1 == lugar2){
		return 0;
	}
	if(lugar1 > lugar2){
		return 1;
  	}
 	else{	
    	return -1;
	}
}		