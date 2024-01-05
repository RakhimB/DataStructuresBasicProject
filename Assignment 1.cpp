#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring a structure of Employee

struct empInfo
{
	long empNum;
	char name[15];
	float workedHours;
	float hourlySalary;
	float monthlySalary;
	
	
};



// SWAPPING method

void swap(struct empInfo *A1,struct empInfo *B1)
{
	struct empInfo temp1;
	
	temp1 = *A1;
	*A1 = *B1;
	*B1 = temp1;
	
}

// SELECTION sorting

void selectSorting (struct empInfo *allEmp, int num1)
{
	for(int i = 0; i<num1 - 1; i++)
	{
		int pos = i;
		for(int j = i + 1; j<num1; j++)
		{
			if(strcmp(allEmp[pos].name, allEmp[j].name) > 0)
			{
				pos = j;
			}
		}
			if(pos != i)
			{
				swap(&allEmp[i], &allEmp[pos]);
			}
	}
	
}

// BUBBLE sorting

void bubbleSorting (struct empInfo *allEmp, int num2)
{
	for(int i = 0; i<num2; i++)
	{
		for(int j = 0; j < num2 - i - 1; j++)
		{
			if(allEmp[j].empNum > allEmp[j+1].empNum)
			{
				swap(&allEmp[j], &allEmp[j+1]);
			}
		}
	}
}

// INSERTION operation

void Inserting (struct empInfo *allEmp,int *num3)
{	
    struct empInfo inputEmployees;
    printf ("Please input employee number: ");
    scanf("%lld",&inputEmployees.empNum);
    printf ("Please input employee name: ");
    scanf("%s",inputEmployees.name);
    printf ("Please input employee work hours: ");
    scanf("%f",&inputEmployees.workedHours);
    printf ("Please input employee hourly salary: ");
    scanf("%f",&inputEmployees.hourlySalary);
    printf ("Please input employee salary: ");
    scanf("%f",&inputEmployees.monthlySalary);

    int insertPos=0;
    for(int i=0;i<*num3;i++)
	{
        if(inputEmployees.empNum < allEmp[i].empNum)
        {
            insertPos = i;
            break;
        }
    }
    for(int i=*num3;i>=insertPos;i--)
	{
        allEmp[i].empNum=allEmp[i-1].empNum;
        strcpy(allEmp[i].name,allEmp[i-1].name);
        allEmp[i].workedHours=allEmp[i-1].workedHours;
        allEmp[i].hourlySalary=allEmp[i-1].hourlySalary;
        allEmp[i].monthlySalary=allEmp[i-1].monthlySalary;
    }
    allEmp[insertPos].empNum=inputEmployees.empNum;
    strcpy(allEmp[insertPos].name,inputEmployees.name);
    allEmp[insertPos].workedHours=inputEmployees.workedHours;
    allEmp[insertPos].hourlySalary=inputEmployees.hourlySalary;
    allEmp[insertPos].monthlySalary=inputEmployees.monthlySalary;
    *num3 = *num3+1;
}

// DELETION operation

void Deletion(struct empInfo *allEmp, int *num4)
{
	bubbleSorting(allEmp, *num4);
	int employee_num;
	printf("Please input employee number to delete: ");
	scanf("%d",&employee_num);
	
	int posDel = -1;
	
	for(int i = 0; i<*num4; i++)
	{
		if(employee_num == allEmp[i].empNum)
		{
			posDel = i;
			printf("\n%s is deletet from the list!\n", allEmp[posDel].name);
			break;
		}
	
	}
		
		if(posDel == -1)
		{
			printf("This employee is not found\n");
		}
			else
			{
				for(int j = posDel; j<*num4 - 1; j++)
				{
					allEmp[j].empNum = allEmp[j+1].empNum;
					strcpy(allEmp[j].name,allEmp[j+1].name);
					allEmp[j].workedHours= allEmp[j+1].workedHours;
					allEmp[j].hourlySalary= allEmp[j+1].hourlySalary;
					allEmp[j].monthlySalary= allEmp[j+1].monthlySalary;
					
				}
					*num4 = *num4 - 1;
					
			}
					
			
}

    	
void binarySearch(struct empInfo *allEmp, int num){
	
	bubbleSorting (allEmp, num);
	
    int empID;
    printf ("Enter Emploee number to Search: ");
    scanf("%d",&empID);
    int low = 0;
    int high = num - 1;
    int mid = (low+high)/2;
    while (low <= high) {
    	
        if(allEmp[mid].empNum < empID){
		low = mid + 1;
		}
            
        else if (allEmp[mid].empNum == empID) {
            
			printf("Employee number is: %lld\n",allEmp[mid].empNum);
			printf("Employee name is:  %s\n",allEmp[mid].name);
			printf("Employee worked hours is: %.2f\n",allEmp[mid].workedHours);
			printf("Employee hourly salary is: %.2f\n",allEmp[mid].hourlySalary);
			printf("Employee monthly salary is: %.2f\n",allEmp[mid].workedHours*allEmp[mid].hourlySalary);
            break;
        }
        else{
		high = mid - 1;
		}
            
        mid = (low + high)/2;
    }
    if(low > high)
        printf("Emploee is not found\n");
}
			

