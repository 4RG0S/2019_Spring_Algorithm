#include<stdio.h>

void sort(int * arr, int i, int j)    //버블정렬
{
	arr[i] = 100;
	arr[j] = 100;
	int save;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				save = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = save;
			}
		}

	}
}


int main(void)
{
	int arr[9];
	int total=0;

	for (int i = 0; i < 9; i++)   //난쟁이 키 입력
		scanf("%d", arr + i);

	for (int i = 0; i < 9; i++)   //9명 합
		total += arr[i];

	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if ((total - arr[i] - arr[j] == 100))
			{
				sort(arr, i, j);
				for (int k = 0; k < 7; k++)
					printf("%d\n", arr[k]);
			}

		}
		
	}

}