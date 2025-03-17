#include <string>
#include <vector>
#include <iostream>
using namespace std;

int select_one(string number, int s, int e){
    int maxIdx, maxVal = -1;
    for(int i = s; i <= e; i++){
        if(number[i] > maxVal){
            maxIdx = i;
            maxVal = number[i];
        }
    }
    return maxIdx;
}
string solution(string number, int k) {
    string answer = "";
    //범위를 제한하여 하나씩 선택
    int SELECT_SIZE = number.size()-k;
    int start = 0, end = number.size()-1;
    vector<bool> selected = vector<bool>(number.size(), false);
    for(int i = 0; i < SELECT_SIZE; i++){
        end = (number.size()-1) - (SELECT_SIZE-i-1);
        int selectedIdx = select_one(number, start, end);
        selected[selectedIdx] = true;
        start = selectedIdx + 1;
    }
    
    //선택한 것들 출력
    for(int i = 0; i < number.size(); i++){
        if(selected[i])
            answer.push_back(number[i]);
    }
    return answer;
}