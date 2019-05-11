using namespace std;

#include <utility>
#include <iostream>
#include <algorithm>

int main()
{
	int n, x, y;
	pair<int, int> p[10001];
	std::cin >> n;

	int answer[10001];

	for (int i = 0; i<n ; i++)
	{
		std::cin >> x; std::cin >> y;
		p[i].first = x; p[i].second = y;
	}
	sort(p, p+n);
	
	answer[0] = abs(p[0].second)*2;	//�ʱⰪ.

	for (int i = 1; i < n; i++)
	{	
		//�ʱⰪ: i��° �ǹ��� ȥ�� ������ ���簢���� �ִٰ� ģ��
		answer[i] = answer[i-1]+abs(p[i].second) * 2;
		int maxlen = abs(p[i].second);
		for (int j = i-1; j >=0; j--)
		{	//i��° �ǹ��� ���� ���簢���� j��° �ǹ� ���� ���� ���� ���� ������ �� �� �� �������� ��
			maxlen = max(maxlen, abs(p[j].second));	//ó���� ���� ���� ��
			//���� ���̿� ���� ���� ��, �� �� ���� ���簢���� ���̰� ��
			int reallen = max(2 * maxlen, p[i].first - p[j].first);
			if(j==0)
				answer[i] = min(answer[i], reallen);		//j�� 0�̶� ���� answer�� ����
			else
				answer[i] = min(answer[i], reallen + answer[j - 1]);
		}
		//std::cout << i <<"��°: "<<answer[i]<<"\n";
	}
	std::cout << answer[n-1];

}