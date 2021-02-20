class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                count++;
            }
            else if(s[i] == ')') {
                count--;
                if(count < 0) {
                    s.erase(i, 1);
                    count++;
                    i--;
                }
            }
        }
        
        count = 0;
        cout << s << endl;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ')') {
                count++;
            }
            else if(s[i] == '(') {
                count--;
                if(count < 0) {
                    s.erase(i, 1);
                    count++;
                }
            }
        }
        return s;
    }
};