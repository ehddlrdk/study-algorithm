class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        // 처음에 차이가 양수로 시작했을 때 값과 차이가 음수로 시작했을 때 값 중 큰 값 
        int p_max = 0;
        bool next_flag = true;
        for(int i = 0; i < nums.size()-1; i++) {
                if (nums[i+1] > nums[i]) {
                    if (next_flag) {
                        p_max++;
                        next_flag = false;
                    }
                } else if (nums[i+1] < nums[i]) {
                    if (!next_flag) {
                        p_max++;
                        next_flag = true;
                    }
                }
            }
        int n_max = 0;
        next_flag = false;
            for(int i = 0; i < nums.size()-1; i++) {
                if (nums[i+1] < nums[i]) {
                    if (!next_flag) {
                        n_max++;
                        next_flag = true;
                    }
                } else if (nums[i+1] > nums[i]) {
                    if (next_flag) {
                        n_max++;
                        next_flag = false;
                    }
                }
            }
            
        if (p_max > n_max)
            return p_max + 1;
        return n_max + 1;
    }
};