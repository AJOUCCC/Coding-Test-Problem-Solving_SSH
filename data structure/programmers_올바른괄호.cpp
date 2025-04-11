#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    //스택 선언
    stack<char> st;
    
    //s를 순회
    for(int i = 0; i < s.size(); i++){
        //'('라면 push, ')'라면 하나를 pop(pop 못한다면 false)
        if(s[i] == '(') st.push('(');
        else{
            if(!st.empty()) st.pop();
            else return false;
        }
    } 
    
    //stack이 비었다면 true, 아니면 false 반환
    if(st.empty()) return true;
    else return false;
}