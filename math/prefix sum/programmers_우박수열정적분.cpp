#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    //우박수열과 구간합을 구하기
    vector<int> seq;
    vector<double> sum;
    seq.push_back(k);
    sum.push_back(0);
    while(k > 1){
        if(k % 2 == 0){
            k /= 2;
        }
        else{
            k = k * 3 + 1;
        }
        sum.push_back(sum[sum.size()-1] + (double)(seq[seq.size()-1] + k) / 2);
        seq.push_back(k);
    }
    
    // for(int i = 0; i < sum.size(); i++){
    //     cout << seq[i] << ", " << sum[i] << "\n";
    // }
    
    //ranges를 순회하며, Sum(Re) - Sum(Rs)를 계산하기
    int n = seq.size()-1;
    for(int i = 0; i < ranges.size(); i++){
        if(ranges[i][0] > n + ranges[i][1]) answer.push_back(-1.0);
        else answer.push_back(sum[n + ranges[i][1]] - sum[ranges[i][0]]);
    }
    return answer;
}