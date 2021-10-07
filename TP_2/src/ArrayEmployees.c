#include "ArrayEmployees.h"

void Menu()
{
	printf("\n   *************************");
	printf("\n   *  MENU DE OPERACIONES  *\n");
	printf("   *************************");
	printf("\n1- ALTA Empleado.\n");
	printf("2- MODIFICAR Empleado.\n");
	printf("3- BAJA Empleado.\n");
	printf("4- INFORMAR..\n");
	printf(" -Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
	printf(" -Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
	printf("5- Salir del programa.\n");
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

int CreateEmployee(eEmployee* listEmployees, int len)
{
	int rtnValue = -1;
	eEmployee myEmployee;

	if( PedirString(myEmployee.name, 15, "\n-Ingrese el nombre del/la empleado/a: ", "\n.ERROR! -> MAX CARACTERES: 15 / SOLO LETRAS / SIN ESPACIOS." , 4) == 0
	&&	PedirString(myEmployee.lastName, 20, "\n-Ingrese el apellido del/la empleado/a: ", "\n.ERROR! -> MAX.CARACTERES: 20 / SOLO LETRAS / SIN ESPACIOS." , 4) == 0
	&&	PedirFlotante(&myEmployee.salary, "\n-Ingrese el salario del/la empleado/a: ", "\n.ERROR! -> MIN: 14K MAX: 350K", 14000, 350000, 4) == 0
	&&	PedirEntero(&myEmployee.sector, "\n-Ingrese el sector del/la empleado/a: ", "\n.ERROR.. SECTOR INVALIDO! 1 | 2 | 3 | 4.", 1, 4, 4) == 0)
	{
		if(AddEmployee(listEmployees, len, myEmployee.id, myEmployee.name, myEmployee.lastName, myEmployee.salary, myEmployee.sector) == 0)
		{
			rtnValue = 0;
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




