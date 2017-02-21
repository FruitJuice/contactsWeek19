// contactsWeek19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <cstdlib>

int readFile(char *fileLoc);
void printIt();

struct info {
	char user_name[25];
	char fname[15];
	char lname[15];
	char dname[30];
	char jobTi[20];
	char depart[50];
	char officeNum[10];
	char officePhone[20];
	char mobilePhone[20];
	char fax[20];
	char address[25];
	char city[15];
	char state[5];
	char zip[10];
	char regCount[25];
	struct info *next;
};

struct info *first, *current, *new_info;


int main()
{
	first = NULL;
	char fileName[150] = "C:\\Users\\sndri\\Documents\\Visual Studio 2015\\Projects\\contactsWeek19\\contactsWeek19\\contacts.txt";
	readFile(fileName);
	printIt();
    return 0;
}



int readFile(char *fileLoc)
{
	FILE *ptr;
	char delim[3] = ",";
	char line[300];
	char *token;
	ptr = fopen(fileLoc, "r");
	if (ptr == NULL) return 0;

	first = (struct info *)malloc(sizeof(struct info));
	current = first;
	while (1) {
		fgets(line, 200, ptr);
		if (strstr(line, "1"))
		{
			new_info = (struct info *)malloc(sizeof(struct info));

			token = strtok(line, delim);
			strcpy(current->user_name, token);

			token = strtok(NULL, delim);
			strcpy(current->fname, token);

			token = strtok(NULL, delim);
			strcpy(current->lname, token);

			token = strtok(NULL, delim);
			strcpy(current->dname, token);

			token = strtok(NULL, delim);
			strcpy(current->jobTi, token);

			token = strtok(NULL, delim);
			strcpy(current->depart, token);

			token = strtok(NULL, delim);
			strcpy(current->officeNum, token);

			token = strtok(NULL, delim);
			strcpy(current->officePhone, token);

			token = strtok(NULL, delim);
			strcpy(current->mobilePhone, token);

			token = strtok(NULL, delim);
			strcpy(current->fax, token);

			token = strtok(NULL, delim);
			strcpy(current->address, token);

			token = strtok(NULL, delim);
			strcpy(current->city, token);

			token = strtok(NULL, delim);
			strcpy(current->state, token);

			token = strtok(NULL, delim);
			strcpy(current->zip, token);

			token = strtok(NULL, delim);
			strcpy(current->regCount, token);

			if(feof(ptr))
			{
				current->next = NULL;
				break;
			}
			current->next = new_info;
			current = new_info;
		}
	}
	fclose(ptr);
	return 1;
}


void printIt()
{
	if(first == NULL)
	{
		puts("There are no records to print!");
	}
	else
	{
		current = first;
		do
		{
			printf("User Name: %s\nFirst Name: %s\nLast Name: %s\nDisplay Name: %s\nJob Title: %s\nDepartment: %s\nOffice Number: %s\nOffice Phone: %s\nMobile Phone: %s\nFax: %s\nAddress: %s\nCity: %s\nState: %s\nZIP: %s\nCountry or Region: %s\n",
				current->user_name,
				current->fname,
				current->lname,
				current->dname,
				current->jobTi,
				current->depart,
				current->officeNum,
				current->officePhone,
				current->mobilePhone,
				current->fax,
				current->address,
				current->city,
				current->state,
				current->zip,
				current->regCount
				);
		} while ((current = current->next) != NULL);
	}
}