class Solution {
public:
	vector<string> answer;
	string str;

	void Combination(vector<pair<char, int>> alpha, vector<pair<char, int>> com, int depth, int next) {

		// 탈출조건. index가 조합 갯수랑 같을때 
		if (depth == com.size()) {
			string permutation = str;
			for (int i = 0; i < com.size(); i++) {
				// cout << com[i].first << " ";
				// 대문자는 소문자로, 소문자는 대문자로 변형.
				if (isupper(com[i].first))
					permutation[com[i].second] = tolower(com[i].first);
				if (islower(com[i].first))
					permutation[com[i].second] = toupper(com[i].first);
			}
			answer.push_back(permutation);
			// cout << endl;
			return;
		}
		else {
			// 재귀 돌려가며 조합찾기. 
			for (int i = next; i < alpha.size(); i++) {
				com[depth].first = alpha[i].first;
				com[depth].second = alpha[i].second;
				Combination(alpha, com, depth + 1, i + 1);
			}
		}
	}

	vector<string> letterCasePermutation(string S) {
		vector<pair<char, int>> alpha; // S에서 뽑아낸 알파벳 저장
		vector<pair<char, int>> com; // alpha에서 뽑아낸 조합 저장
		str = S;
		// S에서 알파벳만 골라서 index와 알파벳 저장.
		for (int i = 0; i < S.size(); i++) {
			if (isalpha(S[i])) {
				alpha.push_back(make_pair(S[i], i));
			}
		}

		// 0 ~ S에서 뽑아낸 알파벳 개수까지 조합돌리기.
		for (int i = 0; i <= alpha.size(); i++) {
			com.resize(i);
			Combination(alpha, com, 0, 0);
		}


		// Combination(alpha, com, 0, 0);

		return answer;
	}
};