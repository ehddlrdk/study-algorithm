class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int> weakest;
        vector<int> result;
        
        int rowN = mat.size(); //m
        int colN = mat[0].size(); //n
        
        //이미 끝난 Row 기록
        bool isEnded[101] = {0,};
        
        int i, j = 0;
        
        //차례대로 Weakest Row 저장
        for(i=0; i<colN; i++) {
            for(j=0; j<rowN; j++) {
                if(isEnded[j] == false && mat[j][i] == 0) {
                    isEnded[j] = true;
                    weakest.push_back(j);
                }
            }
        }
        
        //병사만 있는 Row 저장
        for(i=0; i<rowN; i++) {
            if(isEnded[i] == false) {
                weakest.push_back(i);
            }
        }
        
        for(i=0; i<k; i++) {
            result.push_back(weakest[i]);
        }
        
        return result;
    }
};