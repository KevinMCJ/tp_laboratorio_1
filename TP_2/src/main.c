#include "input.h"
#include "ArrayEmployees.h"

#define TAM 4

int main(void) {

	setbuf(stdout, NULL);

	eEmployee listEmployees[TAM];
	int optionSelected;

	if(InitEmployee(listEmployees, TAM) != 0)
	{
		printf("\n-No se pudo iniciar la lista correctamente, saliendo del programa..\n");
		exit(0);
	}

	do
	{
		Menu();

		if(PedirEntero(&optionSelected, "\n-Que desea hacer?: ", "\n.ERROR! -> Ingrese una opcion valida (1 - 5).", 1, 5, 8) != 0)
		{
			printf("\n-Saliendo del programa..");
			exit(0);
		}

		switch(optionSelected)
		{
			case 1:
				if(CreateEmployee(listEmployees, TAM) == 0)
				{
					printf("\n-Alta de empleado exitosa...\n");
				}else{
					printf("\n-No se pudo dar de alta al empleado..\n");
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				printf("\n.Gracias por utilizar el programa...\n\n");
		}

	}while(optionSelected != 5);

	return EXIT_SUCCESS;
}
