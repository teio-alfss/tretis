/*TEIO*/
/*jogo interativo tetris
para rodar no terminal
programado em .c 

Alifer da silva souza
*/
#include <stdio.h>
#include <stdlib.h>

#define COLUNN 60
#define ROWS   25


void init(char matrix[ROWS][COLUNN]);
void printMatrix(char matrix[ROWS][COLUNN]);