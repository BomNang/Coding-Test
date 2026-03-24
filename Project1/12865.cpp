//백준 12865 평범한 배낭
//난이도 : 골드5

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int dp[100001] = { 0, };

    for (int i = 0; i < N; ++i)
    {
        int weight, value;
        cin >> weight >> value;
        
        //최대무게와 입력한 무게 사이의 값들을 저장하고 재활용
        //(max무게가 7이고 입력 무게가 5면 2나 1이 들어오는게 아닌이상 5,6,7은 5일때 가치와 같음)
        for (int j = K; j >= weight; --j)
            dp[j] = max(dp[j], dp[j - weight] + value);
    }

    cout << dp[K] << "\n";
}