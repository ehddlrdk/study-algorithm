class Solution {
public:
    
    int check[12] = {0,};
    
    int size;
    string copy_S;
    vector<string> result;
    
    vector<string> letterCasePermutation(string S) {
        
        copy_S = S;
        size = S.size();
        
        //숫자인 경우 저장, 대문자는 소문자로 미리 변경
        for(int i=0; i<S.size(); i++) {
            char cur = S[i];
            if(cur >= '0' && cur <= '9') {
                check[i] = -1; 
            }
            else if(cur >= 'A' && cur <= 'Z') {
                copy_S[i] = copy_S[i] + 32;
            }
        }
        
        DFS(0);
        
        return result;
    }

    void DFS(int level) {
        
        //마지막 Level까지 탐색한 후 String 저장
        if(level == size) {
            string output = "";
            for(int i=0; i<size; i++) {

                switch(check[i]) {
                    case -1 : //숫자
                        output.push_back(copy_S[i]);
                        break;
                    case 0 : //소문자
                        output.push_back(copy_S[i]);
                        break;
                    case 1 : //대문자
                        output.push_back(copy_S[i] - 32);
                        break;
                }
            }

            result.push_back(output);
            return;
        }
        
        //알파벳인 경우, 소문자 / 대문자 각각 탐색
        if(check[level] != -1) {
            check[level] = 0;
            DFS(level+1);
            
            check[level] = 1;
            DFS(level+1);
            check[level] = 0;
        }
        //숫자인 경우, 바로 다음 Level로 이동
        else {
            DFS(level+1);
        }
    }    
    
};