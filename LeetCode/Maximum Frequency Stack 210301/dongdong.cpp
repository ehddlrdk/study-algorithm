class FreqStack {
public:
	// map으로 구현?

	map<int, int> max_m; // x : max_num
	map<int, stack<int>> m; // max,push_num;
	int max = 0;
	FreqStack() {

	}

	void push(int x) {
		max_m[x]++;
		if (max_m[x] > max) {
			max = max_m[x];
		}
		m[max_m[x]].push(x);
	}

	int pop() {
		int pop_num = m[max].top();
		max_m[pop_num]--;
		m[max].pop();

		if (m[max].size() == 0)
			max--;

		return  pop_num;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */