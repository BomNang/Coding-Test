//백준 11035  가장 긴 증가하는 부분 수열 
//난이도 : 실버2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
    {
        int num;
		cin >> num;
        nums[i] = num;
    }

    vector<int> dp(N, 1);


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
	

	cout << *max_element(dp.begin(), dp.end()) << "\n";
}