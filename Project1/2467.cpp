//백준 2467 용액
//난이도 : 골드5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> liquid(N, 0);

    for (int i = 0; i < N; ++i)
    {
        int att;
        cin >> att;
        liquid[i] = att;
    }
    
    sort(liquid.begin(), liquid.end());

    int left = 0, right = N - 1;
    long long best = 2e18;
    pair<long long, long long> ans;
    while (left < right)
    {
        long long sum = liquid[left] + liquid[right];

        if (abs(sum) < best)
        {
            best = abs(sum);
            ans = { liquid[left], liquid[right] };
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << ans.first << " " << ans.second << "\n";
}