#include "input.h"
#include "ArrayEmployees.h"

#define TAM 1000

int main(void) {

	setbuf(stdout, NULL);

	eEmployee listEmployees[TAM];
	int optionSelected;
	int idToRemove;
	int idToModify;
	int sortOrder;

	if(InitEmployee(listEmployees, TAM) != 0)
	{
		printf("\n-No se pudo iniciar la lista correctamente, saliendo del programa..\n");
		exit(0);
	}

	do
	{
		MainMenu();

		if(PedirEntero(&optionSelected, "\n-Que desea hacer?: ", "\n.ERROR! -> Ingrese una opcion valida (1 - 6).", 1, 6, 8) != 0)
		{
			printf("\n-Saliendo del programa..");
			exit(0);
		}

		switch(optionSelected)
		{
			case 1:
				if(ThereIsAnEmptyPlace(listEmployees, TAM) == 0)
				{
					if(CreateEmployee(listEmployees, TAM) == 0) //Usa AddEmployee.
					{
						printf("\n-Alta de empleado exitosa...\n");
					}else{
						printf("\n-No se pudo dar de alta al empleado... -> ERROR INGRESO DE DATOS.\n");
					}
				}else{
					printf("\n-No es posible dar de alta un empleado -> LISTA LLENA (MAX: %d).\n", TAM);
				}
				break;
			case 2:
				if(ThereIsAnEmployee(listEmployees, TAM) == 0)
				{
					if(PrintEmployees(listEmployees, TAM) == 0
					&& PedirEntero(&idToModify, "\n-Ingrese el ID del/la empleado/a a modificar: ", "\n.ID Invalido! MIN:1 MAX:1000", 1, 10000, 4) == 0)
					{
						switch(ModifyEmployee(listEmployees, TAM, idToModify))
						{
							case 1:
								printf("\n-No existe un/a empleado/a con el ID correspondiente, regresando...\n");
								break;
							case 0:
								printf("\n-Modificacion exitosa...\n");
								break;
							default: //-1
								printf("\n-Cancelando operacion...\n");
						}
					}
				}else{
					printf("\n-No hay empleado en la lista para modificar...\n");
				}
				break;
			case 3:
				if(ThereIsAnEmployee(listEmployees, TAM) == 0)
				{
					if(PrintEmployees(listEmployees, TAM) == 0
					&& PedirEntero(&idToRemove, "\n-Ingrese el ID del/la empleado/a a eliminar: ", "\n.ID Invalido! MIN:1 MAX:1000", 1, 1000, 4) == 0)
					{
						switch(RemoveEmployee(listEmployees, TAM, idToRemove))
						{
							case 1:
								printf("\n-No existe un/a empleado/a con el ID correspondiente, regresando...\n");
								break;
							case 0:
								printf("\n-Baja de empleado exitosa...\n");
								break;
							default: //-1
								printf("\n-Cancelando operacion...\n");
						}
					}
				}else{
					printf("\n-No hay empleados en la lista para dar de baja...\n");
				}
				break;
			case 4:
				if(ThereIsAnEmployee(listEmployees, TAM) == 0)
				{
					PrintEmployees(listEmployees, TAM);
				}else{
					printf("\n-No hay empleados en la lista para mostrar...\n");
				}
				break;
			case 5:
				if(ThereIsAnEmployee(listEmployees, TAM) == 0)
				{
					if(PedirEntero(&sortOrder, "\n-Ingrese el orden de ordenamiento -> 1 = ASCENDENTE | 0 = DESCENDENTE: ", "\n-ERROR! Ingrese 1 | 0 .", 0, 1, 4) == 0
					&& SortEmployees(listEmployees, TAM, sortOrder) == 0)
					{
						printf("\n-Empleados ordenados correctamente..\n");
						PrintEmployees(listEmployees, TAM);
						PrintSalaryStadistics(listEmployees, TAM);
					}else{
						printf("\n-No se pudo ordenar la lista reintente..\n");
					}

				}else{
					printf("\n-No hay empleados en la lista para ordenar / mostrar estadisticas..\n");
				}
				break;
			default:
				printf("\n.Gracias por utilizar el programa, saliendo...\n\n");
		}

	}while(optionSelected != 6);

	return EXIT_SUCCESS;
}
