#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Create_File(const char* name)
{
	char* temp = (char*)calloc(255, sizeof(char));
	FILE* S1 = fopen(name, "wb+");
	if (S1 != NULL)
	{
		printf("file create\n");
	}
	else
	{
		printf("file not found\n");
		return;
	}
	fclose(S1);
}
void input(const char* name)
{
	FILE* S1 = fopen(name, "rb+");
	if (S1 != NULL)
	{
		printf("file create\n");
	}
	else
	{
		printf("file not found\n");
		return;
	}
	printf("input number of nunbers");
	int N, k;
	while (scanf("%d", &N) != 1 || getchar() != '\n')
	{
		printf("wrong input\n");
		rewind(stdin);
	}
	while (N <= 0)
	{
		printf("Incorrect input\n");
		rewind(stdin);
		fscanf(stdin, "%d", &N);
	}
	rewind(stdin);
	for (int i = 0; i < N; i++)
	{
		while (scanf("%d", &k) != 1 || getchar() != '\n')
		{
			printf("wrong input\n");
			rewind(stdin);
		}
		fwrite(&k,sizeof(int),1,S1);
	}
	fclose(S1);
}
void open(const char* name)
{
	FILE* S1 = fopen(name, "rb+");
	int temp = 0;
	if (S1 != NULL)
	{
		printf("file create\n");
	}
	else
	{
		printf("file not found\n");
		return;
	}
	while (fread(&temp,sizeof(int),1,S1) == 1)
	{
		printf("%4d", temp);
	}
	fclose(S1);
}

void minus(const char* name)
{
	FILE* S1 = fopen(name, "rb+");
	int temp = 0,cout = 0;
	if (S1 != NULL)
	{
		printf("\nfile create\n");
	}
	else
	{
		printf("file not found\n");
		return;
	}
	while (fread(&temp,sizeof(int),1,S1) == 1)
	{
		if(temp<0)
		cout++;
	}
	printf("%d\n", cout);
	fclose(S1);
}
void replacement_minus(const char* name)
{
	int temp = 0, temp1 = 0;
	int pos;
	FILE* S1 = fopen(name, "rb+");
	if (S1 != NULL)
	{
		printf("create\n");
	}
	else
	{
		printf("file not found\n");
		return;
	}
	fread(&temp, sizeof(int), 1, S1);
	temp1 = temp;
	while (fread(&temp, sizeof(int), 1, S1) == 1)
	{
		if (temp >= temp1)
		{
			temp1 = temp;
		}
	}
	fseek(S1, 0, SEEK_END);
	pos = ftell(S1);
	int n = pos / sizeof(int);
	rewind(S1);
	fseek(S1, 0, SEEK_SET);
	for (int i = 0; i < n; i++)
	{
		fseek(S1, i * sizeof(int), SEEK_SET);
		fread(&temp, sizeof(int), 1, S1);

		if (temp < 0)
		{
			fseek(S1, i * sizeof(int), SEEK_SET);
			fwrite(&temp1, sizeof(int), 1, S1);
		}
	}
	fclose(S1);
}
void sort(const char* name)
{
	int num1, num2;
	FILE* S1 = fopen(name, "rb+");
	if (S1 != NULL)
	{
		printf("create\n");
	}
	else
	{
		printf("file not found\n");
		return;
	}
	int pos;
	fseek(S1, 0, SEEK_END);
	pos = ftell(S1);
	int n = pos / sizeof(int);
	rewind(S1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n - 2; j++)
		{
			fseek(S1, j * sizeof(int), SEEK_SET);
			fread(&num1, sizeof(int),1, S1);
			fread(&num2, sizeof(int), 1, S1);
			if (num1 > num2)
			{
				fseek(S1, j * sizeof(int), SEEK_SET);
				fwrite(&num2, sizeof(int), 1, S1);
				fwrite(&num1, sizeof(int), 1, S1);
			}

		}
	}
	fclose(S1);
}