#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include "input.h"

/// @brief Imprime el menu de una calculadora con 2 operandos actualizables.
///
/// @param	Primer Operando a mostrar.
/// @param	Segundo Operando a mostrar.
void ImprimirMenuCalculadora(float, float);

/// @brief	Calcula la suma entre dos operandos flotantes.
///
/// @param	Primer Operando.
/// @param	Segundo Operando.
/// @return	El resultado de la suma realizada.
float CalcularSuma(float, float);

/// @brief 	Calcula la resta entre dos operandos flotantes.
///
/// @param	Primer Operando.
/// @param	Segundo Operando.
/// @return	El resultado de la resta realizada.
float CalcularResta(float, float);

/// @brief Calcula la division entre dos operandos flotantes.
///
/// @param	Primer Operando.
/// @param	Segundo Operando.
/// @param	Puntero a la variable donde se almacenara el resultado de la division realizada.
/// @return	-1 en caso de error por division entre cero - 0 en caso de exito.
int CalcularDivision(float, float, float *);

/// @brief	Calcula el producto entre dos operandos flotantes.
///
/// @param	Primer Operando.
/// @param	Segundo Operando.
/// @return	El resultado de la multiplicacion realizada.
float CalcularMultiplicacion(float, float);

/// @brief	Calcula el factorial de un numero ingresado (MAX:34).
///
/// @param	Numero
/// @param	Puntero a la variable donde se almacenara el resultado del factorial realizado.
/// @return	-1 en caso de error por ser un numero negativo o mayor a 34(Maximo) - 0 en caso de exito.
int CalcularFactorial(float, float *);

/// @brief	Imprime un menu con los resultados de las operaciones realizadas o mensajes en caso de error.
///
/// @param	Resultado de la suma realizada.
/// @param	Resultado de la resta realizada.
/// @param	Resultado de la division realizada.
/// @param	Resultado del producto realizado.
/// @param	Factorial calculado del primer operando.
/// @param	Factorial calculado del segundo operando.
/// @param	Retorno de la division a analizar en caso de error.
/// @param	Retorno del factorialA para analizar el caso de error.
/// @param	Retorno del factorialB para analizar el caso de error.
void MostrarResultados(float, float, float, float, float, float, int, int, int);

#endif /* CALCULADORA_H_ */
