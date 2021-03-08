class Solution {
public:


    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_set<string> wset(words.begin(), words.end());
        for (string &word : words)
            if (wset.find(word) != wset.end())
                for (int i = 1; i < word.length(); i++) 
                    wset.erase(word.substr(i));
        int ans = wset.size();
        for (string word : wset) ans += word.size();
        return ans;

    }
};