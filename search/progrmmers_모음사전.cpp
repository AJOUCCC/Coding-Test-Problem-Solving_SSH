#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cnt = 0;
int stopFlag = false;
void next(string target, string answer){
    //target == answer면 그만
    if(target == answer){
        stopFlag = true;
        return;
    }
    //target의 길이가 5 미만이라면 하나씩 추가하면서 재귀
    if(target.size() < 5){
        vector<int> nums = {'A','E','I','O','U'};
        for(int num : nums){
            if(stopFlag) return;
            cnt++;
            target.push_back(num);
            if(cnt < 10) cout << target << "\n";
            next(target, answer);
            target.pop_back();
        }
    }
}

int solution(string word) {
    int answer = 0;
    
    next("", word);
    answer = cnt;
    return answer;
}