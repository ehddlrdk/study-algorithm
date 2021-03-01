class FreqStack {
public:
    
    map<int, int> cnt;
    map<int, stack<int>> fStack;
    
    int maxFreq = 0;
    
    FreqStack() {
        maxFreq = 0;
        cnt.clear();
        fStack.clear();
    }
    
    void push(int x) {
        
        if(cnt.find(x) == cnt.end()) {
            cnt[x] = 1;
        }
        else {
            cnt[x]++;
        }
        
        fStack[cnt[x]].push(x);
        maxFreq = maxFreq > cnt[x] ? maxFreq : cnt[x];
    }
    
    int pop() {
        
        int maxKey = maxFreq;
        int popped = fStack[maxKey].top();
        
        fStack[maxKey].pop();
        
        if(fStack[maxKey].empty()) {
            fStack.erase(maxKey);
            maxFreq--;
        }
        cnt[popped]--;
        return popped;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */