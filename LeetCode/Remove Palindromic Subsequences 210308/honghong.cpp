class Solution {
public:
    int removePalindromeSub(string s) {
        
        /*
        a, b 두 알파벳만 쓰기 때문에
        동일하면 return 1, 다르면 a끼리 b끼리 Palindrome 만들면 되니까 return 2
        */
        
        string rvs = "";
        for(int i=s.length()-1; i>=0; i--) {
            rvs.push_back(s[i]);
        }
        
        if(s == "")
            return 0;
        else if(s.compare(rvs) == 0)
            return 1;
        else
            return 2;
        
    }
};