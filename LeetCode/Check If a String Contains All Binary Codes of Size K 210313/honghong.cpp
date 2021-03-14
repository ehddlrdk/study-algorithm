class Solution {
public:
    
    int strToint(string str) {
        
        int num = 0;
        int mul = 1;
        for(int i=str.size()-1; i>=0; i--) {
            num += mul * (str[i] - '0');
            mul *= 2;
        }
        
        return num;
    }
    
    bool hasAllCodes(string s, int k) {
        
        int size = s.size();
        
        map<long int, bool> isExist;
        
        for(int i=0; i<=size-k; i++) {

            string curstr = s.substr(i, k);
            isExist[strToint(curstr)] = true;
        }
        
        for(int i=0; i<pow(2,k); i++) {
            if(isExist.find(i) == isExist.end())
                return false;
        }
        
        return true;

    }
};

/*

-. 참고. Map이 아닌 Set으로 저장해서, 나중에 개수만 세어 비교하면 됨

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false;
        
        unordered_set<string> nums;
        int count = 1 << k;
        
        for(int i=0;i<=s.size()-k;i++){
            string temp = s.substr(i, k);
            nums.insert(temp);
            if(nums.size() == count)
                return true;
        }
        
        return nums.size() == count;
    }
};
*/
