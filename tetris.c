/*TEIO*/
#include "tetris.h"


//preenche a matrix espaços vazios================================
void init(char matrix[ROWS][COLUNN] ){
    int i, j;
        for ( i = 0; i <= ROWS; i++){
            for ( j = 0; j <= COLUNN; j++){
              
               if (i == 0 || i == (ROWS) || j == 0 || j == (COLUNN)){ matrix[i][j] = '*';} //cria paredes no mapa============
              
               else 
                matrix[i][j] = ' ';
            }
            
        }
        


}
//imprimi a matrix jogo===========================================
void printMatrix(char matrix[ROWS][COLUNN]){
    int i, j;

        for ( i = 0; i <= ROWS; i++){
            for ( j = 0; j <= COLUNN; j++){
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


//===============================================
void initBar(Bloco *barra){
    
// posicao inicial do avatar
    barra->i =          0;//ROWS/2;  //faz A PECA fica em cima do mapa===============
    barra->j =          COLUNN/2;
    barra->tipo =       TIPO_I;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width =      5;
    barra->height =     1;

}

// rotacao da peca
void rotate(Bloco *bloco){
    if(bloco->orientacao == ORIENTACAO_RIGHT)
        bloco->orientacao = ORIENTACAO_UP;
    else
        bloco->orientacao++;
                                
        //inverte as dimensoes do tijolo
        int aux = bloco->width;
        bloco->width = bloco->height;
        bloco->height = aux;

        //arrumando bug cantos
        if(bloco->j < (bloco->width/2))
            bloco->j = bloco->width/2;
        else if(bloco->j > COLUNN - (bloco->width/2) - 1)
            bloco->j = COLUNN - (bloco->width/2) - 1;
}


//colisao das pecas
int collisionDetect(char matrix[ROWS][COLUNN], Bloco barra){
    int retorno = 0;

    //colisao da barra
    if((barra.i + barra.height/2) >= (ROWS -1))
        retorno = 1;

        return retorno;
    }