#include <iostream>
#include <vector>
using namespace std;

unsigned long long get_wave(vector<unsigned long long> &dp, int n){
    //만약 0이거나 1이라면
    if(n == 0 || n == 1 | n == 2) return dp[n];
    //만약 이미 dp에 저장된 값이 있다면 리턴
    else if(dp[n] != 0) return dp[n];

    //없다면 점화식으로 계산
    long result = get_wave(dp, n-2) + get_wave(dp, n-3);
    dp[n] = result;
    return result;
}

int main(void){
    int T;
    cin >> T;
    vector<unsigned long long> dp = vector<unsigned long long>(101, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        
        unsigned long long result = get_wave(dp, N);
        cout << result << "\n";
        
    }
}