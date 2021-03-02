class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        bool visited[10001] = {0,};
        vector<int> answer;
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            int cur = *iter;
            if(!visited[cur]) {
                visited[cur] = true; 
            }
            else
                answer.push_back(cur);
        }
        for(int i=1; i<10001; i++) {
            if(!visited[i]) {
                answer.push_back(i);
                break;
            }
        }
        
        return answer;
    }
};