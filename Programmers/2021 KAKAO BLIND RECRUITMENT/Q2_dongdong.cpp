#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//course num에 따라 저장할 map 필요. map<string, int> m ; course메뉴, 숫자
// course_num에 따라 max값을 넣을 배열 필요 max_num[11];
map<string, int> m[11];
int max_num[11];
string order; // order
vector<char> menu; // course메뉴
int course_num;

void combination(int depth, int next) {
	//탈출조건
	if (depth == course_num) {
		// map에 저장
		string course_menu = "";
		for (char c : menu) {
			course_menu += c;
		}
		m[course_num][course_menu]++;
		if (max_num[course_num] < m[course_num][course_menu]) {
			max_num[course_num] = m[course_num][course_menu];
		}
	}
	else {
		//depth를 기준으로 next를 통해 확장해나감.
		for (int i = next; i < order.size(); i++) {
			menu[depth] = order[i];
			combination(depth + 1, i + 1);
		}
	}
}


vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	//orders에 따라 course_num에 따른 조합 구하기 위해 combination에 넣기
	for (int num : course) {
		course_num = num;
		for (string str : orders) {
			order = str;
			sort(order.begin(), order.end());
			menu.resize(course_num);
			combination(0, 0);
		}
	}

	//map에 저장되어 있는것들 중 가장 많이 주문한 것들 뽑아냄
	for (int num : course) {
		for (auto course_menu : m[num]) {
			if (course_menu.second >= 2 && course_menu.second == max_num[num]) {
				answer.push_back(course_menu.first);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}