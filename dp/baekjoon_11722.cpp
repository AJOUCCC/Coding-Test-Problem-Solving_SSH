#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> nums = vector<int>(N, 0);
    vector<int> dp = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < N; i++){
        int max = -1;
        for(int j = 0; j < i; j++){
            if(nums[i] >= nums[j]) continue;
            if(dp[j] > max) max = dp[j];
        }
        if(max == -1) dp[i] = 1;
        else dp[i] = max + 1;
    }

    int max = -1;
    for(int i = 0; i < N; i++){
        if(dp[i] > max) max = dp[i];
    }   
    cout << max << "\n"; 

}