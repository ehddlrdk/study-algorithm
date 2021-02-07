#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1단계
    string stage_one = "";
    int len = new_id.length();
    for(int i=0; i<len; i++) {
        char cur = new_id[i];
        if(cur >= 'A' && cur <= 'Z')
            stage_one.push_back(cur - 'A' + 'a');
        else
            stage_one.push_back(cur);
    }
    //2단계
    string stage_two = "";
    len = stage_one.length();
    for(int i=0; i<len; i++) {
        char cur = stage_one[i];
        if(cur >= 'a' && cur <= 'z')
            stage_two.push_back(cur);
        else if(cur >= '0' && cur <= '9')
            stage_two.push_back(cur);
        else if(cur == '-' || cur == '_' || cur == '.')
            stage_two.push_back(cur);
    }
    //3단계
    string stage_three = "";
    bool flag_three = false;
    len = stage_two.length();
    for(int i=0; i<len; i++) {
        char cur = stage_two[i];
        if(cur == '.') {
            if(flag_three == true) 
                continue;
            else if(flag_three == false)
                stage_three.push_back(cur);
            
            flag_three = true;
        }
        else {
            stage_three.push_back(cur);
            flag_three = false;
        }
    }
    //4단계
    string stage_four = "";
    len = stage_three.length();
    for(int i=0; i<len; i++) {
        char cur = stage_three[i];
        if((i == 0 && cur == '.') || (i == len-1 && cur == '.')) {
            continue;
        }
        stage_four.push_back(cur);
    }

    //5단계
    string stage_five = "";
    if(stage_four.empty()) {
        stage_five.push_back('a');
    }
    else 
        stage_five = stage_four;
    
    //6단계
    string stage_six = "";
    len = stage_five.length();
    if(len >= 16) {
        for(int i=0; i<15; i++)
            stage_six.push_back(stage_five[i]);
        if(stage_six[14] == '.')
            stage_six.pop_back();
    }
    else 
        stage_six = stage_five;
    
    //7단계
    string stage_seven = "";
    len = stage_six.length();
    if(len <= 2) {
        stage_seven = stage_six;
        for(int i=len; i<3; i++) {
            stage_seven.push_back(stage_six[len-1]);
        }
    }
    else
        stage_seven = stage_six;
    
    //cout << stage_seven;
    answer = stage_seven;
    return answer;
}