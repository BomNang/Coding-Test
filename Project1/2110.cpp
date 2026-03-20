//백준 2110 공유기 설치
//난이도 : 골드4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isInstall(vector<long long>& houses, int dist, int wifiCnt)
{
    int cnt = 1;
    int lastDist = houses[0];

    for (int i = 0; i < houses.size(); ++i)
    {
        if (houses[i] - lastDist >= dist)
        {
            lastDist = houses[i];
            cnt++;
        }
    }

    return cnt >= wifiCnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, C;

    cin >> N >> C;

    vector<long long> houses(N);
    for (long long i = 0; i < N; ++i)
    {
        long long pos;
        cin >> pos;
        houses[i] = pos;
    }

    sort(houses.begin(), houses.end());

    int left = 0, right = houses.back() - houses.front();
    int result = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        //거리 기준으로 얼만큼 떨어졌을 때 공유기 설치개수를 만족하고 최대인지
        if (isInstall(houses, mid, C))//C만큼의 공유기를 설치 할 수 있을 때 (left를 증가 시켜 공유기 사이 거리 증가)
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else //C만큼 공유기를 설치할 수 없다면 거리를 줄여 설치가능한 거리를 탐색
            right = mid - 1;
    }

    cout << result << "\n";
}