#include <string>
#include <vector>

using namespace std;
vector<int> find_carpet(int brown, int yellow){
    //이중for문으로 완전 탐색
    for(int i = 3; i <= 5000;i++){
        for(int j = i; j <= 5000; j++){
            if(i * j - yellow == brown && (i-2) * (j-2) == yellow){
                return {j, i};
            }         
        }
    }
    return {-1,-1};
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    answer = find_carpet(brown, yellow);
    return answer;
}