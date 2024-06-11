/*COP 2220  (lastname_prog4.c) - larger program app purchasing
//add you name, date and description here*/

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings


#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes

void Greeting(void);
//welcome the user to the coffee and snack shop

void ViewBalance(double balance);
//display the current account balance

int DisplayMenu();
//display item options and prices
//asks, gets, and returns the item number

double OrderPrice(int itemNumber);
//input: item number
//returns the price of the item

int CheckForEnoughMoney(double balance, double price);
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough 

double Reload(double balance);
//reload the account balance

int main()
{
	//declare variables

	char again = 'y'; //initialize the while loop

	//greet the user
	
	while (again == 'y' || again == 'Y')//while loop test
	{
		//view the account balance (ViewBalance function call)
		
		//display the menu choices and get the itemSelection (DisplayMenu function call)
		
		//get the price (OrderPrice function call)
		
		//make a purchase if there is enough money
		//reload the card if there is not enough money
		//CheckForEnoughMoney function call

		//view the account balance (ViewBalance function call)
		
		//another purchase?
		printf("\nWould you like to make another purchase? (y or n)\n");
		scanf(" %c", &again);
	}
	//display remaining account balance (ViewBalance function call)
	//say goodbye to the user
	return 0;
}


//function definitions

int CheckForEnoughMoney(double balance, double price)
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough 
{
	if (price > balance)
	{
		//not enough money
		return 0;
	}
	else return 1;
}


double Reload(double balance)
//reload the account balance
{
	//declare amount
	//ask and get amount
	//add amount to balance
	//return the new balance
}


