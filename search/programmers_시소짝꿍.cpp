#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    //오름차순 정렬
    sort(weights.begin(), weights.end());
    
    //짝을 순회하며 판단
    for(int i = 0; i < weights.size(); i++){
        for(int j = i+1; i < weights.size(); j++){
            //무게 차이가 너무 난다면 break -> 이거 있어야 시간 초과 안뜸~~
            if(3 * weights[i] < 2 * weights[j] && 2 * weights[i] < weights[j] && 4 * weights[i] < 3 * weights[j]) break;
            //비교해볼만 하다면 비교해서 시소짝꿍인지 카운트
            if(weights[i] == weights[j] || 3 * weights[i] == 2 * weights[j] || 2 * weights[i] == weights[j] || 4 * weights[i] == 3 * weights[j]) answer++;      
        }
    }
    
    return answer;
}