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
	int rtn = -1;
	int maxId;
	int idElegido;
	int indexEmpleadoAModificar;
	int option = 0;
	char confirm;

	Employee* empleadoAux;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;


	if(pArrayListEmployee != NULL)
	{
		if(controller_ListEmployee(pArrayListEmployee) == 0)
		{
			if(controller_getMaxIdFromText(pArrayListEmployee, &maxId) == 0
			&& PedirEntero(&idElegido, "\n-Ingrese el ID del/la empleado/a a modificar: ", "\n.ERROR! -> Ingrese un ID Valido.", 1, maxId, 4) == 0)
			{
				indexEmpleadoAModificar = controller_Find_Employee_ById(pArrayListEmployee, idElegido);

				if(indexEmpleadoAModificar != -1)
				{
					empleadoAux = ll_get(pArrayListEmployee, indexEmpleadoAModificar);
					employee_listAnEmployeeWithHeader(empleadoAux);

					controller_modifyMenu();

					if(PedirEntero(&option, "\n-Que desea modificar?: ", "\n.ERROR! -> Ingrese una opcion valida (1 - 4).", 1, 4, 6) == 0)
					{
						switch(option)
						{
							case 1:
								if(PedirString(auxNombre, 20, "\n-Ingrese el nuevo nombre del/la empleado/a: ", "\n.ERROR! -> MAX.CARACTERES: 20 - SOLO LETRAS", 4) == 0
								&& GetConfirmCharacter(&confirm, "\n-Esta seguro de que desea modificar el nombre? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
								&& confirm == 'S')
								{
									employee_setNombre(empleadoAux, auxNombre);
									rtn = 0;
								}
								break;
							case 2:
								if(PedirEntero(&auxHorasTrabajadas, "\n-Ingrese las nuevas horas trabajadas del/la empleado/a: ", "\n.ERROR! -> MIN: 100 MAX: 300", 100, 300, 4) == 0
								&& GetConfirmCharacter(&confirm, "\n-Esta seguro de que desea modificar las horas? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
								&& confirm == 'S')
								{
									employee_setHorasTrabajadas(empleadoAux, auxHorasTrabajadas);
									rtn = 0;
								}
								break;
							case 3:
								if(PedirEntero(&auxSueldo, "\n-Ingrese el nuevo sueldo del/la empleado/a: ", "\n.ERROR! -> MIN: 15K MAX: 600k", 15000, 600000, 4) == 0
								&& GetConfirmCharacter(&confirm, "\n-Esta seguro de que desea modificar el sueldo? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
								&& confirm == 'S')
								{
									employee_setSueldo(empleadoAux, auxSueldo);
									rtn = 0;
								}
								break;
						}
					}

				}else{
					rtn = 2;
				}
			}
		}
		else{
			rtn = 1;
		}
	}

    return rtn;
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
	int rtn = -1;
	int sortOption;
	int menuOption = 0;

	if(pArrayListEmployee != NULL)
	{
		controller_sortMenu();

		if(PedirEntero(&menuOption, "\n-Que desea hacer?: ", "\n.ERROR! -> Ingrese una opcion valida (1 - 5)", 1, 5, 4) == 0
		&& menuOption != 5)
		{
			if(PedirEntero(&sortOption, "\n.Eliga el criterio de ordenamiento -> 0.DESCENDENTE 1.ASCENDENTE: ", "\n.ERROR! -> Ingrese 0 o 1.", 0, 1, 4) == 0)
			{
				printf("\n-Ordenando...\n");

				switch(menuOption)
				{
					case 1:
						ll_sort(pArrayListEmployee, employee_CompareByName, sortOption);
						rtn = 0;
						break;
					case 2:
						ll_sort(pArrayListEmployee, employee_CompareById, sortOption);
						rtn = 0;
						break;
					case 3:
						ll_sort(pArrayListEmployee, employee_CompareByHorasT, sortOption);
						rtn = 0;
						break;
					case 4:
						ll_sort(pArrayListEmployee, employee_CompareBySueldo, sortOption);
						rtn = 0;
						break;
				}
			}
		}
	}

    return rtn;
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

void controller_modifyMenu()
{
	printf("\n   *************************");
	printf("\n   *  MENU DE MODIFICACION  *\n");
	printf("   *************************");
	printf("\n1. NOMBRE.\n");
	printf("2. HORAS TRABAJADAS.\n");
	printf("3. SUELDO\n");
	printf("4. CANCELAR\n");
}

void controller_sortMenu()
{
	printf("\n   *************************");
	printf("\n   *  MENU DE ORDENAMIENTO *\n");
	printf("   *************************");
	printf("\n1. Ordenar empleados por NOMBRE.\n");
	printf("2. Ordenar empleados por ID.\n");
	printf("3. Ordenar empleados por HORAS TRABAJADAS.\n");
	printf("4. Ordenar empleados por SUELDO.\n");
	printf("5. CANCELAR\n");
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

