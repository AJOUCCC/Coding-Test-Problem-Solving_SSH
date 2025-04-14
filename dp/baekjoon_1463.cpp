#include <iostream>
#include <vector>
using namespace std;

int get_min_operation(vector<int> &dp, int N){
    //DP에 저장된 값이 있다면 리턴
    if(dp[N] != -1) return dp[N];
    
    //없다면 3개의 연산 차례로 시도하고 재귀 호출
    int r1 = N, r2 = N, r3 = N;
    int min = N;
    if(N % 3 == 0) {
        r1 = get_min_operation(dp, N / 3) + 1;
        if(r1 < min) min = r1;
    }
    if(N % 2 == 0) {
        r2 = get_min_operation(dp, N / 2) + 1;
        if(r2 < min) min = r2;
    }
    r3 = get_min_operation(dp, N-1) + 1; 
    if(r3 < min) min = r3;
     
    dp[N] = min;
    //cout << "N: " << N << " dp[N]: " << dp[N] << "\n";
    return dp[N];
}

int main(void){
    //입력받기
    int N;
    cin >> N;

    //DP, Top-down 방식으로 풀기
    vector<int> dp = vector<int>(N+1, -1);
    dp[1] = 0;
    int operations = get_min_operation(dp, N);

    //출력하기
    cout << operations << "\n";
}