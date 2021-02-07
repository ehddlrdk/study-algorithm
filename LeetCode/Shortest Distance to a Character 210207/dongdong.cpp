class Solution {
public:
	vector<int> shortestToChar(string s, char c) {

		vector<int> c_index;
		vector<int> answer;
		int index_size = 0;
		int index = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == c) {
				c_index.push_back(i);
			}
		}

		index_size = c_index.size();

		for (int i = 0; i < s.size(); i++) {
			if (index_size == 1) {
				answer.push_back(abs(c_index[index] - i));
			}
			else {
				if (c_index[index] < i) {
					if (index != index_size - 1) {
						index++;
					}
				}

				if (index == 0) {
					answer.push_back(abs(c_index[index] - i));
				}
				else {
					answer.push_back(min(abs(c_index[index] - i), abs(c_index[index - 1] - i)));
				}
			}

		}

		return answer;
	}
};