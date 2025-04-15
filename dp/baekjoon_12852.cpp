#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int N;
    cin >> N;
    vector<int> dp = vector<int>(N+1, 0);
    vector<int> prev = vector<int>(N+1, 0);

    //N까지 순회
    for(int i = 2; i < N+1; i++){
        //dp[N] = 1 + min(dp[N/3], dp[N/2], dp[N-1])
        //prev[N] = 세 선택지 중 min인 선택지의 N값
        int min = N+1;
        int minIdx = 0;
        if(i % 3 == 0 && dp[i / 3] < min) {
            min = dp[i / 3];
            minIdx = i / 3;
        }
        if(i % 2 == 0 && dp[i / 2] < min) {
            min = dp[i / 2];
            minIdx = i / 2;
        }
        if(dp[i-1] < min) { 
            min = dp[i-1];
            minIdx = i -1;
        }
        
        dp[i] = 1 + min;
        prev[i] = minIdx;
    }
        
    //N부터 prev[N]을 순회하며 출력
    cout << dp[N] << "\n";
    int idx = N;
    while(idx != 0){
        cout << idx << " ";
        idx = prev[idx];
    }
}