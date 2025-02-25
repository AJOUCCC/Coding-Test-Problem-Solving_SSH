#include <iostream>
#include <vector>
using namespace std;

int find_methods(vector<int> &dp, int n){
    //초기값이라면 리턴
    if(n == 1 || n == 2) return dp[n];

    //값이 저장되어있다면 리턴
    else if(dp[n] != 0) return dp[n];
    
    //아니라면 점화식 세우기
    int result = (find_methods(dp, n-1) + find_methods(dp, n-2)) % 10007;
    dp[n] = result;
    return result;
}

int main(void){
    int n;
    cin >> n;
    vector<int> dp = vector<int>(1001, 0);
    dp[1] = 1;
    dp[2] = 2;

    int result = find_methods(dp, n);
    cout << result << "\n";

}