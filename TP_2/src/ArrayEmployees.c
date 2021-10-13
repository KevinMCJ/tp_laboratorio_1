#include "ArrayEmployees.h"

void MainMenu()
{
	printf("\n   *************************");
	printf("\n   *  MENU DE OPERACIONES  *\n");
	printf("   *************************");
	printf("\n1- ALTA Empleado.\n");
	printf("2- MODIFICAR Empleado.\n");
	printf("3- BAJA Empleado.\n");
	printf("4- MOSTRAR Empleados.\n");
	printf("5- INFORMAR..\n");
	printf(" -Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
	printf(" -Total y promedio de los salarios.\n");
	printf(" -Cuantos empleados superan el salario promedio.\n");
	printf("6- Salir del programa.\n");
}

void ModifyMenu()
{
	printf("\n   *********************");
	printf("\n   *     MODIFICAR     *\n");
	printf("   *********************");
	printf("\n1- NOMBRE.\n");
	printf("2- APELLIDO.\n");
	printf("3- SALARIO.\n");
	printf("4- SECTOR.\n");
	printf("5- CANCELAR Modificacion.\n");
}

int ThereIsAnEmployee(eEmployee* listEmployees, int len)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0 )
	{
		for(int i = 0; i < len; i++)
		{
			if(listEmployees[i].isEmpty == BUSY)
			{
				rtnValue = 0;
				break;
			}
		}
	}

	return rtnValue;
}

int ThereIsAnEmptyPlace(eEmployee* listEmployees, int len)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(listEmployees[i].isEmpty == EMPTY)
			{
				rtnValue = 0;
				break;
			}
		}
	}

	return rtnValue;
}

void PrintEmployee(eEmployee employee)
{
	printf(" |%-7d %-18s %-19s %-17.3f %-4d  |\n", employee.id, employee.lastName, employee.name, employee.salary, employee.sector);
    printf(" -------------------------------------------------------------------------\n");
}

int PrintEmployees(eEmployee* listEmployees, int len)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0 )
	{
		for(int i = 0; i < len; i++)
		{
			if(i == 0)
			{
				printf("\n -------------------------------------------------------------------------\n");
				printf(" | ID  |     APELLIDO     |      NOMBRE       |    SALARIO    |  SECTOR  |\n");
				printf(" -------------------------------------------------------------------------\n");
			}

			if(listEmployees[i].isEmpty == BUSY)
			{
				PrintEmployee(listEmployees[i]);
				rtnValue = 0;
			}
		}
	}

	return rtnValue;
}

int InitEmployee(eEmployee* listEmployees, int len)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			listEmployees[i].isEmpty = EMPTY;
		}

		rtnValue = 0;
	}

	return rtnValue;
}

int GetNextID(eEmployee* listEmployees, int len)
{
	int newID;

	for(int i = 0; i < len; i++)
	{
		if(listEmployees[i].isEmpty == EMPTY)
		{
			newID = i+1; //Empieza en 1.
			break;
		}
	}

	return newID;
}

int CreateEmployee(eEmployee* listEmployees, int len)
{
	int rtnValue = -1;
	eEmployee myEmployee;

	if(listEmployees != NULL && len > 0)
	{
		if( PedirString(myEmployee.name, 18, "\n-Ingrese el nombre del/la empleado/a: ", "\n.ERROR! -> MAX CARACTERES: 18 / SOLO LETRAS / SIN ESPACIOS." , 4) == 0
		&&	PedirString(myEmployee.lastName, 18, "\n-Ingrese el apellido del/la empleado/a: ", "\n.ERROR! -> MAX.CARACTERES: 18 / SOLO LETRAS / SIN ESPACIOS." , 4) == 0
		&&	PedirFlotante(&myEmployee.salary, "\n-Ingrese el salario del/la empleado/a: ", "\n.ERROR! -> MIN: 14K MAX: 350K", 14000, 350000, 4) == 0
		&&	PedirEntero(&myEmployee.sector, "\n-Ingrese el sector del/la empleado/a: ", "\n.ERROR.. SECTOR INVALIDO! 1 | 2 | 3 | 4.", 1, 4, 4) == 0)
		{
			myEmployee.id = GetNextID(listEmployees, len);

			if(AddEmployee(listEmployees, len, myEmployee.id, myEmployee.name, myEmployee.lastName, myEmployee.salary, myEmployee.sector) == 0)
			{
				rtnValue = 0;
			}
		}
	}

	return rtnValue;
}

