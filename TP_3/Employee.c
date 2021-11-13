#include "Employee.h"

Employee* employee_new()
{
	Employee* pEmpleado = NULL;

	pEmpleado = (Employee*) malloc(sizeof(Employee));

	if(pEmpleado != NULL)
	{
		employee_setId(pEmpleado, 0);
		employee_setNombre(pEmpleado, "\0");
		employee_setHorasTrabajadas(pEmpleado, 0);
		employee_setSueldo(pEmpleado, 0);
	}

	return pEmpleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleado = NULL;

	pEmpleado = employee_new();

	if(pEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{
		pEmpleado->id = atoi(idStr);
		strcpy(pEmpleado->nombre, nombreStr);
		pEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
		pEmpleado->sueldo = atoi(sueldoStr);
	}

	return pEmpleado;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setId(Employee* this, int id)
{
	int rtn = -1;

	if(this != NULL)
	{
		this->id = id;
		rtn = 0;
	}

	return rtn;
}

int employee_getId(Employee* this, int* id) //Retorna por referencia
{
	int rtn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}

	return rtn;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = 0;
	}

	return rtn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int rtn = -1;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		rtn = 0;
	}

	return rtn;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int rtn = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		rtn = 0;
	}

	return rtn;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int rtn = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		rtn = 0;
	}

	return rtn;
}
int employee_getSueldo(Employee* this, int* sueldo)
{
	int rtn = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		rtn = 0;
	}

	return rtn;
}

void employee_listAnEmployee(Employee* this)
{
	printf(" | %-8d %-24s %-16d %-10d |\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
	printf(" -----------------------------------------------------------------\n");
}

int employee_CompareByName(void* e1, void* e2)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int compara;

	if(e1 != NULL && e2 != NULL)
	{
		//Recordar castear los punteros a void al tipo de dato que usamos , en este caso empleados para usar los datos.
		unEmpleado = (Employee*) e1;
		otroEmpleado = (Employee*) e2;

		compara = strcmp(unEmpleado->nombre, otroEmpleado->nombre);
	}

	return compara;
}

int employee_CompareById(void* e1, void* e2)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int compara = 0; //Por default decimos que son iguales, si no es asi. va a cambiar.

	if(e1 != NULL && e2 != NULL)
	{
		unEmpleado = (Employee*) e1;
		otroEmpleado = (Employee*) e2;

		if(unEmpleado->id > otroEmpleado->id)
		{
			compara = 1;
		}else{
			if(unEmpleado->id < otroEmpleado->id)
			{
				compara = -1;
			}
		}
	}

	return compara;
}

int employee_CompareBySueldo(void* e1, void* e2)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int compara = 0;

	if(e1 != NULL && e2 != NULL)
	{
		unEmpleado = (Employee*) e1;
		otroEmpleado = (Employee*) e2;

		if(unEmpleado->sueldo > otroEmpleado->sueldo)
		{
			compara = 1;
		}else{
			if(unEmpleado->sueldo < otroEmpleado->sueldo)
			{
				compara = -1;
			}
		}
	}

	return compara;
}

int employee_CompareByHorasT(void* e1, void* e2)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int compara = 0;

	if(e1 != NULL && e2 != NULL)
	{
		unEmpleado = (Employee*) e1;
		otroEmpleado = (Employee*) e2;

		if(unEmpleado->horasTrabajadas > otroEmpleado->horasTrabajadas)
		{
			compara = 1;
		}else{
			if(unEmpleado->horasTrabajadas < otroEmpleado->horasTrabajadas)
			{
				compara = -1;
			}
		}
	}

	return compara;
}

