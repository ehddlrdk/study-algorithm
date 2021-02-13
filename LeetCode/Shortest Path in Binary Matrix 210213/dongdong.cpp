class Solution {
public:
	vector<vector<int>> copy_grid;
	vector<vector<int>> check_grid;


	bool check(int x, int y) {
		// grid범위 벗어난지 체크
		if (x < 0 || y < 0 || x > copy_grid.size() - 1 || y > copy_grid.size() - 1) {
			return false;
		}
		// grid이미 방문한지 체크
		if (copy_grid[x][y] == 0 && check_grid[x][y] == 0) {
			return true;
		}
		return false;
	}
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

		queue<pair<int, int>> q;
		queue<int> path;
		int shortest_path = 0;
		bool flag_path = false; // 길이 존재하는지 안하는지 체크
		copy_grid = grid;
		check_grid = grid;
		// 초기화
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				check_grid[i][j] = 0;
			}
		}
		// 0,0부터 시작.
		if (check(0, 0)) {
			q.push(make_pair(0, 0));
			path.push(1);
			check_grid[0][0] = 1;
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			int min_path = path.front();
			q.pop();
			path.pop();

			// n-1, n-1 에 도착했는지 체크
			if (x == grid.size() - 1 && y == grid.size() - 1) {
				flag_path = true;
				shortest_path = min_path;
				break;
			}

			//상
			if (check(x - 1, y)) {
				q.push(make_pair(x - 1, y));
				path.push(min_path + 1);
				check_grid[x - 1][y] = 1;
			}
			//하
			if (check(x + 1, y)) {
				q.push(make_pair(x + 1, y));
				path.push(min_path + 1);
				check_grid[x + 1][y] = 1;
			}
			//좌
			if (check(x, y - 1)) {
				q.push(make_pair(x, y - 1));
				path.push(min_path + 1);
				check_grid[x][y - 1] = 1;
			}
			//우
			if (check(x, y + 1)) {
				q.push(make_pair(x, y + 1));
				path.push(min_path + 1);
				check_grid[x][y + 1] = 1;
			}
			//우상
			if (check(x - 1, y + 1)) {
				q.push(make_pair(x - 1, y + 1));
				path.push(min_path + 1);
				check_grid[x - 1][y + 1] = 1;
			}
			//좌상
			if (check(x - 1, y - 1)) {
				q.push(make_pair(x - 1, y - 1));
				path.push(min_path + 1);
				check_grid[x - 1][y - 1] = 1;
			}
			//우하
			if (check(x + 1, y + 1)) {
				q.push(make_pair(x + 1, y + 1));
				path.push(min_path + 1);
				check_grid[x + 1][y + 1] = 1;
			}
			//좌하
			if (check(x + 1, y - 1)) {
				q.push(make_pair(x + 1, y - 1));
				path.push(min_path + 1);
				check_grid[x + 1][y - 1] = 1;
			}


		}
		if (flag_path == false) {
			return -1;
		}

		return shortest_path;
	}
};