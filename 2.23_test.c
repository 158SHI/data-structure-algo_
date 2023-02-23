#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>

int main()
{
	int* p = (int*)malloc(sizeof(int) * 5);
	//int* tmp1 = (int*)realloc(p, sizeof(int) * 6);
	//int* tmp2 = (int*)realloc(p, sizeof(int) * 5);
	printf("%p\n", p);
	int* tmp = (int*)realloc(p, sizeof(int) * 6);
	printf("%p\n", tmp);

	return 0;
}