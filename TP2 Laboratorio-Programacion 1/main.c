#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "myvalidations.h"

#define TAM 1000

//KEVIN MAMANI      1°B

/*A tener en cuenta
1.No logre hacer el ordenamiento.
2.Lo realize este dia probando y borrando y me olvide de realizar los commits , perdon,
Justamente lo entrego en horario casi limite.*/

int main()
{
    eEmployee listEmployees[TAM];
    int idToRemove;
    int idToModify;
    //int sortOrder;
    int optionSelected;
    int countEmployees;

    //ESTE CONTADOR NOS SIRVE COMO FLAG PARA SABER SI HAY AL MENOS UN EMPLEADO CARGADO Y SI ES ASI REALIZAR LAS FUNCIONALIDADES DEL MENU
    countEmployees = 0;

    InitEmployees(listEmployees, TAM);

    do
    {
        Menu();

        //PEDIMOS LA OPCION A ELEGIR DEL MENU.
        utn_getNumero(&optionSelected, "\n-Que desea hacer?: ", "\n.Error! Opcion invalida.", 1, 5);

        switch(optionSelected)
        {
            case 1:
                if(CreateEmployee(listEmployees, TAM) == 0)
                {
                    printf("\n#.Empleado cargado correctamente.\n\n");
                    countEmployees++;
                }else{
                    printf("\n#.No hay espacio para cargar mas empleados.\n\n");
                }
                break;
            case 2:
                if(countEmployees != 0)
                {
                    utn_getNumero(&idToModify, "\n-Ingrese el ID del empleado/a a modificar: ", "\nID invalido! MIN:1 MAX:1000", 1, 1000);
                    if(ModifyEmployee(listEmployees, TAM, idToModify) == 0)
                    {
                        printf("\n-Modificacion realizada correctamente.\n\n");
                    }
                }else{
                    printf("\n-No se encontraron empleados en la lista para modificar.\n\n");
                }
                break;
            case 3:
                if(countEmployees != 0)
                {
                    utn_getNumero(&idToRemove, "\n-Ingrese el ID del empleado/a a eliminar: ", "\nID invalido! MIN:1 MAX:1000", 1, 1000);
                    if(RemoveEmployee(listEmployees, TAM, idToRemove) == 0)
                    {
                        printf("\n-Empleado/a eliminado/a correctamente.\n\n");
                        countEmployees--;
                    }
                }else{
                    printf("\n-No se encontraron empleados en la lista para eliminar.\n\n");
                }
                break;
            case 4:
                if(countEmployees != 0)
                {
                    //utn_getNumero(&sortOrder, "\n-Ingrese el sentido a ordenar (1.ASCENDENTE / 2.DESCENDENTE): ", "\nSentido invalido!", 1, 2);
                    //SortEmployeesByLastNameOrSector(listEmployees, TAM, sortOrder);
                    PrintEmployees(listEmployees, TAM);
                    PrintWageStatistics(listEmployees, TAM);
                }else{
                    printf("\n-No se encontraron empleados en la lista para ordenar, mostrar y imprimir.\n\n");
                }
                break;
            case 5:
                printf("\n-Gracias por utilizar el programa...\n");
                break;
        }

        if(optionSelected != 5)
        {
            ClearConsole();
        }

    }while(optionSelected != 5);


    return 0;
}

