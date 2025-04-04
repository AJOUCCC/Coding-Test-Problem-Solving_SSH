#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력받기
    int N;
    cin >> N;
    vector<pair<int,int>> items = vector<pair<int,int>>(N+1, make_pair(0,0));
    for(int i = 1; i < N+1; i++)
        cin >> items[i].first >> items[i].second;
        
    //무게별로 가로축, 고려하는 원소수별로 세로축으로 한 dp 구하기
    vector<int> dp = vector<int>(N+2, 0);
    for(int i = 1; i < N+2; i++){
        if(dp[i] < dp[i-1])
            dp[i] = dp[i-1];
        
        if(i == N+1) break;
        if(items[i].first + i < N+2 && dp[i] + items[i].second > dp[items[i].first + i]){
            dp[items[i].first + i] = dp[i] + items[i].second;
        }
    }

    //마지막 dp 출력
    cout << dp[N+1] << "\n";
}