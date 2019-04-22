/**
 * 	@file main.c
 * 	@brief Simply main funtion (look at comments). 
 * 
 * 	@author Tymoteusz Perka
 *
 * 	@date 26/03/2019
 **/
/**
 * @mainpage Calculator for large integers
 * @section intro_sec Introduction
 * 
 * This program allows you to operate on large integer numbers.
 * If you want to use it, edit it or whatever, feel free to do it.
 * I know the code isn't written the best it could but I was beginner
 * then and didn't know how to write readable and editable code.
 * Sorry for inconvenience. However, the program works perfect and 
 * provides great performance and low memory usage.
*/


#include <stdio.h>
#include <string.h>

#include "Operations.h"
#include "Interface.h"
#include "Arrays_management.h"

int main(void)
{
	DynArray* result = createDynArray();
	insertDynArray(result, 0);
	char err = 0;					//error message flag
	char res[3], menu[3];
	do
	{
		//system("clear"); uncomment if using Linux
		//system("cls") if using Windows
		printf("What would you like to do?\n1. Add\n2. Subtract\n3. Multiply\n4. Factorial\n5. Exit\nResult: "); //User's menu
		for(int i = 0; i < result->used; i++)		//Displaying actual result
			printf("%d", result->array[i]);
		
		printf("\n");

		if(err == 1)
			printf("Factorial is defined only for not negative numbers!\n");

		err = 0;
		
		while(scanf("%2[^\n]", menu) == 0 || strlen(menu) > 1 || menu[0] >'5' || menu[0] < '1')
		{
			printf("Unavaible command. Use integer in range of 1-5. Try again.\n");
			cleanBuff();
		}
		cleanBuff();
		/**
		 * @note Our functions (+,-,*) don't work on negative numbers, so I did some work with signs
		 * to deny its influence on program.
		 * 
		 */
		if(menu[0] == '1')
		{
			ask(res);
			if(res[0] == 'y')
			{	
				DynArray* arr2 =  createDynArray();
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(result->array[0] < 0 && arr2->array[0] < 0) // -a + (-b) = -(a + b)
				{
					FlipSign(result);
					FlipSign(arr2);
					result = addition(result, arr2);
					FlipSign(result);	
				}
				else if(result->array[0] < 0 && arr2->array[0] >= 0) // -a + b = b - a
				{
					FlipSign(result);
					result = subtraction(arr2, result);
				}
				else if(result->array[0] >= 0 && arr2->array[0] < 0) // a - b
				{
					FlipSign(arr2);
					result = subtraction(result, arr2);
				}
				else
				{
					result = addition(result, arr2); // simply a + b
				}
			}
			else
			{
				freeDynArray(result);
				DynArray* arr1 =  createDynArray();
				DynArray* arr2 =  createDynArray();
				printf("Insert first number:\n");
				arr1 = scanDynArray(arr1);
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(arr1->array[0] < 0 && arr2->array[0] < 0)
				{
					FlipSign(arr1);
					FlipSign(arr2);
					result = addition(arr1, arr2);
					FlipSign(result);
				}
				else if(arr1->array[0] < 0 && arr2->array[0] >= 0)
				{
					FlipSign(arr1);
					result = subtraction(arr2, arr1);
				}
				else if(arr1->array[0] >= 0 && arr2->array[0] < 0)
				{
					FlipSign(arr2);
					result = subtraction(arr1, arr2);	
				}
				else
				{
					result = addition(arr1, arr2);
				}
			}
		}
	
		else if(menu[0] == '2')
		{
			ask(res);
			if(res[0] == 'y')
			{	
				DynArray* arr2 = createDynArray();
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(result->array[0] < 0 && arr2->array[0] < 0) // -a - (-b) = b - a
				{
					FlipSign(result);
					FlipSign(arr2);
					result = subtraction(arr2, result);	
				}
				else if(result->array[0] < 0 && arr2->array[0] >= 0) // -a - b = -(a+b)
				{
					FlipSign(result);
					result = addition(arr2, result);
					FlipSign(result);
				}
				else if(result->array[0] >= 0 && arr2->array[0] < 0) // a - (-b) = a + b
				{
					FlipSign(arr2);
					result = addition(result, arr2);
				}
				else
				{
					result = subtraction(result, arr2);
				}
			}
			else
			{
				freeDynArray(result);
				DynArray* arr1 = createDynArray();
				DynArray* arr2 = createDynArray();
				printf("Insert first number:\n");
				arr1 = scanDynArray(arr1);
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(arr1->array[0] < 0 && arr2->array[0] < 0)
				{
					FlipSign(arr1);
					FlipSign(arr2);
					result = subtraction(arr2, arr1);	
				}
				else if(arr1->array[0] < 0 && arr2->array[0] >= 0)
				{
					FlipSign(arr1);
					result = addition(arr2, arr1);
					FlipSign(result);
				}
				else if(arr1->array[0] >= 0 && arr2->array[0] < 0)
				{
					FlipSign(arr2);
					result = addition(arr1, arr2);
				}
				else
				{
					result = subtraction(arr1, arr2);
				}
			}
		}
			
		else if(menu[0] == '3')
		{
			ask(res);
			if(res[0] == 'y')
			{	
				DynArray* arr2 = createDynArray();
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(result->array[0] < 0 && arr2->array[0] < 0) // - a * (-b) = a*b
				{
					FlipSign(result);
					FlipSign(arr2);
					result = multiply(arr2, result);	
				}
				else if(result->array[0] < 0 && arr2->array[0] >= 0) // -a * b = -(a*b)
				{
					FlipSign(result);
					result = multiply(arr2, result);
					FlipSign(result);
				}
				else if(result->array[0] >= 0 && arr2->array[0] < 0) // a*(-b) = -(a*b)
				{
					FlipSign(arr2);
					result = multiply(result, arr2);
					FlipSign(result);
				}
				else
				{
					result = multiply(result, arr2);
				}
			}
			else
			{
				freeDynArray(result);
				DynArray* arr1 = createDynArray();
				DynArray* arr2 = createDynArray();
				printf("Insert first number\n");
				arr1 = scanDynArray(arr1);
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(arr1->array[0] < 0 && arr2->array[0] < 0)
				{
					FlipSign(arr1);
					FlipSign(arr2);
					result = multiply(arr2, arr1);	
				}
				else if(arr1->array[0] < 0 && arr2->array[0] >= 0)
				{
					FlipSign(arr1);
					result = multiply(arr2, arr1);
					FlipSign(result);
				}
				else if(arr1->array[0] >= 0 && arr2->array[0] < 0)
				{
					FlipSign(arr2);
					result = multiply(arr1, arr2);
					FlipSign(result);
				}
				else
				{
					result = multiply(arr1, arr2);
				}
			}
		}
		
		else if(menu[0] == '4')
		{
			ask(res);
			if(res[0] == 'y')
			{
				if(result->array[0] < 0)
				{
					err = 1;
					result = cleanArray(result);
				}
				else
				{
					result = factorial(result);
				}
			}
			else
			{
				DynArray* arr = createDynArray();
				printf("Insert number:\n");
				arr = scanDynArray(arr);
				if(arr->array[0] < 0)
				{
					err = 1;
					freeDynArray(arr);
					result = cleanArray(result);
				}
				else
				{
					freeDynArray(result);
					result = factorial(arr);
				}
			}
		}
		else if(menu[0] == '5')
		{
			freeDynArray(result);
			return 0;
		}
		else
		{
			fputs("Fatal error.\n", stderr);
			exit(EXIT_FAILURE);
		}

	}while(1);
}

