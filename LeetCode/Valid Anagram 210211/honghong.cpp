class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int count_s[26] = {0,};
        int count_t[26] = {0,};
        
        for(int i=0; i<s.size(); i++) {
            int ind = s[i] - 'a';
            count_s[ind]++;
        }
        for(int i=0; i<t.size(); i++) {
            int ind = t[i] - 'a';
            count_t[ind]++;
        }
        
        bool flag = true;
        for(int i=0; i<26; i++) {
            if(count_s[i] != count_t[i]) {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};