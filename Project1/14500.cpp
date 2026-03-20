//백준 14500 테트로미노
//난이도 : 골드4

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visit;
int N, M;

void DFS(int y, int x, int cnt, int sum, vector<vector<bool>>& visit, int& result) 
{
    if (cnt == 4) {
        result = max(result, sum);
        return;
    }
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
            continue;
        if (visit[ny][nx]) 
            continue;

        visit[ny][nx] = true;                          
        DFS(ny, nx, cnt + 1, sum + board[ny][nx], visit, result);
        visit[ny][nx] = false;                        
    }
}

void CheckT(int y, int x, int& result) {
    vector<vector<pair<int, int>>> T_shapes = {
        {{0,0},{0,1},{0,2},{1,1}},  // ㅏ
        {{1,0},{1,1},{1,2},{0,1}},  // ㅓ
        {{0,0},{1,0},{2,0},{1,1}},  // ㅜ
        {{0,1},{1,1},{2,1},{1,0}},  // ㅗ
    };

    for (auto& shape : T_shapes) {
        int sum = 0;
        bool valid = true;
        for (auto p : shape) {
            int ny = y + p.second, nx = x + p.first;
            if (ny >= N || nx >= M) 
            { 
                valid = false; 
                break; 
            }
            sum += board[ny][nx];
        }
        if (valid) result = max(result, sum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    
    board.resize(N, vector<int>(M, 0));
    visit.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int num;
            cin >> num;
            board[i][j] = num;
        }
    }
    //결국 이웃한(상하좌우) 4개의 영역에 대해 dfs + backtracking를 돌려서 최대합을 찾으면 됨
    //문제는 ㅗㅜㅏㅓ모양이 안됨
    //따로 처리 ㄱㄱ
    //가로 영역 기준

    int result = 0;
    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            visit[i][j] = true;
            DFS(i, j, 1, board[i][j], visit, result); 
            visit[i][j] = false;
            CheckT(i, j, result);
        }
    }

    cout << result << "\n";
}