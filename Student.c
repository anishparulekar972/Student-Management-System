#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int rollnumber;
    char fname[50];
    char lname[100];
    char address[200];
    char phone[100];
    double percentage;
    struct Student *next;

}* head;
void login()
{
    char name[20];
    char password[50];
    char id[20]="abc";
    char pass[50]="pqr";
    int x,y;
     printf("##############################################################################################################################\n");
    printf("#####################################     STUDENT INFORMATION MANAGEMENT SYSTEM     ##########################################\n");
    printf("##############################################################################################################################\n\n\n");
    printf(" username:\t");
    scanf("%s",name);
    printf("\n password:\t");
    scanf("%s",&password);
    x=strcmp(id,name);
    y=strcmp(password,pass);

    if(x==0&&y==0)
    {
        printf("login success");
    }
    else
    {
        printf("access denied,try again...");
        exit(0);
    }
}
void insert(int rollnumber, char* fname, char* lname, char* address, char* phone, double percentage)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->rollnumber = rollnumber;
	strcpy(student->fname, fname);
	strcpy(student->lname, lname);
	strcpy(student->address, address);
	strcpy(student->phone, phone);
	student->percentage = percentage;
	student->next = NULL;

	if(head==NULL){
		// if head is NULL
		// set student as the new head
		head = student;
	}
	else{
		// if list is not empty
		// insert student in beginning of head
		student->next = head;
		head = student;
	}

}

void search(int rollnumber)
{
    struct Student * temp = head;
	while(temp!=NULL){
		if(temp->rollnumber==rollnumber){
			printf("\nRoll Number: %d\n", temp->rollnumber);
			printf("First Name: %s\n", temp->fname);
			printf("Last Name: %s\n", temp->lname);
			printf("Address: %s\n", temp->address);
			printf("Phone: %s\n", temp->phone);
			printf("Percentage: %lf\n", temp->percentage);
			return;
		}
		temp = temp->next;
	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void update(int rollnumber)
{

    struct Student * temp = head;
	while(temp!=NULL){

		if(temp->rollnumber==rollnumber){
			printf("Record with roll number %d Found !!!\n", rollnumber);
			printf("Enter new first name: ");
			scanf("%s", temp->fname);
			printf("Enter new last name: ");
			scanf("%s", temp->lname);
			printf("Enter new address: ");
			scanf("%s", temp->address);
			printf("Enter new phone number: ");
			scanf("%s", temp->phone);
			printf("Enter new percentage: ");
			scanf("%lf",&temp->percentage);
			printf("RECORD UPDATED SUCCESSFULLY....!!!\n");
			return;
		}
		temp = temp->next;

	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);

}

void Delete(int rollnumber)
{

    struct Student * temp1 = head;
	struct Student * temp2 = head;
	while(temp1!=NULL){

		if(temp1->rollnumber==rollnumber){

			printf("Record with roll number %d Found !!!\n", rollnumber);

			if(temp1==temp2){
				// this condition will run if
				// the record that we need to delete is the first node
				// of the linked list
				head = head->next;
				free(temp1);
			}
			else{
				// temp1 is the node we need to delete
				// temp2 is the node previous to temp1
				temp2->next = temp1->next;
				free(temp1);
			}
            printf("RECORD SUCCESSFULLY DELETED....!!!\n");
			return;

		}
		temp2 = temp1;
		temp1 = temp1->next;

	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);

}

void display()
{
    struct Student * temp = head;
	while(temp!=NULL){

		printf("Roll Number: %d\n", temp->rollnumber);
		printf("First Name: %s\n", temp->fname);
		printf("Last Name: %s\n",temp->lname);
		printf("Address: %s\n",temp->address);
		printf("Phone Number: %s\n", temp->phone);
		printf("Percentage: %lf\n\n", temp->percentage);
		temp = temp->next;

	}
}

int main()
{
    login();
    system("cls");
    printf("\n\n========================================= WELCOME TO STUDENT INFORMATION MANAGEMENT SYSTEM ==================================================\n\n\n");
    head = NULL;
    int choice;
    char fname[50];
    char lname[100];
    char address[200];
    char phone[100];
    int rollnumber;
    double percentage;
do{
    printf("\n\nPress '1' to insert student details\nPress '2' to search for student details\nPress '3' to delete student details\nPress '4' to update student details\nPress '5' to display all student details\nPress '6' to exit\n");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter first name: ");
                scanf("%s", fname);
                printf("Enter last name: ");
                scanf("%s", lname);
                printf("Enter the address: ");
                scanf("%s", address);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%lf", &percentage);
                insert(rollnumber, fname, lname, address, phone, percentage);
                printf("\nSTUDENT DETAILS INSERTED SUCCESSFULLY....!");
                break;
            case 2:
                printf("\nEnter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("\nEnter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("\nEnter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
            printf("\nPlease enter valid choice\n");

        }

    }while (choice != 6);

}
