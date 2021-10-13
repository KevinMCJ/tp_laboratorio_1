#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief	Solicita un numero entero al usuario, luego de verificarlo guarda el resultado.
///
/// @param	Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param	El mensaje a mostrar.
/// @param	El mensaje a mostrar en caso de ERROR.
/// @param	Numero minimo aceptado.
/// @param	Numero maximo aceptado.
/// @param	Cantidad de reintentos posibles.
/// @return 0 -> si obtuvo un entero correcto | -1 en caso de ERROR.
int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// @brief	Solicita un numero flotante al usuario, luego de verificarlo guarda el resultado.
///
/// @param	Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param	El mensaje a mostrar.
/// @param	El mensaje a mostrar en caso de ERROR.
/// @param	Numero minimo aceptado.
/// @param	Numero maxiom aceptado.
/// @param	Cantidad de reintentos posibles-
/// @return	0 -> si obtuvo un flotante correcto | -1 -> en caso de ERROR.
int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
/// @brief	Solicita un string al usuario, luego de verificarlo devuelve el resultado.
///
/// @param	Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param	La longitud del array resultado.
/// @param	Mensaje a ser mostrado.
/// @param	Mensaje en caso de ERROR a ser mostrado.
/// @param	Cantidad de reintentos.
/// @return	0 -> Si se obtuvo el string correctamente | -1 -> en caso de ERROR.
int PedirString(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
/// @brief	Solicita el ingreso de un caracter de confirmacion(SI -> S | NO -> N) al usuario, luego de verificarlo devuelve el resultado.
///
/// @param 	Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param	Mensaje a ser mostrado.
/// @param	Mensaje en caso de ERROR a ser mostrado.
/// @param	Cantidad de reintentos.
/// @return	0 -> Si se obtuvo un caracter correcto  |  -1 -> En caso de ERROR.
int GetConfirmCharacter(char* confirmC, char* mensaje, char* mensajeError, int reintentos);

#endif /* INPUT_H_ */
