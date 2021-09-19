#include "input.h"
#include "calculadora.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcionElegida;
	float primerNumero;
	float segundoNumero;

	/*INICIALIZAMOS LOS OPERANDOS EN CERO PARA QUE OBTENGAN UN VALOR INICIAL
	            AL MOSTRARSE EN EL MENU Y QUEDE MAS ESTETICO.*/
	primerNumero = 0;
	segundoNumero = 0;

	do
	{
		ImprimirMenuConOperandos(primerNumero, segundoNumero);

		opcionElegida = PedirEntero("\n-Que desea hacer?: ", "\n-ERROR! Por favor ingrese una opcion valida: ", 1, 5);

	}while(opcionElegida != 5);

	return EXIT_SUCCESS;
}
