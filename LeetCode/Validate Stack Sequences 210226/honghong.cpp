class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> S;
        
        if(pushed.empty())
            return true;
        
        int i = 0; S.push(pushed[0]);
        int j = 0;
        
        bool answer = true;
        
        while(!(i == pushed.size() - 1 && S.empty())) {
            
            if(i == pushed.size() - 1 && S.top() != popped[j]) {
                answer = false;
                break;
            }
            
            if(!S.empty()) {
                if(S.top() == popped[j]) {
                    cout << "pop " << S.top() << endl; 
                    S.pop();
                    j++;   
                }
                else if(S.top() != popped[j]) {
                    cout << "push " << pushed[i+1] << endl;
                    S.push(pushed[i+1]);
                    i++;    
                }
            }
            else {
                cout << "push " << pushed[i+1] << endl;
                S.push(pushed[i+1]);
                i++;                
            }
        }
    
        return answer;
    }
};