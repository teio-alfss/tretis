/*TEIO*/
/*jogo interativo tetris
para rodar no terminal
programado em .c 

Alifer da silva souza
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//para capturar teclas

#define COLUNN      60
#define ROWS        25
#define ESC         27
#define ARROWS      224
#define LEFT        75
#define RIGHT       77
#define TECLA_a     97
#define TECLA_d     100
#define TECLA_AA    65
#define TECLA_DD    68


void init(char matrix[ROWS][COLUNN]);
void printMatrix(char matrix[ROWS][COLUNN]);