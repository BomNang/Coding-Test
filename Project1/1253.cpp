//백준 1253 좋다
//난이도 : 골드4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Check_Good_Num(vector<int>& nums, int targetIdx)
{
    int target = nums[targetIdx];
    int left = 0, right = nums.size() - 1;

    if (left == targetIdx)
        left++;

    if (right == targetIdx)
        right--;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
            return true;
        else if (sum < target)
        {
            left++;
            if (left == targetIdx)
                left++;
        }
        else
        {
            right--;
            if (right == targetIdx)
                right--;
        }
            
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        if (Check_Good_Num(nums, i))
            ++result;
    }

    cout << result << "\n";
}