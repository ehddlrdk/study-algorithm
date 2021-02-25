class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		// 정렬한거랑 nums랑 비교해서 젤 처음으로 다른게 start 마지막으로 다른게 end해서 계산
		int start = -1;
		int end = -1;

		vector<int> sort_nums = nums;
		sort(sort_nums.begin(), sort_nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != sort_nums[i]) {
				if (start == -1)
					start = i;
				end = i;
			}
		}

		if (start == -1 && end == -1)
			return 0;

		return end - start + 1;
	}
};