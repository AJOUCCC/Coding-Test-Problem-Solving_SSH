#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    //사전 초기화
    int dict_cnt = 1;
    unordered_map<string, int> dict;
    for(int i = 0; i < 26; i++){
        char ch = 'A' + i;
        string str;
        str.push_back(ch);
        dict.insert(make_pair(str, dict_cnt++));
    }
    
    //msg 끝날때까지 진행
    int s = 0;
    for(int i = 0; i < msg.size(); i++){
        //일치하는 가장 긴 문자열 w 찾기
        string target = msg.substr(s, i-s+1);
        if(dict.find(target) != dict.end()){
            if(i == msg.size()-1)
                answer.push_back(dict.find(target)->second);
            continue;
        }
        else{
            //w에 대한 색인 출력, w + c를 사전에 등록
            string w = target.substr(0, target.size()-1);
            answer.push_back(dict.find(w)->second);
            dict.insert(make_pair(target, dict_cnt++));
            s = i;
            i--;
        }
        
    }
    
    return answer;
}