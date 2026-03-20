//백준 2805 나무 자르기
//난이도 : 실버2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> trees(N, 0);


    int left = 0, right = 0;
    for (int i = 0; i < N; ++i)
    {
        int height = 0;
        cin >> height;
        trees[i] = height;
        //left = min(left, height);
        right = max(right, height);
    }
    
    int result = 0;
    int cnt = 0;
    while (left <= right)
    {
        ++cnt;
        int mid = (left + right) / 2;
        long long total = 0;
        for (int height : trees) //현재 중간값 기준으로 얻을 수 있는 나무 획득량
        {
            if (height > mid)
                total += (height - mid);
        }

        if (total >= M) //현재 mid 기준 나무 획득량이 요구 획득량 보다 높다면 기록 및 left 증가(최선인지 아닌지 모름)
        {
            result = mid;
            left = mid + 1;
        }
        else //작다면 조건에 맞지 않으므로 right 감소후 재탐색
            right = mid - 1;
    }

    cout << result << "\n";
}