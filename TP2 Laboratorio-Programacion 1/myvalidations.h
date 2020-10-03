/*PROTOTIPO O FIRMA*/
#ifndef MYVALIDATIONS_H
#define MYVALIDATIONS_H

/** \brief Realiza el pedido y carga de una cadena de acuerdo a un nombre o caracter de no mas de 15 caracteres.
 *
 * \param pCadena char* Direccion de memoria de la variable a cargar
 * \param mensaje char* Mensaje para el pedido de la cadena.
 * \param mensajeError char* Mensaje de error para el pedido de la cadena.
 * \return int Retorna 0 si todo salio bien.
 *
 */
int GetNombre(char* pCadena, char* mensaje, char* mensajeError);

/** \brief Realiza el pedido y carga de un caracter de confirmacion (SI O NO)
 *
 * \param mensaje[] char    Mensaje para el pedido de la cadena.
 * \param mensajeError[] char    Mensaje de error para el pedido de la cadena.
 * \return char Retorna el caracter de confirmacion cargado.
 *
 */
char GetConfirmCharacter(char mensaje[], char mensajeError[]);

#endif
