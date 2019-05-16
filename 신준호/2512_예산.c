#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int* req, int n);
int IsSumLessThanBudget(int* req, int n, int budget);
void DecreaseOverReq(int* req, int n, int max_value);

int main() {
	int n, budget;
	int i;
	int *req;
	int max_value;

	scanf("%d", &n);
	req = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", req+i);
	scanf("%d", &budget);
	
	max_value = max(req, n);

	while (!IsSumLessThanBudget(req, n, budget)) {
		max_value--;
		DecreaseOverReq(req, n, max_value);
	}

	printf("%d", max_value);

	return 0;
}

int max(int* req, int n) {
	int i;
	int ret = 0;

	for (i = 0; i < n; i++)
		if (ret < req[i]) ret = req[i];

	return ret;
}

int IsSumLessThanBudget(int* req, int n, int budget) {
	int i;
	int sum = 0;

	for (i = 0; i < n; i++)
		sum += req[i];

	return sum <= budget ? 1 : 0;
}

void DecreaseOverReq(int* req, int n, int max_value) {
	int i;

	for (i = 0; i < n; i++)
		if (req[i] > max_value) req[i] = max_value;
}