#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(void){
    //입력
    string str, target;
    cin >> str >> target;

    //문자 하나씩 넣고 뒤에서 target 발견 시 삭제제
    string newStr;
    int tIdx = 0;
    for(int i = 0; i < str.size(); i++){
        //문자 넣기
        newStr.push_back(str[i]);

        //target인지 확인
        if(newStr.size() >= target.size() && newStr.substr(newStr.size()-target.size(), target.size()) == target){
            for(int i = 0; i < target.size(); i++)
                newStr.pop_back();
        }
    }

    //출력
    if(newStr.empty()) cout << "FRULA\n";
    else cout << newStr << "\n";
}