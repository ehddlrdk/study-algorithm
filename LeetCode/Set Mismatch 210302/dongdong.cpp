class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // nums의 배열 중 순서에 어긋난 숫자와 들어가야하는 숫자를 answer에 push_back
        int order = 1;
        int dup = 0;
        int change_num = 0;
        vector<int> answer;
        sort(nums.begin(), nums.end());
        
        // 정렬 후 nums의 숫자 배열중 1~ n 까지의 순서에 어긋난걸 찾아 change_num을 변경시켜줌.
        for(int i = 0; i < nums.size(); i++) {
            if (dup != nums[i]) {
                dup = nums[i];
                if (change_num == 0) {
                    if (order == nums[i]) {
                        order++;
                    } else {
                        change_num = order;
                        order++;
                    }
                }
            } else {
                answer.push_back(nums[i]);
            }
        }
        if (change_num == 0)
            answer.push_back(order);
        else
            answer.push_back(change_num);
        return answer;
    }
};
