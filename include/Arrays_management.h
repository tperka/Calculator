/**
 * 	@file Arrays_management.h
 * 	@brief This header file will contain definition of struct used
 * 	inf whole program and functions operating on them (something like methods)
 *
 * 	@author Tymoteusz Perka
 *
 * 	@date 26/03/2019
 */

#ifndef ARRAYS_MANAGEMENT_H
#define ARRAYS_MANAGEMENT_H

#include <stdlib.h>
/**
 * @brief Our main struct on which we operate.
 * 
 * This is something like vector in C++. Using pointer instead of array allows us to malloc and realloc memory
 * if we have overflow. I used char instead of int because we will only store single digits on each position.
 * 
 */
typedef struct
{
	char *array;
    size_t used;
	size_t size;
}DynArray;

void* AllocCheck(void *p);

DynArray* createDynArray();

void insertDynArray(DynArray *a, int element);

void freeDynArray(DynArray *arr);

DynArray* DelFirstElement(DynArray* arr);

void ReverseArray(DynArray* arr);

void FlipSign(DynArray* arr);

DynArray* DelZeros(DynArray* arr);

DynArray* cleanArray(DynArray* arr);

int Max(DynArray* arr1, DynArray* arr2);

#endif