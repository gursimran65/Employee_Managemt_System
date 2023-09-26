#include<stdio.h>
#include "Emp.h"
int main(void) {
  int choice;
  do{
    showChoices();
    scanf("%d",&choice);
    switch(choice){
      case 1:
        searchEmployee();
        break;
      case 2:
        addEmployee();
        break;
      case 3:
        printf("Enter the no of employees you want to add\n");
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
          addEmployee();
        }
        break;
      case 4:
        updateEmployeeDetails();
      break;
      default:
      printf("Invalid input");
    }
  }
  while(choice!=4);
  printf("\nyou have been exited from the program");
  return 0;
}