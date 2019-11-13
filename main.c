/*TEIO*/
/*jogo interativo tetris
para rodar no terminal 
para executar start .\programa.exe
***Alifer da silva souza***
*/
#include "tetris.h"
#include "display.h"

#define DEBUG 1

int main (){
    char matrix[ROWS][COLUNN];   
    Bloco tijolo;
    int keypressed=0;
    
    //apagar cursor da tela
        ShowConsoleCursor(0);
        system("cls");
   
    initBar(&tijolo);

    init(matrix);

        
        
        //rotina principal jogo=============================
        while (keypressed != ESC){
            gotoxy(0,0);

            #if DEBUG == 1
                printf("posicao = (%d,%d)\n",tijolo.i, tijolo.j);
                printf("dimensao = (%d,%d)\n",tijolo.width, tijolo.height);
            #endif
            
            //coloca o @ no meio da tela
            drawBar(matrix, tijolo, PiXEL);

            //mostro a matrix na tela
            printMatrix(matrix);

            //apaga a posicao anterior
            if(!collisionBar(matrix, tijolo, NOME, NOME)) {
                drawBar(matrix, tijolo, EMPTY);
                          
                //para o @ ir para direita
                if(tijolo.i < (ROWS-1) ) tijolo.i++;
            
            }else{
                initBar(&tijolo);
            }

        //lendo teclas-------------------------------------------------------------------------------------------------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case (int) 'a':
                    case (int) 'A': 
                    case LEFT: if(!collisionBar(matrix, tijolo, CHECK_SIDE, LEFT)) tijolo.j--; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(!collisionBar(matrix, tijolo, CHECK_SIDE, RIGHT)) tijolo.j++;  //move para direita------------------
                        break;
                    
                    case TECLA_ESPACO:
                        rotate(&tijolo);
                        break;
                    
                        
            }
           
}//fim while************************************
    
    system("pause");

return 0;
}