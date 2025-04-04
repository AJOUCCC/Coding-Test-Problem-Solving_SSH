#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int N;
    cin >> N;
    vector<pair<int,int>> sched = vector<pair<int,int>>(N+1, make_pair(0,0));
    for(int i = 1; i < sched.size(); i++)
        cin >> sched[i].first >> sched[i].second;

    //DP로 풀기
    vector<vector<int>> dp = vector<vector<int>>(N+1, vector<int>(N+1, 0));
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            if(i + sched[i].first - 1 <= j){
                if(sched[i].second + dp[i-1][i-1] > dp[i-1][j])
                    dp[i][j] = sched[i].second + dp[i-1][i-1];
                else 
                    dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }

    //결과를 출력
    cout << dp[N][N] << "\n";
}