#include <iostream>
#include <vector>
using namespace std;

int count = 0;
void get_upstair(vector<vector<int>> &dp, int size, int curr){
    //종결 조건
    if(curr >= size) return;

    //이전 자리수에 온 숫자들 정보로 현재 자리수의 숫자들 세팅
    for(int i = 0; i < 10; i++){
        if(i != 0)
            dp[curr][i-1] = (dp[curr][i-1] + dp[curr-1][i]) % 1000000000;
        if(i != 9)
            dp[curr][i+1] = (dp[curr][i+1] + dp[curr-1][i]) % 1000000000;
    }

    get_upstair(dp, size, curr+1);
}


int main(void){
    //입력
    int N;
    cin >> N;
    vector<vector<int>> dp = vector<vector<int>>(N, vector<int>(10, 0));

    //계단 수를 한 자리씩 살펴보며 경우의 수 세기
    for(int i = 1; i < 10; i++){
        dp[0][i] = 1;
    }
    get_upstair(dp, N, 1);

    //출력
    int count = 0;
    for(int i = 0; i < 10; i++){
        count = (count + dp[N-1][i]) % 1000000000;
    }
    cout << count << "\n";
}