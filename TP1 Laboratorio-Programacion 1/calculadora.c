/*DESAROLLO*/
#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

void ImprimirMenu(float primerNumero, float segundoNumero)
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

float PedirOperando(char texto[])
{
    float operandoFlotante;

    printf("%s", texto);
    scanf("%f", &operandoFlotante);

    return operandoFlotante;
}

int ElegirOpcion()
{
    int opcionElegida;

    printf("\n-Que desea hacer?: ");
    scanf("%d", &opcionElegida);

    while(ValidarOpcion(opcionElegida) == 0)
    {
        printf("\nERROR! Por favor ingrese una opcion valida: ");
        scanf("%d", &opcionElegida);
    }

    return opcionElegida;
}

int ValidarOpcion(int OpcionElegida)
{
    int retorno;

    retorno = 1;

    if(OpcionElegida > 5 || OpcionElegida < 1)
    {
        retorno = 0;
    }

    return retorno;
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

float CalcularDivision(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero / segundoNumero;

    return resultado;
}


float CalcularMultiplicacion(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero * segundoNumero;

    return resultado;
}

float CalcularFactorial(float numero)
{
    int i;
    float resultado;

    resultado = 1;

    for(i=numero; i>0; i--)
    {
        if(numero == 0)
        {
            resultado = 1;
        }
        else
        {
            resultado = resultado * i;
        }
    }

    return resultado;
}
