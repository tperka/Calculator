#include <stdio.h>

#include "Arrays_management.h"

DynArray* createDynArray()
{
	DynArray* arr = malloc(sizeof(DynArray));
	AllocCheck(arr);
	arr->array = (char*)malloc(sizeof(char));
	AllocCheck(arr->array);
	arr->used = 0;
	arr->size = 1;
	return arr;
}

void insertDynArray(DynArray *arr, int element)
{
	if (arr->used == arr->size) 
	{
		arr->size += 1;
		arr->array = (char*)realloc(arr->array, arr->size * sizeof(char));
		AllocCheck(arr->array);
	}
	arr->array[arr->used++] = (char)element;
}

void freeDynArray(DynArray *arr) 
{
	free(arr->array);
	free(arr);
}

DynArray* DelFirstElement(DynArray* arr)
{
	DynArray* arr2 = createDynArray();
	if(arr->used > 1)
	{
		for(int i = 1; i < arr->used; i++)
			insertDynArray(arr2, arr->array[i]);
	}
	else
	{
		insertDynArray(arr2, 0);
	}	
	freeDynArray(arr);
	return arr2;
}

void ReverseArray(DynArray* arr)
{
	for(int i = 0; i < (arr->used/2); ++i)
	{
		int temp = arr->array[i];
		arr->array[i] = arr->array[arr->used-1-i];
		arr->array[arr->used-1-i] = temp;
	}
}

void FlipSign(DynArray* arr)
{
	arr->array[0] *= (-1);
}

DynArray* DelZeros(DynArray* arr)
{
        while(arr->array[0] == 0)
        {
        	if(arr->used > 1)
        	{
        		arr = DelFirstElement(arr);
        	}
        	else
        	{
        		break;
        	}
        }
       	return arr;
}

DynArray* cleanArray(DynArray* arr)
{
	freeDynArray(arr);
	DynArray* arr2 = createDynArray();
	insertDynArray(arr2, 0);
	return arr2;
}

int Max(DynArray* arr1, DynArray* arr2)
{
	if(arr1->used>arr2->used)
		return 1;
	else if (arr1->used<arr2->used)
		return 2;
	else
	{
		for(int i = 0; i < arr1->used; i++)
		{	
			if(arr1->array[i] > arr2->array[i])
				return 1;
			else if(arr1->array[i] < arr2->array[i])
				return 2;
		}
	}
	return 0;	
}