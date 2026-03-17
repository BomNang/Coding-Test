//백준 1로 만들기
//난이도 : 실버3

#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 1e9);
    dp[N] = 0;
    for (int i = N; i >= 0; --i)
    {
        if(i - 3 >= 0 && dp[i - 3] > dp[i] + 1)
			dp[i - 3] = dp[i] + 1;

        if (i - 5 >= 0 && dp[i - 5] > dp[i] + 1)
            dp[i - 5] = dp[i] + 1;
    }

    if(dp[0] != 1e9)
        cout << dp[0] << "\n";
    else
        cout << -1 << "\n";
}