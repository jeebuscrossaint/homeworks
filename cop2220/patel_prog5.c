/*COP 2220  (lastname_prog5.c) - small program
//Amarnath Patel 10 4 2022 displaying menu options*/

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes
void Greeting();
//welcome the user to the purchasing app

char OptionList();
//display the program options and get the users selection

void ProcessOption(char choice);
//input: the user's choice 
//Display a message based on the user’s choice
//call the Display Menu function if the user selects ‘S’ or ‘s’

void DisplayMenu();
//display beverage/food options and prices
//NOTE: this function is not the same as program 4, it has a void return type


int main()
{
	char choiceInMain;
	//greet the user 
	Greeting();
	//call OptionList 
	choiceInMain = OptionList();
	//change the choiceInMain to lowercase //INITIALIZATION
	choiceInMain = tolower(choiceInMain);
	while (choiceInMain != 'q') //TEST
	{
		//call ProcessOption and pass the choiceInMain
		ProcessOption(choiceInMain);
		//call OptionList 
		OptionList();
		//change the choiceInMain to lowercase //UPDATE
		choiceInMain = tolower(choiceInMain);
	}

	printf("\nHave a great day!\n\n");
	return 0;
}


//function definitions

void Greeting()
{
	printf("Welcome to the purchasing app\n");
}

char OptionList()
//display the program options and get the users selection
{
	//display the program options, get, and return the option
	char choice;
	printf("\n");
	printf("Please select an option:\n");
	printf("\n");
	printf("S - See the item on the menu\n");
	printf("O - Order an item\n");
	printf("B - See the balance\n");
	printf("A - Add money to the balance\n");
	printf("Q - Quit\n");
	printf("\nEnter your letter of choice: ");
	scanf(" %c", &choice);
	//('S', 'O', 'B', 'A', 'Q')
	return choice;
}

void DisplayMenu()
//display beverage/food options and prices
//NOTE: this function is not the same as program 4, it has a void return type
{
	printf("\n----------------------------------\n");
	printf("Here is the menu:\n");
	printf("\n");
	printf("1 - Coffee - $1.50\n");
	printf("2 - Tea - $1.00\n");
	printf("3 - Water - $0.50\n");
	printf("4 - Soda - $1.25\n");
	printf("5 - Chips - $1.75\n");
	printf("6 - Candy - $1.25\n");
	printf("7 - Cookies - $1.50\n");
	printf("8 - Brownie - $2.00\n");
	printf("\n");
}

void ProcessOption(char choice)
//input: the user's choice 
//Display a message based on the user’s choice
//call the Display Menu function if the user selects ‘S’ or ‘s’

{
	if (choice == 's')
	{
		printf("\n----------------------------------\n");
		printf("Display the menu\n");
		//display the menu 	//call DisplayMeny function
		DisplayMenu();
	}
	else
	{
		if (choice == 'o')
		{
			printf("\n----------------------------------\n");
			printf("Order an item\n");
		}
		else
		{
			if (choice == 'b')
			{
				printf("\n----------------------------------\n");
				printf("See the balance\n");
			}
			else
			{
				if (choice == 'a')
				{
					printf("\n----------------------------------\n");
					printf("Add money to the balance\n");
				}
				else
				{
					if (choice == 'q')
					{
						printf("\n----------------------------------\n");
						printf("Quit\n");
					}
					else
					{
						printf("\n----------------------------------\n");
						printf("Invalid option\n");
					}
				}
			}
		}
	}
}
