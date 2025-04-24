#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b){
    return a > b;
}
int solution(vector<int> cards) {
    int answer = 0;
    
    //cards를 순회
    vector<bool> visited = vector<bool>(cards.size(), false);
    vector<int> score;
    for(int i = 0; i < cards.size(); i++){
        //visited 참이라면 넘기기
        if(visited[i]) continue;
        
        //visited를 참으로 변경
        visited[i] = true;
        
        //cards[i] = i+1가 될때까지 상자 열기
        int box_cnt = 1;
        int idx = cards[i] - 1;
        while(!visited[idx]){
            //현 상자를 visited 참으로 변경
            //상자 그룹의 상자 수 카운팅
            visited[idx] = true;
            box_cnt++;
            idx = cards[idx] - 1;   
        }
            
        //카운팅된 상자의 수 벡터에 넣기
        score.push_back(box_cnt);    
    }
    
    //벡터 내림차순 정렬
    sort(score.begin(), score.end(), compare);
    
    //벡터의 크기 2보다 작다면 점수는 0
    //아니라면 벡터에서 맨 앞 두개의 곱이 점수
    if(score.size() < 2) return 0;
    else return score[0] * score[1];
}