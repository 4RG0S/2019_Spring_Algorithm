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
	
	answer[0] = abs(p[0].second)*2;	//초기값.

	for (int i = 1; i < n; i++)
	{	
		//초기값: i번째 건물이 혼자 별도의 정사각형에 있다고 친다
		answer[i] = answer[i-1]+abs(p[i].second) * 2;
		int maxlen = abs(p[i].second);
		for (int j = i-1; j >=0; j--)
		{	//i번째 건물을 감싼 정사각형이 j번째 건물 까지 감쌀 때의 값과 현재의 값 중 더 작은것을 택
			maxlen = max(maxlen, abs(p[j].second));	//처음에 세로 길이 비교
			//세로 길이와 가로 길이 비교, 더 긴 것이 정사각형의 길이가 됨
			int reallen = max(2 * maxlen, p[i].first - p[j].first);
			if(j==0)
				answer[i] = min(answer[i], reallen);		//j가 0이라서 더할 answer가 없음
			else
				answer[i] = min(answer[i], reallen + answer[j - 1]);
		}
		//std::cout << i <<"번째: "<<answer[i]<<"\n";
	}
	std::cout << answer[n-1];

}