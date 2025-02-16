#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int N;
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string cmd;
    queue<int> qu;
    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd.compare("push") == 0){
            int X;
            cin >> X;
            qu.push(X);
        }
        else if(cmd.compare("pop") == 0){
            if(qu.empty()) cout << "-1\n";
            else{
                cout << qu.front() << "\n";
                qu.pop();
            }
        }
        else if(cmd.compare("size") == 0){
            cout << qu.size() << "\n";
        }
        else if(cmd.compare("empty") == 0){
            cout << qu.empty() << "\n";
        }
        else if(cmd.compare("front") == 0){
            if(qu.empty()) cout << "-1\n";
            else cout << qu.front() << "\n";
        }
        else{
            if(qu.empty()) cout << "-1\n";
            else cout << qu.back() << "\n";
        }
    }
}