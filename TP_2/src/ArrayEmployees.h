#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "input.h"

#define EMPTY 0
#define BUSY 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty; //FLAG Estado logico -> 1-OCUPADO/CARGADO | 0-VACIO.

}eEmployee;

/// @brief	Imprime el menu principal del programa.
///
void MainMenu();

/// @brief	Imprime el menu de moficiacion de datos.
///
void ModifyMenu();

/// @brief	Verifica si existe al menos un empleado cargado en la lista.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio de la lista de empleados.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [No encontro un empleado | NULL Pointer | TAM invalido].
int ThereIsAnEmployee(eEmployee* listEmployees, int len);

/// @brief	Verifica si hay un espacio disponible en la Lista.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [No encontro un espacio disponible | NULL Pointer | TAM invalido].
int ThereIsAnEmptyPlace(eEmployee* listEmployees, int len);

/// @brief	Inicializa el estado logico[isEmpty] de los elementos en el array[listEmployees] como VACIO[0-EMPTY].
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [NULL pointer | TAM Invalido].
int InitEmployee(eEmployee* listEmployees, int len);

/// @brief	Obtiene un ID para el empleado, siendo el indice del elemento +1.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @return	ID Obtenido -> En caso de EXITO  |  -1 -> En caso de ERROR [No se encontro un elemento disponible | NULL pointer | TAM invalido].
int GetNextID(eEmployee* listEmployees, int len);

/// @brief	Pide al usuario el ingreso de los datos de un empleado y lo da de alta.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [NULL pointer | TAM invalido | No se pudo dar de alta]
int CreateEmployee(eEmployee* listEmployees, int len);

/// @brief	Añade los valores recibidos por parametros a la primer posicion vacia en la lista de empleados.
///
/// @param	Lista empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	ID recibido.
/// @param	Nombre recibido.
/// @param	Apellido recibido.
/// @param	Salario recibido.
/// @param	Sector recibido.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [ NULL Pointer | TAM Invalido | No encontro un elemento vacio].
int AddEmployee(eEmployee* listEmployees, int len, int id, char* name, char* lastName, float salary, int sector);

/// @brief	Imprime los datos de un empleado.
///
/// @param	Un empleado.
void PrintEmployee(eEmployee employee);

/// @brief	Imprime los datos de los empleados cargados en la lista en un formato de tabla.
///
/// @param	Lista empleados.
/// @param	Tamanio lista empleados.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [NULL pointer | TAM invalido]
int PrintEmployees(eEmployee* listEmployees, int len);

/// @brief	Busca un empleado cargado mediante su ID y obtiene su posicion(index) en el array[listEmployees].
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	ID como parametro de busqueda.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [ID no encontrado en la lista | NULL Pointer | TAM invalido].
int FindEmployeeById(eEmployee* listEmployees, int len, int id);

/// @brief	Modifica algun dato de un empleado a eleccion del usuario, luego de una confirmacion.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	ID del empleado a modificar.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [ID no existente en la lista | NULL Pointer | TAM invalido].
int ModifyEmployee(eEmployee* listEmployees, int len, int id);

/// @brief	Elimina de manera logica (isEmpty flag en 0-VACIO) un empleado recibiendo como parametro su ID.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	ID del empleado a dar de baja.
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [ID no existente en la lista | NULL Pointer | TAM invalido].
int RemoveEmployee(eEmployee* listEmployees, int len, int id);

/// @brief	Ordena el array de empleados por apellido y sector de manera ASCENDENTE O DESCENDENTE.
///
/// @param 	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	Parametro de ordenamiento recibido. ASCENDENTE(1) - DESCENDENTE(0)
/// @return	0 -> En caso de EXITO  |  -1 -> En caso de ERROR [NULL Pointer | TAM invalido].
int SortEmployees(eEmployee* listEmployees, int len, int order);

/// @brief	Ordena el array de empleados por apellido de manera ASCENDENTE O DESCENDENTE.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	Parametro de ordenamiento recibido. ASCENDENTE(1) - DESCENDENTE(0)
void SortEmployeesByLastName(eEmployee* listEmployees, int len, int order);

/// @brief	Ordena el array de empleados por sector de manera ASCENDENTE O DESCENDENTE.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
/// @param	Parametro de ordenamiento recibido. ASCENDENTE(1) - DESCENDENTE(0)
void SortEmployeesBySector(eEmployee* listEmployees, int len, int order);

/// @brief	Calcula e Imprime las estadisticas salariales entre los empleados cargados en la lista.
///
/// @param	Lista de empleados [array].
/// @param	Tamanio lista de empleados.
void PrintSalaryStadistics(eEmployee* listEmployees, int len);

#endif /* ARRAYEMPLOYEES_H_ */
