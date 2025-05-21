#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> max_result = {0, 0};
vector<int> ratios;
vector<int> RATIOS_OPT = {10, 20, 30, 40};
void select(int k, vector<vector<int>> &users, vector<int> &emoticons){
    //k == emoticons.size()라면, 이때의 이득 계산 
    if(k == emoticons.size()){
        int plus = 0, sum_money = 0;
        for(int i = 0; i < users.size(); i++){
            int money = 0;
            for(int j = 0; j < emoticons.size(); j++){
                if(ratios[j] >= users[i][0])
                    money += emoticons[j] - (emoticons[j] * ratios[j] / 100);
            }
            if(money >= users[i][1])
                plus++;
            else 
                sum_money += money;
        }
        //현재 플러스 고객, 이모티콘 수익이 최대라면 업데이트
        //cout << "Ratios: ";
        // for(int l = 0; l < ratios.size(); l++)
        //     cout << ratios[l] << " ";
        // cout << "\n";
        // cout << plus << ", " << sum_money << "\n";
        if(plus > max_result[0] || (plus == max_result[0] && sum_money > max_result[1]))
            max_result = {plus, sum_money};
        return;
    }
    
    //for문으로 k번째 이모티콘의 할인율을 선택
    for(int i = 0; i < RATIOS_OPT.size(); i++){
        //선택
        ratios[k] = RATIOS_OPT[i];
        //k+1번째로 가기
        select(k+1, users, emoticons);
        //선택 해제
        ratios[k] = 0;
    }     
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    //완전 탐색 가능한 범위이므로 완탐 ㄱㄱ
    ratios = vector<int>(emoticons.size(), 0);
    select(0, users, emoticons);
    return max_result;
}