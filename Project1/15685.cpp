//백준 15685 드래곤커브
//난이도 : 골드3

#include <iostream>
#include <vector>

using namespace std;

bool board[101][101] = { false, };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    for (int i = 0; i < N; ++i)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        
        vector<pair<int, int>> pos;
        pos.push_back({ x, y });
        pos.push_back({ x + dx[d], y + dy[d] });

        board[y][x] = true;
        board[y + dy[d]][x + dx[d]] = true;
        for (int i = 0; i < g; ++i)
        {
            pair<int, int> lastPos = pos.back(); //끝점을 꺼내옴
            int pivotX = lastPos.first, pivotY = lastPos.second;
            int size = pos.size();
            for (int j = size - 2; j >= 0; --j)//가장 첫원소가 다음 끝점이 될 요소이기때문에 감소로 진행
            {
                int rotatePosX = -(pos[j].second - pivotY) + pivotX;
                int rotatePosY = (pos[j].first - pivotX) + pivotY;

                pos.push_back({ rotatePosX, rotatePosY });
                board[rotatePosY][rotatePosX] = true;
            }
        }
    }
    //사각형 범위로 보드 검사
    int squareX[4] = { 0, 1, 0, 1 };
    int squareY[4] = { 0, 0, 1, 1 };
    int result = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            bool isSquare = true;
            //4점이 모두 true면 사각형을 이룸
            for (int k = 0; k < 4; ++k)
            {
                if (!board[i + squareY[k]][j + squareX[k]])
                {
                    isSquare = false;
                    break;
                }
            }
            if (isSquare)
                ++result;
        }
    }
    cout << result << "\n";

    //90도 시계방향 회전한다는 뜻은 결국 x,y -> -y,x로 바꾼다는 뜻 
    //끝점을 0,0으로 기준으로한 상태로 모든 좌표를 변경 및 회전 후 다시 되돌리면서 보드를 채우기
}