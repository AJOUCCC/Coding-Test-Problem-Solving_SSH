#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    int N;
    stack<pair<int,int>> st;
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < N; i++){
        int height;
        cin >> height;

        while(!st.empty() && st.top().second < height)
            st.pop();        

        if(st.empty()) cout << "0 ";
        else cout << st.top().first << " ";

        st.push(make_pair(i+1, height));
    }

    cout << "\n";
}