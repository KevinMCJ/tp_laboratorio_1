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

    do
    {
        ImprimirMenu(primerNumero, segundoNumero);

        ElegirOpcion();

    }while(opcionElegida != 5);

    return 0;
}
