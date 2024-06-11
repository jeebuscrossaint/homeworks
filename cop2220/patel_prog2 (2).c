//Amarnath Patel 9 7 2022 program 2

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warning

#include<stdio.h> //printf and scanf
#include<ctype.h> //toupper and tolower

int main()
{
    char userInput;
    char userInputupper;
    int numuserInput;
    int numuserInputupper;

	printf((char [32] "Hello my name is Amarnath Patel");
    printf((char [26] "please enter a character!");
    scanf("%c", userInput);
    char userInputupper = toupper(userInput);
    printf(" %c" userInput);
    printf(" %c" userInputupper);
    int numuserInputupper = (int)userInputupper;
    numuserInputupper = numuserInputupper*10;
    printf(" %c"numuserInputupper);
    int numuserInput = (int)userInput;
    numuserInput = numuserInput*10;
    printf(numuserInput);

	return 0;
}