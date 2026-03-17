//백준 1149 RGB거리
//난이도 : 실버1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int c;
            cin >> c;
            cost[i][j] = c;
		}
    }

    vector<vector<int>> dp(n, vector<int>(n, 1e9));

	dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (j == k)
                    continue;

                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + cost[i + 1][k]);
            }
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
}