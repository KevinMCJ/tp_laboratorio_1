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
	int isEmpty; //Flag

}eEmployee;

void Menu();

int InitEmployee(eEmployee* listEmployees, int len);

int CreateEmployee(eEmployee* listEmployees, int len);

int AddEmployee(eEmployee* listEmployees, int len, int id, char* name, char* lastName, float salary, int sector);





#endif /* ARRAYEMPLOYEES_H_ */
