#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*구간합 + 투포인터*/
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, (int)sequence.size()-1};
    
    //합 배열 생성
    vector<int> sum = vector<int>(sequence.size()+1, 0);
    for(int i = 0; i < sequence.size(); i++){
        sum[i+1] = sum[i] + sequence[i]; 
    }
    
    //투포인터로 순회, 시작은 start = end = 1
    int s = 1, e = 1;
    while(true){
        if(s > e || e > sequence.size()) break;
        //sum[e] - sum[s-1] > k -> s++;
        if(sum[e] - sum[s-1] > k) s++;
        //sum[e] - sum[s-1] < k -> e++;
        else if(sum[e] - sum[s-1] < k) e++;
        //sum[e] - sum[s-1] = k -> FIND!;
        else{
            if(e-s < answer[1] - answer[0])
                answer = {s-1, e-1};
            e++;
        }
    }
    return answer;
}