/*Nome: Matheus Felipe Magalhães de Assis
 *Matrícula: 19/0035242
 *Disciplina: Algoritmos e Programação de Computadores
 *E-mail: matheusfelipemdeassis@gmail.com*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
                  linha = rand()%3;
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


