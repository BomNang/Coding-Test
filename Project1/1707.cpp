//백준 1707 이분 그래프
//난이도 : 골드4

#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int K;
    cin >> K;
    string result;
    for (int i = 0; i < K; ++i)
    {
        int V, E;
        cin >> V >> E;
        //노드 간선 연결
        vector<vector<int>> graph(V + 1, vector<int>());
        for (int i = 1; i <= E; ++i)
        {
            int first, second;
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        
		vector<bool> visit(V + 1, false);
        vector<bool> nodeColor(V + 1, false);
		stack<int> st;
        bool isStop = false;

        for (int j = 1; j <= V; j++)
        {
            if (visit[j]) continue;

            st.push(j);
            visit[j] = true;

            while (!st.empty())
            {
                int top = st.top();
                st.pop();

                for (int neighbor : graph[top])
                {
                    if (!visit[neighbor])
                    {
                        visit[neighbor] = true;
                        nodeColor[neighbor] = !nodeColor[top];
                        st.push(neighbor);
                    }
                    else if (nodeColor[neighbor] == nodeColor[top]) 
                    {
                        //이미 방문한 노드가 색이 다를때 : 부모노드가 아님, 내가 탐색한 노드이거나, 
                        //사이클을 이루지만 해당 사이클을 구성하는 노드의 개수가 짝수일때
                        //색이 같다면 : 현재 노드가 탐색한 노드가 아님 -> 사이클 발생, 사이클을 이루는 노드 개수 홀수 뜻함
                        isStop = true;
                        break;
                    }
                }
                if (isStop)
                    break;
            }
        }

        if (isStop)
            result += "NO\n";
        else
            result += "YES\n";
    }
    cout << result;

    //이분 그래프가 되려면 사이클이 없거나 사이클이 존재하더라도 
    //이 사이클을 이루는 노드의 개수가 짝수이거나 -> 이 부분에 대한 구현 필요
    //추가로 연결되지 않은 부분에 대한 예외 처리
}