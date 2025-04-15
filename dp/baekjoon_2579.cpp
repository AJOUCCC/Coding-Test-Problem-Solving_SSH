#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
    return (a > b)? a : b;
}

int main(void){
    //입력
    int N;
    cin >> N;
    vector<int> stairs = vector<int>(N+3, 0);
    for(int i = 3; i < N+3; i++)
        cin >> stairs[i];
    
    //계단 처음부터 순회
    vector<int> dp = vector<int>(N+3, 0);
    for(int i = 3; i < N+3; i++){
        //max(dp[n-2], v[n-1] + dp[n-3]) + v[n]값이 현 계단을 도착으로 하는 최대값
        dp[i] = stairs[i] + max(dp[i-2], stairs[i-1] + dp[i-3]);
    }

    //출력
    cout << dp[N+2] << "\n";
}