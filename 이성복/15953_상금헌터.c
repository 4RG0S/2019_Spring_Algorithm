#include<stdio.h>

int main()
{
	int N;
	int a, b;
	int prize = 0;
	int first[] = {0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10};
	int second[] = {0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &a, &b);
		if (a > sizeof(first) / sizeof(int) - 1) {
			a = 0;
		}
		if (b > sizeof(second) / sizeof(int) - 1) {
			b = 0;
		}
		if (first[a] == 0 && second[b] == 0) {
			printf("0\n");
		}
		else {
			prize = first[a] * 10000 + second[b] * 10000;
			printf("%d\n", prize);
		}
	}

	return 0;
}