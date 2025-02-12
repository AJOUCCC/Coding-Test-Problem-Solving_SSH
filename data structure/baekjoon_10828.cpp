#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    vector<string> cmds;
    cmds.push_back("push");
    cmds.push_back("pop");
    cmds.push_back("empty");
    cmds.push_back("size");
    cmds.push_back("top");
    stack<string> s;
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;
        if(cmd.compare(cmds[0]) == 0){
            string val;
            cin >> val;
            s.push(val);
        }
        else if(cmd.compare(cmds[1]) == 0){
            if(s.empty()) cout << "-1\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(cmd.compare(cmds[2]) == 0){
            cout << s.empty() << "\n";   
        }
        else if(cmd.compare(cmds[3]) == 0){
            cout << s.size() << "\n";
        }
        else{
            if(s.empty()) cout << "-1\n";
            else 
                cout << s.top() << "\n";
        }
    }
}