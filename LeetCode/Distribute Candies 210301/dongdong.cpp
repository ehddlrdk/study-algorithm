class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
		int maximum = 0;
		int type_num = 0;
		maximum = candyType.size() / 2;
		// type 중복제거 
		sort(candyType.begin(), candyType.end());
		candyType.erase(unique(candyType.begin(), candyType.end()), candyType.end());
		type_num = candyType.size();
		if (maximum > type_num)
			return type_num;
		return maximum;

	}
};