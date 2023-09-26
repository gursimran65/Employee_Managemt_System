#include <stdio.h>

struct Employee {
  int Empno;
  struct Date {
    int dd;
    int mm;
    int year;
  };
  struct Date hireDate;
  char firstName[30];
  char lastName[20];
  float basicSalary;
};
struct Employee fetchEmpDetails(struct Employee);
float getNetSalary(struct Employee);
void dispInformation(struct Employee);
void addEmployee();
void showChoices();
void dispAllEmployees();
void searchEmployee();
void updateEmployeeDetails();

// validation functions :
int validateEmpid();
int validateEmpHireMonth();
int validateEmpHireyear();
int validateEmpHireDate();
int validateEmpBasicSalary();
int validateUniqueEmployeeId();
