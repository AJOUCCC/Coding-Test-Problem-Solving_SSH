#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int N;
    string cmd;
    stack<double> st;
    cin >> N >> cmd;
    int n[N];

    for(int i = 0; i < N; i++){
        cin >> n[i];
    }

    //후위 표기식 순회하며 계산
    //피연산자는 push, 연산자 등장 시 2번 pop 후 계산하고 결과 push
    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i] >= 'A' && cmd[i] <= 'Z'){
            st.push(n[cmd[i] - 'A']);
            continue;
        }
        else{
            double first, second, result;
            second = st.top();
            st.pop();
            first = st.top();
            st.pop();
            
            if(cmd[i] == '+')
                result = first + second;
            else if(cmd[i] == '-')
                result = first - second;
            else if(cmd[i] == '*')
                result = first * second;
            else
                result = first / second;
        
            st.push(result);
        } 
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top() << "\n";
}