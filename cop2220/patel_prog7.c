/*COP 2220  (patel_prog7.c) - larger program
//Amarnath Patel - 10/27/2022 this program will be the cumulative effort of the last 3 assignments.*/

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
//input/output character parameter
//display the program options and get the users selection
//HINT: use scanf without &

double ProcessOption(char choice, double balance);
//input: a character (choice) and a double (balance) by copy
//uses conditions or switch to process the choice ‘s’,’o’,’b’,or ‘a’ 
// returns the updated balance if a purchase was made or money was added to the account

void DisplayMenu();
//display beverage/food options and prices
//NOTE: this function has a void return type

void OrderPricePtr(double* pricePtr);
//input output parameter the price of the item
//Inside the function block: declare the item number, use Display Menu function to display the prices
//ask and get the item number
//set the price of the item to the "value at" pricePtr

int CheckForEnoughMoney(double balance, double price);
//input: a double  (balance) and a double (price) by copy
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough 

double Reload(double balance);
//reload the account balance
//input: a double (balance) by copy
//returns the updated balance


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

int CheckForEnoughMoney(double balance, double price)
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough
{
	if (price > balance)
	{
		printf("\nYou do not have enough money in your account.\n\n");
		printf("You will need to make a selection again after you reload your account.\n\n");
		return 0;
	}
	else return 1;
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




void Greeting()
{
	//welcome the user to the purchasing app
	printf("Welcome to the purchasing app!\n\n");
}

void ViewBalance(double balance)
//input: double
//display the current account balance

{
	printf("Your current balance is $%.2lf\n", balance);
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
	int enough = 0;
	double price;
	if (choice == 's')
	{
		printf("\n----------------------------------\n");
		printf("Display the menu\n");
		//display the menu (snack and coffee choices)
		DisplayMenu();
	}
	else if (choice == 'o')
	{
		printf("\n----------------------------------\n");
		printf("Order an item and complete the purchase");
		//view the balance
		ViewBalance(balance);
		//display the menu (snack and coffee choices)
		DisplayMenu();
		//complete the order only if there is enough money

		OrderPricePtr(&price);

		enough = CheckForEnoughMoney(balance, price);
		while (enough == 0)//not enough
		{
			//reload
			ViewBalance(balance);
			balance = Reload(balance);
			ViewBalance(balance);
			//check if it is enough
			enough = CheckForEnoughMoney(balance, price);
		}
		
		//if (price != 0)
		{
			//view the balance
			ViewBalance(balance);
			//make the purchase
			balance = balance - price;
			//view the balance
			ViewBalance(balance);
		}
	}
//add the other options 
	else if (choice == 'b')
	{
		printf("\n---------------------------------\n");
		printf("Display the account balance\n");
		ViewBalance(balance);
	}
	else if (choice == 'a')
	{
		printf("\n---------------------------------\n");
		printf("Add money to the account");
		ViewBalance(balance);
		balance = Reload(balance);
		ViewBalance(balance);
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


void OrderPricePtr(double* pricePtr)
//input output parameter the price of the item
//Inside the funciton block: declare the item number, use Display Menu function to display the prices
//ask and get the item number
//set the price of the item to the "value at" pricePtr
{
	int itemNumber;
	//DisplayMenu();
	printf("\nEnter your selection: ");
	scanf("%d", &itemNumber);
	switch (itemNumber) {
	case 1:
		printf("\nYou selected Coffee, the price is $1.50\n");
		*pricePtr = 1.50;
		break;
	case 2:
		printf("\nYou selected Tea, the price is $1.00\n");
		*pricePtr = 1.00;
		break;
	case 3:
		printf("\nYou selected Water, the price is $0.50\n");
		*pricePtr = 0.50;
		break;
	case 4:
		printf("\nYou selected Soda, the price is $1.25\n");
		*pricePtr = 1.25;
		break;
	case 5:
		printf("\nYou selected Chips, the price is $1.75\n");
		*pricePtr = 1.75;
		break;
	case 6:
		printf("\nYou selected Candy, the price is $1.25\n");
		*pricePtr = 1.25;
		break;
	case 7:
		printf("\nYou selected Cookies, the price is $1.50\n");
		*pricePtr = 1.50;
		break;
	case 8:
		printf("\nYou selected Brownie, the price is $2.00\n");
		*pricePtr = 2.00;
		break;
	//add the other cases here
	default:
		printf("\nThere is no item with that number");
		*pricePtr = 0.0;
	}
}

double Reload(double balance)
//reload the account balance
{
	double amount;
	printf("\nEnter the amount you want to add: ");
	scanf("%lf", &amount);
	return amount + balance;
}

