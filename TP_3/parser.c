#include "parser.h"

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

int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int len;
	Employee* empleadoAux;
	int idAux;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		rtn = 0;
		len = ll_len(pArrayListEmployee);

		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n"); //Imprime el encabezado

		for(int i = 0; i < len; i++)
		{
			empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

			if(empleadoAux != NULL)
			{
				if(employee_getId(empleadoAux, &idAux) == 0 && employee_getNombre(empleadoAux, nombreAux) == 0
				&& employee_getHorasTrabajadas(empleadoAux, &horasTrabajadasAux) == 0 && employee_getSueldo(empleadoAux, &sueldoAux) == 0)
				{
					fprintf(pFile, "%d,%s,%d,%d\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
				}
			}
		}
	}

	return rtn;
}

int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
    int len;
    Employee* empleadoAux;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
    	rtn = 0;
        len = ll_len(pArrayListEmployee);

		for(int i = 0; i < len ; i++)
		{
			empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

			if(empleadoAux != NULL)
			{
				fwrite(empleadoAux, sizeof(Employee), 1, pFile);
			}
		}
    }

    return rtn;
}

int parser_IdFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* pId)
{
	int rtn = -1;
	char idConseguido[51];

	if(pFile != NULL && pArrayListEmployee != NULL && pId != NULL)
	{
		rtn = 0;
		fgets(idConseguido, 51, pFile);
		*pId = atoi(idConseguido);
	}

	return rtn;
}

int parser_textFromId(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int maxId = 0;
	int idAux;
	int len;

	Employee* empleadoAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		rtn = 0;
		len = ll_len(pArrayListEmployee);

		for(int i = 0; i < len; i++)
		{
			empleadoAux = ll_get(pArrayListEmployee, i);

			if(empleadoAux != NULL)
			{
				employee_getId(empleadoAux, &idAux);

				if(idAux > maxId || i == 0)
				{
					maxId = idAux;
				}
			}
		}

		fprintf(pFile, "%d", maxId);
	}

	return rtn;
}
