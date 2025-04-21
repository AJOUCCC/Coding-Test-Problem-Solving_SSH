#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

bool compare(int a, int b){
    return a > b;
}

int main(void){
    //입력
    int N, K; 
    cin >> N >> K;
    vector<int> coins = vector<int>(N+1, 0);
    vector<vector<int>> dp = vector<vector<int>>(N+1, vector<int>(K+1, -1));
    for(int i = 0; i < dp.size(); i++)
        dp[i][0] = 0;
    for(int i = 1; i < N+1; i++)
        cin >> coins[i];

    //동전을 가치 오름차순 정렬
    sort(coins.begin(), coins.end());

    //DP 순회
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            //현 동전 i를 추가 가능하지 않다면 이전 것으로
            if(coins[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            //현 동전 i를 추가 가능하다면
            //불가능한 경우라면 이전 것으로
            else if(dp[i][j - coins[i]] == -1){
                dp[i][j] = dp[i-1][j];
            }
            else if(dp[i-1][j] == -1){
                dp[i][j] = 1 + dp[i][j - coins[i]];
            }
            //가능한 경우라면, min(이전 것, 현 동전 + 가치 뺀 만큼의 dp)로
            else{
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i]]);
            }
        }
    }

    // for(int i = 1; i < dp.size(); i++){
    //     for(int j = 1; j < dp[0].size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[N][K] << "\n";
 
}