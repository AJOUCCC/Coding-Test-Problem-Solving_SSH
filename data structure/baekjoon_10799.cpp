#include <iostream>
#include <stack>
using namespace std;

int main(void){
    string str;
    int count = 0;
    stack<char> st;
    cin >> str;

    //문자열 순회하며 판단
    bool rasor;
    for(int i = 0; i < str.size(); i++){
        
        if(str[i] == '('){
            st.push('(');
            rasor = true;
        }else{
            if(rasor){
                st.pop();
                count += st.size();
            }
            else{
                st.pop();
                count += 1;
            }
            rasor = false;
        }
    }

    //카운트 수 출력
    cout << count << "\n";
}