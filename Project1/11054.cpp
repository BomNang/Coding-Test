//백준 11054 가장 긴 바이토닉 부분 수열
//난이도 : 골드4

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }
    //자리를 기준으로 해당 자리 왼쪽과 오른쪽 최대값들을 구함
    //구한 왼쪽과 오른쪽을 더해서 최종 값 산출
   
    vector<int> lDP(N, 1);
    vector<int> rDP(N, 1);
    
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
                lDP[i] = max(lDP[i], lDP[j] + 1);
        }
    }

    for (int i = N - 2; i >= 0; --i)
    {
        for (int j = N - 1; j > i; --j)
        {
            if (nums[i] > nums[j])
                rDP[i] = max(rDP[i], rDP[j] + 1);
        }
    }

    int result = 0;
    for (int i = 0; i < N; ++i)
        result = max(result, rDP[i] + lDP[i] - 1);

    cout << result << "\n";
}