#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 100 + 1;
int N, K;
int schedule[MAX], plug[MAX];
int main(void)

{
        ios_base::sync_with_stdio(0);

        cin.tie(0); //cin 실행속도 향상

        cin >> N >> K;

        for (int i = 0; i < K; i++)
                 cin >> schedule[i];

        int result = 0;
        for (int i = 0; i < K; i++)
        {
                 bool pluggedIn = false;
                 //해당 기기가 꽂혀있는지 확인
                 for (int j = 0; j < N; j++)
                         if (plug[j] == schedule[i])
                         {
                                 pluggedIn = true;
                                 break;
                         }
                 if (pluggedIn)
                         continue;
                 //비어있는 구멍 확인
                 for (int j = 0; j < N; j++)
                         if (!plug[j])
                        {
                                 plug[j] = schedule[i];
                                 pluggedIn = true;
                                 break;
                         }
                 if (pluggedIn)
                   continue;
                 //가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾고
                 int idx, deviceIdx = -1;
                 for (int j = 0; j < N; j++)
                 {
                         int lastIdx= 0;
                         for (int k = i + 1; k < K; k++)
                         {
                                 if (plug[j] == schedule[k])
                                          break;
                                 lastIdx++;
                         }
                         if (lastIdx > deviceIdx)
                         {
                                 idx = j;
                                deviceIdx = lastIdx;
                         }
                 }
                 result++;
                 //앞서 찾은 기기가 꽂혀있던 곳에 현재 꽂을 예정이였던 기기를 꽂음
                 plug[idx] = schedule[i];
        }
        cout << result << "\n";
        return 0;
}