#include <stdio.h>
#include <string.h>

#include "Operations.h"
#include "Interface.h"
#include "Arrays_management.h"

int main(void)
{
	DynArray* result = createDynArray();
	insertDynArray(result, 0);
	char err = 0;
	char res[3], menu[3];
	do
	{
		system("clear");
		printf("What would you like to do?\n1. Add\n2. Subtract\n3. Multiply\n4. Factorial\n5. Exit\nResult: ");
		for(int i = 0; i < result->used; i++)
			printf("%d", result->array[i]);
		
		printf("\n");

		if(err == 1)
			printf("Factorial is defined only for not negative numbers!\n");

		err = 0;
		
		while(scanf("%2[^\n]", menu) == 0 || strlen(menu) > 1 || menu[0] >'5' || menu[0] < '1')
		{
			printf("Unavaible command. Użyj liczby z zakresu 1-5. Spróbuj ponownie.\n");
			cleanBuff();
		}
		cleanBuff();
		
		if(menu[0] == '1')
		{
			ask(res);
			if(res[0] == 'y')
			{	
				DynArray* arr2 =  createDynArray();
				printf("Insert second number:\n");
				arr2 = scanDynArray(arr2);
				if(result->array[0] < 0 && arr2->array[0] < 0)
				{
					FlipSign(result);
					FlipSign(arr2);
					result = addition(result, arr2);
					FlipSign(result);	
				}
				else if(result->array[0] < 0 && arr2->array[0] >= 0)
				{
					FlipSign(result);
					result = subtraction(arr2, result);
				}
				else if(result->array[0] >= 0 && arr2->array[0] < 0)
				{
					FlipSign(arr2);
					result = subtraction(result, arr2);
				}
				else
				{
					result = addition(result, arr2);
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
				if(result->array[0] < 0 && arr2->array[0] < 0)
				{
					FlipSign(result);
					FlipSign(arr2);
					result = subtraction(arr2, result);	
				}
				else if(result->array[0] < 0 && arr2->array[0] >= 0)
				{
					FlipSign(result);
					result = addition(arr2, result);
					FlipSign(result);
				}
				else if(result->array[0] >= 0 && arr2->array[0] < 0)
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
				if(result->array[0] < 0 && arr2->array[0] < 0)
				{
					FlipSign(result);
					FlipSign(arr2);
					result = multiply(arr2, result);	
				}
				else if(result->array[0] < 0 && arr2->array[0] >= 0)
				{
					FlipSign(result);
					result = multiply(arr2, result);
					FlipSign(result);
				}
				else if(result->array[0] >= 0 && arr2->array[0] < 0)
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
					err = 2;
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

