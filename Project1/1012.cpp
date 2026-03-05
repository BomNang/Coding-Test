//백준 1012 유기농 배추
//난이도 : 실버2

#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int width, height, cnt;
		cin >> width >> height >> cnt;
		vector<vector<int>> map(height, vector<int>(width, 0));
		vector<pair<int, int>> cabbages;

		for (int i = 0; i < cnt; ++i)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
			cabbages.push_back({ x, y });
		}

		int result = 0;
		for (auto cabbage : cabbages)
		{
			if (map[cabbage.second][cabbage.first] != 1)
				continue;
			queue<pair<int, int>> q;
			q.push(cabbage);
			map[cabbage.second][cabbage.first] = -1;
			while (!q.empty())
			{
				auto front = q.front();
				q.pop();
				

				int x = front.first;
				int y = front.second;

				if (x + 1 < width && map[y][x + 1] == 1)
				{
					q.push({ x + 1, y });
					map[y][x + 1] = -1;
				}
					

				if (x - 1 >= 0 && map[y][x - 1] == 1)
				{
					q.push({ x - 1, y });
					map[y][x - 1] = -1;
				}

				if (y + 1 < height && map[y + 1][x] == 1)
				{
					q.push({ x, y + 1 });
					map[y + 1][x] = -1;
				}

				if (y - 1 >= 0 && map[y - 1][x] == 1)
				{
					q.push({ x, y - 1 });
					map[y - 1][x] = -1;
				}
			}
			++result;
		}
		cout << result << "\n";
	}

	return 0;
}