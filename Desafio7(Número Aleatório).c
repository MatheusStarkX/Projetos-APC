/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

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