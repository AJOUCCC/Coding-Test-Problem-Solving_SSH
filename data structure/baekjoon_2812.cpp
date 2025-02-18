#include <iostream>
#include <deque>
using namespace std;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    string num;
    deque<char> dq;
    cin >> N >> K >> num;

    for(int i = 0; i < N; i++){
        while(!dq.empty() && dq.back() < num[i] && K > 0){
            dq.pop_back();
            K--;
        }
        dq.push_back(num[i]);
    }
    
    for(int i = 0; i < dq.size() - K; i++){
        cout << dq[i];
    }
    cout << "\n";
}