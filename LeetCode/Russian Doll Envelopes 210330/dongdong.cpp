class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 작은 순서대로 정렬하기? 케이스를 다 못담음  ==> dp문제로 바꿔서
        int size = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(size+1, 1);
        int max = 1;
        
        for(int i = 1; i < size; i++) {
            for(int j  = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1] && 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j];
                if (max < dp[i])
                    max = dp[i];
            }
        }
        return max;
    }
};