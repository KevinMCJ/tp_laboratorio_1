/*PROTOTIPO O FIRMA*/
#include <stdio.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

/** \brief Imprime un menu de operaciones
 *
 * \return void No retorna nada ya que solo imprime.
 *
 */
void Menu();

/** \brief Pide los datos necesarios para despues cargar un empleado en la lista.
 *
 * \param listEmployees eEmployee* Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \return int  Retorna (-1) Si hubo un error , o (0) en caso de que todo este bien y se halla cargado dicho empleado.
 *
 */
int CreateEmployee(eEmployee* listEmployees, int len);

/** \brief Le asigna a todos los elementos de la lista el valor EMPTY (0), en el campo isEmpty.
 *
 * \param listEmployees eEmployee* Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \return int  Retorna (-1) Si hubo un error , o (0) en caso de que se haya inicializado el array correctamente.
 *
 */
int InitEmployees(eEmployee* listEmployees, int len);

/** \brief Recibe los datos necesarios para cargar un empleado y los carga en la primera posicion libre de la lista.
 *
 * \param listEmployees eEmployee*  Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \param id int    ID del empleado a cargar , generado con otra funcion.
 * \param name[] char   Nombre del empleado a cargar.
 * \param lastName[] char Apellido del empleado a cargar.
 * \param salary float  Salario del empleado a cargar.
 * \param sector int Sector del empleado a cargar
 * \return int int  Retorna (-1) Si hubo un error , o (0) en caso de que todo este bien.
 *
 */
int AddEmployees(eEmployee* listEmployees, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Recibe un ID a buscar en la lista de empleados y busca si existe dentro de ella.
 *
 * \param listEmployees eEmployee* Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \param id int    ID a buscar en la lista.
 * \return int  Retorna (-1) Si el ID no es inexistente dentro de la lista , o (0) en caso de que lo halla encontrado.
 *
 */
int FindEmployeeById(eEmployee* listEmployees, int len, int id);

/** \brief Le da al usuario la opcion de modificar cualquier campo del empleado perteneciente al ID recibido.
 *
 * \param listEmployees eEmployee*  Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \param id int    ID a modificar de la lista;
 * \return int  Retorna (-1) No se encontro el ID y cancelo la operacion , o (0) en caso de que la modificacion se haya realizado correctamente.
 *
 */
int ModifyEmployee(eEmployee* listEmployees, int len, int id);

/** \brief Realiza la baja logica del empleado perteneciente al ID recibido.
 *
 * \param listEmployees eEmployee*  Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \param id int ID a eliminar de la lista
 * \return int Retorna (-1) No se encontro el ID y cancelo la operacion , o (0) en caso de que la baja se haya realizado correctamente.
 *
 */
int RemoveEmployee(eEmployee* listEmployees, int len, int id);

/*int SortEmployeesByLastNameOrSector(eEmployee* listEmployees, int len, int order);*/

/** \brief Calcula e Imprime, las estadisticas salariales de la lista de empleados.
 *
 * \param listEmployees eEmployee*  Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \return int  Return (0) if ok.
 *
 */
int PrintWageStatistics(eEmployee* listEmployees, int len);

/** \brief Busca un lugar vacio en la lista para asignarle un ID unico a un empleado a cargar.
 *
 * \param listEmployees[] eEmployee Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \return int  Retorna el nuevo ID , iniciando en 1 para quedar mas estetico.
 *
 */
int NextId(eEmployee listEmployees[], int len);

/** \brief Imprime la lista de empleados que se encuentran activos.
 *
 * \param listEmployees[] eEmployee Lista de empleados.
 * \param len int   Tamanio de la lista de empleados.
 * \return int  Return (0) if ok.
 *
 */
int PrintEmployees(eEmployee listEmployees[], int len);

/** \brief Limpia la consola/terminal para que quede mas estetico.
 *
 * \return void No retorna nada.
 *
 */
void ClearConsole();
