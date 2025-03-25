#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = vector<int>(numbers.size(), 0);
    
    stack<int> st;
    //뒤 원소부터 순회
    for(int i = numbers.size()-1; i >= 0; i--){
        //현 원소 >= top이라면 pop하고 다시 반복
        while(!st.empty() && numbers[i] >= st.top())
            st.pop();
        
        //stack이 비었다면 -1 출력
        if(st.empty())
            answer[i] = -1;
        //현 원소 < top이라면 top 출력
        else
            answer[i] = st.top();        
        
        //현 원소 push
        st.push(numbers[i]);
    }
       
    return answer;
}