#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string ps;
        stack<char> st;
        bool isValid = true;
        cin >> ps;
        for(int j = 0; j < ps.size(); j++){
            if(ps[j] == '(')
                st.push('(');
            else if(ps[j] == ')'){
                if(st.empty()){
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }

        if(st.size() != 0 || !isValid) cout << "NO\n";
        else cout << "YES\n"; 
    }
}