#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

struct Node
{
    int start;
    int depth;
    string str;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    cin >> L >> C;

    vector<char> arr(C);

    for (int i = 0; i < C; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    stack<Node> st;
    st.push({ 0,0,"" });

    while (!st.empty())
    {
        Node cur = st.top();
        st.pop();

        if (cur.depth == L)
        {
            int v = 0, c = 0;

            for (char x : cur.str)
            {
                if (vowel(x)) v++;
                else c++;
            }

            if (v >= 1 && c >= 2)
                cout << cur.str << "\n";

            continue;
        }

        for (int i = C - 1; i >= cur.start; i--)
        {
            st.push({ i + 1, cur.depth + 1, cur.str + arr[i] });
        }
    }
}