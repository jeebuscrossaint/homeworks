/*COP 2220  (patel_prog8.c) - larger program
//this program will be a practice assignment with strings/character arrays */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h>
#include<ctype.h>
#include<string.h>


//A function that greets the user and gets the first name of the user
void Greeting(char name[]);
//complete

//A function that gets a word from the user and makes a copy of that word
void GetWord(char input[], char copy[]); //character arrays
//complete

//A function that changes a word to all uppercase letters 
void UppercaseWord(char upper[]);
//complete

//input: character array (string)
//display the number of A.s and list the index locations 
//display the number of E.s and list the index locations 
//display the number of I.s and list the index locations 
//display the number of O.s and list the index locations 
//display the number of U.s and list the index locations 
//return the total number of vowel in the array
int CountVowels(char upper[]);

//reverses a word
void ReverseTheWord(char upper[], char reverse[]);



int main()
{
    //declare 4 character arrays
    char input[25];
    char upper[25];
    char reverse[25];

    char firstName[30];

    char quit;
    int vowelCount = 0;

    //greeting and get the first name
	Greeting(firstName);


    printf("\n----------------------------------------\n");

    //ask the user if they would like to enter a word
	printf("Would you like to enter a word? (y/n): ");

    scanf(" %c", &quit);

    while (quit != 'N' && quit != 'n')
    {
        //get the word (input) and make a copy(upper) - call the function
		GetWord(input, upper);
        //change the copy(upper) to all uppercase letters - call the function
		UppercaseWord(upper);
        //make a reverse(reverse) copy(upper) of the word - call the function
		ReverseTheWord(upper, reverse);

        printf("\nPrinting the words in the main function:\n\n");
        printf("original word:\t%s\nuppercase:\t%s\nreverse:\t%s\n", input, upper, reverse);

        vowelCount = CountVowels(upper);
        printf("\nPrinting total number of vowels in the main function:\n\n");
        printf("\nThe total number of vowels is %d\n", vowelCount);
        

        //again?
		printf("Would you like to enter a word? (y/n): ");
        scanf(" %c", &quit);
    }

	//say goodbye
	return 0;
}


//A function that greets the user and gets the first name of the user
void Greeting(char name[])
{
	printf("What is your first name? ");
	scanf(" %s", name); //USE %s with a space and no &
	printf("\n***  Welcome to the character array practice program  ***\n");
}


//A function that gets the word from the user and makes a copy
void GetWord(char input[], char copy[])
{
	printf("Enter a word: ");
	scanf(" %s", input);
	//use strcpy to copy the word
	strcpy(copy, input);
}


//A function that changes the word to all uppercase 
void UppercaseWord(char upper[])
{
	//use strlen to get the length of the word
	int length = strlen(upper);
	// int len = (int)strlen(upper);

	//use a loop to change all the characters to uppercase letters

	for (int i = 0; i < length; i++)
	{
		upper[i] = toupper(upper[i]);
	}
	printf(" %s\n", upper);
}

//reverse a word
void ReverseTheWord(char upper[], char reverse[])
{
	//use strlen
	int length = strlen(upper);
	//int len = (int)strlen(upper);
	
	//use a loop
	for (int i = 0; i < length; i++)
	{
		reverse[i] = upper[length - i - 1];
	}
	//assign the reverse of the upper 
	reverse[length] = '\0';
	printf(" %s\n", reverse);

	//remember to add the null character

	reverse[i] = '\0';
}

//input: character array (string)
//display the number of A.s and list the index locations 
//display the number of E.s and list the index locations 
//display the number of I.s and list the index locations 
//display the number of O.s and list the index locations 
//display the number of U.s and list the index locations 
//return the total number of vowel in the array
int CountVowels(char upper[])
{
	int i;
	int len = (int)strlen(upper);
	int total = 0, aCount = 0;//add variabels to count e,i,o,and u
	int eCount = 0;
	int iCount = 0;
	int oCount = 0;
	int uCount = 0;
	for (i = 0; i < len; i++)
	{
		if (upper[i] == 'A')
		{
			aCount++;
			total++;
			printf("\nThere is an 'A' located at index %d\n", i);
		}

		if (upper[i] == 'E')
		{
			total++;
			printf("\nThere is an 'E' located at index %d\n", i);
		}

		if (upper[i] == 'I')
		{
			total++;
			printf("\nThere is an 'I' located at index %d\n", i);
		}

		if (upper[i] == 'O')
		{
			total++;
			printf("\nThere is an 'O' located at index %d\n", i);
		}

		if (upper[i] == 'U')
		{
			total++;
			printf("\nThere is an 'U' located at index %d\n", i);
		}

		
		//add conditions for the other vowels
	}
	printf("\n The total number of A's is %d\n", aCount);
	printf("\n The total number of E's is %d\n", eCount);
	printf("\n The total number of I's is %d\n", iCount);
	printf("\n The total number of O's is %d\n", oCount);
	printf("\n The total number of U's is %d\n", uCount);


	//add the printf statements for the other vowels


	return total;
}





