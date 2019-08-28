/*TEIO*/
/*jogo interativo tetris
para rodar no terminal 
para executar start .\programa.exe
Alifer da silva souza
*/
#include "tetris.h"

int main (){
    
    int posi, posj;
    char matrix[ROWS][COLUNN];
    
    // posicao inicial do avatar
    posi = ROWS/2;
    posj = COLUNN/2;
    init(matrix);

        while (1){
            system("cls");
            matrix[posi][posj] = '@';
            printMatrix(matrix);

            matrix[posi][posj] = ' ';

                if ( posj < COLUNN ) posj++; // colisao com a parede  
        }
    
    system("pause");

return 0;
}