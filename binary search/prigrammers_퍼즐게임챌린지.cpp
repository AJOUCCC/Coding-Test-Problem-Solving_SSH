#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    //diffs를 정렬
    vector<int> sorted_diffs = vector<int>(diffs);
    sort(sorted_diffs.begin(), sorted_diffs.end());
    int left = diffs[0]; //맨 처음 퍼즐은 무조건 풀 수 있어야 하므로 이것이 초기 left
    int right = sorted_diffs[diffs.size()-1]; //diffs 중에서 가장 큰 값이 right
    int mid = (left + right) / 2;
    
    //level 값을 이분 탐색으로 바꿔가며 탐색
    while(true){
         //종결조건
        if(left > right){
            break;
        }
        else if(left == right){
            answer = left;
            break;
        }
        
        long long total_times = 0;
        for(int i = 0; i < diffs.size(); i++){
            if(diffs[i] <= mid)
                total_times += times[i];
            else
                total_times += (diffs[i] - mid) * (times[i] + times[i-1]) + times[i];
            
            if(total_times > limit){
                break;
            }
        }
            
        //전체 합이 limit값의 대소관계에 따라 탐색 범위 변경
        answer = mid;
        if(total_times > limit){
            left = mid + 1;
            mid =  (left + right) / 2;
        }
        else if(total_times < limit){
            right = mid;
            mid =  (left + right) / 2;
        }
        else{
            break;
        }
    }
    return answer;
}