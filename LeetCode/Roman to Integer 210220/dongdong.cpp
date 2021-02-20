class Solution {
public:
	int romanToInt(string s) {
		// I1 V5 X10 L50 C100 D500 M1000 
		// I,X,C  V X, L C, D M  
		// IV IX XL XC CD CM
		//경우 나눠서 계산
		vector<int> roman_to_int;
		int answer = 0;
		char pre = '\0';


		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'I') {
				answer += 1;
				pre = 'I';
			}
			if (s[i] == 'V') {
				if (pre == 'I')
					answer += 5 - 2;
				else
					answer += 5;
				pre = 'V';
			}
			if (s[i] == 'X') {
				if (pre == 'I')
					answer += 10 - 2;
				else
					answer += 10;
				pre = 'X';
			}
			if (s[i] == 'L') {
				if (pre == 'X')
					answer += 50 - 20;
				else
					answer += 50;
				pre = 'L';
			}
			if (s[i] == 'C') {
				if (pre == 'X')
					answer += 100 - 20;
				else
					answer += 100;
				pre = 'C';
			}
			if (s[i] == 'D') {
				if (pre == 'C')
					answer += 500 - 200;
				else
					answer += 500;
				pre = 'D';

			}
			if (s[i] == 'M') {
				if (pre == 'C')
					answer += 1000 - 200;
				else
					answer += 1000;
				pre = 'M';
			}
		}

		return answer;
	}
};