#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int n;
    cin >> n;
    vector<int> nums = vector<int>(n+1, 0);
    vector<int> dp = vector<int>(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i+1];
    }

    //현재 수로 끝나는 연속합 중 최대값을 DP에 저장
    for(int i = 1; i < n+1; i++){
        if(nums[i] + dp[i-1] > nums[i]){
            dp[i] = nums[i] + dp[i-1];
        }
        else{
            dp[i] = nums[i];
        }
    }

    //출력
    int max = dp[1];
    for(int i = 1; i < n+1; i++){
        if(dp[i] > max) max = dp[i];
    }
    cout << max << "\n";
}