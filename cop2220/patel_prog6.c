/*COP 2220  (lastname_prog6.c) - smaller program
// Amarnath Patel 10/17/22 this program is utilizing more files than 1*/

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes
void Greeting();
//welcome the user to the purchasing app

void ViewBalance(double balance);
//input: double
//display the current account balance

void OptionListPtr(char* choicePtr);
//input/ output character parameter
//display the program options and get the users selection
//HINT: use scanf without &

double ProcessOption(char choice, double balance);
//input: a character (choice) and a double (balance) by copy
//uses conditions or switch to process the choice ‘s’,’o’,’b’,or ‘a’ 
// returns the updated balance if a purchase was made or money was added to the account

void DisplayMenu();
//display beverage/food options and prices
//NOTE: this function has a void return type


int main()
{
	//declare the variables
	char choiceInMain;
	FILE* inPtr, * outPtr; //for file input and output
	double balanceInMain; 

	//greet the user
	inPtr = fopen("accountBalance.txt", "r");//connect to the file
	printf("\nGetting the balance from the file\n\n");
	//use fscanf to get the balance from the file
	fscanf(inPtr, "%lf", &balanceInMain);

	//display the balance
	ViewBalance(balanceInMain);

	//while loop INITIALIZATION
	OptionListPtr(&choiceInMain);
	choiceInMain = tolower(choiceInMain);

	while (choiceInMain != 'q') //TEST
	{
		//call ProcessOption and pass the choiceInMain anf the balance
		balanceInMain = ProcessOption(choiceInMain, balanceInMain);
		//call OptionListPtr and pass the "address of" choiceInMain
		//change the choiceInMain to lowercase //UPDATE
		OptionListPtr(&choiceInMain);
		choiceInMain = tolower(choiceInMain);
	}

	printf("\nSaving the balance to the file\n\n");
	outPtr = fopen("accountBalance.txt", "w");//connect to the  file
	//use fprintf to save the balance in the file
	fprintf(outPtr, "%f", balanceInMain);
	
	printf("\nHave a great day!\n\n");

	//close the file pointers
	fclose(inPtr);
	fclose(outPtr);

	return 0;
}


//function definitions

void Greeting()
//welcome the user to the purchasing app
{
	//Greet the user
	printf("Welcome to the purchasing app\n");
	
}

void ViewBalance(double balance)
//input: double
//display the current account balance

{
	printf("\nYour current balance is %.2f\n", balance);

}

void OptionListPtr(char* choicePtr)
//input/ ouput charater parameter
//display the program options and get the users selection
//HINT: use scanf without &
{
	//display the program options, get the choice from the user
	//('S', 'O', 'B', 'A', 'Q')
	printf("\n");
	printf("Please select an option:\n");
	printf("\n");
	printf("S - See the item on the menu\n");
	printf("O - Order an item\n");
	printf("B - See the balance\n");
	printf("A - Add money to the balance\n");
	printf("Q - Quit\n");
	printf("\nEnter your letter of choice: ");

	scanf(" %c", choicePtr);
}

double ProcessOption(char choice, double balance)
//input: a character (choice) and a double (balance) by copy
//uses conditions or switch to process the choice ‘s’,’o’,’b’,or ‘a’ 
// returns the updated balance if a purchase was made or money was added to the account

{
	if (choice == 's')
	{
		printf("\n----------------------------------\n");
		printf("Display the menu\n");
		DisplayMenu();
		//call DisplayMeny function
		//display the menu (snack and coffee choices)
	}
	if (choice == 'S')
	{
		printf("\n----------------------------------\n");
		printf("Display the menu\n");
		DisplayMenu();
		//call DisplayMeny function
		//display the menu (snack and coffee choices)
	}
	else if (choice == 'o')
	{
		printf("\n----------------------------------\n");
		printf("\nYou made an purchase\n");
		//display message 
		DisplayMenu();
		//DisplayMenu();
		//the balance will be changed after a purchase is made in program 7
		
	}
	//complete for all the other selections
	else if (choice == 'b')
	{
		printf("this is supposed to display the balance\n");
	}
	else if (choice == 'a')
	{
		printf("\n adding money to the account will be done later\n");
	}
	else if (choice == 'q')
	{
		printf("\nQuitting the program\n");
	}
	else
	{
		printf("\n----------------------------------\n");
		printf("\nThat is not a valid option\n");
	}
	return balance;
}

void DisplayMenu()
//display beverage/food options and prices
//NOTE: this function is has a void return type

{
	//same as program 5
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


