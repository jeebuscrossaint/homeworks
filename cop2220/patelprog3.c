/*
 * patel_prog.c
  Amarnath Patel 9 16 2022 program 3 converting certain units
 *
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include <stdio.h> //for printf and scanf

 //greets the user
 //asks, get, and returns the first initial
char Greeting();

//input: the users initial 
//asks and gets centimeters, converts to inches
//prints the results
void CmToInches(char initial);

//input: the users initial 
//asks and gets inches, converts to centimeters
//prints the results
void InchesToCm(char initial);

//input: the users initial 
//asks and gets the temperature in Celsius
//converts to Fahrenheit
//prints the results
void CelsiusToFahrenheit(char initial);

//input: the users initial 
//asks and gets the temperature in Fahrenheit
//converts to Celsius
//prints the results
void FahrenheitToCelsius(char initial);



int main()
{
	char initial;
	//function calls here
        initial = Greeting(); //function call
        CmToInches(initial);//function call
        InchesToCm(initial);// function call
        CelsiusToFahrenheit(initial);// function call
        FahrenheitToCelsius(initial);// function call

	printf("\n%c., Have a Great Day!", initial);
	return 0;
}

//function definitions here

void FahrenheitToCelsius(char initial)
{
    double fahrenheit;
    double celsius;
    printf(" %c, Enter Fahrenheit \n", initial);
    scanf("%lf", &fahrenheit);
    celsius = fahrenheit * 5/9 - 32;
    printf(" %c, %.2f fahrenheit equals %.2f celsius \n", initial, fahrenheit, celsius);
}
void CelsiusToFahrenheit(char initial)
{
    double celsius;
    double fahrenheit;
    printf(" %c, Enter Celsius \n", initial);
    scanf("%lf", &celsius);
    fahrenheit = celsius * 1.8;
    printf(" %c, %.2f celsius equals %.2f fahrenheit \n", initial, celsius, fahrenheit);
}
//input: the users initial
//asks and gets inches, converts to centimeters
//prints the results
void InchesToCm(char initial)
{
    double centimeters;
    double inches;
    printf(" %c, Enter Inches \n", initial);
    scanf("%lf", &inches);
    centimeters = inches * 2.54;
    printf(" %c, %.2f centimeters equals %.2f inches \n", initial, inches, centimeters);
}
//input: the users initial 
//asks and gets centimeters, converts to inches
//prints the results
void CmToInches(char initial)
{

	double centimeters;
	double inches;
	printf(" %c, Enter centimeters \n", initial);
	scanf("%lf", &centimeters);
	inches = centimeters / 2.54; 
	printf(" %c, %.2f centimeters equals %.2f inches \n", initial, centimeters, inches);
}

 //greets the user
 //asks, get, and returns the first initial
char Greeting()
{

	//declare a character (letter)
 	//greets the user
	//ask for the character
	//scanf(" %c", &letter);
	//return the character
	char letter;
	printf("Hello user. Please input a character.");
	scanf(" %c", &letter);
	return(letter);
}