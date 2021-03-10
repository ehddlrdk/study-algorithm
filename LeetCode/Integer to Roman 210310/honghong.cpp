class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";
        
        //천의 자리
        int thousand = num / 1000;
        num = num % 1000;
        
        for(int i=0; i<thousand; i++) {
            ans.push_back('M');
        }
        
        //백의 자리
        int hundred = num / 100;
        num = num % 100;
        
        if(hundred == 9)
            ans.append("CM");
        else if(hundred >= 5) {
            ans.push_back('D');
            for(int i=0; i<hundred-5;i++)
                ans.push_back('C');
        }
        else if(hundred == 4)
            ans.append("CD");
        else if(hundred < 4) {
            for(int i=0; i<hundred; i++) {
                ans.push_back('C');
            }
        }
        
        //십의 자리
        int ten = num / 10;
        num = num % 10;
        
        if(ten == 9)
            ans.append("XC");
        else if(ten >= 5) {
            ans.push_back('L');
            for(int i=0; i<ten-5;i++)
                ans.push_back('X');
        }
        else if(ten == 4)
            ans.append("XL");
        else if(ten < 4) {
            for(int i=0; i<ten; i++) {
                ans.push_back('X');
            }
        }
        
        //일의 자리
        int one = num;
        
        if(one == 9)
            ans.append("IX");
        else if(one >= 5) {
            ans.push_back('V');
            for(int i=0; i<one-5;i++)
                ans.push_back('I');
        }
        else if(one == 4)
            ans.append("IV");
        else if(one < 4) {
            for(int i=0; i<one; i++) {
                ans.push_back('I');
            }
        }
        
        return ans;
    }
};

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/