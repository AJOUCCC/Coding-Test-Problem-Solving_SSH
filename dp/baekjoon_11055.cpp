#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int N;
    cin >> N;
    vector<int> nums = vector<int>(N, 0);
    vector<int> dp = vector<int>(N, 0); //지금까지의 가장 큰 sum을 저장할 벡터
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    //가장 큰 증가하는 부분 수열 dp로 구하기
    for(int i = 0; i < N; i++){
        bool isAllSmall = true;
        int max = -1;
        for(int j = 0; j < i; j++){
            if(nums[i] <= nums[j]) continue;
            if(dp[j] > max) {
                max = dp[j];
                isAllSmall = false;
            }
        }

        //이전 수열이 모두 현재 수보다 컸다면, 현재 수를 저장
        //아니라면 이전 수 중 dp값이 가장 큰 값 + 현재 수를 저장
        if(isAllSmall){
            dp[i] = nums[i];
        }
        else{
            dp[i] = max + nums[i];
        }
    }

    //출력
    int max = -1;
    for(int i = 0; i < N; i++){
        if(max < dp[i]) max = dp[i];
    }
    cout << max << "\n";
}