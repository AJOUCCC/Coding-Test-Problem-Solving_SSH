#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    //입력 받기
    int N, M;
    cin >> N >> M;

    //길이가 M인 수열 초기화
    vector<int> targets;
    vector<int> hints;
    int MIN_VAL = 1, MAX_VAL = 9;
    for(int i = 0; i < N; i++){
        targets.push_back(i+1);
        if(i < M) hints.push_back(MIN_VAL);
        else hints.push_back(MAX_VAL);
    }

    //순열을 프린트
    do{
        for(int i = 0; i < hints.size(); i++){
            if(hints[i] == MAX_VAL) continue;
            else {
                cout << targets[i] << " ";
            }
        }
        cout << "\n";
    } while(next_permutation(hints.begin(), hints.end()));
    
}
