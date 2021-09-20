#ifndef INPUT_H_
#define INPUT_H_
#include <stdlib.h>
#include <stdio.h>

/// @brief Pide al usuario el ingreso de un entero entre un rango maximo y minimo.
///
/// @param	Mensaje del ingreso.
/// @param	Mensaje del ingreso en caso de error.
/// @param	Minimo valor a ingresar.
/// @param	Maximo valor a ingresar.
/// @return	El entero ingresado entre los rangos validos.
int PedirEntero(char[], char[], int, int);

/// @brief Pregunta si un entero se encuentra entre el rango valido de ingreso.
///
/// @param	El entero a validar.
/// @param	Minimo valor aceptado.
/// @param	Maximo valor aceptado.
/// @return	-1 en caso de que el entero no se encuentre entre  el rango aceptdo - 0 en caso de exito.
int ValidarEntero(int, int, int);

/// @brief Pide al usuario el ingreso de un flotante entre un rango maximo y minimo.
///
/// @param	Mensaje del ingreso.
/// @param	Mensaje del ingreso en caso de error.
/// @param	Minimo valor a ingresar.
/// @param	Maximo valor a ingresar.
/// @return	El flotante ingresado entre los rangos validos.
float PedirFlotante(char[], char[], float, float);

/// @brief Pregunta si un flotante se encuentra entre el rango valido de ingreso.
///
/// @param	El flotante a validar.
/// @param	Minimo valor aceptado.
/// @param	Maximo valor aceptado.
/// @return	0 si el flotante se encuentra en el rango aceptado - -1 en caso de que no lo este.
int ValidarFlotante(float, float, float);

#endif /* INPUT_H_ */
