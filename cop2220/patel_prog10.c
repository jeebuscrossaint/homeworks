
// program 10 amarnath patel this program will use arrays strings and struts in one program it will ask the user for a word and then it will display the word in uppercase and reverse and it will also display the number of vowels in the word and the index of the vowels in the word it will also save the word in a file and the number of vowels and the index of the vowels in the word in the file */


#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 30

typedef struct {
	//add five data fields
	char inputWord[SIZE];
	int length;
	char upperWord[SIZE];
	char reverseWord[SIZE];
	int numVowels;
} wordInfo;

//Function Prototypes

//same as program 8
//A function that greets the user and gets the first name of the user
void Greeting(char firstName[]);

//same as program 8
//A function that gets a word from the user and makes a copy of that word
void GetWord(char input[], char copy[]); //character arrays

//same as program 8
//A function that changes a word to all uppercase letters 
void UppercaseWord(char upper[]);

//same as program 8
//input: character array (string)
//display the number of A.s and list the index locations 
//display the number of E.s and list the index locations 
//display the number of I.s and list the index locations 
//display the number of O.s and list the index locations 
//display the number of U.s and list the index locations 
//return the total number of vowels in the array
int CountVowels(char upper[]);

//same as program 8
//reverses a word
void ReverseTheWord(char upper[], char reverse[]);

//new function for program 10 
//call from main after the while loop
void SaveToFile(FILE* outPtr, wordInfo wordlist[], int num);

int main()
{
	char quit;
	//character array for the first name
	wordInfo currentWord;
	wordInfo wordList[50];//list of all the words entered
	int num = 0;//number of wordInfo words in the list
	FILE* outPtr;
	
	//declare file pointer and connect to "wordsProgram10.txt"
	outPtr = fopen("wordsProgram10.txt", "w");

	//call the greeting function	


	//greeting and get the first name

	printf("\n----------------------------------------\n");
	//ask the user if they would like to enter a word
	scanf(" %c", &quit);

	while (quit != 'N' && quit != 'n')
	{
		//get the word and make a copy - call the function
		GetWord(currentWord.inputWord, currentWord.upperWord);

 		//get the length of the word
		currentWord.length = (int)strlen(currentWord.inputWord);

		//change the copy to all uppercase letters - call the function
		UppercaseWord(currentWord.upperWord);
		//make a reverse copy of the word - call the function
		ReverseTheWord(currentWord.upperWord, currentWord.reverseWord);

		printf("\nPrinting the words in the main function:\n\n");
		printf("original word:\t%s\nuppercase:\t%s\nreverse:\t%s\n", currentWord.inputWord, currentWord.upperWord, currentWord.reverseWord);

		currentWord.numVowels = CountVowels(currentWord.upperWord);
		printf("\nPrinting total number of vowels in the main function:\n\n");
		//print the number of vowels in the current word
		printf("The number of vowels in the word %s is %d\n", currentWord.inputWord, currentWord.numVowels);
		//add the current word to the word list array
		wordList[num] = currentWord;

		//add one to num;
		num++;

		//again?
		printf("\n----------------------------------------\n");
		printf("Would you like to enter another word? (Y/N) ");
		scanf(" %c", &quit);
	}

	//save the wordList to the file
	printf("\n----------------------------------");
	printf("\nsaving all the information in the word list to the output file");
	//save to file function

	printf("\nThank you, and have a great day!\n");

	//close the file pointer
	fclose(outPtr);
	return 0;

}

//Function Definitions
//A function that greets the user
void Greeting(char firstName[])
{
	printf("What is your first name? ");
	scanf(" %s ", firstName);
	printf("\n***  Welcome to the character array practice program  ***\n");
}

//A function that gets the word from the user and makes a copy
void GetWord(char input[], char copy[])
{
	//use 
	printf("\n\nEnter a word  ");
	scanf(" %s ", input);
	strcpy(copy, input);
}


//A function that changes the word to all uppercase 
void UppercaseWord(char upper[])
{
	//use strlen
	// int len = (int)strlen(upper);
	//use a loop to change all the characters to uppercase letters
	//use toupper
	int i, length;
	length = (int)strlen(upper);

	for (i = 0; i < length; i++)
	{
		upper[i] = toupper(upper[i]);
	}
}

//reverse a word
void ReverseTheWord(char upper[], char reverse[])
{
	//use strlen
	//int len = (int)strlen(upper);

	//use a loop
	//assign the reverse of the upper 

	//remember to add the null character
	//reverse[j] = '\0';
	int len = (int)strlen(upper);
	int i;
	int j = 0;
	for (i = len - 1; i >= 0; i--)
	{
		reverse[j] = upper[i];
		j++;
	}
	reverse[j] = '\0';
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
			//add conditions for the other vowels
		}
		if (upper[i] == 'E')
		{
			eCount++;
			total++;
			printf("\nThere is an 'E' located at index %d\n", i);
		}
		if (upper[i] == 'I')
		{
			iCount++;
			total++;
			printf("\nThere is an 'I' located at index %d\n", i);
		}
		if (upper[i] == 'O')
		{
			oCount++;
			total++;
			printf("\nThere is an 'O' located at index %d\n", i);
		}
		if (upper[i] == 'U')
		{
			uCount++;
			total++;
			printf("\nThere is an 'U' located at index %d\n", i);
		}
		//add conditions for the other vowels
	}
	printf("\n The total number of A's is %d\n", aCount);
	//add the printf statements for the other vowels
	printf("\n The total number of E's is %d\n", eCount);
	printf("\n The total number of I's is %d\n", iCount);
	printf("\n The total number of O's is %d\n", oCount);
	printf("\n The total number of U's is %d\n", uCount);
	return total;
}


//call from main
void SaveToFile(FILE* outPtr, wordInfo wordList[], int num)
{
	int i;
	//for //loop through the array  and print the information to the file
	for (i = 0; i < num; i++)
	{
		fprintf(outPtr, "--------------------------------------");
		fprintf(outPtr, "\nThe input word was: %s ", wordList[i].inputWord);
		fprintf(outPtr, "\nThe uppercase word is: %s ", wordList[i].upperWord);
		fprintf(outPtr, "\nThe reverse word is: %s ", wordList[i].reverseWord);
		fprintf(outPtr, "\nThe number of vowels is: %d ", wordList[i].numVowels);
		fprintf(outPtr, "\nThe length of the word is: %d ", wordList[i].length);
		fprintf(outPtr, "\n--------------------------------------");
	}
}
