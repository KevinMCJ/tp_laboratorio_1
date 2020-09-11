/*DESAROLLO O IMPLEMENTACION*/

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
