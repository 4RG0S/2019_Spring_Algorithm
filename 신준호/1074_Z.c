#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Z(int N, int r, int c, int offset);

int target_r, target_c;

int main() {
	int N, r, c;
	int i;

	scanf("%d %d %d", &N, &target_r, &target_c);
	
	Z(N, 0, 0, 0);
	
	return 0;
}

int Z(int N, int r, int c, int offset) {
	int i;
	int result = 0;
	int tmp_r, tmp_c;

	if (N == 0) {
		printf("%d", offset);
		return 1;
	}

	if (r + pow(2, N - 1) <= target_r) {
		tmp_r = r + pow(2, N - 1);
		offset += pow(pow(2, N), 2) / 4 * 2;
	}
	else tmp_r = r;
	
	if (c + pow(2, N - 1) <= target_c) {
		tmp_c = c + pow(2, N - 1);
		offset += pow(pow(2, N), 2) / 4;
	}
	else tmp_c = c;

	Z(N - 1, tmp_r, tmp_c, offset);

	return 0;
}