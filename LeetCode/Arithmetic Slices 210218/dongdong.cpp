class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {

		vector<pair<int, int>> a; // (첫 index, 끝 index 페어)
		vector<int> diff; // A 벡터에서 차이 나는 거 집어넣기
		int answer = 0;

		// 연속된 3개이상이 등차일때,
		if (A.size() >= 3) {
			// 차이를 구해서 새로운 벡터에 넣고
			for (int i = 0; i < A.size() - 1; i++) {
				diff.push_back(A[i + 1] - A[i]);
			}

			// 거기서 연속된 숫자 나오면 그 인덱스를 기준으로 선택 후
			int diff_num = diff[0];
			int start = 0;
			int check = 0;
			for (int i = 1; i < diff.size(); i++) {
				if (diff[i] == diff_num) {
					check++;
					if (i == diff.size() - 1) {
						if (check >= 1) {
							a.push_back(make_pair(start, i));
							check = 0;
						}
					}
				}
				else {
					if (check >= 1) {
						a.push_back(make_pair(start, i - 1));
					}
					start = i;
					check = 0;
					diff_num = diff[i];
				}
			}

			// 경우의 수 구하기. 연속된수 5 개면 3개짜리 3개 4개짜리 2개 5개짜리 1개 이런 형태를 띔.
			for (int i = 0; i < a.size(); i++) {
				int x1 = a[i].first;  // 등차인 배열의 첫 인덱스
				int x2 = a[i].second + 1; // 등차인 배열의 마지막 인덱스

				for (int j = 3; j <= x2 - x1 + 1; j++) {
					answer += (x2 - x1 + 1) - j + 1;
				}
			}
		}
		else {
			// 배열 3개 미만일시 등차인 배열이 나올 수 없음.
			return 0;
		}

		return answer;
	}
};