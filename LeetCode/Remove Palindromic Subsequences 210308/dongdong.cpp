class Solution {
public:
    int removePalindromeSub(string s) {
        int start = 0;
        int end = s.size() - 1;
        if (s == "")
            return 0;
        while(start <= end) {
            if (s[start] != s[end])
                return 2;
            start++;
            end--;
        }
        return 1;
    }
};
