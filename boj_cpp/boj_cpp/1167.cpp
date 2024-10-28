/*
* BOJ 1167
* Gold II
* 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef std::pair<int, int> edge;

static std::vector<std::vector<edge>> A;
static std::vector<bool> visited;
static std::vector<int> distance;

void bfs(int index) {
	std::queue<int> q;

	q.push(index);

	visited[index] = true;

	while (!q.empty())
	{
		int nowNode = q.front();

		q.pop();

		for (edge e : A[nowNode])
		{
			if (!visited[e.first])
			{
				visited[e.first] = true;
				q.push(e.first);

				distance[e.first] = distance[nowNode] + e.second;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	A.resize(n + 1);

	for (int i = 0; i < n; ++i)
	{
		int s;
		std::cin >> s;
		while (true)
		{
			int e, v;
			std::cin >> e;

			if (e == -1) { break; }

			std::cin >> v;

			A[s].push_back(edge(e, v));
		}
	}

	distance = std::vector<int>(n + 1, 0);
	visited = std::vector<bool>(n + 1, false);
	bfs(1);
	int Max = 1;

	for (int i = 2; i <= n; ++i)
	{
		if (distance[Max] < distance[i]) { Max = i; }
	}

	std::fill(distance.begin(), distance.end(), 0);
	std::fill(visited.begin(), visited.end(), false);

	bfs(Max);

	std::sort(distance.begin(), distance.end());

	std::cout << distance[n] << std::endl;

	return 0;
}