#ifndef INTERFACE_H
#define INTERFACE_H
#include "Arrays_management.h"

void cleanBuff();
void scanChar(char ar[]);
void ask(char *res);
DynArray *checkSign(DynArray *arr);
int loadInt(char *str, DynArray *arr);
DynArray *scanDynArray(DynArray *arr);

#endif
