#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int N;
    cin >> N;
    vector<int> levels = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> levels[i];
    }

    //뒤에부터 하나씩 그리디하게 값 결정
    int prev = 20000;
    int cnt = 0;
    for(int i = levels.size()-1; i >= 0; i--){
        while(levels[i] >= prev){
            levels[i]--;
            cnt++;
        }
        prev = levels[i];
    }

    //출력
    cout << cnt << "\n";
}