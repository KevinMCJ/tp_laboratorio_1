#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee* empleadoAux = NULL;
	char id[100];
	char nombre[100];
	char horasTrabajadas[100];
	char sueldo[100];
	int r;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo); //Falsa lectura cabecera.

		if(esNumericaSinSigno(id, sizeof(id)) != 0)
		{
			rewind(pFile);
		}

		while(!feof(pFile))
		{
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

			if(r == 4)
			{
				empleadoAux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(empleadoAux != NULL)
				{
					ll_add(pArrayListEmployee, empleadoAux);
				}
			}
		}

		rtn = 0;
	}

    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee* empleadoAux = NULL;
	int r;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		rtn = 0;

		while(!feof(pFile))
		{
			empleadoAux = employee_new();

			if(empleadoAux != NULL)
			{
				r = fread(empleadoAux, sizeof(Employee), 1, pFile);

				if(r == 1)
				{
					ll_add(pArrayListEmployee, empleadoAux);
				}
			}
		}
	}

	return rtn;
}
