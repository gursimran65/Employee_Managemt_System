#include<stdio.h>
#include<string.h>
#include "Emp.h"
struct Employee employees[100];
int counter=0;

void showChoices(){
  printf("\n Enter your Choice \n");
  printf("1:Display Employees NetSalary\n");
  printf("2:Add single employee \n");
  printf("3:Add multiple employees\n");
  printf("4:Make Updataion in Basic salary\n");
  printf("5:Exit\n"); 
}
//*************validations****************
int validateUniqueEmployeeId(int empId){
  for(int i=0;i<counter;i++){
    if(empId==employees[i].Empno){
      return 1;
    }
  }
  return 0;
}
int validateEmpId(int empId){
  if(empId>=100000 && empId<=999999){
    return validateUniqueEmployeeId(empId);
  }
    return 1;
}

int validateEmpName(char*Fname){
  char*Fme=Fname;
  if((Fme[0]>=65 && Fme[0]<=90)||(Fme[0]>=97 && Fme[0]<=122)){
    return 0;
  }
 return 1;
}


int validateEmpHireMonth(int hireMonth){
  if(hireMonth>=1 && hireMonth<=12)
    return 0;
  else 
    return 1;
}

int validateEmpHireyear(int hireYear){
  if(hireYear>=1900 && hireYear<=2023)
    return 0;
  else 
    return 1;
}
int validateEmpHireDate(int hireDate , int hireMonth ,int hireYear){
  if(hireMonth==2 && hireDate<=28 && hireYear%4!=0){
    return 1;
  }
  if(hireMonth==2 && hireDate<=29 && hireYear%4==0){
    return 1;
  }
  if(hireDate>=1 && hireDate<=12)
    return 0;
  else 
    return 1;
}
int validateEmpBasicSalary(int empSalary){
  if(empSalary>=0)
    return 0;
  else 
    return 1;
}
//******************************


//*******fetching the employee Detrails******
struct Employee fetchEmpDetails(struct Employee emp){
  int Empno;
  char firstName[30];
  char lastName[20];
  float basicSalary;
  
  printf("Enter your Employee number\n");
  scanf("%d",&emp.Empno);
    if(validateEmpId(emp.Empno)==1){
      printf("Enter a valid Employee Number*\n");
      fetchEmpDetails(emp);
    }
  
  printf("Enter your First Name (without spaces)\n");
  scanf("%s",emp.firstName);
  if(validateEmpName(emp.firstName)==1){
      printf("Enter a valid Employee First Name*\n");
      fetchEmpDetails(emp);
  }

  printf("Enter your Last Name\n");
  scanf("%s",emp.lastName);
  if(validateEmpName(emp.firstName)==1){
      printf("Enter a valid Employee First Name*\n");
      fetchEmpDetails(emp);
    }
  printf("Enter your Hire Year\n");
  scanf("%d",&emp.hireDate.year);
  if(validateEmpHireyear(emp.hireDate.year)==1){
        printf("Enter a valid Hire year*\n");
        fetchEmpDetails(emp);
  }
  printf("Enter your Hire Month\n");
  scanf("%d",&emp.hireDate.mm);
  if(validateEmpHireMonth(emp.hireDate.mm)==1){
        printf("Enter a valid Hire Month*\n");
        fetchEmpDetails(emp);
      }
  
  printf("Enter your Hire date\n");
  scanf("%d",&emp.hireDate.dd);
  if(validateEmpHireDate(emp.hireDate.dd,emp.hireDate.mm,emp.hireDate.year)==1){
        printf("Enter a valid hire date*\n");
        fetchEmpDetails(emp);
      }

  printf("Enter your Basic Salary\n");
  scanf("%f",&emp.basicSalary);
  if(validateEmpBasicSalary(emp.basicSalary)==1){
      printf("Enter a valid Basic Salary*\n");
      fetchEmpDetails(emp);
    }
  return emp;
}
 float getNetSalary(struct Employee emp) {
   float bs=emp.basicSalary;
    float Da=.40*bs;
    float Ta=.10*bs;
    float Pf=.05*bs;
    return (Da +Ta - Pf);
  }
  void dispInformation(struct Employee emp) {
    printf("Employee number: %d\n",emp.Empno);
    
    printf("Employee name: %s %s\n", emp.firstName, emp.lastName);
    printf("Hire Date: ""%d-%d-%d\n",emp.hireDate.dd, emp.hireDate.mm,emp.hireDate.year);
    printf("Basic Salary: %f\n",emp.basicSalary);
    printf("Net salary: %f\n\n",getNetSalary(emp));
    // return emp;
  }

void addEmployee(){
  struct Employee emp;
  emp=fetchEmpDetails(emp);
  employees[counter]=emp;
  counter++;
}
void dispAllEmployees(){
  for(int i=0;i<counter;i++){
    dispInformation(employees[i]);
  }
}
void searchEmployee(){
  int employeeNumber;
  if(counter==0){
    printf("Your Employee list is empty");
    return;
  }
  printf("enter the Employee ID\n");
  scanf("%d",&employeeNumber);
  int flg=0;
  for(int i=0;i<counter;i++){
    if(employees[i].Empno==employeeNumber){
      dispInformation(employees[i]);
      return;
    }
  }
  printf("please enter a valid Employee Number\n");
}
void updateEmployeeDetails(){
  int employeeNumber;
  if(counter==0){
    printf("Your Employee list is empty");
    return;
  }
  printf("enter the Employee ID");
  scanf("%d",&employeeNumber);
  int flg=0;
  for(int i=0;i<counter;i++){
    if(employees[i].Empno==employeeNumber){
      printf("Your current registered Datils are:\n");
      dispInformation(employees[i]);
      int newbasic;
      printf("Enter the updated Basic Salary");
      employees[i].basicSalary=newbasic;
      return;
    }
  }
  printf("please enter a valid Employee Number\n");
}