int AddEmployee(eEmployee* listEmployees, int len, int id, char* name, char* lastName, float salary, int sector)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(listEmployees[i].isEmpty == EMPTY)
			{
				rtnValue = 0;
				listEmployees[i].id = id;
				strcpy(listEmployees[i].name, name);
				strcpy(listEmployees[i].lastName, lastName);
				listEmployees[i].salary = salary;
				listEmployees[i].sector = sector;
				listEmployees[i].isEmpty = BUSY;
				break;
			}
		}
	}

	return rtnValue;
}

int FindEmployeeById(eEmployee* listEmployees, int len, int id)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(listEmployees[i].isEmpty == BUSY && listEmployees[i].id == id)
			{
				rtnValue = i;
				break;
			}
		}
	}

	return rtnValue;
}

int ModifyEmployee(eEmployee* listEmployees, int len, int id)
{
	int rtnValue = -1;
	int idToModify;
	int optionSelected;
	char confirmCharacter;

	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;


	if(listEmployees != NULL && len > 0)
	{
		idToModify = FindEmployeeById(listEmployees, len, id);

		if(idToModify != -1) //Encontro un empleado con el ID ingresado.
		{
			ModifyMenu();

			if(PedirEntero(&optionSelected, "\n-Que desea hacer?: ", "\n.ERROR! -> Ingrese una opcion valida (1 - 5).", 1, 5, 4) == 0)
			{
				switch(optionSelected)
				{
					case 1:
						if(PedirString(auxName, 15, "\n-Ingrese el nuevo nombre del/la empleado/a: ", "\n.ERROR! -> MAX CARACTERES: 15 / SOLO LETRAS / SIN ESPACIOS." , 4) == 0
						&& GetConfirmCharacter(&confirmCharacter, "\n-Esta seguro de que desea modificar el nombre del/la empleado/a? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
						&& confirmCharacter == 'S')
						{
							strcpy(listEmployees[idToModify].name, auxName);
							rtnValue = 0;
						}
						break;
					case 2:
						if(PedirString(auxLastName, 20, "\n-Ingrese el nuevo apellido del/la empleado/a: ", "\n.ERROR! -> MAX.CARACTERES: 20 / SOLO LETRAS / SIN ESPACIOS." , 4) == 0
						&& GetConfirmCharacter(&confirmCharacter, "\n-Esta seguro de que desea modificar el apellido del/la empleado/a? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
						&& confirmCharacter == 'S')
						{
							strcpy(listEmployees[idToModify].lastName, auxLastName);
							rtnValue = 0;
						}
						break;
					case 3:
						if(PedirFlotante(&auxSalary, "\n-Ingrese el nuevo salario del/la empleado/a: ", "\n.ERROR! -> MIN: 14K MAX: 350K", 14000, 350000, 4) == 0
						&& GetConfirmCharacter(&confirmCharacter, "\n-Esta seguro de que desea modificar el salario del/la empleado/a? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
						&& confirmCharacter == 'S')
						{
							listEmployees[idToModify].salary = auxSalary;
							rtnValue = 0;
						}
						break;
					case 4:
						if(PedirEntero(&auxSector, "\n-Ingrese el nuevo sector del/la empleado/a: ", "\n.ERROR.. SECTOR INVALIDO! 1 | 2 | 3 | 4.", 1, 4, 4) == 0
						&& GetConfirmCharacter(&confirmCharacter, "\n-Esta seguro de que desea modificar el sector del/la empleado/a? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
						&& confirmCharacter == 'S')
						{
							listEmployees[idToModify].sector = auxSector;
							rtnValue = 0;
						}
						break;
				}

			}

		}else{
			rtnValue = 1;
		}
	}

	return rtnValue;
}

int RemoveEmployee(eEmployee* listEmployees, int len, int id)
{
	int rtnValue = -1;
	int idToRemove;
	char confirmCharacter;

	if(listEmployees != NULL && len > 0)
	{
		idToRemove = FindEmployeeById(listEmployees, len, id);

		if(idToRemove != -1) //Encontro un empleado con ese ID correcto.
		{
			if(GetConfirmCharacter(&confirmCharacter, "\n-Esta seguro de que desea eliminar el/la empleado/a? S / N: ", "\n.ERROR! Solo ingrese S / N", 4) == 0
			&& confirmCharacter == 'S')
			{
				listEmployees[idToRemove].isEmpty = EMPTY;
				rtnValue = 0;
			}

		}else{
			rtnValue = 1;
		}
	}

	return rtnValue;
}

int SortEmployees(eEmployee* listEmployees, int len, int order)
{
	int rtnValue = -1;

	if(listEmployees != NULL && len > 0)
	{
		SortEmployeesByLastNameAndSector(listEmployees, len, order);
		rtnValue = 0;
	}

	return rtnValue;
}

void SortEmployeesByLastNameAndSector(eEmployee* listEmployees, int len, int order)
{
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(listEmployees[i].isEmpty == BUSY && listEmployees[j].isEmpty == BUSY)
			{
				SortEmployeesByLastName(listEmployees, len, order);

				if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) == 0)
				{
					SortEmployeesBySector(listEmployees, len, order);
				}
			}
		}
	}
}

