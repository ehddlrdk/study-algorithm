class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		// pushed에 있는걸 스택에 순서대로 넣으면서 popped에서 첫 index부터 확인해가며 pop해보기. 
		// 같으면 ture 다르면 false
		stack<int> s;
		int push_index = 0;
		int pop_index = 0;

		// pushed의 원소를 스택에 다 넣을 때까지
		while (push_index != pushed.size()) {

			if (!s.empty() && s.top() == popped[pop_index]) {
				// pop 후 다음 pop_index에 해당하는게 스택에 넣어져있는 원소인지 판단.
				s.pop();
				pop_index++;
			}
			else if (pushed[push_index] == popped[pop_index]) {
				// pushed의 원소가 pop해야 될 순서이면 pop
				pop_index++;
				push_index++;
			}
			else if (pushed[push_index] != popped[pop_index]) {
				// pushed의 원소가 pop해야 될 순서가 아니면 push
				s.push(pushed[push_index]);
				push_index++;
			}
		}

		while (!s.empty()) {
			// 스택에 남아있는걸 pop했을 때 popped의 원소와 같은지 판단. 
			int pop_num = s.top();
			if (pop_num != popped[pop_index]) {
				return false;
			}
			s.pop();
			pop_index++;
		}

		return true;


	}
};