class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		// map에 dictionary에 있는 단어들 넣기
		// 최대길이 담는 애들
		// s의 조합을 구해서 d와 비교는 시간초과.
		// 그냥 d와 s의 char비교로 해결.
		string answer = "";
		sort(d.begin(), d.end());
		int max = 0;


		for (string s_d : d) {
			int num = 0;
			int z = 0;
			cout << " s_d : " << s_d << endl;
			for (int i = 0; i < s_d.size(); i++) {
				char check = s_d[i];
				for (int j = z; j < s.size(); j++) {
					if (check == s[j]) {
						z = j + 1;
						num++;
						break;
					}
				}
			}
			if (s_d.size() == num) {
				if (max < s_d.size()) {
					max = s_d.size();
					answer = s_d;
				}
			}
		}

		return answer;
	}
};