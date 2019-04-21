/**
 * 	@file Operations.c
 * 	@brief This source file will contain mathematical operations on DynArrays. 
 * 
 * 	@author Tymoteusz Perka
 *
 * 	@date 26/03/2019
 **/
#include "Arrays_management.h"
#include "Operations.h"
/**
 * @brief This is something like overloaded + operator for our struct.
 * 
 * At the beggining it reverses both arrays and checks if arr1 and arr2 have the same number of elements.
 * If not, it fills the smaller one with zeros and then the addition is done from left to right (since our
 * arrays are reversed) the same way you do it by your hand (summing numbers on every position and carrying
 * overflow).
 * 
 * @warning Both arr1 and arr2 are freed after this operation.
 * 
 * @param Two arrays we want to add. 
 * @return Pointer to DynArray which is result of adding numbers stored in arr1 and arr2.
 */
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
/**
 * @brief This is something like overloaded - operator for our struct.
 * 
 * At the beggining it checks which array stores larger number, reverses both arrays and checks if arr1 and arr2 have the same number of elements.
 * If not, it fills the smaller one with zeros and then the subtraction is done from left to right (since our
 * arrays are reversed) the same way you do it by your hand (subtracting numbers on every position and filling underflow by borrowing).
 * 
 * @note This operation always returns positive number or zero since we subtract smaller number
 * 		 from bigger number.
 * 
 * @warning Both arr1 and arr2 are freed after this operation.
 * 
 * @param Two arrays we want to subtract. 
 * @return Pointer to DynArray which is result of subtracting number stored in arr2 from arr1.
 */
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
/**
 * @brief This is something like overloaded * operator for our struct.
 * 
 * At the beggining it checks if any of DynArrays represents zero. If yes, it returns 0 no matter what second array looks like. Otherwise it reverses arrays and
 * then the multiplication is done from left to right (since our arrays are reversed) the same way you do it by your hand:
 * Firstly, help array is created. Then all digits in arr1 are multiplied by the last digit in arr2, carring overflow to the next position and storing result as help.
 * Then help is reversed and filled with as many zeros as iterations of the loop (which is also the position of number of arr 2 which we multiplicated by)
 * and added to result. It repeats arr2->used times.
 * 
 * @warning Both arr1 and arr2 are freed after this operation.
 * 
 * @param Two arrays we want to multiply. 
 * @return Pointer to DynArray which is result of multiplying numbers stored in arr1 and arr2.
 */
DynArray* multiply(DynArray* arr1, DynArray* arr2)
{
	DynArray* result = createDynArray();
	insertDynArray(result, 0);

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
/**
 * @brief This function returns factorial of number stored in arr.
 * 
 * At the beginning it creates two DynArrays- counter and result, filling counter with 0 and result with 1. Then a copy of arr is done, help array created
 * and initialised with 1. Result and arrcopy are multiplicated and stored as result and number stored in arr is reduced by one using help array(something like --).
 * It is repeated as long as arr != 0.
 * @warning Both arr is freed after this operation.
 * 
 * @param Array we want to take factorial from. 
 * @return Pointer to DynArray which is result of factorial.
 */
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