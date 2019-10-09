/*TEIO*/
/*jogo interativo tetris
para rodar no terminal 
para executar start .\programa.exe
Alifer da silva souza
*/
#include "tetris.h"
#include "display.h"

#define DEBUG 0

int main (){
   
    int keypressed=0;
    char matrix[ROWS][COLUNN];
    Bloco tijolo;
    
    // posicao inicial do avatar
    tijolo.i =          0;//ROWS/2;  //faz A PECA fica em cima do mapa===============
    tijolo.j =          COLUNN/2;
    tijolo.tipo =       TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width =      1;
    tijolo.height =     4;


    init(matrix);

        //apagar cursor da tela
        ShowConsoleCursor(0);
        system("cls");
        
        //rotina principal jogo=============================
        while (keypressed != ESC){


            gotoxy(0,0);

            #if DEBUG == 1
                printf("@ = (%d, %d)\n", posi, posj);
            #endif
            //desenha a peca
            switch (tijolo.orientacao){
                case ORIENTACAO_UP:
                    if(tijolo.i-3 >= 0) matrix[tijolo.i-3][tijolo.j] = PiXEL;
                    if(tijolo.i-2 >= 0) matrix[tijolo.i-2][tijolo.j] = PiXEL;
                    if(tijolo.i-1 >= 0) matrix[tijolo.i-1][tijolo.j] = PiXEL;
                    matrix[tijolo.i][tijolo.j] =   PiXEL;
            break;
                case ORIENTACAO_LEFT:
                    //outro desenho barra de lado
                    
                break;
            }

            //IMPRIME
            printMatrix(matrix);

            //APAGA A VERSAO ANTERIO DA TELA
            if(tijolo.i-3 >=0) matrix[tijolo.i-3][tijolo.j] = EMPTY;
            if(tijolo.i-2 >=0 )matrix[tijolo.i-2][tijolo.j] = EMPTY;
            if(tijolo.i-1 >=0) matrix[tijolo.i-1][tijolo.j] = EMPTY;
            matrix[tijolo.i][tijolo.j] =   EMPTY;

                if ( tijolo.i < (ROWS -2)) tijolo.i++; //faz cair ate bate no chao=========  
        
        
        //lendo teclas--------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case TECLA_AA:
                    case TECLA_a:
                    case LEFT: if(tijolo.j > 1) tijolo.j--; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(tijolo.j < (COLUNN-2)) tijolo.j++; //move para direita------------------
                        break;
            }
           
}//fim while************************************
    
    system("pause");

return 0;
}