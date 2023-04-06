//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define INT_MAX 2147483647
//
//using namespace std;
//
//int number = 1001;
//vector<pair<int, int>> nodes[1001];
//int distances[1001] = { 0 };
//short parents[1001] = { 0 };
//
//void dijkstra(int start)
//{
//	distances[start] = 0;
//	priority_queue<pair<int, int>> pq;
//	pq.push(make_pair(start, 0));
//
//	while (!pq.empty())
//	{
//		int current = pq.top().first;
//		int distance = -pq.top().second;
//		pq.pop();
//
//		if (distances[current] < distance)
//		{
//			continue;
//		}
//
//		for (long unsigned int i = 0; i < nodes[current].size(); i++)
//		{
//			int next = nodes[current][i].first;
//			int nextDistance = distance + nodes[current][i].second;
//			if (nextDistance < distances[next])
//			{
//				distances[next] = nextDistance;
//				parents[next] = current;
//				pq.push(make_pair(next, -nextDistance));
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin.tie(0);
//	cout.tie(0);
//
//	for (int i = 1; i < number; i++)
//	{
//		distances[i] = INT_MAX;
//	}
//
//	int N, M;
//
//	cin >> N >> M;
//
//	for (int i = 0; i < M; i++)
//	{
//		int current, next, distance;
//		cin >> current >> next >> distance;
//		nodes[current].push_back(make_pair(next, distance));
//		nodes[next].push_back(make_pair(current, distance));
//	}
//
//	dijkstra(1);
//
//	int parent_node = parents[N], cur_node = N;
//
//	while (cur_node != 1)
//	{
//		int distance_min = INT_MAX;
//		int index_min = 0;
//		for (long unsigned int i = 0; i < nodes[parent_node].size(); i++)
//		{
//			if (nodes[parent_node][i].first == cur_node)
//			{
//				if (distance_min > nodes[parent_node][i].second)
//				{
//					distance_min = nodes[parent_node][i].second;
//					index_min = i;
//				}
//			}
//		}
//		nodes[parent_node].erase(nodes[parent_node].begin() + index_min);
//
//		for (long unsigned int i = 0; i < nodes[cur_node].size(); i++)
//		{
//			if (nodes[cur_node][i].first == parent_node && nodes[cur_node][i].second == distance_min)
//			{
//				index_min = i;
//				break;
//			}
//		}
//		nodes[cur_node].erase(nodes[cur_node].begin() + index_min);
//
//		cur_node = parent_node;
//		parent_node = parents[cur_node];
//	}
//
//	for (int i = 1; i < number; i++)
//	{
//		distances[i] = INT_MAX;
//	}
//
//	dijkstra(1);
//
//	cout << distances[N];
//
//	cout << endl;
//}