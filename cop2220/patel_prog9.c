/* program 9 amarnath pate 12/1/2022 this program will build with program 8 and do some stuff with words like capitalizing and reversing them
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 30

typedef struct {
	char inputWord[SIZE];
	int length;
	char upperWord[SIZE];
	char reverseWord[SIZE];
	int vowelCount;
} wordInfo;

//Function Prototypes

// fills the data fields of a wordInfo instance
//returns the filled wordInfo
wordInfo FillWords();

//fills the data fields of a wordInfo instance
//by reference using a pointer to a wordInfo
void FillWordPtr(wordInfo* wordptr);

//fills an array of wordInfo
void FillWordArray(wordInfo wordList[], int* size);

//displays one wordInfo
void DisplaywordData(wordInfo anyWord);

int main()
{

	//Declare variables
	wordInfo myWord1, myWord2, myWord3;
	wordInfo wordList[SIZE];
	int cSize;
	int i;

	//Fill structures with a function
	myWord1 = FillWords();
	myWord2 = FillWords();

	//print using display function
	printf("\n---------Display myWord1\n");
	DisplaywordData(myWord1);
	printf("\n---------Display myWord2\n");
	DisplaywordData(myWord2);

	//Fill structure using pointers and display it
	//FillWordPtr(myWord3);
	printf("\n---------Display myWord3\n");
	DisplaywordData(myWord3);

	//Fill the array with the function
	printf("\n---------Fill array wordList\n");
	FillWordArray(wordList, &cSize);

	//display an array of words
	printf("\n---------Display array wordList\n");
	for (i = 0; i < cSize; i++)
	{
		DisplaywordData(wordList[i]);
	}

	return 0;
}

//Function Definitions

// fills the data fields of a word instance
//returns the filled word 
wordInfo FillWords()
{
	//Declare local variables
	wordInfo tempC;
	//prompt and get information
	printf("\nplease enter your word: ");
	scanf("%s", tempC.inputWord);
	//print to check
	printf("given word:  %s\n", tempC.inputWord);

	//prompt and get information
	printf("\nplease enter the upper case word: ");
	scanf("%s", tempC.upperWord);
	//print to check
	printf("uppercased word:  %s\n", tempC.upperWord);

	//prompt and get information
	printf("\nplease enter the reverse word: ");
	scanf("%c", tempC.reverseWord);
	printf("reverse word:  %s\n", tempC.reverseWord);
	return tempC;
}



//displays one word information
void DisplaywordData(wordInfo anyWord)
{
	printf(" Word: %s Length: %d Upper: %s Reverse: %s Vowel Count: %d ", anyWord.inputWord, anyWord.length, anyWord.upperWord, anyWord.reverseWord, anyWord.vowelCount);
}
	
	/*printf("\n\n word:  %s\n", (wordInfo).inputWord);
	printf("\n\n reversed word:  %s\n", (wordInfo).reverseWord);
	printf("\n\n uppercased word:  %s\n", (wordInfo).upperWord);
}
*/

//fills the data fields of a word instance
//by reference using a pointer to a word
void FillWordPtr(wordInfo* wordPtr)
{
	//prompt and get information
	printf("\nplease enter the word: "); 
	scanf("%s", wordPtr->inputWord);

	//prompt and get information
	printf("\nplease enter the upper case word: ");
	scanf("%s", wordPtr->upperWord);

	//prompt and get information
	printf("\nplease enter the reverse word: ");
	scanf("%s", wordPtr->reverseWord);
}


//fills an array of words
void FillWordArray(wordInfo wordList[], int* size)
{
	int i;
	//prompt the user
	printf("\nenter the number of words: ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i = 0; i < *size; i++)
	{
		printf("enter original word:  ");
		scanf("%s", wordList[i].inputWord);

		printf("enter reversed word:  ");
		scanf("%s", wordList[i].reverseWord);

		printf("enter uppercased word:  ");
		scanf("%c", wordList[i].upperWord);
	}
}

