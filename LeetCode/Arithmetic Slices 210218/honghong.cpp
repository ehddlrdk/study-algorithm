class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int sum = 0;
        vector<int> sub;
        vector<int> len_arith;
        
        //차이값 저장
        for(int i=1; i<A.size(); i++) {
            sub.push_back(A[i] - A[i-1]);
        }
        
        //Arithmetic한 배열 길이 저장(등차수열 길이 저장)
        int count = 1;
        for(int i=1; i<sub.size(); i++) {
            if(sub[i] == sub[i-1]) {
                count++;
                
                if(i == sub.size() - 1 && count >= 2) {
                    len_arith.push_back(count + 1);
                }
            }
            else {
                if(count >= 2) {
                    len_arith.push_back(count + 1);
                }
                count = 1;
            }
        }
        
        //등차수열별 Slice 개수 SUM 구하기
        for(int i=0; i<len_arith.size(); i++) {
            for(int j=3; j<=len_arith[i]; j++) {
                sum += len_arith[i] - j + 1;
            }
        }
        
        return sum;
    }
};