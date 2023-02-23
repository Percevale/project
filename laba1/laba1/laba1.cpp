#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
void Create_File(const char* name);
void open(const char* name);
void input(const char* name);
void minus(const char* name);
void replacement_minus(const char* name);
void sort(const char* name);
int main(int argc, char** argv)
{
	char* name = (char*)calloc(255, sizeof(char));
	if (argc > 1)
		name = argv[1];
	Create_File(name);
	int y1;
	float y, check = 1;
	while (check == 1)
	{
		printf("Choose your tasks\n1.input\n2.open\n3.minus\n4.replacement\n5.sort\n");
		while (scanf("%f", &y) != 1 || getchar() != '\n' || y < 0 || y>5)
		{
			printf("wrong input\n");
			rewind(stdin);
		}
		y1 = (int)y;
		switch (y1)
		{
		case 1:
			input(name);
			break;
		case 2:
			open(name);
			break;
		case 3:
			minus(name);
			break;
		case 4:
			replacement_minus(name);
			break;
		case 5:
			sort(name);
			break;
		}
		printf("\nContinue? 1-yes  2-no\n");
		while (scanf("%f", &check) != 1 || getchar() != '\n' || check < 0 || check>2)
		{
			printf("wrong input\n");
			rewind(stdin);
		}
	}
	return 0;

}
