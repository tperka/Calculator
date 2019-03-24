#ifndef ARRAYS_MANAGEMENT_H
#define ARRAYS_MANAGEMENT_H

#include <stdlib.h>

typedef struct 
{
	char *array;
    size_t used;
	size_t size;
} DynArray;

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