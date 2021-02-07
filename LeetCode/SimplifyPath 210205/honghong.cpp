class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> input;
        vector<string> output;
        
        string word = "";
        for(int i=0; i<path.size(); i++) {
            char cur = path[i];
            if(cur != '/') {
                word.push_back(cur);
            }
            else if(cur == '/') {
                input.push_back(word);
                word = "";
            }
        }
        if(word != "") { //마지막에 슬래시가 없는 경우 처리
            input.push_back(word);
        }
        
        for(auto word: input) {
            
            if(word == "")
                continue;
            else if(word == ".")
                continue;  
                
            else if(word == "..") {
                if(!output.empty()) {   //
                    output.pop_back();  // 슬래시 삭제
                    output.pop_back();  // Current Directory 삭제                
                }
            }
            else {
                output.push_back("/");
                output.push_back(word);
            }
        }
        
        string result = "";
        for(auto word: output) {
            result.append(word);
        }
        if(result == "") {
            result.append("/");
        }
        
        return result;
    }

};