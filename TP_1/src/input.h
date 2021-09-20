#ifndef INPUT_H_
#define INPUT_H_
#include <stdlib.h>
#include <stdio.h>

int PedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);

int ValidarEntero(int numeroAValidar, int minimo, int maximo);

float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo);

int ValidarFlotante(float numeroAValidar, float minimo, float maximo);

#endif /* INPUT_H_ */
