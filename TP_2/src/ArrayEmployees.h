#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "input.h"

#define EMPTY 0
#define BUSY 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty; //Estado logico.

}eEmployee;

void MainMenu();

void ModifyMenu();

int ThereIsAnEmployee(eEmployee* listEmployees, int len);

int ThereIsAnEmptyPlace(eEmployee* listEmployees, int len);

int InitEmployee(eEmployee* listEmployees, int len);

int GetNextID(eEmployee* listEmployees, int len);

int CreateEmployee(eEmployee* listEmployees, int len);

int AddEmployee(eEmployee* listEmployees, int len, int id, char* name, char* lastName, float salary, int sector);

void PrintEmployee(eEmployee employee);

int PrintEmployees(eEmployee* listEmployees, int len);

int FindEmployeeById(eEmployee* listEmployees, int len, int id);

int ModifyEmployee(eEmployee* listEmployees, int len, int id);

int RemoveEmployee(eEmployee* listEmployees, int len, int id);

int SortEmployees(eEmployee* listEmployees, int len, int order);

void SortEmployeesByLastNameAndSector(eEmployee* listEmployees, int len, int order);

void SortEmployeesByLastName(eEmployee* listEmployees, int len, int order);

void SortEmployeesBySector(eEmployee* listEmployees, int len, int order);

void PrintWageStatistics(eEmployee* listEmployees, int len);

#endif /* ARRAYEMPLOYEES_H_ */
