class Solution {
public:
	string minRemoveToMakeValid(string s) {
		// stack에( ( or ), index)를 pair로 하나씩 넣고, 최종적으로 남아있는애 제외하고 string구성하면 됨.  
		stack<pair<char, int>> c;
		string answer;

		// 끝나는 조건. stirng끝까지 갔을때, 
		for (int i = 0; i < s.size(); i++) {
			if (!c.empty()) {
				if (s[i] == ')') {
					if (c.top().first == '(') {
						c.pop();
					}
					else {
						c.push(make_pair(s[i], i));
					}
				}
				else if (s[i] == '(') {
					c.push(make_pair(s[i], i));
				}
			}
			else {
				if (s[i] == '(' || s[i] == ')')
					c.push(make_pair(s[i], i));
			}
		}

		// 스택에 남아있는 ( or ) 를 제거하기 위해서. 
		while (!c.empty()) {
			s.replace(c.top().second, 1, "");
			c.pop();
		}

		return s;
	}
};