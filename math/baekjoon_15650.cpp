#include <iostream>
using namespace std;
void print(int* str, int M);
bool is_last(int* str, int curr);
int N, M;

//불합격!
int main(void){

    //입력 받기
    cin >> N >> M;

    //길이가 M인 수열 초기화
    int str[M];
    for(int i = 0; i < M; i++){
        str[i] = i+1;
    }
    print(str, M);

    //마지막 것을 옮기고 프린트
    for(int i = M-1; i >= 0; i--){
        while(!is_last(str, i)){
            str[i] = str[i] + 1;
            print(str, M);   
        }
    }
}

void print(int* str, int M){
    for(int i = 0; i < M; i++){
        cout << str[i] << " ";
    }
    cout << "\n";
}

bool is_last(int* str, int curr){
    if(str[curr] == N-(M-(curr+1))){
        return true;
    }
    else{
        return false;
    }
}