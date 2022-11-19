#include <stdio.h>
#include <string.h>

void input();
void show();
void options(int);
void quit();
void modify();
void editDetails(int,int);
void delete();

struct Employee {
	int id;
	char name[20];
	char designation[15];
	char doj[10];
	int salary;
};

struct Employee eArr[10];
int isQuit = 0;

int main(void) {
	printf("\tEmployee Management System\n");
	input();
	show();
	while (!isQuit) {
		printf("\nEnter the number for following options below ??");
		printf("\n1. Modify\n2. Delete\n3. Show\n4. Quit\n");
		int opt;
                scanf("%d", &opt);
		gets();
		options(opt);
	}
	return 0;
}

void input() {
	for (int i = 0; i < 10; i++) {
		printf("\nEnter Employee %d Id : ", i + 1);
		scanf("%d", &eArr[i].id);
		gets();
		printf("\nEnter Employee %d Name : ", i + 1);
		gets(eArr[i].name);
		printf("\nEnter Employee %d Designation : ", i + 1);
		gets(eArr[i].designation);
		printf("\nEnter Employee %d Date of Joining : ", i + 1);
		gets(eArr[i].doj);
		printf("\nEnter Employee %d Salary : ", i + 1);
		scanf("%d", &eArr[i].salary);
		gets();
	}
}

void show() {
	printf("\nID \tName \t\tPost \tDate of Join \tSalary");
	for (int i = 0; i < 10; i++) {
		printf("\n%d \t %s \t%s \t%s \t%d", eArr[i].id, eArr[i].name,
 eArr[i].designation, eArr[i].doj, eArr[i].salary);
	}
}

void options(int opt) {
	if (opt == 1) {
		modify();
	} else if (opt == 2) {
		delete();
	} else if (opt == 3) {
		show();
	} else if(opt == 4) {
		quit();
	}else {
		printf("\nPlease Enter a valid option");
	}
}

void quit() {
	isQuit = 1;
	printf("\n\nThanks for Checking My Project");
}

void modify() {
	int query, selected;
	int found = 0;
	printf("\nEnter ID of the employee you want to edit\n");
	scanf("%d", &query);
	gets();
	for (int i = 0; i < 10; i++) {
		if (query == eArr[i].id) {
			selected = i;
			found = 1;
		}
	}
	if (!found) {
		printf("\nPlease Enter a Valid ID\n");
	}else {
		printf("\nWhat Detail you want to edit :\n1. ID\n2. Name\n3. Post\n4. Date of Join\n5. Salary\n");
		int editQuery;
		scanf("%d", &editQuery);
		gets();
		editDetails(selected,editQuery);
	}
}

void editDetails(int selected,int editQuery) {
	if(editQuery == 1){
		printf("\nPlease enter new ID of the Employee\n");
		scanf("%d", &eArr[selected].id);
		gets();
	}else if(editQuery == 2){
		printf("\nPlease enter new Name of the Employee\n");
		gets(eArr[selected].name);
	}else if(editQuery == 3){
		printf("\nPlease enter new Post of the Employee\n");
		gets(eArr[selected].designation);
	}else if(editQuery == 4){
		printf("\nPlease enter new Date of Joining of the Employee\n");
		gets(eArr[selected].doj);
	}else if(editQuery == 5){
		printf("\nPlease enter new Salary of the Employee\n");
		scanf("%d", &eArr[selected].salary);
		gets();
	}else {
		printf("\nPlease Enter a Valid option\n");
		return;
	}
	printf("\nYour Query has been updated!\n");
}

void delete(){
	int query, selected;
	int found = 0;
	printf("\nEnter ID of the employee you want to delete\n");
	scanf("%d", &query);
	gets();
	for(int i=0;i<10;i++){
		if(eArr[i].id == query){
			selected = i;
			found = 1;
			break;
		}
	}
	if(found){
		eArr[selected].id = 0;
		eArr[selected].name[0] = '\0';
		eArr[selected].designation[0] = '\0';
		eArr[selected].doj[0] = '\0';
		eArr[selected].salary = 0;
		printf("\nThe following entry has been deleted!\n");
	}else {
		printf("\nPleade enter a valid Id\n");
	}
}
