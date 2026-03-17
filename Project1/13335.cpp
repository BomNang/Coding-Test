//백준 13335 트록
//난이도 : 실버1

#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, l;

	cin >> n >> w >> l;
    queue<int> trucks;
	vector<pair<int, int>> truckWeights;
    for (int i = 0; i < n; ++i)
    {
        int truck;
		cin >> truck;
        truckWeights.push_back({ truck, 0 });
		trucks.push(i);
    }
    
    queue<int> bridge;
    int bridgeWeight = 0;
    int time = 0;

    while (!trucks.empty() || !bridge.empty())
    {
        ++time;

        int qSize = bridge.size();

        for (int i = 0; i < qSize; ++i)
        {
            int f = bridge.front();
            bridge.pop();
            int enterTime = truckWeights[f].second;
            if (time - enterTime < w)
                bridge.push(f);
            else
                bridgeWeight -= truckWeights[f].first;
        }

        if (!trucks.empty())
        {
            int front = trucks.front();
            int truckWeight = truckWeights[front].first;

            if (bridgeWeight + truckWeight <= l)
            {
                bridge.push(front);
                bridgeWeight += truckWeight;
                truckWeights[front].second = time;
                trucks.pop();
            }
        }
    }

	cout << time << "\n";
}