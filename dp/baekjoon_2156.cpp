#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b, int c){
    vector<int> vec = {a,b,c};
    sort(vec.begin(), vec.end());
    return vec[2];
}
int main(void){
    //입력받기
    int n;
    cin >> n;
    vector<int> drinks = vector<int>(n+3,0);
    for(int i = 3; i < drinks.size(); i++)
        cin >> drinks[i];

    //DP로 풀기
    vector<int> dp = vector<int>(n+3, 0);//dp[i]는 i번째 포도주를 반드시 포함할때의 최대 포도주 양양
    for(int i = 3; i < drinks.size(); i++){

        //점화식 계산
        dp[i] = max(dp[i-2] + drinks[i], (drinks[i-1] + dp[i-3]) + drinks[i], dp[i-1]);
        //cout << i << ", " << dp[i] << "\n";
    }

    //출력하기
    int max = -1;
    for(int i = 3; i < dp.size(); i++)
        if(dp[i] > max) max = dp[i];
    cout << max << "\n";

}