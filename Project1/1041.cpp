//백준 1041 주사위
//난이도 : 골드5

#include <iostream>
#include <vector>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //ABCDEF 
    //A-F, B-E, C-D
    //고려해야할건 테두리 부분인가
    //겉면의 주사위 개수를 구하기
    //겉면의 테두리 개수를 구하기
    //겉면의 개수에서 아랫면 개수와 테두리 개수 빼기(이때 중복되는 주사위 제외)
    //위쪽 꼭짓점 4개는 3면이 정해짐, 꼭짓점을 제외한 테두리는 2면, 나머지는 1면
    //맨 아랫면은 합 포함을 안하기 때문에 아래 꼭짓점도 2면만 고려

    //그러면 4개의 꼭짓점에 대해 3면의 합이 최소인 경우를 구하기
    //테두리는 2면의 합이 최소인 경우
    //1면은 값이 최소인 경우
    
    //A-B-C, A-B-D, A-C-E, A-D-E, F-B-C, F-B-D, F-C-E, F-D-E
	//0-1-2, 0-1-3, 0-2-4, 0-3-4, 5-1-2, 5-1-3, 5-2-4, 5-3-4

    const vector<vector<int>> threeFace = { {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4},
		{5, 1, 2}, {5, 1, 3}, {5, 2, 4}, {5, 3, 4} };

    long long n;
    cin >> n;

	vector<int> dice(6);
    vector<int> pairDiceNum(6);
    int minNum = 50;
    int maxNum = 0;
    for (int i = 0; i < 6; ++i)
    {
        int num;
        cin >> num;
		dice[i] = num;
        if (minNum > num)
            minNum = num;

        if (maxNum < num)
            maxNum = num;
    }

    if (n == 1)
    {
        int sum = 0;
        for(int num : dice)
			sum += num;

		cout << sum - maxNum << "\n";
        return 0;
    }

    long long surface = (n - 2) * (n - 1) * 4 + (n - 2) * (n - 2);
    long long side = (n * n * 5 - surface - 12) / 2;

    pairDiceNum[0] = 5; pairDiceNum[1] = 4; pairDiceNum[2] = 3;
    pairDiceNum[5] = 0; pairDiceNum[4] = 1; pairDiceNum[3] = 2;

    int pairMin = 100;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (pairDiceNum[i] == j || pairDiceNum[j] == i)
                continue;

            if(pairMin > dice[i] + dice[j])
				pairMin = dice[i] + dice[j];
		}
    }

    long long tripleMin = 150;

    for (auto nums : threeFace)
    {
        int temp = 0;
        for (int num : nums)
        {
            temp += dice[num];
        }
		if (tripleMin > temp)
			tripleMin = temp;
    }
    
    long long result = 0;
    result += tripleMin * 4 + pairMin * side + surface * minNum;

	cout << result << "\n";
}