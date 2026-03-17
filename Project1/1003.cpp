//백준 1003 피보나치 함수
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

    vector<pair<int, int>> results;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            results.push_back({ 0, 1 });
            continue;
        }
        else if (num == 1)
        {
            results.push_back({ 1, 0 });
            continue;
        }

        vector<int> dp(num + 1, 0);

        dp[num] = 1;
        for (int i = num; i > 1; --i)
        {
            if (i - 1 >= 0)
                dp[i - 1] += dp[i];

            if (i - 2 >= 0)
                dp[i - 2] += dp[i];
        }

		results.push_back({ dp[1], dp[0] });
		
    }

    for (auto data : results)
    {
		cout << data.second << " " << data.first << "\n";   
    }
}