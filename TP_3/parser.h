#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_IdFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* pId);
int parser_textFromId(FILE* pFile, LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
