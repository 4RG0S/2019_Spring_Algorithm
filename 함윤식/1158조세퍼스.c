#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int N,k,i;
	i = 0;
	int number = 0;
	int arr[5000];

	scanf("%d %d", &N, &k);
	

	for (i = 0; i < N; i++)
		arr[i] = i+1;


	i = -1;


	printf("<");
	while (1)
	{
		for (int j = 0; j < k;)
		{
			i++;

			if (i == N)
				i -= N;

			if (arr[i] == 0)
				continue;
			j++;
		}


		number++;

		if (number == N)
			break;
		printf("%d, ",arr[i]);
		arr[i] = 0;
	
	}

	printf("%d>", arr[i]);
}