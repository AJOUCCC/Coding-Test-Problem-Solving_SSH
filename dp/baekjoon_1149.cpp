#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b){
    return (a < b)? a : b;
}

int main(void){
    //입력
    int N;
    cin >> N;
    //DP로 하되, RGB를 열로 집 개수를 행으로 하여 2차원 DP 선언
    vector<vector<int>> rgbs = vector<vector<int>>(N+1, vector<int>(3, 0));
    vector<vector<int>> dp = vector<vector<int>>(N+1, vector<int>(3, 0));
    for(int i = 1; i < N+1; i++)
        cin >> rgbs[i][0] >> rgbs[i][1] >> rgbs[i][2];

    //집 순회
    for(int i = 1; i < N+1; i++){
        //dp[n][R] = v[n][R] + min(dp[n-1][G], dp[n-1][B])
        dp[i][0] = rgbs[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = rgbs[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = rgbs[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    //출력
    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << "\n";
        
}