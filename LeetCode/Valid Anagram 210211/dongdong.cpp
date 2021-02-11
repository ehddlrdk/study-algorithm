class Solution {
public:
	bool isAnagram(string s, string t) {
		// 문자열을 알파벳순서로 정렬
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t)
			return true;
		return false;
	}
};