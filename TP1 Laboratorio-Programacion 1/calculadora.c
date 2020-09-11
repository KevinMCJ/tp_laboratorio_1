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

void MostrarResultados(float sumaR, float restaR, float divisionR, float multiplicacionR, float factorialRA, float factorialRB, float numeroVerificar1, float numeroVerificar2)
{
    printf("\n---RESULTADOS---\n");
    printf("a) El resultado de A+B es: %.2f\n", sumaR);
    printf("b) El resultado de A-B es: %.2f\n", restaR);

    if(numeroVerificar1 == 0 || numeroVerificar2 == 0)
    {
        printf("c) NO es posible dividir por cero\n");
    }//SI UNO DE LOS NUMEROS DE LA OPERACION ES MAYOR A 100 MOSTRAR LA DIVISION CON 5 DECIMALES
    else if(numeroVerificar1 > 99 || numeroVerificar2 > 99)
    {
        printf("c) El resultado de A/B es: %f\n", divisionR);
    }
    else//SI NO (PRIMER O SEGUNDO OPERADOR, NO SON 0 Y TAMPOCO MAYORES A 99 MOSTRAR RESULTADO CON 2 DECIMALES
    {
        printf("c) El resultado de A/B es: %.2f\n", divisionR);
    }

    printf("d) El resultado de A*B es: %.2f\n", multiplicacionR);

    /*CUANDO SACAMOS EL FACTORIAL DE UN OPERANDO MAYOR A 34 , TIRA COMO RESULTADO ".1#F"
                        ASI QUE PONEMOS ESTO PARA ARREGLARLO EN CADA SITUACION.*/
    if(numeroVerificar1 > 34 && numeroVerificar2 >34)
    {
        printf("e) No se puede mostrar factoriales tan grandes (MAX:34).\n\n");
    }
    else if(numeroVerificar1 > 34)
    {
        printf("e) El factorial de A es: Es muy grande para mostrarlo y El factorial de b es: %.2f\n\n", factorialRB);
    }
    else if(numeroVerificar2 > 34)
    {
        printf("e) El factorial de A es: %.2f y El factorial de b es muy grande para mostrarlo.\n\n", factorialRA);
    }
    else
    {
        printf("e) El factorial de A es: %.2f y El factorial de b es: %.2f\n\n", factorialRA, factorialRB);
    }

}

void LimpiarConsola()
{
    system("pause");
    system("cls");
}
