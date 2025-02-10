#include <iostream>
using namespace std;

int main(void){
    int N, M;
    int smalls[101];
    cin >> N >> M;

    //계산 효율을 위한 식 변경
    if(M > 50){
        M = 100 - M;
    }

    //분자에 올 숫자들 배열에 저장
    for(int j = 0; j < M; j++){
        smalls[j+1] = j+1;
    }

    //nCm 계산
    unsigned long long big = 1;
    unsigned long long small = 1;
    int temp = N;
    for(int i = M; i > 1; i--){
        small *= i;
    }
    for(int i = 0; i < M; i++){
        big *= temp--;
        for(int j = 0; j < M; j++){
            if(smalls[j+1] != 0 && big % smalls[j+1] == 0) {
                big /= smalls[j+1];
                smalls[j+1] = 0;
            }
        }
    }
    cout << big << endl;

}