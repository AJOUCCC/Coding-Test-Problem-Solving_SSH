#include <string>
#include <vector>
#include <iostream>
using namespace std;

int MAX_SIZE;
vector<pair<int,int>> trapzoid_dp;
vector<pair<int,int>> parallelogram_dp;
int trapzoid(int k, vector<int> &tops);
int parallelogram(int k, vector<int> &tops);

int trapzoid(int k, vector<int> &tops){ //윗변의 길이 k인 사다리꼴
    int idx = MAX_SIZE - k;
    //이번 인덱스에서 산이 없으면
    if(tops[idx] == 0){
        if(trapzoid_dp[idx].first != -1) {
            //cout << "k: " << k << " " << "trapzoid without: " << trapzoid_dp[idx].first << "\n";
            return trapzoid_dp[idx].first;
        }
        int result = (parallelogram(k, tops) + trapzoid(k-1, tops)) % 10007;
        trapzoid_dp[idx].first = result;
        //cout << "k: " << k << " " << "trapzoid without: " << result << "\n";
        return result;
    }
    //산이 있으면
    else{
        if(trapzoid_dp[idx].second != -1) {
            //cout << "k: " << k << " " << "trapzoid with: " << trapzoid_dp[idx].second << "\n";
            return trapzoid_dp[idx].second;
        }
        int result = (parallelogram(k, tops) + trapzoid(k-1, tops)) % 10007;
        trapzoid_dp[idx].second = result;
        //cout << "k: " << k << " " << "trapzoid with: " << result << "\n";
        return result;
    }
}

int parallelogram(int k, vector<int> &tops){ //윗변의 길이 k인 평행사변형
    int idx = MAX_SIZE - k;
    //이번 인덱스에서 산이 없으면
    if(tops[idx] == 0){
        if(parallelogram_dp[idx].first != -1) {
            //cout << "k: " << k << " " << "parallelogram without: " << parallelogram_dp[idx].first << "\n";
            return parallelogram_dp[idx].first;
        }
        int result = (parallelogram(k-1, tops) + trapzoid(k-1, tops)) % 10007;
        parallelogram_dp[idx].first = result;
        //cout << "k: " << k << " " << "parallelogram without: " << result << "\n";
        return result;
    }
    //산이 있으면
    else{
        if(parallelogram_dp[idx].second != -1) {
            //cout << "k: " << k << " " << "parallelogram with: " << parallelogram_dp[idx].second << "\n";
            return parallelogram_dp[idx].second;
        }
        int result = (parallelogram(k-1, tops) + 2 * trapzoid(k-1, tops)) % 10007;
        parallelogram_dp[idx].second = result;
        //cout << "k: " << k << " " << "parallelogram with: " << result << "\n";
        return result;
    }
}

int solution(int n, vector<int> tops) {
    int answer = 0;
    MAX_SIZE = n;
    trapzoid_dp = vector<pair<int,int>>(n, make_pair(-1,-1));
    parallelogram_dp = vector<pair<int,int>>(n, make_pair(-1,-1));
    trapzoid_dp[n-1] = {3, 4};
    parallelogram_dp[n-1] = {2, 3};
    
    //DP로 풀되, 평행사변형과 사다리꼴 두개로 나눔
    int result = trapzoid(n, tops);
        
    return result;
}