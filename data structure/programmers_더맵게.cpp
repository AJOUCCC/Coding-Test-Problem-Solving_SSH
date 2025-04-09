#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //우선순위 큐로 풀기
    priority_queue<int, vector<int>, greater<int>> pq;
    int mix_cnt = 0;
    for(int i = 0; i < scoville.size(); i++)    
        pq.push(scoville[i]);
    
    while(true){
        //큐 크기가 1개라면 끝
        if(pq.size() == 1){
            if(pq.top() >= K) break;
            else return -1;
        }
        
        //큐에서 2개 pop한 것이 둘 다 K이상이라면 끝
        int minFirst, minSecond;
        minFirst = pq.top();
        pq.pop();
        minSecond = pq.top();
        pq.pop();
        //cout << minFirst << ", " << minSecond << "\n";
        if(minFirst >= K && minSecond >= K) break;
        
        //아니라면, 섞어서 새 것을 push
        pq.push(minFirst + minSecond * 2);
        mix_cnt++;
    }
    
    answer = mix_cnt;
    return answer;
}