class Solution {
public:
    map<string, string> m;
    string url = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        char encoding[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789";
        string shorturl = "";
        
        for(int i = 0; i < 6; i++) {
            shorturl += encoding[i%62];
        }
  
        reverse(shorturl.begin(), shorturl.end());
        m.insert(make_pair(shorturl, longUrl));
        return url+shorturl;
    }

    string decode(string shortUrl) {
        string shorturl = shortUrl.substr(url.size());
        return m[shorturl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));