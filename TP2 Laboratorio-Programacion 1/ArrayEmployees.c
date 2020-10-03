#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "myvalidations.h"

#define EMPTY 0
#define BUSY 1

void Menu()
{
    printf("\n*********************\n");
    printf("*MENU DE OPERACIONES*\n");
    printf("*********************\n");
    printf("1.ALTAS.\n");
    printf("2.MODIFICAR.\n");
    printf("3.BAJA.\n");
    printf("4.INFORMAR\n");
    printf(" -Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf(" -Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    printf("5.Salir.\n");
}

int InitEmployees(eEmployee* listEmployees, int len)
{
    int returnValue = -1;
    int i;

    if(listEmployees != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            returnValue = 0;
            listEmployees[i].isEmpty = EMPTY;
        }
    }

    return returnValue;
}

int CreateEmployee(eEmployee* listEmployees, int len)
{
    int returnValue = -1;
    eEmployee myEmployee;

    myEmployee.id = NextId(listEmployees, len);

    GetNombre(myEmployee.name, "\n-Ingrese el nombre del/la empleado/a: ", "\n.Nombre Invalido! Muy largo(Max 15c) / Solo letras / Un nombre.");

    GetNombre(myEmployee.lastName, "\n-Ingrese el apellido del/la empleado/a: ", "\n.Apellido Invalido! Muy largo(Max 15c) / Solo letras / Un apellido.");

    utn_getNumeroFlotante(&myEmployee.salary, "\n-Ingrese el salario: ", "\n.Salario Invalido! Min: 14k Max: 300k", 14000, 300000);

    utn_getNumero(&myEmployee.sector, "\n-Ingrese el sector del empleado: ", "\n.Sector invalido . 1, 2 , 3 o 4", 1, 4);

    myEmployee.isEmpty = BUSY;

    if(AddEmployees(listEmployees, len, myEmployee.id, myEmployee.name, myEmployee.lastName, myEmployee.salary, myEmployee.sector) == 0)
    {
        returnValue = 0;
    }

    return returnValue;
}

