#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int K;
    cin >> K;

    //K개를 한 개씩 읽음
    //정수가 0이면 스택에서 pop, 0아니면 push
    stack<int> st;
    for(int i = 0; i < K; i++){
        int input;
        cin >> input;
        if(input == 0) st.pop();
        else st.push(input);
    }

    //최종적으로 스택 모두 pop 해서 unsigned long long에 더하기
    unsigned long long sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }

    cout << sum << "\n";
}