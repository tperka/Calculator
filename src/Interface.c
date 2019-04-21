#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
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
 * @brief It checks if user passed valid answer to yes/no question.
 * 
 * @param ar string taken from stdin using scanf().
 */
void scanChar(char ar[])
{
	while(scanf("%2[^\n]", ar) == 0 || strlen(ar) > 1 || (ar[0] != 'y' && ar[0] != 'n'))
	{
		cleanBuff();
		printf("Unaviable command. use 'y' or 'n'. Try again.\n");
	}
	cleanBuff();
}
/**
 * @brief 
 * 
 * @param res 
 */
void ask(char* res)
{
	printf("Do you want to use the previous result? (y/n)\n");
	scanChar(res);
}

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

int loadInt(char* str, DynArray* arr)
{
	if(strlen(str) > 1000)
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

DynArray* checkSign(DynArray* arr)
{
	if(arr->array[0] == -1)
	{
		arr = DelFirstElement(arr);
		FlipSign(arr);
	}
	return arr;
}

DynArray* scanDynArray(DynArray* arr)
{
	insertDynArray(arr, 0);
	char ar[1002];
	while(scanf("%1001[^\n]", ar) == 0 || loadInt(ar, arr) == 0)
	{
		arr = cleanArray(arr);
		cleanBuff();
		printf("Incorrect value. Insert an integer, up to 1000 digits. Try again.\n");
	}
	cleanBuff();
	arr = checkSign(arr);
	return arr;
}
