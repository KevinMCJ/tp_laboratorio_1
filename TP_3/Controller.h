#include <stdio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* spArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//.txt ID
int controller_saveIdAsText(LinkedList* pArrayListEmployee);
int controller_getMaxIdFromText(LinkedList* pArrayListEmployee, int* pId);
int controller_newId(LinkedList* pArrayListEmployee, int* newId);
int controller_Find_Employee_ById(LinkedList* pArrayListEmployee, int idBuscado);

void controller_menuWithCounter(int len);
void controller_modifyMenu();
void controller_sortMenu();


