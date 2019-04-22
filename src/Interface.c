/**
 * 	@file Interface.c
 * 	@brief Basically functions that operate on input from user. 
 * 
 * 	@author Tymoteusz Perka
 *
 * 	@date 26/03/2019
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
#define LIMIT 1000
/**
 * @brief Checks if allocation of memory was succesful.
 * 
 * It simply checks if pointer isn't NULL after malloc or realloc.
 * If yes, it shuts down the program.
 * 
 * @param p pointer we tried to allocate memory for.
 */
void* AllocCheck(void *p)
{
	if(!p)
	{
		fputs("Lack of memory.\n", stderr);
		exit(EXIT_FAILURE);
	}
	return p;
}
/**
 * @brief Cleans buffer after using scanf().
 * 
 */
void cleanBuff()
{
	char c = getchar();
	while( c != '\n')
		c = getchar();
}
/**
 * @brief It give user a question and checks if user passed valid answer to it.
 * 
 * @param ar string we will load the answer to
 */ 
void ask(char* ar)
{
	printf("Do you want to use the previous result? (y/n)\n");
	while(scanf("%2[^\n]", ar) == 0 || strlen(ar) > 1 || (ar[0] != 'y' && ar[0] != 'n'))
	{
		cleanBuff();
		printf("Unaviable command. use 'y' or 'n'. Try again.\n");
	}
	cleanBuff();
}
/**
 * @brief Checks if character represents a number or - sign.
 * 
 * @return int value represented by digit in c, -1 if it is - sign or 10 otherwise. 
 */
int isInt(char c)
{
	if(c >= '0' && c <= '9') {
		return (c - '0');
	}
	else if(c == '-')
	{
		return -1;
	}
	else
	    return 10;
}
/**
 * @brief Converts number stored in string to DynArray.
 * 
 * @param str string passed by user to stdin.
 * @param arr array in which we will store number passed by user.
 * @return int 1 if convertion was succesful, 0 otherwise.
 * 
 * @warning You can't pass number that has >1000 digits.
 */
int loadInt(char* str, DynArray* arr)
{
	if(strlen(str) > LIMIT)
		return 0;

	if(strlen(str) == 1 && str[0] == '-')
		return 0;
		
	if(strlen(str) > 1 && str[0] == '-' && str[1] == '0')
		return 0;
		
	if(strlen(str) > 1 && str[0] == '0')
		return 0;
		
	for(int i = 0; i < strlen(str); i++)
	{
		if(isInt(str[i]) == 10)
		{	
			return 0;
		}
		else if(isInt(str[i]) == (-1) && i != 0)
		{
			return 0;
		}
		else
		{
			if(i == 0)
			{
				arr->array[i] = isInt(str[i]);
			}
			else
				insertDynArray(arr, isInt(str[i]));
		}
	}
	
	return 1;
}
/**
 * @brief Checks the sign of converted number and flips it, if necessary.
 * 
 * @param arr array that just has been converted using loadInt() function(since loadInt leaves -1 at the beginning if number is negative).
 * @return Pointer to the same DynArray without first element and with second having flipped sign.
 * 
 * @note Use it the same way as DelFirstZeros().
 */
DynArray* checkSign(DynArray* arr)
{
	if(arr->array[0] == -1)
	{
		arr = DelFirstElement(arr);
		FlipSign(arr);
	}
	return arr;
}
/**
 * @brief This function takes and converts input from user.
 * 
 * It uses funtions above to take input from user and convert it into number stored in DynArray, checking correctness of input.
 * 
 * @param arr an instance of our struct we wanna load to.
 * @return Pointer to array passed as argument, with number loaded to it.
 * 
 * @note Use it the same way as DelFirstZeros().
 */
DynArray* scanDynArray(DynArray* arr)
{
	insertDynArray(arr, 0);
	char ar[LIMIT + 2];
	while(scanf("%1001[^\n]", ar) == 0 || loadInt(ar, arr) == 0) //in scanf it should be LIMIT + 1
	{
		arr = cleanArray(arr);
		cleanBuff();
		printf("Incorrect value. Insert an integer, up to 1000 digits. Try again.\n");
	}
	cleanBuff();
	arr = checkSign(arr);
	return arr;
}