int AddEmployees(eEmployee* listEmployees, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int returnValue = -1;
    int i;

    if(listEmployees != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(listEmployees[i].isEmpty == EMPTY)
            {
                returnValue = 0;

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

    return returnValue;
}

int FindEmployeeById(eEmployee* listEmployees, int len, int id)
{
    int returnValue = -1;
    int i;

    for(i=0; i<len; i++)
    {
        if(listEmployees[i].id == id)
        {
            returnValue = i;
            break;
        }
    }

    return returnValue;
}

int ModifyEmployee(eEmployee* listEmployees, int len, int id)
{
    int retorno = -1;
    int optionSelected;

    if(FindEmployeeById(listEmployees, len, id) != -1 && listEmployees[id-1].isEmpty == BUSY)
    {
        printf("\nMODIFICAR\n---------");
        printf("\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Cancelar\n");

        utn_getNumero(&optionSelected, "\n-Que desea hacer?: ", "\n.Opcion Invalida!", 1, 5);

        switch(optionSelected)
        {
            case 1:
                GetNombre(listEmployees[id-1].name, "\n-Ingrese el nuevo nombre del/la empleado/a: ", "\n.Nombre Invalido! Muy largo(Max 15c) / Solo letras / Un nombre.");
                break;
            case 2:
                GetNombre(listEmployees[id-1].lastName, "\n-Ingrese el nuevo apellido del/la empleado/a: ", "\n.Apellido Invalido! Muy largo(Max 15c) / Solo letras / Un apellido.");
                break;
            case 3:
                utn_getNumeroFlotante(&listEmployees[id-1].salary, "\n-Ingrese el nuevo salario: ", "\n.Salario Invalido! Min: 14k Max: 300k", 14000, 300000);
                break;
            case 4:
                utn_getNumero(&listEmployees[id-1].sector, "\n-Ingrese el sector del empleado: ", "\n.Sector invalido . 1, 2 , 3 o 4", 1, 4);
                break;
            case 5:
                printf("\n-Cancelando operacion correctamente...\n\n");
                break;
        }

        if(optionSelected != 5)
        {
            retorno = 0;
        }
    }
    else
    {
        printf("\n-No se encontro un empleado con el ID correspondiente... cancelando operacion\n\n");
    }

    return retorno;
}

int RemoveEmployee(eEmployee* listEmployees, int len, int id)
{
    int retorno = -1;
    char confirm;

    if(FindEmployeeById(listEmployees, len, id) != -1 && listEmployees[id-1].isEmpty == BUSY)
    {
        confirm = GetConfirmCharacter("\n-Esta seguro de que desea eliminar el/la empleado/a? S / N: ", "\n.Error! Solo ingrese si o no.");

        if(confirm == 'S')
        {
            //-1 YA QUE LOS ID QUE LE DI EMPIEZAN EN 1 PARA QUE SEA MAS ESTETICO , ASI QUE LA POSICION REAL SERIA LA ANTERIOR.
            listEmployees[id-1].isEmpty = EMPTY;
            retorno = 0;
        }
        else
        {
            printf("\n-Operacion cancelada correctamente.\n\n");
        }
    }
    else
    {
        printf("\n-No se encontro un empleado/a con el ID correspondiente... cancelando operacion.\n\n");
    }


    return retorno;
}

/*int SortEmployeesByLastNameOrSector(eEmployee* listEmployees, int len, int order)
{
    int i;
    int j;

    eEmployee auxLastName;
    eEmployee auxSector;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; i++)
        {
            if(order == 1) //ASCENDENTE
            {
                if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) > 0)
                {
                    auxLastName = listEmployees[i];
                    listEmployees[i] = listEmployees[j];
                    listEmployees[j] = auxLastName;
                }

                if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) == 0)
                {
                    if(listEmployees[i].sector > listEmployees[j].sector)
                    {
                        auxSector = listEmployees[i];
                        listEmployees[i] = listEmployees[j];
                        listEmployees[j] = auxSector;
                    }
                }
            }
            else //DESCENDENTE
            {
                if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) < 0)
                {
                    auxLastName = listEmployees[i];
                    listEmployees[i] = listEmployees[j];
                    listEmployees[j] = auxLastName;
                }

                if(strcmp(listEmployees[i].lastName, listEmployees[j].lastName) == 0)
                {
                    if(listEmployees[i].sector < listEmployees[j].sector)
                    {
                        auxSector = listEmployees[i];
                        listEmployees[i] = listEmployees[j];
                        listEmployees[j] = auxSector;
                    }
                }
            }
        }
    }

    return 0;
}*/

int PrintWageStatistics(eEmployee* listEmployees, int len)
{
    int i;
    int employeesCount;
    int employeesAboveAverage;
    float salaryAverage;
    float salaryAccum;

    employeesCount = 0;
    employeesAboveAverage = 0;
    salaryAccum = 0;

    for(i=0; i<len; i++)
    {
        if(listEmployees[i].isEmpty == BUSY)
        {
            employeesCount++;
            salaryAccum += listEmployees[i].salary;
        }
    }

    salaryAverage = salaryAccum / employeesCount;

    for(i=0; i<len; i++)
    {
        if(listEmployees[i].salary > salaryAverage && listEmployees[i].isEmpty == BUSY)
        {
            employeesAboveAverage++;
            break;
        }
    }

    printf("\n.El salario total entre todos los empleados es de: %.3f", salaryAccum);
    printf("\n.El salario promedio entre todos los empleados es de: %.3f", salaryAverage);
    printf("\n.Se encontraron: %d empleados que superan el salario promedio.\n\n", employeesAboveAverage);

    return 0;
}

int NextId(eEmployee listEmployees[], int len)
{
    int i;
    int newId;

    for(i=0; i<len; i++)
    {
        if(listEmployees[i].isEmpty == EMPTY)
        {
            newId = i+1;
            break;
        }
    }

    return newId;
}

int PrintEmployees(eEmployee listEmployees[], int len)
{
    int i;

    printf(" -----------------------------------------------------\n");
    printf(" | ID  |  APELLIDO  |  NOMBRE  |  SALARIO  |  SECTOR |\n");
    printf(" -----------------------------------------------------\n");

    for(i=0; i<len; i++)
    {
        if(listEmployees[i].isEmpty == BUSY)
        {
            printf(" |%3d %11s %10s %13.3f %7d   |\n", listEmployees[i].id, listEmployees[i].lastName, listEmployees[i].name, listEmployees[i].salary, listEmployees[i].sector);
            printf(" -----------------------------------------------------\n");
        }
    }

    return 0;
}

void ClearConsole()
{
    system("pause");
    system("cls");
}



