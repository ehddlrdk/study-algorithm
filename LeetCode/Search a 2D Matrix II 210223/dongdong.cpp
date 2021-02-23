class Solution {
public:
	/*
	int binary_search(int target, vector<int> sub_matrix, int start, int end) {
		int mid = (start + end) / 2;

		if (start > end)
			return -1;
		if (sub_matrix[mid] > target)
			return binary_search(target, sub_matrix, start, mid-1);
		else if (sub_matrix[mid] < target)
			return binary_search(target, sub_matrix, mid+1, end);
		else return mid;

	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		binary search ??
		각 row 한줄마다 체크. 가운데 숫자가 target보다 작은지 큰지로 비교.

		for(int i = 0; i < matrix.size(); i++) {
			vector<int> m = matrix[i];
			if (m[m.size()-1] >= target){
				if (binary_search(target, m, 0, m.size() - 1) != -1)
					return true;
			}
			if (m[0] > target)
				return false;
		}
		return false;
	}
	*/
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		// 오른쪽 위에서 탐색 시작. 
		int col = matrix[0].size() - 1;
		int row = 0;

		while (row < matrix.size() && col >= 0) {
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] > target)
				col--;
			else row++;
		}
		return false;
	}
};