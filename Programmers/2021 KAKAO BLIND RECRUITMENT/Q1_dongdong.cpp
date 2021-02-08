#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	int id_leng = new_id.size();
	int flag_dot = 0;

	//1단계 대문자 -> 소문자로 치환
	//2단계 -, _, . 제외한 문자 제거
	//3단계 마침표 2번 이상 연속된 부분 마침표 하나로 치환
	for (int i = 0; i < id_leng; i++) {
		if (isdigit(new_id[i]) || isalpha(new_id[i]) || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_') {
			if (new_id[i] == '.') {
				if (flag_dot == 0) {
					answer += new_id[i];
					flag_dot = 1;
				}
			}
			else {
				answer += tolower(new_id[i]);
				flag_dot = 0;
			}
		}
	}
	//4단계 마침표 처음, 끝 제거
	if (answer[0] == '.') {
		answer = answer.erase(0, 1);
	}
	if (answer[answer.size() - 1] == '.') {
		answer = answer.erase(answer.size() - 1, 1);
	}

	//5단계 빈 문자열이라면 new_id에 a를 대입?
	if (answer.size() == 0) {
		answer += "a";
	}
	//6단계 16자 이상 , 15개의 문자 제외한 나머지 제거. 제거 후 마침표가 끝에 존재하면 마침표 제거
	if (answer.size() >= 16) {
		answer = answer.substr(0, 15);
	}
	if (answer[answer.size() - 1] == '.') {
		answer = answer.erase(answer.size() - 1, 1);
	}
	//7단계 2자 이하, 마지막 문자를 길이 3될 때  까지 반복.
	if (answer.size() <= 2) {
		while (answer.size() != 3) {
			answer += answer[answer.size() - 1];
		}
	}

	return answer;
}