class Solution {
public:

	bool isBipartite(vector<vector<int>>& graph) {
		// 모든 노드에 대해 두 부류의 그룹으로 나눈다
		// 최종적으로 겹치는것이 없으면 true, 있으면 false
		// bfs로 노드 넣을때 그룹 지정, 간선으로 연결된 노드는 같은 그룹으로 지정
		// 방문체크 
		bool check[101] = { false };
		bool group[101] = { false };
		bool cur_group = false;
		queue<int> q;

		for (int j = 0; j < graph.size(); j++) {
			// 연결안된 노드도 고려해주기 위해
			if (!check[j]) {
				q.push(j);
				check[j] = true;
				group[j] = cur_group;
			}

			while (!q.empty()) {
				int node = q.front();
				cur_group = !group[node];
				q.pop();
				for (int i = 0; i < graph[node].size(); i++) {
					//방문안한 상태
					if (check[graph[node][i]] == false) {
						q.push(graph[node][i]);
						check[graph[node][i]] = true;
						group[graph[node][i]] = cur_group;
					}
					//방문했던 상태
					else {
						// 인접노드가 같은 그룹에 속해있는지 판단
						if (group[graph[node][i]] == group[node]) {
							return false;
						}
					}

				}

			}
		}
		return true;
	}
};