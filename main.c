/*TEIO*/
/*jogo interativo tetris
para rodar no terminal 
para executar start .\programa.exe
Alifer da silva souza
*/
#include "tetris.h"
#include "display.h"

int main (){
    
    int posi, posj;
    char matrix[ROWS][COLUNN];
    
    // posicao inicial do avatar
    posi = 1;//ROWS/2;  //faz o '@' fica em cima do mapa===============
    posj = COLUNN/2;
    init(matrix);

        //apagar cursor da tela
        ShowConsoleCursor(0);
        system("cls");
        while (1){
            gotoxy(0,0);

            matrix[posi][posj] = '@';

            printMatrix(matrix);

            matrix[posi][posj] = ' ';

                if ( posj < COLUNN ) posi++; //faz cair ate bate no chao=========  
        }
    
    system("pause");

return 0;
}