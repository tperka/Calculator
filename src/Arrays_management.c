/**
 * 	@file Arrays_management.c
 * 	@brief This source file will contain functions operating on DynArrays (something like methods). 
 * 
 * 	@author Tymoteusz Perka
 *
 * 	@date 26/03/2019
 */
#include <stdio.h>

#include "Arrays_management.h"


/**
 * @brief "Constructor" of our struct.
 * 
 * This function allocates memory needed to create an instance
 * of DynArray, sets default values (size = 1, used = 0).
 *
 * @return Pointer to allocated DynArray.
 * 
 * Use it as follow:
 * @code
 * DynArray* X = createDynArray();
 * @endcode
**/
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
/**
 * @brief "Setter" of our struct.
 * 
 * This function checks if our DynArray is full and then
 * adds element to our array, either by changing the value
 * of the first free space or by reallocating the array with
 * size.
 *
 *@param arr a pointer to our DynArray.
 *@param element a value we want to add to our array.
 *
**/
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
/**
 * @brief "Destructor" of our struct.
 * 
 * This function frees memory allocated for array member
 * of DynArray and then frees the pointer to this struct.
 * 
 * @param arr the object we want to destroy.
 **/
void freeDynArray(DynArray *arr) 
{
	free(arr->array);
	free(arr);
}
/**
 * @brief Deletes first element from array.
 * 
 * It creates a new object and copy the old one without
 * first element.
 * 
 * @param arr the array we want to delete first element from.
 * 
 * @return It returns the same array without the first element.
 * 
 * Use it as follow:
 * @code
 * //DynArray* X
 * //...
 * X = DelFirstElement(X);
 * @endcode
 **/
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
/**
 * @brief Reverse the stored array.
 * 
 * @param arr array we want to reverse.
**/
void ReverseArray(DynArray* arr)
{
	for(int i = 0; i < (arr->used/2); ++i)
	{
		int temp = arr->array[i];
		arr->array[i] = arr->array[arr->used-1-i];
		arr->array[arr->used-1-i] = temp;
	}
}
/**
 * @brief Name say it all
**/
void FlipSign(DynArray* arr)
{
	arr->array[0] *= (-1);
}
/**
 * @brief This function removes all the leading zeros.
 * 
 * For example, it converts 000003 to 3. It is done by removing first elements
 * until we reach non-zero.
 * 
 * @param arr an array we want to remove leading zeros from.
 * @return The same array without leading zeros.
 * 
 * @note It should be used the same way as DelFirstElement().
 **/
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
/**
 * @brief Cleans an array.
 * 
 * It simply creates array containing only 0 and
 * frees the old one.
 * 
 * @param arr array we want to 'reset'
 * @return Pointer to new array, containing only 0.
 * 
 * @note It should be used the same way as DelFirstElement().
 **/
DynArray* cleanArray(DynArray* arr)
{
	freeDynArray(arr);
	DynArray* arr2 = createDynArray();
	insertDynArray(arr2, 0);
	return arr2;
}
/**
 * @brief This function compares two DynArrays.
 * 
 * Precisely, it compares two numbers stored in DynArrays.
 * 
 * @param arr1 
 * @param arr2 
 * @return 1 if arr1 > arr2, 2 if arr1 < arr2 or 0 if arr1 = arr2
 */
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