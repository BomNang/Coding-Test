//백준 11724 연결 요소의 개수
//난이도 : 실버2

#include <iostream>
#include <string.h>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int nodeCnt, edgeCnt;
	int result = 0;
	cin >> nodeCnt >> edgeCnt;

	unordered_map<int, vector<int>> edges;

	for (int i = 0; i < edgeCnt; ++i)
	{
		int u, v;
		cin >> u >> v;
		auto iter = edges.find(u);
		if (iter == edges.end())
			edges.insert({ u, vector<int>(1, v) });
		else
			edges[u].push_back(v);

		iter = edges.find(v);
		if (iter == edges.end())
			edges.insert({ v, vector<int>(1, u) });
		else
			edges[v].push_back(u);
	}

	vector<bool> visit(nodeCnt + 1, false);
	
	for (int i = 1; i <= nodeCnt; ++i)
	{
		if (visit[i])
			continue;
		stack<int> st;
		st.push(i);
		
		while (!st.empty())
		{
			int top = st.top();
			st.pop();
			visit[top] = true;
			auto children = edges[top];

			for (int node : children)
			{
				if (visit[node])
					continue;

				st.push(node);
			}
		}

		result++;
	}

	cout << result << "\n";
	return 0;
}