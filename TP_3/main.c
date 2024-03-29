#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	int option = 0;
	int len;
	char confirm;
	int salio = 0;

	LinkedList* listaEmpleados = ll_newLinkedList(); //Constructor lista.

	do{
		len = ll_len(listaEmpleados);

		controller_saveIdAsText(listaEmpleados);
		controller_menuWithCounter(len);

		if(PedirEntero(&option, "\n-Que desea hacer?: ", "\n.ERROR! -> Ingrese una opcion valida (1 - 10).", 1, 10, 8) != 0)
		{
			ll_deleteLinkedList(listaEmpleados);
			printf("\n-Saliendo del programa..");
			exit(0);
		}

        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv", listaEmpleados) == 0)
				{
					printf("\n-Datos cargados en memoria correctamente.\n");
				}else{
					printf("\n-No fue posible cargar los datos desde el archivo .csv..\n");
				}
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
				{
					printf("\n-Datos cargados en memoria correctamente.\n");
				}else{
					printf("\n-No fue posible cargar los datos desde el archivo .bin..\n");
				}
            	break;
            case 3:
            	switch(controller_addEmployee(listaEmpleados))
				{
					case 0:
						printf("\n-Alta de empleado exitosa.\n");
						break;
					case 1:
						printf("\n-Cancelando operacion..\n");
						break;
					default: //-1
						printf("\n-No se pudo dar de alta un empleado -> ERROR CARGA DE DATOS.\n");
				}
				break;
			case 4:
				switch(controller_editEmployee(listaEmpleados))
				{
					case 0:
						printf("\n-Modificacion de empleado exitosa.\n");
						break;
					case 1:
						printf("\n-No se encontraron empleados en la lista para modificar...\n");
						break;
					case 2:
						printf("\n-No se encontro un empleado con el ID correspondiente..\n");
						break;
					default:
						printf("\n-Cancelando operacion..\n");
				}
				break;
			case 5:
				switch(controller_removeEmployee(listaEmpleados))
				{
					case 0:
						printf("\n-Empleado dado de baja correctamente.\n");
						break;
					case 1:
						printf("\n-No se encontraron empleados en la lista para eliminar.\n");
						break;
					case 2:
						printf("\n-No se encontro un empleado con el ID correspondiente..\n");
						break;
					default: // 3 | -1
						printf("\n-Cancelando operacion...\n");
				}
				break;
			case 6:
				if(controller_ListEmployee(listaEmpleados) == 0)
				{
					printf("\n-Empleados listados correctamente.\n");
				}else{
					printf("\n-No hay empleados en la lista para mostrar.\n");
				}
				break;
			case 7:
				if(len > 0)
				{
					if(controller_sortEmployee(listaEmpleados) == 0)
					{
						printf("\n-Lista ordenada correctamente.\n");
					}else{
						printf("\n-Cancelando operacion...\n");
					}
				}else{
					printf("\n-No hay empleados en la lista para ordenar...\n");
				}
				break;
				break;
			case 8:
				if(len > 0 && controller_saveAsText("data.csv", listaEmpleados) == 0)
				{
					printf("\n-Datos guardados correctamente.\n");
				}else{
					printf("\n-No fue posible guardar los datos en el archivo .csv -> CARGUE AL MENOS 1 EMPLEADO\n");
				}
				break;
			case 9:
				if(len > 0 && controller_saveAsBinary("data.bin", listaEmpleados) == 0)
				{
					printf("\n-Datos guardados correctamente.\n");
				}else{
					printf("\n-No fue posible guardar los datos en el archivo .csv -> CARGUE AL MENOS 1 EMPLEADO\n");
				}
				break;
			default:
				if(GetConfirmCharacter(&confirm, "\n.Recuerde guardar los cambios.\n-Esta seguro de que desea salir? S / N: ", ".ERROR! -> Solo ingrese S o N.", 2) == 0
				&& confirm == 'S')
				{
					salio = 1;
					ll_deleteLinkedList(listaEmpleados);
					printf("\n-Gracias por utilizar el programa...\n");
				}
        }

    }while(salio != 1);

    return 0;
}

