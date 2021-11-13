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
    return 1;
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
    return 1;
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

