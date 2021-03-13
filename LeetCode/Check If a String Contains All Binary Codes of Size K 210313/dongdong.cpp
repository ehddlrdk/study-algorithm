class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> sub;
        if (s.size() < k)
            return false;
        for(int i = 0; i <= s.size() - k; i++) {
            sub.insert(s.substr(i, k));
        }

        if (sub.size() == pow(2,k))
            return true;
        
        return false;
    }
};
