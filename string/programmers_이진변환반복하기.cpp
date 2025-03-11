#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int iter_cnt = 0;
    int zero_cnt = 0;
    
    while(s.compare("1") != 0){
        
        iter_cnt++;
        
        //x의 모든 0을 제거
        int before_size = s.size();
        int idx = s.find("0");
        while(idx != string::npos){
            s.erase(idx, 1);
            zero_cnt++;
            idx = s.find("0");
        }
        cout << s << "\n";

        //x -> c를 2진법으로 표현한 문자열로 변경
        string res;
        int after_size = s.size();
        int c = s.size();
        while(c / 2 != 0){
            if(c % 2 == 0) res.insert(0, "0");
            else res.insert(0, "1");
            c = c / 2;
        }
        if(c % 2 == 0) res.insert(0, "0");
        else res.insert(0, "1");
        cout << res << "\n";
        
        //반복
        s = res;
    }
    
    answer.push_back(iter_cnt);
    answer.push_back(zero_cnt);
    return answer;
}