#include<stdio.h>


int main(void)
{
	int number;
	int total = 0;
	int k = 0;


	scanf_s("%d", &number);

	for (int i = 1; i <= 1000000; i++)
	{
		if (i == number)
		{
			printf("%d", 0);
			break;
		}
		total = 0;
		for (int j = 6; j > -1; j--)
		{
			int l = j;
			for (k=1; l > 0; l--)
			{
				k *= 10;
				
			}
			total += (i / k) % 10;
			
		}
		if(number==total+i)
		{
			printf("%d", i);
			break;
		}

	}
}