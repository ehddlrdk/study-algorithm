class Solution {
public:
	int romanToInt(string s) {

        int answer = 0;
	    map<char, int> M;
        M.insert(make_pair('I', 1));
        M.insert(make_pair('V', 5));
        M.insert(make_pair('X', 10));
        M.insert(make_pair('L', 50));
        M.insert(make_pair('C', 100));
        M.insert(make_pair('D', 500));
        M.insert(make_pair('M', 1000));
        
        int pre = 10000;
        for(int i=0; i<s.size(); i++) {
            int cur = M.find(s[i])->second;
            answer = answer + cur;
            
            if(pre < cur) {
                answer = answer - pre*2;
            }
            
            pre = cur;
        }
        
        return answer;
	}
};