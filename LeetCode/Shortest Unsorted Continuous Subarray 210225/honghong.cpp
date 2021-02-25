class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        /* 정렬이 되어있는 Array인지 확인 */
        bool isContinuous = true;
        int pre = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(pre > nums[i]) {
                isContinuous = false;
                break;
            }
            pre = nums[i];
        }
        if(isContinuous) return 0;
        
        /* 왼쪽 Index 찾는 과정 */
        
        //기본적으로 오름차순 규칙에 벗어나는 인덱스 이후에서 가장 작은 값을 찾고
        //앞쪽에 넣어줘야하는 위치를 검색함 = Substring의 왼쪽 위치
        int pre_l = nums[0];
        int change_point_l = 0;
        
        //오름차순 규칙에 벗어나는 인덱스 확인
        for(int i=0; i<nums.size(); i++) {
            if(pre_l > nums[i]) {
                change_point_l = i;
                break;
            }
            pre_l = nums[i];
        }
       
        //해당 인덱스 이후에서 가장 작은 값을 검색
        int min_index = change_point_l;
        for(int i=change_point_l; i<nums.size(); i++) {
            min_index = nums[i] < nums[min_index] ? i : min_index;
        }
        
        //그 가장 작은 값을 앞쪽 어디에 넣어줘야하는 지 검색
        int smallest_l = 0;
        for(int i=change_point_l-1; i>=0; i--) {
            if(nums[min_index] >= nums[i]) {
                smallest_l = i+1;
                break;
            }
            smallest_l = 0;
        }
        
        /* 오른쪽 Index 찾는 과정 - 왼쪽 반대로 수행 */
        int last = nums.size() - 1;
        int pre_r = nums[last];
        int change_point_r = last;
        for(int i=last; i>=0; i--) {
            if(pre_r < nums[i]) {
                change_point_r = i;
                break;
            }
            pre_r = nums[i];
        }

        int max_index = change_point_r;
        for(int i=change_point_r; i>=0; i--) {
            max_index = nums[i] > nums[max_index] ? i : max_index;
        }
        
        int biggest_r = 0;
        for(int i=change_point_r+1; i<=last; i++) {
            if(nums[max_index] <= nums[i]) {
                biggest_r = i-1;
                break;
            }
            biggest_r = last;
        }

        return biggest_r - smallest_l + 1;
    }
};