#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pFile = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			rtn = 0;
			parser_EmployeeFromText(pFile, pArrayListEmployee);
			fclose(pFile);
		}

	}

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pFile = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			rtn = 0;
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}

    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;

	int idValido;
	char nombreValido[128];
	int horasTrabajadasValido;
	int sueldoValido;
	char confirm;

	Employee* empleadoAux;

	empleadoAux = employee_new();

	if(pArrayListEmployee != NULL && empleadoAux != NULL)
	{
		if(PedirString(nombreValido, 15, "\n-Ingrese el nombre del/la empleado/a: ", "\n.ERROR! -> MAX.CARACTERES: 20 - SOLO LETRAS", 4) == 0
		&& PedirEntero(&horasTrabajadasValido, "\n-Ingrese las horas trabajadas del/la empleado/a: ", "\n.ERROR! -> MIN: 100 MAX: 300", 100, 300, 4) == 0
		&& PedirEntero(&sueldoValido, "\n-Ingrese el sueldo del/la empleado/a: ", "\n.ERROR! -> MIN: 15K MAX: 600k", 15000, 600000, 4) == 0
		&& controller_newId(pArrayListEmployee, &idValido) == 0)
		{
			if(GetConfirmCharacter(&confirm, "\n-Esta seguro de dar de alta al empleado/a? S / N: ", ".ERROR! -> SOLO Ingrese S o N.", 4) == 0
			&& confirm == 'S')
			{
				rtn = 0;
				employee_setId(empleadoAux, idValido);
				employee_setNombre(empleadoAux, nombreValido);
				employee_setHorasTrabajadas(empleadoAux, horasTrabajadasValido);
				employee_setSueldo(empleadoAux, sueldoValido);

				ll_add(pArrayListEmployee, empleadoAux);

			}else{
				rtn = 1;
			}
		}

	}

    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int maxId;
	int idElegido;
	int indexEmpleadoAEliminar;
	char confirm;

	Employee* empleadoAux;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ListEmployee(pArrayListEmployee) == 0)
		{
			if(controller_getMaxIdFromText(pArrayListEmployee, &maxId) == 0
			&& PedirEntero(&idElegido, "\n-Ingrese el ID del/la empleado/a a eliminar: ", "\n.ERROR! -> Ingrese un ID Valido.", 1, maxId, 4) == 0)
			{
				indexEmpleadoAEliminar = controller_Find_Employee_ById(pArrayListEmployee, idElegido);

				if(indexEmpleadoAEliminar != -1)
				{
					empleadoAux = ll_get(pArrayListEmployee, indexEmpleadoAEliminar);
					employee_listAnEmployeeWithHeader(empleadoAux);

					if(GetConfirmCharacter(&confirm, "\n-Esta seguro de que desea eliminar a este empleado/a? S / N: ", "\n.ERROR! -> Solo ingrese S o N.", 4) == 0
					&& confirm == 'S')
					{
						rtn = 0;
						ll_remove(pArrayListEmployee, indexEmpleadoAEliminar);
						employee_delete(empleadoAux);

					}else{
						rtn = 3;
					}

				}else{
					rtn = 2;
				}
			}
		}else{
			rtn = 1;
		}
	}

    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee* empleadoAux = NULL;
	int len;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(len > 0)
		{
			rtn = 0;
			printf("\n -----------------------------------------------------------------\n");
			printf(" | ID   |       NOMBRE      |  HORAS TRABAJADAS |     SUELDO     |\n");
			printf(" -----------------------------------------------------------------\n");

			for(int i = 0; i < len; i++)
			{
				empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

				if(empleadoAux != NULL)
				{
					employee_listAnEmployee(empleadoAux);
				}
			}
		}
	}

    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			rtn = 0;
			parser_TextFromEmployee(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}

	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			rtn = 0;
			parser_BinaryFromEmployee(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}

	return rtn;
}

int controller_saveIdAsText(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pFile;

	if(pArrayListEmployee != NULL)
	{
		pFile = fopen("Maximo_ID_Empleado.txt", "w");

		if(pFile != NULL)
		{
			rtn = 0;
			parser_textFromId(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}

    return rtn;
}

int controller_getMaxIdFromText(LinkedList* pArrayListEmployee, int* pId)
{
	int rtn = -1;
	FILE* pFile = NULL;

	if(pArrayListEmployee != NULL)
	{
		pFile = fopen("Maximo_ID_Empleado.txt", "r");

		if(pFile != NULL)
		{
			if(parser_IdFromText(pFile, pArrayListEmployee, pId) == 0)
			{
				rtn = 0;
			}

			fclose(pFile);
		}

	}

    return rtn;
}

void controller_menuWithCounter(int len)
{
	printf("\n   *************************          ******************************");
	printf("\n   *  MENU DE OPERACIONES  *          *  EMPLEADOS CARGADOS: %-6d*\n", len);
	printf("   *************************          ******************************");
	printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado.\n");
	printf("4. Modificar datos de empleado.\n");
	printf("5. Baja de empleado.\n");
	printf("6. Listar empleados.\n");
	printf("7. Ordenar empleados.\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");
}

int controller_newId(LinkedList* pArrayListEmployee, int* newId)
{
	int rtn = -1;
	int maxId;

    if(pArrayListEmployee!=NULL)
    {
    	if(controller_getMaxIdFromText(pArrayListEmployee, &maxId) == 0)
    	{
    		rtn = 0;
    		*newId = maxId + 1;
    	}
    }

    return rtn;
}

int controller_Find_Employee_ById(LinkedList* pArrayListEmployee, int idBuscado)
{
	int rtn = -1;
	int len;
	int idObtenido;
	int i;

	Employee* empleadoAux;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i = 0; i < len; i++)
		{
			empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

			if(empleadoAux != NULL)
			{
				employee_getId(empleadoAux, &idObtenido);

				if(idBuscado == idObtenido)
				{
					rtn = ll_indexOf(pArrayListEmployee, empleadoAux);
					break; //Encontro un empleado con el id correspondiente, retorna su index.
				}
			}
		}
	}

	return rtn;
}

