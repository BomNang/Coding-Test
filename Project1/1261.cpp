//백준 1707 이분 그래프
//난이도 : 골드4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int M, N;
    cin >> M >> N;

    vector<vector<int>> area(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
    {
        string nums;
        cin >> nums;
        
        for (int j = 0; j < M; ++j)
        {
            char sz = nums[j];
            area[i][j]= atoi(&sz);
        }
    }

    //간선의 가중치를 벽이 없으면 0 있으면 1로 구분
    //1,1 에서 각 노드에 도착할 때의 최소 비용을 구하기
    //그러면 자연스럽게 N, M의 최소 값도 구해짐

    vector<vector<int>> cost(N, vector<int>(M, 1e9));
    cost[0][0] = 0;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({ 0, {0, 0}});
    cost[0][0] = 0;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };
    while (!pq.empty())
    {
        auto data = pq.top();
        pq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int x = data.second.first + dx[i];
            int y = data.second.second + dy[i];

            if (x < 0 || y < 0 || x >= M || y >= N)
                continue;

            int newCost = cost[data.second.second][data.second.first] + area[y][x];
            if (newCost < cost[y][x])
            {
                cost[y][x] = newCost;
                pq.push({ newCost, {x, y} });
            }
        }
    }

    cout << cost[N - 1][M - 1] << "\n";
}