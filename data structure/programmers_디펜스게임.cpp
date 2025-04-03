#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    //만약 무적권의 수가 충분하면 모든 라운드 통과
    if(enemy.size() <= k) return enemy.size();
    
    //우선순위 큐 사용
    int max_round = 0;
    priority_queue<int> pq;
    for(int i = 0; i < enemy.size(); i++){
        //n으로 처리 가능하면 처리
        if(n >= enemy[i]){
            n -= enemy[i];
            pq.push(enemy[i]);
            max_round++;
        }
        //안된다면 k로 무적권 사용
        else{
            if(k > 0){
                if(pq.empty() || pq.top() < enemy[i]){//만약 이전에 지나간 것이 없으면 얘를 무적권 사용
                    k--;
                    max_round++;
                    continue;
                }
                else{//이전에 지나간 것이 있다면 그 중 가장 큰 값을 무적권 사용
                    k--;
                    n += pq.top();
                    pq.pop();
                    i--;
                    continue;
                }
            }
            else{
                break;
            }
        }
    }
    answer = max_round;
    return answer;
}