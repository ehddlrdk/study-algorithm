#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<vector<string>> infos;
	vector<vector<string>> querys;


	// info, query 파싱해서 넣어두기 
	// info 파싱 -> 공백기준으로
	for (int i = 0; i < info.size(); i++) {
		string s = info[i];
		int start = 0;
		vector<string> sub;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				string a = s.substr(start, j - start);
				sub.push_back(a);
				start = j + 1;
			}
			if (j == s.size() - 1) {
				string a = s.substr(start);
				sub.push_back(a);
			}
		}
		infos.push_back(sub);
	}

	// query 파싱 -> - 기준으로 
	for (int i = 0; i < query.size(); i++) {
		string s = query[i];
		int start = 0;
		vector<string> sub;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				string a = s.substr(start, j - start);
				sub.push_back(a);
				if (!isdigit(s[j + 1])) {
					start = j + 5;
					j = j + 5;
				}
				else {
					start = j + 1;
				}
			}
			if (j == s.size() - 1) {
				string a = s.substr(start);
				sub.push_back(a);
			}
		}
		querys.push_back(sub);
	}

	// querys를 for문 돌려 해당하는거 체크 후 answer++;
	for (int i = 0; i < querys.size(); i++) {
		int num = 0;

		for (int j = 0; j < infos.size(); j++) {
			string info_s = "";
			string query_s = "";
			if (querys[i][0] != "-") {
				info_s += infos[j][0];
				query_s += querys[i][0];
			}
			if (querys[i][1] != "-") {
				info_s += infos[j][1];
				query_s += querys[i][1];
			}
			if (querys[i][2] != "-") {
				info_s += infos[j][2];
				query_s += querys[i][2];
			}
			if (querys[i][3] != "-") {
				info_s += infos[j][3];
				query_s += querys[i][3];
			}
			if (info_s == query_s) {
				if (stoi(infos[j][4]) >= stoi(querys[i][4])) {
					num++;
				}
			}
		}
		answer.push_back(num);
	}

	return answer;
}