//백준 12865 평범한 배낭
//난이도 : 골드5

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[100001] = {0};
    

    int N, K;

	cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int w, v;
        cin >> w >> v;
        for (int j = K; j >= w; --j)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[K] << "\n";
    
}