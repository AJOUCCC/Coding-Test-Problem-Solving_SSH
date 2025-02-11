#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;

    //시간 단축용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //순열 구하기 위한 배열 2개 
    string targets;
    string stores;
    for(int i = 0; i < N; i++){
        targets.push_back(i+1+'0');
    }

    //permuation으로 순열 구하기
    do{
        //출력
        if(!targets.substr(0, M).compare(stores) == 0){
            for(int i = 0; i < M; i++){
                cout << targets[i] << " ";
            }
            cout << "\n";
            stores = targets.substr(0, M);
        }

    } while(next_permutation(targets.begin(), targets.end()));
}