// LISTING operation

void Listing(struct empInfo *allEmp, int num6)
{
	for(int i = 0; i<num6; i++)
	{
		printf("\n");
		printf("Employee number is: %lld\n",allEmp[i].empNum);
		printf("Employee name is:  %s\n",allEmp[i].name);
		printf("Employee worked hours is: %.2f\n",allEmp[i].workedHours);
		printf("Employee hourly salary is: %.2f\n",allEmp[i].hourlySalary);
		printf("Employee monthly salary is: %.2f\n",allEmp[i].workedHours*allEmp[i].hourlySalary);
	}
	
}

// FILE to open

void ArrayFile (struct empInfo *allEmp, int *number)
{
	FILE *fl;
	
	fl = fopen("C:\\Users\\Public\\employee.txt","rt");
	
	if (fl == NULL)
	{
		printf("Error in opening file\n");
		exit(EXIT_FAILURE);
	}	

	char whole_row[100];
	fscanf(fl,"%[^\n]", whole_row);
	//printf("first row: \t\t%s\n\n", whole_row);
	int rows;
	
	printf("Welcome to first Assignment!\n");
	printf("List of Emploees is created...\n\n");
	
	while((rows = fscanf(fl, "%lld %s %f %f", &allEmp[*number].empNum, &allEmp[*number].name, &allEmp[*number].workedHours, &allEmp[*number].hourlySalary)) != EOF)
	{
		if(rows == 4)
		{
			/*printf("Employee number is: %lld\n",allEmp[*number].empNum);
			printf("Employee name is: %s\n",allEmp[*number].name);
			printf("Employee salary is: %d\n\n",allEmp[*number].salary);*/
			
			*number = *number + 1;
		}
	}
	
	fclose(fl);	
}


// MENU list


int main()
{
	struct empInfo allEmp[150];
	
	
	int choice, choice1;
	
	int num = 0;
	
	
	ArrayFile(allEmp,&num);
	
	printf("\n\nNow select the operation \n");
	
	
	while(1){
		
		printf("\n\n/// MAIN MENU \\\\\\ \n");
		printf("1. List Employee\n");
		printf("2. Sort Employee by name (Selection Sort)\n");
		printf("3. Sort Employee by number (Bubble Sort)\n");
		printf("4. Add a new Employee information (Insertion)\n");
		printf("5. Delete Employee information (Deletion)\n");
		printf("6. Search Employee (Binary Search)\n");
		printf("7. Exit the program.\n");
			
	
		printf("\n\nPlease enter your choice here: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
    			
    			{
    				Listing(allEmp,num);
    				printf("\nPlease enter 1 to go to main menu:");
	 			 	scanf("%d", &choice1);
	 			 	switch(choice1){
	 			 	case 1:
	 			 	{
	 	  			continue;
	 	  			break;
				 	}
	 				default: printf("\nTry again!\n\n");
				 	}
					break;
				}
				
			case 2:
				{
				 selectSorting(allEmp,num);
				 Listing(allEmp,num);
				 printf("\nPlease enter 1 to go to main menu:");
	 			 scanf("%d", &choice1);
	 			 switch(choice1){
	 			 case 1:
	 			 {
	 	  			continue;
	 	  			break;
				 }
	 			default: printf("\nTry again!\n\n");
	 
	 			}
					break;
				}
				
			case 3:
				{
				 bubbleSorting(allEmp,num);
				 Listing(allEmp,num);
				 printf("\nPlease enter 1 to go to main menu:");
	 			 scanf("%d", &choice1);
	 			 switch(choice1){
	 			 case 1:
	 			 {
	 	  			continue;
	 	  			break;
				 }
	 			default: printf("\nTry again!\n\n");
	 
	 			}
					break;
				}

				
			case 4:
				{
				 Inserting(allEmp,&num);
				 Listing(allEmp,num);
				 printf("\nPlease enter 1 to go to main menu:");
	 			 scanf("%d", &choice1);
	 			 switch(choice1){
	 			 case 1:
	 			 {
	 	  			continue;
	 	  			break;
				 }
	 			default: printf("\nTry again!\n\n");
	 			}
					break;
				}
				
			case 5:
				{
				 Deletion(allEmp,&num);
				 Listing(allEmp,num);
				 printf("\nPlease enter 1 to go to main menu:");
	 			 scanf("%d", &choice1);
	 			 switch(choice1){
	 			 case 1:
	 			 {
	 	  			continue;
	 	  			break;
				 }
	 			default: printf("\nTry again!\n\n");
	 
	 			}
					break;
				}
				
			case 6:
				{
				 binarySearch(allEmp, num);
				 printf("\nPlease enter 1 to go to main menu:");
	 			 scanf("%d", &choice1);
	 			 switch(choice1){
	 			 case 1:
	 			 {
	 	  			continue;
	 	  			break;
				 }
	 			default: printf("\nTry again!\n\n");
	 
	 			}
					break;
				}
			
			case 7:
				
				{
      			 printf("End of Program! Thanks for using!\n");
      
      			    break;
    			}
    	
				default: printf("\nTry again!\n\n");
   		}
			return 0;
		}
	return 0;
}
