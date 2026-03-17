//백준 1715 카드 정렬하기
//난이도 : 골드4

#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; ++i)
    {
        int num;
		cin >> num;
        pq.push(num);
    }

    
    while (pq.size() != 1)
    {
		int num1 = pq.top();
        pq.pop();
		int num2 = pq.top();
        pq.pop();

        result += (num1 + num2);
        pq.push(num1 + num2);
    }

	cout << result << "\n";
}