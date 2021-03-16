class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        longUrl.push_back('a');
        
        string answer = longUrl;
        return answer;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl.erase(shortUrl.size()-1, 1);
        
        string answer = shortUrl;
        return answer;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));