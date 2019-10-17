/*TEIO*/
#include "tetris.h"


//preenche a matrix espaços vazios================================
void init(char matrix[ROWS][COLUNN] ){
    int i, j;
        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUNN; j++){
              
               if (i == 0 || i == (ROWS - 1) || j == 0 || j == 59){ matrix[i][j] = '*';} //cria paredes no mapa============
              
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



void drawBar(char matrix[ROWS][COLUNN], Bloco barra, int simbolo){

    switch (barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP:
              if(barra.i-4>=0) matrix[barra.i-4][barra.j] = simbolo; 
              if(barra.i-3>=0) matrix[barra.i-3][barra.j] = simbolo;
              if(barra.i-2>=0) matrix[barra.i-2][barra.j] = simbolo;
              if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
                matrix[barra.i][barra.j] = simbolo;
                break;
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT:
              if(barra.j+1>=0) matrix[barra.i][barra.j+1] = simbolo;
              if(barra.j+1>=0) matrix[barra.i][barra.j+2] = simbolo;
              if(barra.j+1>=0) matrix[barra.i][barra.j-2] = simbolo;
              if(barra.j+1>=0) matrix[barra.i][barra.j-1] = simbolo;
                matrix[barra.i][barra.j] = simbolo;
                break;
    }
}