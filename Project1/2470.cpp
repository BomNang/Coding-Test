//백준 2470 두 용액
//난이도 : 골드5

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //양끝에서 두수를 비교하며 비교
    //이때 두수의 합이 양수냐 음수냐에 따라서 이동인데
    //문제는 모든 수가 양수 혹은 음수일때 혹은 음수 혹은 양수의 값들이 다른 반대쪽과
    //비교했을 때 차이가 너무커서 한쪽으로만 이동이되서 값이 이상해지는 경우
    //그러면 배열에서 양수의 가장 작은 값과 음수의 가장 큰 두 값을 미리 구하고 시작

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
		arr.push_back(num);
        
    }
    sort(arr.begin(), arr.end());
	int left = 0, right = n - 1;
	int ansL, ansR;
	int best = 2000000000;
    while (left < right)
    {
        int data = arr[left] + arr[right];
        if (abs(data) < best)
        {
			best = abs(data);
            ansL = arr[left];
			ansR = arr[right];
        }
        
        if (data < 0) ++left;
        else --right;
    }
    

	cout << ansL << " " << ansR << "\n";
}