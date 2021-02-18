class Solution {
public:
	int maxArea(vector<int>& height) {
		int x1 = 0;
		int x2 = height.size() - 1;
		int max = 0;
		int area = 0;


		// 첫 인덱스를 기준으로 모두 비교 후 가장 넓이 큰 것 출력. ==> 시간초과함.
		// for(int i = 0; i < area.size(); i++) {
		//     int y1 = area[i].first;
		//     int x1 = area[i].second;
		//     for(int j = i + 1; j < area.size(); j++ ) {
		//         int y2 = area[j].first;
		//         int x2 = area[j].second;
		//         int max = y1 * abs(x2 - x1);
		//         if (area_max < max ) {
		//             area_max = max;
		//         }
		//     }
		// }

		// 양방향에서 비교
		while (x1 < x2) {
			// x1높이가 x2 높이보다 작으면 x1 높이를 기준으로
			if (height[x1] < height[x2]) {
				area = abs(x2 - x1) * height[x1];
				if (max < area) {
					max = area;
				}
				// 오른쪽방향으로
				x1++;
			}
			else {
				// x1높이가 x2 높이보다 크으면 x2 높이를 기준으로
				area = abs(x2 - x1) * height[x2];
				if (max < area) {
					max = area;
				}
				// 왼쪽방향으로
				x2--;
			}
		}

		return max;
	}
};