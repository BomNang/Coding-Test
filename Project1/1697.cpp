//백준 1697 숨바꼭질
//난이도 : 실버1

#include <iostream>
#include <string.h>
#include <queue>
#include <set>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int start, end;
	cin >> start >> end;
	if (start >= end)
	{
		cout << start - end;
		return 0;
	}
		
	int result = 0;
	queue<int> q;
	bool visit[100001] = { false, };
	q.push(start);
	visit[start] = true;
	while (true)
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i)
		{
			int front = q.front();
			q.pop();
			if (front == end)
			{
				cout << result;
				return 0;
			}

			if (front + 1 <= 100000 && !visit[front + 1])
			{
				q.push(front + 1);
				visit[front + 1] = true;
			}
				
			if (front * 2 <= 100000 && !visit[front * 2])
			{
				q.push(front * 2);
				visit[front * 2] = true;
			}
			if (front - 1 > 0 && !visit[front - 1])
			{
				q.push(front - 1);
				visit[front - 1] = true;
			}
		}
		++result;
	}

	return 0;
}