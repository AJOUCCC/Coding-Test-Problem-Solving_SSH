#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    //end 오름차순으로 정렬
    sort(targets.begin(), targets.end(), compare);
    
    //target 순서대로 순회
    for(int i = 0; i < targets.size(); i++){
        //target의 맨 앞 것 
        vector<int> curr = targets[i];
        
        //뒤에 있는 것들 차례로 순회하며, target.end > next.start라면 얘도 같이 요격 가능
        for(int j = i+1; j < targets.size(); j++){
            if(curr[1] <= targets[j][0]) break;
            i++;
        }
        //미사일 수 카운팅
        answer++;
    }

    return answer;
}