void SortEmployeesByLastName(eEmployee* listEmployees, int len, int order)
{
	eEmployee auxEmployee;

	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(listEmployees[i].isEmpty == BUSY && listEmployees[j].isEmpty == BUSY)
			{
				if(order == 1) //ASCENDENTE
				{
					if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) > 0)
					{
						auxEmployee = listEmployees[i];
						listEmployees[i] = listEmployees[j];
						listEmployees[j] = auxEmployee;
					}

				}else{ //DESCENDENTE

					if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) < 0)
					{
						auxEmployee = listEmployees[i];
						listEmployees[i] = listEmployees[j];
						listEmployees[j] = auxEmployee;
					}
				}
			}
		}
	}

}

void SortEmployeesBySector(eEmployee* listEmployees, int len, int order)
{
	eEmployee auxEmployee;

	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(listEmployees[i].isEmpty == BUSY && listEmployees[j].isEmpty == BUSY)
			{
				if(order == 1) //1.ASCENDENTE
				{
					if(listEmployees[i].sector > listEmployees[j].sector)
					{
						auxEmployee = listEmployees[i];
						listEmployees[i] = listEmployees[j];
						listEmployees[j] = auxEmployee;
					}

				}else{ //2.DESCENDENTE

					if(listEmployees[i].sector < listEmployees[j].sector)
					{
						auxEmployee = listEmployees[i];
						listEmployees[i] = listEmployees[j];
						listEmployees[j] = auxEmployee;
					}
				}
			}
		}
	}
}

void PrintWageStatistics(eEmployee* listEmployees, int len)
{
    int employeesCount;
    int employeesAboveAverage;
    float salaryAverage;
    float salaryAccum;

    employeesCount = 0;
    employeesAboveAverage = 0;
    salaryAccum = 0;

    //Contador de empleados y acumula sus salarios.
    for(int i = 0; i < len; i++)
    {
        if(listEmployees[i].isEmpty == BUSY)
        {
            employeesCount++;
            salaryAccum += listEmployees[i].salary;
        }
    }

    salaryAverage = salaryAccum / employeesCount; //Calcula el promedio de todos los salarios.

    //Contador para saber cuantos empleados tienen un salario arriba del promedio.
    for(int i = 0; i < len; i++)
    {
        if(listEmployees[i].isEmpty == BUSY && listEmployees[i].salary > salaryAverage)
        {
            employeesAboveAverage++;
        }
    }

    printf("\n.El salario total entre todos los empleados es de: %.3f", salaryAccum);
    printf("\n.El salario promedio entre todos los empleados es de: %.3f", salaryAverage);
    printf("\n.Se encontraron: %d empleados que superan el salario promedio.\n\n", employeesAboveAverage);
}
