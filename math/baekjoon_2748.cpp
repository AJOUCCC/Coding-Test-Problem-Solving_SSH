#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int n;
    cin >> n;

    //점화식대로 DP
    vector<long long> dp = vector<long long>(n+1, 0);
    dp[1] = 1;
    for(int i = 2; i < dp.size(); i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    //출력
    cout << dp[n] << "\n";
}