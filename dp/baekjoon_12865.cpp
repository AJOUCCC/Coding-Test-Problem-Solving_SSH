#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력받기
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> items = vector<pair<int,int>>(N+1, make_pair(0,0));
    for(int i = 1; i < N+1; i++)
        cin >> items[i].first >> items[i].second;

    //무게별로 가로축, 고려하는 원소수별로 세로축으로 한 dp 구하기
    vector<vector<int>> dp = vector<vector<int>>(N+1, vector<int>(K+1, 0));
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < K+1; j++){
            if(items[i].first <= j){
                if(items[i].second + dp[i-1][j-items[i].first] > dp[i-1][j]){
                    dp[i][j] = items[i].second + dp[i-1][j-items[i].first];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    //마지막 dp(n, k) 출력
    cout << dp[N][K] << "\n";
}