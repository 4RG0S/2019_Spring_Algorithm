#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_compact(char** img, int n);
int IsThisAllBlack(char** img, int n);
int IsThisAllWhite(char** img, int n);
char** SplitImg(char** img, int x_start, int x_end, int y_start, int y_end);

int main() {
	int n, i, j;
	char **img;

	scanf("%d", &n);
	img = (char**)malloc(sizeof(char*)*n);
	for (i = 0; i < n; i++)
		img[i] = (char*)malloc(sizeof(char)*n);

	for (i = 0; i < n; i++) {
		while (getchar() != '\n');
		for (j = 0; j < n; j++)
			scanf("%c", &img[i][j]);
	}


	if (IsThisAllBlack(img, n)) printf("1");
	else
		if (IsThisAllWhite(img, n)) printf("0");
		else print_compact(img, n);
	


	return 0;
}

void print_compact(char** img, int n) {
	char **img_quarter;
	int i, j;
	int n_quarter;

	n_quarter = n / 2;
	
	img_quarter = (char**)malloc(sizeof(char*)*n_quarter);
	for (i = 0; i < n_quarter; i++)
		img_quarter[i] = (char*)malloc(sizeof(char)*n_quarter);

	printf("(");
	
	
	for (i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			img_quarter = SplitImg(img, 0, n_quarter, 0, n_quarter); break;
		case 1:
			img_quarter = SplitImg(img, 0, n_quarter, n_quarter, n); break;
		case 2:
			img_quarter = SplitImg(img, n_quarter, n, 0, n_quarter); break;
		case 3:
			img_quarter = SplitImg(img, n_quarter, n, n_quarter, n); break;
		}

		if (IsThisAllBlack(img_quarter, n_quarter)) printf("1");
		else
			if (IsThisAllWhite(img_quarter, n_quarter)) printf("0");
			else print_compact(img_quarter, n_quarter);

	}
	
	printf(")");
}

int IsThisAllBlack(char** img, int n) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (img[i][j] != '1') return 0;

	return 1;
}

int IsThisAllWhite(char** img, int n) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (img[i][j] == '1') return 0;

	return 1;
}

char** SplitImg(char** img, int x_start, int x_end, int y_start, int y_end) {
	
	int i, j;
	char **img_quarter;

	img_quarter = (char**)malloc(sizeof(char*)*(x_end-x_start));
	for (i = 0; i < x_end-x_start; i++)
		img_quarter[i] = (char*)malloc(sizeof(char)*(x_end-x_start));

	for (i = x_start; i < x_end; i++)
		for (j = y_start; j < y_end; j++)
			img_quarter[i-x_start][j-y_start] = img[i][j];

	return img_quarter;
}