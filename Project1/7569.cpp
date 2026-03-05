//백준 7569 토마토
//난이도 : 골드1

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

void printBox(const vector<vector<vector<int>>>& box)
{
	cout << "============================" << "\n";
	for (int i = 0; i < box.size(); ++i)
	{
		for (int j = 0; j < box[i].size(); ++j)
		{
			for (int k = 0; k < box[i][j].size(); ++k)
			{
				cout << box[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "============================" << "\n";
	}
}

struct DATA
{
	int hei;
	int ver;
	int hor;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int vertical, horizontal, height;

	cin >> horizontal >> vertical >> height;

	vector<vector<vector<int>>> box(height, vector<vector<int>>(vertical, vector<int>(horizontal, 0)));
	//h, v, h
	queue<DATA> startPoints;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < vertical; ++j)
		{
			for (int k = 0; k < horizontal; ++k)
			{
				int tomato;
				cin >> tomato;
				box[i][j][k] = tomato;
				if(tomato == 1)
					startPoints.push({ i, j, k });
			}
		}
	}

	int reuslt = -1;
	while (!startPoints.empty())
	{
		int qSize = startPoints.size();

		for (int i = 0; i < qSize; ++i)
		{
			auto data = startPoints.front();
			startPoints.pop();

			int left, right, front, back, up, down;
			left = data.hor - 1;
			right = data.hor + 1;
			front = data.ver + 1;
			back = data.ver - 1;
			up = data.hei + 1;
			down = data.hei - 1;

			if (left >= 0 && box[data.hei][data.ver][left] == 0)
			{
				box[data.hei][data.ver][left] = 1;
				startPoints.push({ data.hei, data.ver, left });
			}

			if (right < horizontal && box[data.hei][data.ver][right] == 0)
			{
				box[data.hei][data.ver][right] = 1;
				startPoints.push({ data.hei, data.ver, right });
			}

			if (back >= 0 && box[data.hei][back][data.hor] == 0)
			{
				box[data.hei][back][data.hor] = 1;
				startPoints.push({ data.hei, back, data.hor });
			}

			if (front < vertical && box[data.hei][front][data.hor] == 0)
			{
				box[data.hei][front][data.hor] = 1;
				startPoints.push({ data.hei, front, data.hor });
			}

			if (down >= 0 && box[down][data.ver][data.hor] == 0)
			{
				box[down][data.ver][data.hor] = 1;
				startPoints.push({ down, data.ver, data.hor });
			}

			if (up < height && box[up][data.ver][data.hor] == 0)
			{
				box[up][data.ver][data.hor] = 1;
				startPoints.push({ up, data.ver, data.hor });
			}
		}
		++reuslt;
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < vertical; ++j)
		{
			for (int k = 0; k < horizontal; ++k)
			{
				if (box[i][j][k] == 0)
				{
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << reuslt << "\n";

	return 0;
}