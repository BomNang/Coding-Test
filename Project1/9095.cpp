//백준 9095 1,2,3 더하기
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
	vector<int> nums;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        vector<int> dp(num + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < num; ++i)
        {
            if (i + 1 <= num)
                dp[i + 1] += dp[i];

            if (i + 2 <= num)
                dp[i + 2] += dp[i];

            if (i + 3 <= num)
                dp[i + 3] += dp[i];
        }

		nums.push_back(dp[num]);
    }

    for(int num : nums)
		cout << num << "\n";
}