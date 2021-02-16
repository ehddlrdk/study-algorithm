class Solution {
public:
	static bool cmp(pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		return a.first < b.first;
	}

	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<int> answer;
		vector<pair<int, int>> k_weakest;

		for (int i = 0; i < mat.size(); i++) {
			int num = 0;
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 1) {
					num++;
				}
			}
			k_weakest.push_back(make_pair(i, num));
		}

		sort(k_weakest.begin(), k_weakest.end(), cmp);

		for (int i = 0; i < k; i++) {
			answer.push_back(k_weakest[i].first);
		}
		return answer;
	}
};