class Solution {
public:
    
    int MOD = 1000000007;
    
    /* 작은 Case부터 쪼개서 합해야하기 때문에 Dynamic Programming으로 풀어야함 */
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int result = 0;
        
        //곱하면서 int 범위를 넘을 수 있으므로 long int 사용
        map<int, long int> DP;
        
        //작은 값부터 계산을 위해 오름차순 정렬
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size();i++) {
            int parent = arr[i];
            DP[parent] = 1;
            
            for(int j=0; j<i; j++) {
                int child = arr[j];
                
                //child 인지 확인, 나눈 몫도 child인지 확인
                if(parent%child == 0 && DP.find(parent/child) != DP.end()) {
                    DP[parent] += (DP[child] * DP[parent/child]) % MOD;
                    DP[parent] %= MOD;
                }
                
            }
        }
        
        for(auto x : DP) {
            result += x.second;
            result %= MOD;
        }

        return result;
    }
};