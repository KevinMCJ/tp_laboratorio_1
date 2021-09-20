#include "calculadora.h"

void ImprimirMenuCalculadora(float primerNumero, float segundoNumero)
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

float CalcularSuma(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero + segundoNumero;

    return resultado;
}

float CalcularResta(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero - segundoNumero;

    return resultado;
}

int CalcularDivision(float primerNumero, float segundoNumero, float *pResultado)
{
    int retorno;

    retorno = -1;

    if(segundoNumero != 0)
    {
    	*pResultado = primerNumero / segundoNumero;
    	retorno = 0;
    }

    return retorno;
}


float CalcularMultiplicacion(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero * segundoNumero;

    return resultado;
}

int CalcularFactorial(float numero, float *pResultado)
{
    int i;
    int retorno;
    float factorial;

    factorial = 1;
    retorno = -1;

    if(numero >= 0 && numero < 35)
    {
    	retorno = 0;
    	for(i=numero; i>0; i--)
    	{
    		factorial = factorial * i;
    	}
    }

    *pResultado = factorial;

    return retorno;
}

void MostrarResultados(float sumaR, float restaR, float divisionR, float multiplicacionR, float factorialRA, float factorialRB, int retornoDivision, int retornoFactorialA, int retornoFactorialB)
{
	printf("\n---RESULTADOS---\n");
	printf("a) El resultado de A+B es: %.2f\n", sumaR);
	printf("b) El resultado de A-B es: %.2f\n", restaR);

	if(retornoDivision == -1)
	{
		printf("c) No es posible dividir entre cero.\n");
	}else{
		printf("c) El resultado de A/B es: %f\n", divisionR);
	}

	printf("d) El resultado de A*B es: %.2f\n", multiplicacionR);

	if(retornoFactorialA == -1 && retornoFactorialB == -1)
	{
		printf("e) No es posible calcular los factoriales de numeros negativos o mayores a 34.\n\n");
	}else if(retornoFactorialA == -1 && retornoFactorialB != -1){
		printf("e) No es posible calcular el factorial de A (Negativo o > 34)\n-> El factorial de B es: %.2f.\n\n", factorialRB);
	}else if(retornoFactorialA != -1 && retornoFactorialB == -1){
		printf("e) El factorial de A es: %.2f\n-> No es posible calcular el factorial de B (Negativo o > 34).\n\n", factorialRA);
	}else{
		printf("e) El factorial de A es: %.2f\n-> El factorial de B es: %.2f\n\n", factorialRA, factorialRB);
	}

}

