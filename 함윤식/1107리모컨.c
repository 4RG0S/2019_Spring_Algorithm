#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

int count_Length(int i)
{
	int j = 10;
	int length;
	for (length = 1; i / j != 0; length++, j *= 10);

	return length;
	
}

int main(void)
{
	int N, M, result;
	int length;
	int kkk;
	char num[10] = {0};


	scanf("%d %d", &N, &M);
	for (int i = 0, j; i < M; i++)
	{
		scanf("%d", &j);
		num[j] = 1;
	}

	result = abs(N - 100);

	for (int i = 0; i <= 1000000; i++)
	{
		kkk = 0;
		length = count_Length(i);

		for (int j = 0, k = i; j < length; j++)
		{
			if (num[k % 10] != 0)
			{
				kkk = 1;
				break;
			}
			k /= 10;
		}

		if(kkk==0)
			if (abs(i - N) + length < result)
				result = abs(i - N) + length;
	}

	printf("%d", result);
}