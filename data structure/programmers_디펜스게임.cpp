#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    //완전 탐색으로 풀자
    //만약 무적권의 수가 충분하면 모든 라운드 통과
    if(enemy.size() <= k) return enemy.size();
    
    //아니라면 완전 탐색
    vector<int> perm = vector<int>(enemy.size(), 1);
    int max_round = 0;
    for(int i = 0; i < k; i++)
        perm[i] = 0;
    do{
        int lives = n;
        int round = 0;
        for(int i = 0; i < enemy.size(); i++){
            if(perm[i] == 0){
                round++;
                continue;
            }
            
            if(lives >= enemy[i]){
                lives -= enemy[i];
                round++;
            }
            else
                break;
        }
        // for(int i = 0; i < enemy.size(); i++){
        //     cout << perm[i] << " ";
        // }
        // cout << "\n";
        // cout << round << "\n";
        if(round > max_round) max_round = round;
    }
    while(next_permutation(perm.begin(), perm.end()));
    answer = max_round;
    return answer;
}