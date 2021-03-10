class Solution {
public:
    string intToRoman(int num) {
        // 몫으로 계산 후 string += 
        string answer = "";
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
    
        while(i != 13) {
            int div_num = num / nums[i];
            for (int j = 0; j < div_num; j++) {
                answer += romans[i];
            }
            num -= div_num * nums[i];
            i++;
        }
        return answer;
    }
};