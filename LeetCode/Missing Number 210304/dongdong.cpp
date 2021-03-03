class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //0~n 까지의 합 - nums의 합 = missingnumber
        int sum = ( ( nums.size() + 0 ) * (nums.size() + 1) ) / 2 ;
        for(int num : nums) {
            sum -= num;
        }
        return sum;
    }
};
