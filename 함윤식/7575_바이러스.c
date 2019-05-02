#include<stdio.h>

int N, k;
int arr[100][1000];
int save[100][1000];
int arr_length[100];
int arr_0[1000];

void upside_Down(int * str_1, int * str_2)
{
	int num = 0;
	for (; *(str_1 + num) != 0; num++);

	for (int i = 0; num - 1 >= 0; i++, num--)
		*(str_2 + num - 1) = *(str_1 + i);
}
// arr1, 2는 arr[0]으로 고정
void compare(int * arr3, int arr3_length,int i)
{
	int num = 0;

	for (int n = 0; n < arr_length[0]; n++)
	{
		if (save[0][n] == 0)
			continue;
		for (int m = 0; m < arr3_length; m++)
		{
			if (*(arr[0] + n) == *(arr3 + m))
			{

				for (num = 0; *(arr3 + m + num) == *(arr[0] + n + num) && (m + num < arr3_length) && (n + num < arr_length[0]); num++);

				if (num < k)
					continue;

				else
				{
					for (int x = n; x < num + n; x++)
						*(save[i] + x) = 1;
					n += num;
				}
			}

		}
	}
	
	for (int n = 0; n < arr_length[0]; n++)
	{
		if (save[0][arr_length[0] - (n + 1)] == 0)
			continue;
		for (int m = 0; m < arr3_length; m++)
		{
			if (*(arr_0 + n) == *(arr3 + m))
			{
				for (num = 0; *(arr3 + m + num) == *(arr_0 + n + num) && (m + num < arr3_length) && (n + num < arr_length[0]); num++);

				if (num < k)
					continue;

				else
				{
					for (int x = n; x < num + n; x++)
						*(save[i] + arr_length[0] - (x + 1)) = 1;
					n += num;
				}
			}
		}
	}

	i++;
}

int main(void)
{
	
	int length;
	int i = 0,num=0;

	scanf("%d %d", &N, &k);


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &length);
		arr_length[i] = length;
		for (int j = 0; j < length; j++)
			scanf("%d", &arr[i][j]);
	}
	
	upside_Down(arr[0], arr_0);

	for (int j = 0; j < arr_length[0]; j++)
		save[0][j] = 1;

	for (int i = 1; i < N; i++)
	{
		compare(arr[i], arr_length[i], i);
		
		

		for (int j = 0; j < arr_length[0]; j++)
		{
			if (save[i][j] == 1)
				continue;
			save[i][j] = 0;
		}
		for (int j = 0; j < arr_length[0]; j++)
			save[0][j] = save[0][j] & save[i][j];
	}

	for (int j = 0; j < arr_length[0]; j++)
	{
		if (num >= k)
			break;
		if (save[0][j] == 1)
			num++;
		else
			num = 0;
	}
	if (num >= k)
		printf("YES");
	else
		printf("NO");
		
}

