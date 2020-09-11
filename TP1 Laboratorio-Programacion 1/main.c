#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    int opcionElegida;
    float primerNumero;
    float segundoNumero;

    /*INICIALIZAMOS LOS OPERANDOS EN CERO PARA QUE OBTENGAN UN VALOR INICIAL
            AL MOSTRARSE EN EL MENU Y TAMBIEN QUEDE MAS ESTETICO.*/
    primerNumero = 0;
    segundoNumero = 0;

    float sumaResuelta;
    float restaResuelta;
    float divisionResuelta;
    float multiplicacionResuelta;
    float factorialResueltoA;
    float factorialResueltoB;

    do
    {
        ImprimirMenu(primerNumero, segundoNumero);

        opcionElegida = ElegirOpcion();

        switch(opcionElegida)
        {
            case 1:
                primerNumero = PedirOperando("\n-Ingrese el primer operando: ");
                break;
            case 2:
                segundoNumero = PedirOperando("\n-Ingrese el segundo operando: ");
                break;
            case 3:
                sumaResuelta = CalcularSuma(primerNumero, segundoNumero);
                restaResuelta = CalcularResta(primerNumero, segundoNumero);
                divisionResuelta = CalcularDivision(primerNumero, segundoNumero);
                multiplicacionResuelta = CalcularMultiplicacion(primerNumero, segundoNumero);
                factorialResueltoA = CalcularFactorial(primerNumero);
                factorialResueltoB = CalcularFactorial(segundoNumero);

                printf("\n-Las operaciones fueron realizadas.\n\n");
                break;
            case 4:
                MostrarResultados(sumaResuelta, restaResuelta, divisionResuelta, multiplicacionResuelta, factorialResueltoA, factorialResueltoB, primerNumero, segundoNumero);
                break;
            default:
                printf("\n.Gracias por utilizar el programa...\n");

        }

        LimpiarConsola();

    }while(opcionElegida != 5);

    return 0;
}
