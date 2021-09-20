#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include "input.h"

void ImprimirMenuCalculadora(float, float);

float CalcularSuma(float primerNumero, float segundoNumero);

float CalcularResta(float primerNumero, float segundoNumero);

int CalcularDivision(float primerNumero, float segundoNumero, float *pResultado);

float CalcularMultiplicacion(float primerNumero, float segundoNumero);

int CalcularFactorial(float numero, float *pResultado);

void MostrarResultados(float sumaR, float restaR, float divisionR, float multiplicacionR, float factorialRA, float factorialRB, int retornoDivision, int retornoFactorialA, int retornoFactorialB);

#endif /* CALCULADORA_H_ */
