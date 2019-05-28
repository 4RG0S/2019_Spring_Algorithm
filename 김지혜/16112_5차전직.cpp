using namespace std;

#include <utility>
#include <iostream>
#include <algorithm>

int main()
{
	int n, k;

	std::cin >> n >> k;

	int *a = (int*)malloc(sizeof(int) * 300001);

	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	sort(a, a + n);
	long long answer = 0;

	for (int i = 1; i < n; i++)
	{
		if (i<k) answer = answer + (long long)a[i] * i;
		else answer = answer + (long long)a[i] * k;
	}

	std::cout << answer;
	free(a);

	return 0;
}