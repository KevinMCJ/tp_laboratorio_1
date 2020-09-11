/*PROTOTIPO O FIRMA*/

/** \brief -Imprimimos el menu de la calculadora con los operandos actualizados.
 *
 * \param float -Obtenemos el primer operando para actualizarlo.
 * \param float -Obtenemos el segundo operando para actualizarlo.
 * \return void -Como la funcion solo imprime un menu no retorna nada.
 *
 */
void ImprimirMenu(float, float);

/** \brief -Pedimos al usuario un operando flotante para la calculadora.
 *
 * \param texto[] char -Escribimos un string acorde a la peticion.
 * \return float -La funcion nos retorna el operando flotante pedido.
 *
 */
float PedirOperando(char texto[]);

/** \brief -Le pedimos al usuario que eliga una opcion del menu.
 *
 * \return int -La funcion nos retorna la opcion elegida y
            validada mediante la llamada de otra funcion (ValidarOpcion).
 *
 */
int ElegirOpcion();

/** \brief -Validamos la opcion elegida por el usuario.
 *
 * \param int -La opcion elegida a validar
 * \return int -Retornamos 1 si la opcion es valida o 0 en caso de que no.
 *
 */
int ValidarOpcion(int);

/** \brief -Calculamos la suma de dos operandos.
 *
 * \param float -Primer operando.
 * \param float -Segundo operando.
 * \return float -Retorna el resultado de la operacion aritmetica.
 *
 */
float CalcularSuma(float, float);

/** \brief -Calculamos la resta de dos operandos.
 *
 * \param float -Primer operando.
 * \param float -Segundo operando.
 * \return float -Retorna el resultado de la operacion aritmetica.
 *
 */
float CalcularResta(float, float);

/** \brief -Calculamos la division de dos operandos.
 *
 * \param float -Primer operando.
 * \param float -Segundo operando.
 * \return float -Retorna el resultado de la operacion aritmetica.
 *
 */
float CalcularDivision(float, float);

/** \brief -Calculamos el producto de dos operandos.
 *
 * \param float -Primer operando.
 * \param float -Segundo operando.
 * \return float -Retorna el resultado de la operacion aritmetica.
 *
 */
float CalcularMultiplicacion(float, float);

/** \brief -Calculamos el factorial de dos operandos distintos.
 *
 * \param float -Primer operando.
 * \param float -Segundo operando.
 * \return float -Retorna el factorial de un operando.
 *
 */
float CalcularFactorial(float);

/** \brief -Mostramos los resultados de cada operacion realizada, tambien mensajes en los casos de error.
 *
 * \param float -Resultado de la suma a mostrar.
 * \param float -Resultado de la resta a mostrar.
 * \param float -Resultado de la division a mostrar.
 * \param float -Resultado de la multiplicacion a mostrar.
 * \param float -Factorial del primer operando a mostrar.
 * \param float -Factorial del segundo operando a mostrar.
 * \param float -Primer operando para contemplar casos de error.
 * \param float -Segundo operando para contemplar casos de error.
 * \return void -La funcion no retorna nada ya que solo imprime textos.
 *
 */
void MostrarResultados(float, float, float, float, float, float, float, float);

/** \brief -Resetea la consola/terminal para poder ver los operandos actualizados
                y continuar con el ingreso de otras opciones.
 *
 * \return void -Con llamar a la funcion basta para realizar su funcionalidad.
 *
 */
void LimpiarConsola();
