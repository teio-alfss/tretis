/*TEIO*/
#include "tetris.h"


//preenche a matrix espaços vazios================================
void init(char matrix[ROWS][COLUNN] ){
    int i, j;
        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUNN; j++){
              
               if (i == 0 || i == 24 || j == 0 || j == 59){ matrix[i][j] = '*';} //cria paredes no mapa============
              
               else 
                matrix[i][j] = ' ';
            }
            
        }
        


}
//imprimi a matrix jogo===========================================
void printMatrix(char matrix[ROWS][COLUNN]){
    int i, j;

        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUNN; j++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    
}
