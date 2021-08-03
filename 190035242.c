/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char entrada_valida(){   
  	int cont;
	char resposta;
	do{
		printf("Anda aí bb: ");
	    cont = 0;
		scanf("%c", &resposta);
		while(getchar()!='\n')
			cont++;
	} while(((resposta != 'w') && (resposta != 'a') && (resposta != 's') && (resposta != 'd') && (resposta != 'm') &&
            (resposta != 'W') && (resposta != 'A') && (resposta != 'S') && (resposta != 'D') && (resposta != 'M')) || (cont > 0));
	return resposta;
}

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

int velhasenhora(){
	int sla=0,i,j,fim=0,linha,coluna,m,n,x,y;/*'m' e 'n' posição do jogador ,'x' e 'y' posição da máquina e 'fim' número de jogadas(Vai até 9 no máximo).*/
	char velha[10][25] = {
		{' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ','2',' ',' ',' ',' ',' ',' ',' ','3',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '},
		{'1',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_'},
		{' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '},
		{'2',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','|','_','_','_','_','_','_','_','_'},
		{' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '},
		{'3',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' '}
	};
	for(j=0;j<10;j++){
		for(i=0;i<24;i++){
			printf("%c",velha[j][i]);
		}
		printf("\n");
	}
	do{
		do{ /*Vez do jogador*/
			printf("\nSelecione a linha desejada: ");
			do{
				scanf("%d", &linha);
			}while ((linha < 1 || linha > 3) && (getchar()!='\n'));
			printf("Selecione a coluna desejada: ");
			do{
				scanf("%d", &coluna);
			}while ((coluna < 1 || coluna > 3) && (getchar()!='\n'));

			if(linha == 1){
				m = 2;
			}
			if(linha == 2){
				m = 5;
			}
			if(linha == 3){
				m = 8;
			}
			if(coluna == 1){
				n = 4;
			}
			if(coluna == 2){
				n = 12;
			}
			if(coluna == 3){
				n = 20;
			}
			if(velha[m][n] == 'X' || velha[m][n] == 'O'){
				printf("Essa posição está ocupada!");
			}	
		}while(velha[m][n] != ' ');
		velha[m][n] = 'X';
		fim++;
		system("clear");
		for(j=0;j<10;j++){
			for(i=0;i<24;i++){
				printf("%c",velha[j][i]);
			}
			printf("\n");
		}
		if(fim == 9){
			break;
		}
		/*Para saber se o jogador ganhou na horizontal*/
		if(velha[2][4]==velha[2][12] && velha[2][12]==velha[2][20] && velha[2][20]=='X'){
			sla++;
			break;
		}
		if(velha[5][4]==velha[5][12] && velha[5][12]==velha[5][20] && velha[5][20]=='X'){
			sla++;
			break;
		}
		if(velha[8][4]==velha[8][12] && velha[8][12]==velha[8][20] && velha[8][20]=='X'){
			sla++;
			break;
		}
		/*Para saber se o jogador ganhou na vertical*/
		if(velha[2][4]==velha[5][4] && velha[5][4]==velha[8][4] && velha[8][4]=='X'){
			sla++;
			break;
		}
		if(velha[2][12]==velha[5][12] && velha[5][12]==velha[8][12] && velha[8][12]=='X'){
			sla++;
			break;
		}
		if(velha[2][20]==velha[5][20] && velha[5][20]==velha[8][20] && velha[8][20]=='X'){
			sla++;
			break;
		}
		/*Para saber se o jogador ganhou na diagonal*/
		if(velha[2][4]==velha[5][12] && velha[5][12]==velha[8][20] && velha[8][20]=='X'){
			sla++;
			break;
		}
		if(velha[2][20]==velha[5][12] && velha[5][12]==velha[8][4] && velha[8][4]=='X'){
			sla++;
			break;
		}
		do{ /*Vez da máquina*/
			/*Analisa se pode ganhar na horizontal*/
      		if(velha[2][4]==velha[2][12] && velha[2][12]=='O'){
        		x=2;
        		y=20;
     		}
     		else if(velha[2][4]==velha[2][20] && velha[2][20]=='O'){
     			x=2;
     			y=12;
     		}
     		else if(velha[2][12]==velha[2][20] && velha[2][20]=='O'){
     			x=2;
     			y=4;
     		}
     		else if(velha[5][4]==velha[5][12] && velha[5][12]=='O'){
     			x=5;
     			y=20;
     		}
     		else if(velha[5][4]==velha[5][20] && velha[5][20]=='O'){
     			x=5;
     			y=12;
     		}
     		else if(velha[8][12]==velha[8][20] && velha[8][20]=='O'){
     			x=8;
     			y=4;
     		}
     		else if(velha[8][4]==velha[8][12] && velha[8][12]=='O'){
     			x=8;
     			y=20;
     		}
     		else if(velha[8][4]==velha[8][20] && velha[8][20]=='O'){
     			x=8;
     			y=12;
     		}
     		else if(velha[8][12]==velha[8][20] && velha[8][20]=='O'){
     			x=8;
     			y=4;
     		}
     		/*Analisa se pode ganhar na vertical*/
     		else if(velha[2][4]==velha[5][4] && velha[5][4]=='O'){
     			x=8;
     			y=4;
     		}
     		else if(velha[2][4]==velha[8][4] && velha[8][4]=='O'){
     			x=5;
     			y=4;
     		}
     		else if(velha[5][4]==velha[8][4] && velha[8][4]=='O'){
     			x=2;
     			y=4;
     		}
    		else if(velha[2][12]==velha[5][12] && velha[5][12]=='O'){
     			x=8;
     			y=12;
     		}
     		else if(velha[2][12]==velha[8][12] && velha[8][12]=='O'){
     			x=5;
     			y=12;
     		}
     		else if(velha[5][12]==velha[8][12] && velha[8][12]=='O'){
     			x=2;
     			y=12;
     		}
     		else if(velha[2][20]==velha[5][20] && velha[5][20]=='O'){
     			x=8;
     			y=20;
     		}
     		else if(velha[2][20]==velha[8][20] && velha[8][20]=='O'){
     			x=5;
     			y=20;
     		}
     		else if(velha[5][20]==velha[8][20] && velha[8][20]=='O'){
     			x=2;
     			y=20;
     		}
     		/*Analisa se pode ganhar na diagonal*/
     		else if(velha[2][4]==velha[5][12] && velha[5][12]=='O'){
     			x=8;
     			y=20;
     		}
     		else if(velha[2][4]==velha[8][20] && velha[8][20]=='O'){
     			x=5;
     			y=12;
     		}
     		else if(velha[5][12]==velha[8][20] && velha[8][20]=='O'){
     			x=2;
     			y=4;
     		}
     		else if(velha[2][20]==velha[5][12] && velha[5][12]=='O'){
     			x=8;
     			y=4;
     		}
     		else if(velha[2][20]==velha[8][4] && velha[8][4]=='O'){
     			x=5;
     			y=12;
     		}
     		else if(velha[5][12]==velha[8][4] && velha[8][4]=='O'){
     			x=2;
     			y=20;
     		}
     		/*Analisa se o jogador irá ganhar na horizontal*/
     		else if(velha[2][4]==velha[2][12] && velha[2][12]=='X'){
        		x=2;
        		y=20;
     		}
     		else if(velha[2][4]==velha[2][20] && velha[2][20]=='X'){
     			x=2;
     			y=12;
     		}
     		else if(velha[2][12]==velha[2][20] && velha[2][20]=='X'){
     			x=2;
     			y=4;
     		}
     		else if(velha[5][4]==velha[5][12] && velha[5][12]=='X'){
     			x=5;
     			y=20;
     		}
     		else if(velha[5][4]==velha[5][20] && velha[5][20]=='X'){
     			x=5;
     			y=12;
     		}
     		else if(velha[8][12]==velha[8][20] && velha[8][20]=='X'){
     			x=8;
     			y=4;
     		}
     		else if(velha[8][4]==velha[8][12] && velha[8][12]=='X'){
     			x=8;
     			y=20;
     		}
     		else if(velha[8][4]==velha[8][20] && velha[8][20]=='X'){
     			x=8;
     			y=12;
     		}
     		else if(velha[8][12]==velha[8][20] && velha[8][20]=='X'){
     			x=8;
     			y=4;
     		}
     		/*Analisa se o jogador irá ganhar na vertical*/
     		else if(velha[2][4]==velha[5][4] && velha[5][4]=='X'){
     			x=8;
     			y=4;
     		}
     		else if(velha[2][4]==velha[8][4] && velha[8][4]=='X'){
     			x=5;
     			y=4;
     		}
     		else if(velha[5][4]==velha[8][4] && velha[8][4]=='X'){
     			x=2;
     			y=4;
     		}
    		else if(velha[2][12]==velha[5][12] && velha[5][12]=='X'){
     			x=8;
     			y=12;
     		}
     		else if(velha[2][12]==velha[8][12] && velha[8][12]=='X'){
     			x=5;
     			y=12;
     		}
     		else if(velha[5][12]==velha[8][12] && velha[8][12]=='X'){
     			x=2;
     			y=12;
     		}
     		else if(velha[2][20]==velha[5][20] && velha[5][20]=='X'){
     			x=8;
     			y=20;
     		}
     		else if(velha[2][20]==velha[8][20] && velha[8][20]=='X'){
     			x=5;
     			y=20;
     		}
     		else if(velha[5][20]==velha[8][20] && velha[8][20]=='X'){
     			x=2;
     			y=20;
     		}
     		/*Analisa se o jogador irá ganhar na diagonal*/ 
     		else if(velha[2][4]==velha[5][12] && velha[5][12]=='X'){
     			x=8;
     			y=20;
     		}
     		else if(velha[2][4]==velha[8][20] && velha[8][20]=='X'){
     			x=5;
     			y=12;
     		}
     		else if(velha[5][12]==velha[8][20] && velha[8][20]=='X'){
     			x=2;
     			y=4;
     		}
     		else if(velha[2][20]==velha[5][12] && velha[5][12]=='X'){
     			x=8;
     			y=4;
     		}
     		else if(velha[2][20]==velha[8][4] && velha[8][4]=='X'){
     			x=5;
     			y=12;
     		}
     		else if(velha[5][12]==velha[8][4] && velha[8][4]=='X'){
     			x=2;
     			y=20;
     		}
	      	else{
		        srand(time(NULL));
		        linha = rand()%2;
		        srand(time(NULL));
		        coluna = rand()%2;
		        if(linha == 0){
		          x = 2;
		        }
		        if(linha == 1){
		          x = 5;
		        }
		        if(linha == 2){
		          x = 8;
		        }
		        if(coluna == 0){
		          y = 4;
		        }
		        if(coluna == 1){
		          y = 12;
		        }
		        if(coluna == 2){
		          y = 20;
		        }
			}  
		}while(velha[x][y] != ' ');
		velha[x][y] = 'O';
		fim++;
		system("clear");
		for(j=0;j<10;j++){
			for(i=0;i<24;i++){
				printf("%c",velha[j][i]);
			}
			printf("\n");
		}
		/*Para saber se a máquina ganhou na horizontal*/
		if(velha[2][4]==velha[2][12] && velha[2][12]==velha[2][20] && velha[2][20]=='O'){
			sla--;
			break;
		}
		if(velha[5][4]==velha[5][12] && velha[5][12]==velha[5][20] && velha[5][20]=='O'){
			sla--;
			break;
		}
		if(velha[8][4]==velha[8][12] && velha[8][12]==velha[8][20] && velha[8][20]=='O'){
			sla--;
			break;
		}
		/*Para saber se a máquina ganhou na vertical*/
		if(velha[2][4]==velha[5][4] && velha[5][4]==velha[8][4] && velha[8][4]=='O'){
			sla--;
			break;
		}
		if(velha[2][12]==velha[5][12] && velha[5][12]==velha[8][12] && velha[8][12]=='O'){
			sla--;
			break;
		}
		if(velha[2][20]==velha[5][20] && velha[5][20]==velha[8][20] && velha[8][20]=='O'){
			sla--;
			break;
		}
		/*Para saber se a máquina ganhou na diagonal*/
		if(velha[2][4]==velha[5][12] && velha[5][12]==velha[8][20] && velha[8][20]=='O'){
			sla--;
			break;
		}
		if(velha[2][20]==velha[5][12] && velha[5][12]==velha[8][4] && velha[8][4]=='O'){
			sla--;
			break;
		}
	}while(fim<9);
	if(sla > 0){	
		return 1;
	}
	if(sla < 0){	
		return -1;
	}	
	if(sla == 0){
		return 0;
	}
}

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

int cobranca(int tribo, int *bat1, int *bat2){
	int b1,b2;
	b1 = batida1();
	b2 = batida2();
  	*bat1 += b1;
  	*bat2 += b2;
  	if(tribo == 1){
		printf("  ___________________\n");
  		printf("  |        |        |\n");
  		printf("  |  REAL  |  BARÇA |\n");
  		printf("  |________|________|\n");
  		printf("  |        |        |\n");
  		printf("  |   %d    |   %d    |\n",*bat1,*bat2);
  		printf("  |________|________|\n");
    	printf("                     \n\n");
    }
    else{
    	printf("  ___________________\n");
  		printf("  |        |        |\n");
  		printf("  |  BARÇA |  REAL  |\n");
  		printf("  |________|________|\n");
  		printf("  |        |        |\n");
  		printf("  |   %d    |   %d    |\n",*bat1,*bat2);
  		printf("  |________|________|\n");
    	printf("                     \n\n");
    }	
	if(b1 == b2){
		return 0;
	}
	if(b1 > b2){
		return 1;
  	}
 	else{	
    	return -1;
	}
}		

int numaleatorio(){
	int Na,Ne,Nt=20;
	srand(time(NULL));
	Na = rand()%1000;
	printf("Digite um número entre 0 e 1000:\n");
	while((Ne != Na) && (Nt > 0)){
		do{
			scanf("%d", &Ne);
		}while((Ne < 0 || Ne > 1000) && (getchar()!='\n'));
    	if(Ne < 0 || Ne > 1000){
     		printf("O número está entre 0 e 1000 lerdão!\n");
    	}
		Nt--;
		if((Nt == 5) && (Ne != Na)){
			printf("Tu é ruim mana!\n");
		}
		if(Ne < Na){
			printf("Maior que %d!\n", Ne);
		}
		if(Ne > Na){
			printf("Menor que %d!\n", Ne);
		}
		if(Ne == Na){
			printf("Boa filhona!!!\n");
		}
	}
	if(Nt == 0){
		return 0;
	}
	else{
		return 1;
	}
	return 0;
}

void menuzada(){
	int tururu;
	char voltinha;
	system("clear");
	printf("   ##     ## ######## ##     ## ######## #########    ###    #######      ###         ######### ##     ## ########   \n");
	printf("   ###   ### ##       ###   ### ##             ###   ## ##   ##    ##    ## ##        ##        ##     ##    ##      \n");
	printf("   #### #### ##       #### #### ##           ###    ##   ##  ##     ##  ##   ##       ##        ##     ##    ##      \n");
	printf("   ## ### ## #####    ## ### ## #####       ###    ##     ## ##     ## ##     ##      ######    ##     ##    ##      \n");
	printf("   ##     ## ##       ##     ## ##        ###      ######### ##     ## #########      ##        ##     ##    ##      \n");
	printf("   ##     ## ##       ##     ## ##       ###       ##     ## ##    ##  ##     ##      ##        ##     ##    ##      \n");
	printf("   ##     ## ######## ##     ## ######## ######### ##     ## #######   ##     ##      ##         #######     ##    \n\n");
	printf("                                    1 - Jogar           \n");
	printf("                                    2 - Sair          \n\n");
	printf("Escolha: ");
	do{
		scanf("%d", &tururu);
	}while ((tururu < 1 || tururu > 2) && (getchar()!='\n'));

	while(getchar() != '\n')
	if(tururu == 1){
		printf("Só Vamo Filhão!\n\n");
	}	
	if(tururu == 2){
		exit(0);
	}
	system("clear"); 
}

int main(){
	char again;
	do{
	int A,na,i,j,l=11,c=2,galo,tribo,vida=5,bat1=0,bat2=0,vs,forquinha1,forquinha2,forquinha3,corda,suecia=0;
	int cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0,cont7=0,contfinal=0;
	int ast1=0,ast2=0,ast3=0,ast4=0,ast5=0,ast6=0,ast7=0,ast8=0,ast9=0,ast10=0,ast11=0,ast12=0,ast13=0,ast14=0,ast15=0;
	char mov,chute[11],mapinha[23][92] = {
		/*Linha 1*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		/*Linha 2*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','*',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','*',' ','#'},
		/*Linha 3*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#'},	 	
		/*Linha 4*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ','#'},
		/*Linha 5*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','!',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'}, 
		/*Linha 6*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#'},
		/*Linha 7*/
	{'#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','!',' ',' ',' ','*',' ',' ','!',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		/*Linha 8*/
	{'#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#'}, 
 		/*Linha 9*/
	{'#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#'}, 
	 	/*Linha 10*/
	{'#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#'},	 
	 	/*Linha 11*/
	{'#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',
	 ' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#'},
	 	/*Linha 12*/
	{'#',' ',' ',' ',' ','?','!',' ',' ',' ',' ',' ','*',' ','#','#','#','#','#','#','#','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','!',' ',' ',' ',
	 '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','?','!',' ',' ','*',' ','!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','C','!',' ',' ','W',' ',' ','#'}, 
	 	/*Linha 13*/
	{'#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',
	 ' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#'}, 
	 	/*Linha 14*/
	{'#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#'},
		/*Linha 15*/ 
	{'#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#'},
		/*Linha 16*/ 
	{'#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#'},
		/*Linha 17*/    
	{'#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','!',' ',' ',' ','*',' ',' ','!',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#'}, 
	 	/*Linha 18*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','!',' ',' ','*',' ',' ','#','#','#','#','#','#','#','#'}, 
	 	/*Linha 19*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#'}, 
	 	/*Linha 20*/
	{'#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}, 
	 	/*Linha 21*/
	{'#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		/*Linha 22*/ 
	{'#','#','#','#','#','#','#','#','#','#','#','#',' ','*',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','*',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},  
	 	/*Linha 23*/
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'} 
	};

	system("clear");
	printf("Bem vindo ao jogo Memezada Fut!\n");
	printf("Esse jogo foi baseado no filme India Joanes e o Mistério de Piraporinha, feito pela consagrada empresa de jogos CALANGUINHO GAMES!\n");
	printf("Nesse jogo você controla a personagem Laryssa Crossfit e deve desvendar,se for capaz, os segredos da tumba do Pajé Moacir dos Milagres!\n");
	printf("A tumba é escondida e para encontra-la você tem que passar por um perigoso e sombrio labirinto, projetado pelo Pajé antes da sua morte!\n");
	printf("Um enigma mortal protege a tumba, e para passa-lo você deve prestar atenção nas dicas do mapa, que daram uma letra do enigma!\n");
	printf("Tudo o que sabemos sobre o Pajé é que ele amava futebol e adorava memes!\n");
	printf("Boa sorte, porque você vai precisar, e que a força esteja com você!\n\n");

	printf("Pressione Enter para começar o jogo!\n");
	while(getchar()!='\n');
	system("clear");
	printf("   ##     ## ######## ##     ## ########   \n");
	printf("   ###   ### ##       ###   ### ##         \n");
	printf("   #### #### ##       #### #### ##         \n");
	printf("   ## ### ## #####    ## ### ## #####      \n");
	printf("   ##     ## ##       ##     ## ##         \n");
	printf("   ##     ## ##       ##     ## ##         \n");
	printf("   ##     ## ######## ##     ## ######## \n\n");
	usleep(500000);
	system("clear");
	printf("   ##     ## ######## ##     ## ######## #########    ###    #######      ###      \n");
	printf("   ###   ### ##       ###   ### ##             ###   ## ##   ##    ##    ## ##     \n");
	printf("   #### #### ##       #### #### ##           ###    ##   ##  ##     ##  ##   ##    \n");
	printf("   ## ### ## #####    ## ### ## #####       ###    ##     ## ##     ## ##     ##   \n");
	printf("   ##     ## ##       ##     ## ##        ###      ######### ##     ## #########   \n");
	printf("   ##     ## ##       ##     ## ##       ###       ##     ## ##    ##  ##     ##   \n");
	printf("   ##     ## ######## ##     ## ######## ######### ##     ## #######   ##     ## \n\n");
	usleep(500000);
	system("clear");
	printf("   ##     ## ######## ##     ## ######## #########    ###    #######      ###         ######### ##     ## ########   \n");
	printf("   ###   ### ##       ###   ### ##             ###   ## ##   ##    ##    ## ##        ##        ##     ##    ##      \n");
	printf("   #### #### ##       #### #### ##           ###    ##   ##  ##     ##  ##   ##       ##        ##     ##    ##      \n");
	printf("   ## ### ## #####    ## ### ## #####       ###    ##     ## ##     ## ##     ##      ######    ##     ##    ##      \n");
	printf("   ##     ## ##       ##     ## ##        ###      ######### ##     ## #########      ##        ##     ##    ##      \n");
	printf("   ##     ## ##       ##     ## ##       ###       ##     ## ##    ##  ##     ##      ##        ##     ##    ##      \n");
	printf("   ##     ## ######## ##     ## ######## ######### ##     ## #######   ##     ##      ##         #######     ##    \n\n");
	usleep(500000);
	printf("                                    1 - Jogar           \n");
	printf("                                    2 - Sair          \n\n");
	printf("Escolha:\n");
	menuzada();
  	mapinha[l][c] = '@';
  	printf("VIDA: %d\n", vida);
	for(j=0;j<23;j++){
	    for(i=0;i<92;i++){
	        if(i==0 || i==91 || j==0 || j==22){
	        	printf("#");           
	        }	      
            else{
	        	if(((i<c-4 && i>0) || (i>c+4 && i<91)) || ((j<l-2 && j>0) || (j>l+2 && j<22))){	 	
	        		printf(" ");
	        	}
                else{
                  printf("%c", mapinha[j][i]);
                }
            }  
	    }	 
        printf("\n");      
	}
	
	while((mapinha[11][88] != '@') && (vida>0)){
	    mov = entrada_valida();
	    if(mov == 'w' || mov == 'W'){
	      	if(mapinha[l-1][c] == '#'){
	        	printf("Jogada inválida\n");
	      	}	
	      	else{
	          	mapinha[l][c] = ' ';
		        l-=1;
		        mapinha[l][c] = '@';
		        system("clear"); 		  
	      	}
	    }
	    if(mov == 's' || mov == 'S'){
	      	if(mapinha[l+1][c] == '#'){
	        	printf("Jogada inválida\n");
	      	}	
	     	else{
	        	mapinha[l][c] = ' ';
	        	l +=1;
	        	mapinha[l][c] = '@';
	        	system("clear"); 
	      	}  
	    }
	    if(mov == 'a' || mov == 'A'){
	      	if(mapinha[l][c-1] == '#' || mapinha[l][c-1] == '!'){
	        	printf("Jogada inválida\n");
	      	}	
	      	else{
	        	mapinha[l][c] = ' ';
	        	c-=1;
	        	mapinha[l][c] = '@';
	        	system("clear"); 
	      	}   
	    }
	    if(mov == 'd' || mov == 'D'){
	      	if(mapinha[l][c+1] == '#' || mapinha[l][c+1] == '!'){
	        	printf("Jogada inválida\n");
	      	}
	      	else{	
	        	mapinha[l][c] = ' ';
	        	c+=1;
	        	mapinha[l][c] = '@';
	        	system("clear"); 
	      	} 
	    }
	    if(mov == 'm' || mov == 'M'){
	    	menuzada();
	    }
		if(('@' == mapinha[11][5]) && (cont1 == 0)){ /*Não conta como desafio, coloquei só de zoas*/
			mapinha[11][6] = ' ';
			cont1++;
			system("clear"); 
		  	printf("Esse é o primeiro desafio do jogo!\n");
		  	printf("Como o pajé teve bastante trabalho pra projetar essa tumba,ele quer saber se você \n");
		  	printf("é digno de desvendar os próximos mistérios e desafios com uma pergunta bem simples:\n");
		  	printf("Quem é o maior e melhor time de Minas Gerais?\n\n");
		  	printf(" 1-Atlético-MG\n");
		  	printf(" 2-Cruzeiro\n\n");
		  	printf("Pense bem na resposta...\n\n");
		  	do{
				scanf("%d", &galo);
			}while((galo < 1 || galo > 2) && (getchar()!='\n'));	
		  	system("clear"); 
		  	if(galo == 1){
		  		printf("Excelente Laryssa!\n");
		  		printf("Acredito em você para desvendar os mistérios do labirinto!\n\n");
		  	}
		  	if(galo == 2){
		  		printf("Estou desapontado com você!\n");
		  		printf("Pensei que você fosse inteligente o bastante para solucionar esse desafio.\n");
		  		printf("Tomara que perca sua horrível!\n\n");
		  		vida--;
		  	}
    	}
		if('@' == mapinha[11][41] && (cont4 == 0)){
			bat1=0;
			bat2=0;
			system("clear");
			printf("Esse é o desafio Pênalti Mortal!\n");
			printf("O Pajé amava uma disputa de pênaltis(quando não era o time dele jogando),\n");
			printf("e por isso colocou no meio do mapa uma disputa, entre as tribos Real e Barça.\n");
			printf("Para passar o desafio você precisa apenas ganhar as penalidades!\n");
			printf("Você deseja jogar por qual tribo?\n\n");
			printf(" 1-Real\n");
		  	printf(" 2-Barça\n\n");
		  	do{
				scanf("%d", &tribo);
			}while((tribo < 1 || tribo > 2) && (getchar()!='\n'));

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			A = cobranca(tribo,&bat1,&bat2) + cobranca(tribo,&bat1,&bat2) + cobranca(tribo,&bat1,&bat2) + cobranca(tribo,&bat1,&bat2) + cobranca(tribo,&bat1,&bat2);

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if (A < 0){
	  			printf("Você perdeu o desafio Pênalti Mortal!\n");
	  			printf("Para passar continuar o labirinto você precisa ganhar essa disputa!\n\n");
	  			vida--;
	  			mapinha[11][41] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}	
			if(A > 0){
				mapinha[11][42] = ' ';
				cont4++;
				printf("Parabéns exploradora!\n");
				printf("Você ganhou o desafio Pênalti Mortal!\n");
				printf("Siga sua jornada rumo a tumba, com certeza você a encontrará!\n");
			}
			if (A == 0){
				printf("Você empatou a disputa, dessa forma não perderá vida, contudo para passar o desafio você precisa ganha-lo!\n\n");
				mapinha[11][41] = '?';
				c-=1;
				mapinha[l][c] = '@';
			}
		}
		if(('@' == mapinha[17][77]) && (cont7 == 0)){
			system("clear");
			printf("Esse é o desafio Sorte Azar.\n");
			printf("O pajé achava que se alguém chegou até aqui é porque ele tem sorte ou habilidade, ou os dois.\n");
			printf("Mostre que você tem essas duas competências.\n");
			printf("Nesse desafio, você deve adivinhar um número entre 0 e 1000 escolhido aleatoriamente.\n\n");
			na = numaleatorio();

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(na == 0){
				printf("Vergonha...Desgraça...Humilhação para toda uma raça!\n");
				printf("Você perdeu o desafio Sorte Azar!\n");
				printf("Para continuar o labirinto você precisa ganhar essa disputa!\n\n");
				vida--;
				mapinha[17][77] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}
			if(na == 1){
				printf("Excelente exploradora!\n");
				printf("Você ganhou o desafio Sorte Azar!\n");
				printf("Siga seu rumo ao encontro da tumba!\n");
				mapinha[17][78] = ' ';
				cont7++;
			}
		}
		if(('@' == mapinha[4][77]) && (cont6 == 0)){
			system("clear");
			printf("Esse é o desafio Velha Senhora!\n");
			printf("Um dos times preferidos do Pajé na Europa era a Juventus,também conhecido como a Velha Senhora.\n");
			printf("Devido a isso, o Pajé colocou no labirinto um jogo da velha, onde você, Laryssa Crossfit,deve ganhar da\n");
			printf("Velha Senhora, uma poderosa força da selva que almeja destruir todas os desafiantes mais novos que ela.\n");
			printf("Mostre-se capaz de passar pela Velha e continue o seu caminho.\n\n");
			vs = velhasenhora();

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(vs == 1){
				printf("Muito bom, Laryssa Crossfit!\n");
				printf("Você passou do desafio Velha Senhora!\n");
				printf("Continue assim e conseguirá encontrar a tumba!\n");
				mapinha[4][78] = ' ';
				cont6++;
			}
			if(vs == -1){
				printf("Hahaha a Velha te puniu bonito exploradora!\n");
				printf("Você perdeu o desafio Velha Senhora!\n");
				printf("Para continuar o labirinto você precisa ganhar essa disputa!\n\n");
				vida--;
				mapinha[4][77] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}
			if(vs == 0){
				printf("Você empatou a disputa, dessa forma não perderá vida, contudo para passar o desafio você precisa ganha-lo!\n\n");
				mapinha[4][77] = '?';
				c-=1;
				mapinha[l][c] = '@';
			}
		}
		if(('@' == mapinha[6][20]) && (cont2 == 0)){
			system("clear");
			printf("Esse é o desafio Ancião dos Fut!\n");
			printf("O Pajé além de amante do futebol, gostava dos recordes e jogadores lendários.\n");
			printf("Por isso, ele colocou no mapa um desafio histórico do futebol por meio de uma forca, em que você terá que descobrir\n");
			printf("o nome que o Ancião do Futebol escolheu, baseado na dica dele.\n");
			printf("OBS: Se olhar na internet é Corno!!!\n");
			printf("Vai na fé exploradora!\n\n");
			srand(time(NULL));
			forquinha1 = rand()%2;

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(forquinha1 == 0){
				char palavra1[] = "RONALDO";
				char mostrador1[] = "_______";
				char dica[] = "Dica: É o maior artilheiro brasileiro em Copas do Mundo com 15 gols!";
				corda = forca(palavra1,mostrador1,dica);
			}
			if(forquinha1 == 1){
				char palavra1[] = "PUSKAS";
				char mostrador1[] = "______";	
				char dica[] = "Dica: O nome do prêmio de gol mais bonito do ano tem o seu nome(Sem acento)!";
				corda = forca(palavra1,mostrador1,dica);	
			}
			if(forquinha1 == 2){
				char palavra1[] = "MALDINI";
				char mostrador1[] = "_______";	
				char dica[] = "Dica: Considerado o maior zagueiro da história do futebol e seu grande time foi o Milan!";
				corda = forca(palavra1,mostrador1,dica);	
			}

			printf("\nPressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(corda == 1){
				printf("Boa aventureira!\n");
				printf("Você passou do desafio Ancião dos Fut!\n");
				printf("Continue seu caminho rumo a tumba!\n");
				mapinha[6][21] = ' ';
				mapinha[6][28] = ' ';
				cont2++;
			}
			if(corda == 0){
				printf("Poxa exploradora!\n");
				printf("Você perdeu o desafio Ancião dos Fut!\n");
	  			printf("Para continuar o labirinto você precisa ganhar essa disputa!\n\n");
	  			vida--;
	  			mapinha[6][20] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}
		}
		if(('@' == mapinha[16][20]) && (cont3 == 0)){
			system("clear");
			printf("Esse é o desafio Ancião dos Fut!\n");
			printf("O Pajé além de amante do futebol, gostava dos recordes e jogadores lendários.\n");
			printf("Por isso, ele colocou no mapa um desafio histórico do futebol por meio de uma forca, em que você terá que descobrir\n");
			printf("o nome que o Ancião do Futebol escolheu, baseado na dica dele.\n");
			printf("OBS: Se olhar na internet é Corno!!!\n");
			printf("Vai na fé exploradora!\n\n");
			srand(time(NULL));
			forquinha2 = rand()%2;

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(forquinha2 == 0){
				char palavra1[] = "MARADONA";
				char mostrador1[] = "________";
				char dica[] = "Dica: Fez gol de mão em uma Copa do Mundo e era cheirador(Combina com o Flamengo rsrs)!";
				corda = forca(palavra1,mostrador1,dica);		
			}
			if(forquinha2 == 1){
				char palavra1[] = "CRUIJFF";
				char mostrador1[] = "_______";	
				char dica[] = "Dica: Maior jogador da história da Holanda e um dos maiores da história do Barcelona!";
				corda = forca(palavra1,mostrador1,dica);	
			}
			if(forquinha2 == 2){
				char palavra1[] = "GARRINCHA";
				char mostrador1[] = "_________";	
				char dica[] = "Dica: Conhecido por seus grandes dribles e destaque da 1ª Copa do Mundo vencida pelo Brasil!";
				corda = forca(palavra1,mostrador1,dica);	
			}
			printf("\nPressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(corda == 1){
				printf("Boa aventureira!\n");
				printf("Você passou do desafio Ancião dos Fut!\n");
				printf("Continue seu caminho rumo a tumba!\n");
				mapinha[16][21] = ' ';
				mapinha[16][28] = ' ';
				cont3++;
			}
			if(corda == 0){
				printf("Poxa exploradora!\n");
				printf("Você perdeu o desafio Ancião dos Fut!\n");
	  			printf("Para continuar o labirinto você precisa ganhar essa disputa!\n\n");
	  			vida--;
	  			mapinha[16][20] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}
		}
		if(('@' == mapinha[11][66]) && (cont5 == 0)){
			system("clear");
			printf("Esse é o desafio Ancião dos Fut!\n");
			printf("O Pajé além de amante do futebol, gostava dos recordes e jogadores lendários.\n");
			printf("Por isso, ele colocou no mapa um desafio histórico do futebol por meio de uma forca, em que você terá que descobrir\n");
			printf("o nome que o Ancião do Futebol escolheu, baseado na dica dele.\n");
			printf("OBS: Se olhar na internet é Corno!!!\n");
			printf("Vai na fé exploradora!\n\n");
			srand(time(NULL));
			forquinha3 = rand()%2;

			printf("Pressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(forquinha3 == 0){
				char palavra1[] = "SHEVCHENKO";
				char mostrador1[] = "__________";
				char dica[] = "Dica: Considerado o melhor jogador da história da Ucrânia!";
				corda = forca(palavra1,mostrador1,dica);		
			}
			if(forquinha3 == 1){
				char palavra1[] = "MATTHAUS";
				char mostrador1[] = "________";	
				char dica[] = "Dica: Primeiro melhor jogador do mundo e possui o melhor nome alemão!";
				corda = forca(palavra1,mostrador1,dica);	
			}
			if(forquinha3 == 2){
				char palavra1[] = "DESCHAMPS";
				char mostrador1[] = "_________";	
				char dica[] = "Dica: Francês campeão da Copa do Mundo como treinador e jogador!";
				corda = forca(palavra1,mostrador1,dica);	
			}
			printf("\nPressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");

			if(corda == 1){
				printf("Boa aventureira!\n");
				printf("Você passou do desafio Ancião dos Fut!\n");
				printf("Continue seu caminho rumo a tumba!\n");
				mapinha[11][67] = ' ';
				mapinha[11][72] = ' ';
				cont5++;
			}
			if(corda == 0){
				printf("Poxa exploradora!\n");
				printf("Você perdeu o desafio Ancião dos Fut!\n");
	  			printf("Para continuar o labirinto você precisa ganhar essa disputa!\n\n");
	  			vida--;
	  			mapinha[11][66] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}
		}
		if(('@' == mapinha[11][84]) && (contfinal == 0)){
			system("clear");
			printf("    ######## ##     ## ## ######### ##     ##    ###       ##     ##  #######  ########  ########   ###    ##         \n");
			usleep(400000);
			printf("    ##       ###    ## ## ##     ## ###   ###   ## ##      ###   ### ##     ## ##     ##    ##     ## ##   ##         \n");
			usleep(400000);
			printf("    ##       ####   ## ## ##        #### ####  ##   ##     #### #### ##     ## ##     ##    ##    ##   ##  ##         \n");
			usleep(400000);
			printf("    #####    ## ##  ## ## ##   #### ## ### ## ##     ##    ## ### ## ##     ## ########     ##   ##     ## ##         \n");
			usleep(400000);
			printf("    ##       ##   #### ## ##    ##  ##     ## #########    ##     ## ##     ## ##   ##      ##   ######### ##         \n");
			usleep(400000);
			printf("    ##       ##    ### ## ##    ##  ##     ## ##     ##    ##     ## ##     ## ##    ##     ##   ##     ## ##         \n");
			usleep(400000);
			printf("    ######## ##     ## ## ########  ##     ## ##     ##    ##     ##  #######  ##     ##    ##   ##     ## ######## \n\n");
			printf("Esse é o último desafio, se você chegou até aqui, PARABÉNS!\n");
			printf("Para passar e encontrar a tumba, você deve juntar as letras expostas nas dicas do mapa para formar uma palavra!\n");
			printf("Essas letras formam o nome do jogador que fez o gol mais bonito que o Pajé viu!\n\n");
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
				mapinha[11][85] = ' ';
				contfinal++;
			}
			else{
				printf("\nPoxa exploradora!\n");
				printf("Tão perto da tumba você errou!\n");
				printf("Para chegar na tumba você precisa ganhar essa disputa!\n");
				vida--;
	  			mapinha[11][84] = '?';
	  			c-=1;
	  			mapinha[l][c] = '@';
			}
			printf("\nPressione Enter para continuar!\n");
			while(getchar()!='\n');
			system("clear");
		}
		printf("VIDA: %d\n", vida);
	    for(j=0;j<23;j++){
	        for(i=0;i<92;i++){
	        	if(i==0 || i==91 || j==0 || j==22){
	        		printf("#");           
	        	}	      
              	else{
	        		if(((i<c-3 && i>0) || (i>c+3 && i<91)) || ((j<l-2 && j>0) || (j>l+2 && j<22))){	 	
	        			printf(" ");
	        		}
                	else{
                  		printf("%c", mapinha[j][i]);
                	}
              	}  
	        }	 
            printf("\n");      
	    }
	    if('@' == mapinha[1][71] && (ast1 == 0)){
			printf("\nPalmeiras não tem Mundial!\n");
			printf("(A verdade global).\n\n");
			mapinha[1][71] = ' ';
			ast1++;
		}
	    if('@' == mapinha[1][89] && (ast2 == 0)){
	    	printf("\nDICA: B!\n");
			printf("Que Deus perdoe essas pessoas ruins!\n");
			printf("Imperador,Adriano(Didico para os íntimos).\n\n");
			mapinha[1][89] = ' ';
			ast2++;
		}
	    if('@' == mapinha[4][48] && (ast3 == 0)){
	    	printf("\nDICA: R!\n");
			printf("Eai fake!\n");
			printf("Saudades do que a gente não viveu ainda!\n");
			printf("Menino Ney.\n\n");
			mapinha[4][48] = ' ';
			ast3++;
		}  
	    if('@' == mapinha[4][81] && (ast4 == 0)){
	    	printf("\nDICA: A!\n");
			printf("Ce vai sentar na cabeçsss!\n");
			printf("Menino Ney.\n\n");
			mapinha[4][81] = ' ';
			ast4++;
		}  
	    if('@' == mapinha[6][25] && (ast5 == 0)){
			printf("\nTinha dica aqui?\n");
			printf("Que merda hein? Sabia não!!\n");
			printf("Marinho(Atual jogador do Santos).\n\n");
			mapinha[6][25] = ' ';
			ast5++;
		}  
	    if('@' == mapinha[11][12] && (ast6 == 0)){
	    	printf("\nDICA: H!\n");
			printf("Maria Eu sei que você Tremeee,sempre que o Galo vai jogar...\n");
			printf("(Torcida do Galo para os cruzeirenses).\n\n");
			mapinha[11][12] = ' ';
			ast6++;
		} 
		if('@' == mapinha[11][24] && (ast7 == 0)){
			printf("\nDICA: I!\n");
			printf("Hã, Quer namorar comigo???\n");
			printf("Gaúcho,Ronaldinho(O Bruxo).\n\n");
			mapinha[11][24] = ' ';
			ast7++;
		}   
		if('@' == mapinha[11][46] && (ast8 == 0)){
			printf("\nDICA: M!\n");
			printf("Entre brigar e bater o pênalti, eu prefiro ajudar na briga!\n");
			printf("Fabiano,Luís(Fabuloso).\n\n");
			mapinha[11][46] = ' ';
			ast8++;
		}    
		if('@' == mapinha[11][58] && (ast9 == 0)){
			printf("\nDICA: O!\n");
			printf("Tão deixando a gente sonhar!\n");
			printf("Gaúcho,Ronaldinho(O Bruxo).\n\n");
			mapinha[11][58] = ' ';
			ast9++;
		}
		if('@' == mapinha[11][70] && (ast10 == 0)){
			printf("\nDICA: V!\n");
			printf("Atacante matador só precisa de uma oportunidade!\n");
			printf("Victor,Paulo(Calouro em Mecatrônica,Futuro chuteira de ouro e melhor do mundo).\n\n");
			mapinha[11][70] = ' ';
			ast10++;
		}
		if('@' == mapinha[16][25] && (ast11 == 0)){
			printf("\nDICA: I!\n");
			printf("É impressionante como vocês querem me derrubarr!\n");
			printf("Imperador,Adriano(Didico para os íntimos).\n\n");
			mapinha[16][25] = ' ';
			ast11++;
		} 
		if('@' == mapinha[17][81] && (ast12 == 0)){
			printf("\nUm Corinthiano roubou essa dica!\n\n");
			mapinha[17][81] = ' ';
			ast12++;
		} 
		if('@' == mapinha[18][48] && (ast13 == 0)){
			printf("\nDICA: C!\n");
			printf("Repórter: Ronaldo, repercutiu muito nas suas férias aquela foto na piscina...\n");
			printf("Ronaldinho: Invejosooo!\n");
			printf("Gaúcho,Ronaldinho(O Bruxo).\n\n");
			mapinha[18][48] = ' ';
			ast13++;
		} 
		if('@' == mapinha[21][13] && (ast14 == 0)){
			printf("\nA Crefisa comprou essa dica!\n\n");
			mapinha[21][13] = ' ';
			ast14++;
		} 
		if('@' == mapinha[21][73] && (ast15 == 0)){
			printf("\nDICA: I!\n");
			printf("Ôo Carille, para com essa conversa mole, vai dar, vai dar... NÃO VAI DARRR!\n");
			printf("Neto(Comentarista da Band).\n\n");
			mapinha[21][73] = ' ';
			ast15++;
		}                                           
  	}
  	system("clear");
  	if(vida <= 0){
  		printf("A exploradora perdeu todas as suas vidas e morreu definitivamente,ou seja, você perdeu, fracassado(a)!\n");
  		printf("Entretanto, você pode ressucitar ela e começar o jogo novamente!\n");
  	}
  	else{
  		printf("Parabéns,excelente,maravilhoso,wonderfull,perfeito,muito bem exploradora Laryssa Crossfit!\n");
  		printf("Você passou dos desafios do labirinto e conseguiu solucionar o enigma final do Pajé!\n");
  		printf("Na tumba estava escondido um tesouro incalculável, que agora pertence a você!\n\n");
  		printf("                                                           #                        \n");
  		usleep(400000);
  		printf("   #########     ###    ########     ###    #########  ######## ##    ##  #######   \n");
  		usleep(400000);
		printf("   ##      ##   ## ##   ##     ##   ## ##   ##      ## ##       ###   ## ##         \n");
		usleep(400000);
		printf("   ##      ##  ##   ##  ##     ##  ##   ##  ##      ## ##       ####  ## ##         \n");
		usleep(400000);
		printf("   #########  ##     ## ########  ##     ## #########  #####    ## ## ##  ######    \n");
		usleep(400000);
		printf("   ##         ######### ##   ##   ######### ##      ## ##       ##  ####       ##   \n");
		usleep(400000);
		printf("   ##         ##     ## ##    ##  ##     ## ##      ## ##       ##   ###       ##   \n");
		usleep(400000);
		printf("   ##         ##     ## ##     ## ##     ## #########  ######## ##    ##  ######  \n\n");
  	}
  	printf("\nPressione Enter para continuar!\n");
	while(getchar()!='\n');
	system("clear");
  	printf("   ##     ## ######## ##     ## ######## #########    ###    #######      ###         ######### ##     ## ########   \n");
	printf("   ###   ### ##       ###   ### ##             ###   ## ##   ##    ##    ## ##        ##        ##     ##    ##      \n");
	printf("   #### #### ##       #### #### ##           ###    ##   ##  ##     ##  ##   ##       ##        ##     ##    ##      \n");
	printf("   ## ### ## #####    ## ### ## #####       ###    ##     ## ##     ## ##     ##      ######    ##     ##    ##      \n");
	printf("   ##     ## ##       ##     ## ##        ###      ######### ##     ## #########      ##        ##     ##    ##      \n");
	printf("   ##     ## ##       ##     ## ##       ###       ##     ## ##    ##  ##     ##      ##        ##     ##    ##      \n");
	printf("   ##     ## ######## ##     ## ######## ######### ##     ## #######   ##     ##      ##         #######     ##    \n\n");
	printf("                                    1 - Jogar Novamente \n");
	printf("                                    2 - Sair          \n\n");
	printf("Escolha: ");
  	do{
		scanf("%c", &again);
	}while ((again < '1' || again > '2') && (getchar()!='\n'));

	}while(again == '1');

	return 0;
}	