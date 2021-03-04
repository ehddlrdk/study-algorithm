class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        int origin = (size * (size + 1)) / 2;
        int sum = 0;
        
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            sum += *iter;
        }
   
        return origin - sum;
    }
};