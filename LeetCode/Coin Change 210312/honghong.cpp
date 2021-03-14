class Solution {
public:

    #define MAX 10001
    int DP[MAX];
    
    /*거꾸로 더해가면서 DP로 풀어야함*/

    int pickCoin(int amount, vector<int>& coins) {
        
        if(amount == 0) return 0;
        
        int ret = DP[amount];
        if(ret != -1) return ret;

        int min = MAX;
        for(int i=0; i<coins.size(); i++) {
            if(amount >= coins[i]) {
                int cur = pickCoin(amount - coins[i], coins) + 1;  
                min = min <= cur ? min : cur;
            }
        }
        DP[amount] = min;
        
        return min;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        fill_n(DP, sizeof(DP)/sizeof(DP[0]), -1);
        
        int ret = pickCoin(amount, coins);
        
        for(int i=0; i<=amount; i++) {
            cout << i << ' ' << DP[i] << endl;
        }
        
        /*주어진 동전으로 만들 수 없는 경우 처리를 위해*/
        return ret > amount ? -1 : ret;
    }
};