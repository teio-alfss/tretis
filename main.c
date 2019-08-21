#include <stdio.h>
#include <stdlib.h>

#define COLUNN 60
#define ROWS   25

//preenche a matrix espaços vazios
void init(char matrix[ROWS][COLUNN] ){
    int i, j;
        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUNN; j++){
                matrix[i][j] = ' ';
            }
            
        }
        


}
//imprimi a matrix jogo
void printMatrix(char matrix[ROWS][COLUNN]){
    int i, j;

        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUNN; j++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    
}

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