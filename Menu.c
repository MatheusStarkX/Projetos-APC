/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include <stdio.h>
#include<stdlib.h>

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
	printf("                                    2 - Curiosidades    \n");
	printf("                                    3 - Sair          \n\n");
	printf("Escolha: ");
	do{
		scanf("%d", &tururu);
	}while ((tururu < 1 || tururu > 3) && (getchar()!='\n'));

	while(getchar() != '\n')
	if(tururu == 1){
		printf("Só Vamo Filhão!\n\n");
	}	
	if(tururu == 2){
		do{
			printf("Curiosidades do jogo:\n\n");
			printf("Para voltar ao menu, aperte enter!\n");
			scanf("%c", &voltinha);
		}while(voltinha != '\n');
		menuzada();
	}
	if(tururu == 3){
		exit(0);
	}
	system("clear"); 
}
