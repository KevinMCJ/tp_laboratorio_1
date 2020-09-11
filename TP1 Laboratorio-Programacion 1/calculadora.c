/*DESAROLLO O IMPLEMENTACION*/

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
