#include "pch.h"
#include <stdio.h>

void passByVal(int val);
void passByRef(int & ref);
void passByPtr(int * ptr);

int main()
{
	int x = 5;
	int *xptr = &x;
	printf("x = %i\n", x);
	printf("*xptr = %i\n", *xptr);
	passByPtr(xptr);
	printf("x = %i\n", x);
	printf("*xptr = %i\n", *xptr);
	return 0;
}

void passByVal(int val) {
	val = 10;
	printf("val = %i\n", val);
}
void passByRef(int & ref) {
	ref = 20;
	printf("ref = %i\n", ref);
}
void passByPtr(int * ptr) {
	*ptr = 30;
	printf("*ptr = %i\n", *ptr);
}