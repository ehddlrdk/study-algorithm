class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
        string answer = "";
        
        //Dictionary 문자열 하나씩 s에 포함되는지 확인
        for(auto dict : d) {
            int cur = 0;
            for(int i=0; i<s.size(); i++) {
                if(dict[cur] == s[i]) {
                    cur++;
                }
                //dict가 s에 포함이 된다면 Longest String을 고른 후 저장
                if(cur == dict.size()) {
                    answer = longestString(answer, dict);
                    cout << answer << endl;
                    break;
                }
            }
        }
        
        return answer;
    }
    
    string longestString(string answer, string dict) {
        
        //먼저 크기 비교
        if(dict.size() > answer.size()) {
            return dict;
        }
        else if(answer.size() > dict.size()) {
            return answer;
        }
        //크기가 동일하다면 사전 순 비교
        else {
            return answer <= dict ? answer : dict;    
        }
    }
};