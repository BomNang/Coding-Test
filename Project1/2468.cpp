//백준 1707 이분 그래프
//난이도 : 골드4

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> area(N, vector<int>(N, 0));

    set<int> heights;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int height;
            cin >> height;
            area[i][j] = height;
            heights.insert(height);
        }
    }

    int result = 1;
    //강수량
    for (int height : heights)
    {
        vector<vector<bool>> visit(N, vector<bool>(N, false));

        int safeArea = 0;

        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
               if(area[j][k] > height && !visit[j][k])
               {
                   queue<pair<int, int>> q;
                   q.push({j, k});
                   visit[j][k] = true;

                   while (!q.empty())
                   {
                       auto front = q.front();
                       int x = front.second, y = front.first;
                       q.pop();

                       if (y - 1 >= 0 && !visit[y - 1][x] && area[y - 1][x] > height)
                       {
                           q.push({ y - 1, x });
                           visit[y - 1][x] = true;
                       }

                       if (y + 1 < N && !visit[y + 1][x] && area[y + 1][x] > height)
                       {
                           q.push({ y + 1, x });
                           visit[y + 1][x] = true;
                       }

                       if (x - 1 >= 0 && !visit[y][x - 1] && area[y][x - 1] > height)
                       {
                           q.push({ y, x - 1});
                           visit[y][x - 1] = true;
                       }

                       if (x + 1 < N && !visit[y][x + 1] && area[y][x + 1] > height)
                       {
                           q.push({ y, x + 1});
                           visit[y][x + 1] = true;
                       }
                   }

                   ++safeArea;
               }
            }
        }

        result = max(result, safeArea);
    }

    cout << result << "\n";
}