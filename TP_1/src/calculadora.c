#include "calculadora.h"

void ImprimirMenuConOperandos(float primerNumero, float segundoNumero)
{
	printf("\n   *************************");
	printf("\n   *      CALCULADORA      *\n");
	printf("   *************************");
	printf("\n1- Ingresar el 1er operando (A = %.2f).\n", primerNumero);
	printf("2- Ingresar el 2do operando (B = %.2f).\n", segundoNumero);
	printf("3- Calcular todas las operaciones.\n");
	printf("   a). Suma\n");
	printf("   b). Resta\n");
	printf("   c). Division\n");
	printf("   d). Multiplicacion\n");
	printf("   e). Factorial (De A y B)\n");
	printf("4- Informar resultados.\n");
	printf("5- Salir del programa.\n");
}

