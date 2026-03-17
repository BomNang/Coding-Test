//백준 11726 2xn타일링
//난이도 : 실버3

#include <iostream>
#include <vector>

using namespace std;


int DP(vector<int>& dp, int idx)
{
    if(dp[idx] != -1)
		return dp[idx];
    
    if (idx <= 2)
        return idx;

	dp[idx] = DP(dp, idx - 1) + DP(dp, idx - 2);

	return dp[idx] % 10007;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

	vector<int> dp(n + 1, -1);
    cout << DP(dp, n) << "\n";
    /*dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }

	cout << dp[n - 1] << "\n";*/
}