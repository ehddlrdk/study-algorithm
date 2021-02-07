class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        vector<int> output;
        int count = 10001;
        int dist[10000] = {0,};
        
        //Forward로 Distance 기록
        for(int i=0; i<s.size(); i++) {
            count++;
            if(s[i] == c) {
                count = 0;
                dist[i] = count;
            }
            else
                dist[i] = count; 
        }
        
        //Backward로 Distance 기록
        for(int i=s.size()-1; i>=0; i--) {
            count++;
            if(s[i] == c) {
                count = 0;
                dist[i] = count;
            }
            else {
                if(dist[i] > count) 
                    dist[i] = count;
            }
        }
        
        for(int i=0; i<s.size(); i++) {
            output.push_back(dist[i]);
        }
        
        return output;
    }
};