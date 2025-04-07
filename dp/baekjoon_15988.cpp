#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력받기
    int t;
    cin >> t;

    //맨 앞이 1, 2, 3일때로 나누어서 divide and conquer
    vector<long long> dp = vector<long long>(1000001, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < dp.size(); i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;      
    }

    //출력
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    
}