#include "input.h"

int PedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int numeroIngresado;
	int retorno;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);
	retorno = ValidarEntero(numeroIngresado, minimo, maximo);

	while(retorno != 0)
	{
		printf("%s", mensajeError);
		scanf("%d", &numeroIngresado);
		retorno = ValidarEntero(numeroIngresado, minimo, maximo);
	}

	return numeroIngresado;
}

int ValidarEntero(int numeroAValidar, int minimo, int maximo)
{
	int retorno;

	retorno = 0;

	if(numeroAValidar < minimo || numeroAValidar > maximo)
	{
		retorno = -1;
	}

	return retorno;
}

float PedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo)
{
	float numeroIngresado;
	int retorno;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	retorno = ValidarFlotante(numeroIngresado, minimo, maximo);

	while(retorno != 0)
	{
		printf("%s", mensajeError);
		scanf("%f", &numeroIngresado);
		retorno = ValidarFlotante(numeroIngresado, minimo, maximo);
	}

	return numeroIngresado;
}

int ValidarFlotante(float numeroAValidar, float minimo, float maximo)
{
	int retorno;

	retorno = 0;

	if(numeroAValidar < minimo || numeroAValidar > maximo)
	{
		retorno = -1;
	}

	return retorno;
}


