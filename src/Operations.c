#include "Arrays_management.h"
#include "Operations.h"

DynArray* addition(DynArray* arr1, DynArray* arr2)
{
	DynArray* result = createDynArray();
	insertDynArray(result, 0);
	ReverseArray(arr1);
	ReverseArray(arr2);
	while(arr1->used != arr2->used)
	{
		if(arr1->used > arr2->used)
			insertDynArray(arr2, 0);
		else
			insertDynArray(arr1, 0);
	}
	for(int i = 0; i < arr1->used; i++)
	{
		result->array[i] += arr1->array[i] + arr2->array[i]; 
		if(result->array[i] >= 10)
		{
			insertDynArray(result, result->array[i] / 10);
			result->array[i] = result->array[i] % 10;
		}
		else
		{
			insertDynArray(result, (arr1->array[i] + arr2->array[i]) / 10);
		}
	}
	
	ReverseArray(result);
	result = DelZeros(result);
	freeDynArray(arr1);
	freeDynArray(arr2);
	return result;
}

DynArray* subtraction(DynArray* arr1, DynArray* arr2)
{
	DynArray* result = createDynArray();
	short int a = Max(arr1, arr2);
	ReverseArray(arr1);
	ReverseArray(arr2); 
	while(arr1->used != arr2->used)
	{
		if(arr1->used > arr2->used)
			insertDynArray(arr2, 0);
		else
			insertDynArray(arr1, 0);
	}
	
	if(a == 0)
	{
		insertDynArray(result, 0);
		freeDynArray(arr1);
		freeDynArray(arr2);
		return result;
	}
	else if(a == 1)
	{
		for(int i = 0; i < arr2->used; i++)
		{
			insertDynArray(result, (arr1->array[i] - arr2->array[i]));
			if(result->array[i] < 0)
			{
				result->array[i] += 10;
				arr1->array[i+1] += (-1);
				int j = i + 1;
				while(arr1->array[j] < 0)
				{
					arr1->array[j] += 10;
					arr1->array[j+1]--;
					j++;
				}	
			}
		}
	
	ReverseArray(result);
	result = DelZeros(result);
	freeDynArray(arr1);
	freeDynArray(arr2);
	return result;
	}
	else
	{
		for(int i = 0; i < arr1->used; i++)
		{
			insertDynArray(result, arr2->array[i] - arr1->array[i]);
			if(result->array[i] < 0)
			{
				result->array[i] += 10;
				arr2->array[i+1]--;
				int j = i + 1;
				while(arr2->array[j] < 0)
				{
					arr2->array[j] += 10;
					arr2->array[j+1]--;
					j++;
				}	
			}	
		}

	}
	
	ReverseArray(result);
	result = DelZeros(result);
	FlipSign(result);
	freeDynArray(arr1);
	freeDynArray(arr2);
	return result;
}

DynArray* multiply(DynArray* arr1, DynArray* arr2)
{
	DynArray* result = createDynArray();
	insertDynArray(result, 0);
	arr1 = DelZeros(arr1);
	arr2 = DelZeros(arr2);
        if(arr1->array[0] == 0 || arr2->array[0] == 0)
        {
        	freeDynArray(arr1);
        	freeDynArray(arr2);
		return result;
        }
        ReverseArray(arr1);
        ReverseArray(arr2);
        for(int i = 0; i < arr2->used; i++)
        {
        	DynArray* help = createDynArray();
		insertDynArray(help, 0);
		
        	for(int j = 0; j < arr1->used; j++)
        	{
        		help->array[j] += arr1->array[j] * arr2->array[i];
        		if(help->array[j] >= 10)
			{
				insertDynArray(help, help->array[j] / 10);
				help->array[j] = help->array[j] % 10;
			}
			else
			{
				insertDynArray(help, (arr1->array[j] * arr2->array[i]) / 10);
			}
        	}
        	ReverseArray(help);
        	help = DelZeros(help);
        	for(int k = 0; k < i; k++)
        		insertDynArray(help, 0);
        		
        	result = addition(result, help);
        }
	freeDynArray(arr1);
        freeDynArray(arr2);
	return result;
}

DynArray* factorial(DynArray* arr)
{
	DynArray* result = createDynArray();
	DynArray* counter = createDynArray();
	insertDynArray(result, 1);
	insertDynArray(counter, 0);
	while(Max(counter, arr) != 0)
	{	
		DynArray* arrcopy = createDynArray();
		for(int i = 0; i < arr->used; i++)
			insertDynArray(arrcopy, arr->array[i]);
			
		DynArray* help = createDynArray();
		insertDynArray(help, 1);
		result = multiply(result, arrcopy);
		arr = subtraction(arr, help);
	}

	freeDynArray(counter);
	freeDynArray(arr);
	return result;
}