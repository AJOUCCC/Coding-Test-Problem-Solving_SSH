#include <iostream>
#include <list>
using namespace std;

int main(void){
    int N, M;
    string initial;
    list<char> editor;

    //초기 값 입력 및 list에 세팅팅
    cin >> initial;
    N = initial.size();
    for(int i = 0; i < N; i++){
        editor.push_back(initial[i]);
    }

    //iterator 맨 뒤로 세팅
    list<char>::iterator iter = editor.end();

    //명령어 하나씩 입력
    //경우에 따라 iterator 이동 및 삭제, 삽입
    cin >> M;
    for(int i = 0; i < M; i++){
        char cmd, value;
        cin >> cmd;

        switch(cmd){
            case 'L':
                if(iter == editor.begin()) break;
                else iter--;
                break;
            case 'D':
                if(iter == editor.end()) break;
                else iter++;
                break;
            case 'B':
                if(iter == editor.begin()) break;
                else{
                    iter = editor.erase(--iter);
                }
                break;
            case 'P':
                cin >> value;
                editor.insert(iter, value);
                break;
            default:
                break;
        }
    }

    //최종 남은 결과 출력
    for(list<char>::iterator it = editor.begin(); it != editor.end(); it++){
        cout << *it;
    }
    cout << "\n";
}