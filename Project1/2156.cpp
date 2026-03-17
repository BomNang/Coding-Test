//백준 2156 포두주 시식
//난이도 : 실버1

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> wines(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        int num;
        cin >> num;
        wines[i] = num;
    }

    vector<long long> dp(N + 1, 0);
	if (N >= 1) dp[1] = wines[1];
	if (N >= 2) dp[2] = wines[1] + wines[2];
    if (N >= 3)
    {
        for (int i = 3; i <= N; ++i)
        {
            dp[i] = max({
                    dp[i - 1],
                    dp[i - 2] + wines[i],
                    dp[i - 3] + wines[i - 1] + wines[i]
                });
        }
    }
    

	cout << dp[N] << "\n";
}