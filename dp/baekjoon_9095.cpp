#include <iostream>
#include <vector>
using namespace std;

int get_operations(vector<int> &dp,  int N){
    //dp가 있다면 리턴
    if(dp[N] != -1) return dp[N];

    //없다면 계산 후 dp에 저장 및 리턴
    dp[N] = get_operations(dp, N-1) + get_operations(dp, N-2) + get_operations(dp, N-3);
    return dp[N];
}

int main(void){
    //입력
    int T;
    cin >> T;

    //Top-down방식 + DP로 방법 수 구하기
    vector<int> dp = vector<int>(12, -1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        cout << get_operations(dp, N) << "\n";
    }
}