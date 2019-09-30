/*TEIO*/
/*jogo interativo tetris
para rodar no terminal 
para executar start .\programa.exe
Alifer da silva souza
*/
#include "tetris.h"
#include "display.h"

int main (){
   
    int keypressed=0;
    int posi, posj;
    char matrix[ROWS][COLUNN];
    
    // posicao inicial do avatar
    posi = 0;//ROWS/2;  //faz o '@' fica em cima do mapa===============
    posj = COLUNN/2;
    init(matrix);

        //apagar cursor da tela
        ShowConsoleCursor(0);
        system("cls");
        
        //rotina principal jogo=============================
        while (keypressed != ESC){


            gotoxy(0,0);

            matrix[posi][posj] = '@';

            printMatrix(matrix);

            matrix[posi][posj] = ' ';

                if ( posi < (ROWS -2)) posi++; //faz cair ate bate no chao=========  
        
        
        //lendo teclas--------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case TECLA_AA:
                    case TECLA_a:
                    case LEFT: if(posj > 1) posj--; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(posj < (COLUNN-2)) posj++; //move para direita------------------
                        break;
            }
           
}//fim while************************************
    
    system("pause");

return 0;
}