#include "input.h"
#include "calculadora.h"

//VALIDAR NO PODER DIVIDIR POR 0 Y SACAR FACTORIAL DE UN NUMERO NEGATIVO. CREO QUE YA LO RESOLVI
/*ARREGLAR PROBLEMAS CON LAS BANDERAS DEL MENU. (LITERAL PROBAR TODAS DE NUEVO Y CAMBIARLAS SI ESTAN MAL,
 * POR QUE ME EXPLOTO LA CABEZA)*/

int main(void) {

	setbuf(stdout, NULL);

	int opcionElegida;
	float primerNumero;
	float segundoNumero;

	/*INICIALIZAMOS LOS OPERANDOS EN CERO, PARA QUE OBTENGAN UN VALOR INICIAL
	AL MOSTRARSE EN EL MENU Y TAMBIEN USARLO COMO BANDERA PARA VERIFICAR QUE EL USUARIO INGRESO AL MENOS UN OPERANDO.*/
	primerNumero = 0;
	segundoNumero = 0;

	float sumaResuelta;
	float restaResuelta;
	float divisionResuelta;
	float multiplicacionResuelta;
	float factorialResueltoA;
	float factorialResueltoB;
	int retornoDivision;
	int retornoFactorialA;
	int retornoFactorialB;
	int flagCalculoOperaciones = 0;

	do
	{

		ImprimirMenuCalculadora(primerNumero, segundoNumero);

		opcionElegida = PedirEntero("\n-Que desea hacer?: ", "\n-ERROR! Por favor ingrese una opcion valida: ", 1, 5);

		//Bandera para que el usuario calcule, si decide cambiar algun operando.
		if(opcionElegida == 1 || opcionElegida == 2)
		{
			flagCalculoOperaciones = 0;
		}

		switch(opcionElegida)
		{
			case 1:
				primerNumero = PedirFlotante("\n-Ingrese el primer operando: ", "\n-ERROR!. Reingrese el primer operando (MAX: 10MILLONES | MIN: -10MILLONES): ", -10000000, 10000000);
				break;
			case 2:
				segundoNumero = PedirFlotante("\n-Ingrese el segundo operando: ", "\n-ERROR!. Reingrese el segundo operando (MAX: 10MILLONES | MIN: -10MILLONES): ", -10000000, 10000000);
				break;
			case 3:
				if(primerNumero != 0 || segundoNumero != 0)
				{
					sumaResuelta = CalcularSuma(primerNumero, segundoNumero);
					restaResuelta = CalcularResta(primerNumero, segundoNumero);
					retornoDivision = CalcularDivision(primerNumero, segundoNumero, &divisionResuelta);
					multiplicacionResuelta = CalcularMultiplicacion(primerNumero, segundoNumero);
					retornoFactorialA = CalcularFactorial(primerNumero, &factorialResueltoA);
					retornoFactorialB = CalcularFactorial(segundoNumero, &factorialResueltoB);
					flagCalculoOperaciones = 1;
					printf("\n-Las operaciones fueron realizadas correctamente.\n\n");
				}else{
					printf("\n-Por favor cargue al menos un operando antes de realizar los calculos.\n");
				}
				break;
			case 4:
				if(flagCalculoOperaciones)
				{
					MostrarResultados(sumaResuelta, restaResuelta, divisionResuelta, multiplicacionResuelta, factorialResueltoA, factorialResueltoB, retornoDivision, retornoFactorialA, retornoFactorialB);
				}else{
					printf("\n-Antes de mostrar, por favor primero calcule las operaciones.\n\n");
				}
				break;
			default:
				printf("\n.Gracias por utilizar el programa...\n\n");
		}

	}while(opcionElegida != 5);

	return EXIT_SUCCESS;
}
