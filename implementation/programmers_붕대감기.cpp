#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    //마지막 공격까지 매 초마다 확인
    int TOTAL_TIME = attacks[attacks.size()-1][0];
    int MAX_HEALTH = health;
    int next_attack_idx = 0;
    int bandage_curr_time = 0;
    bool DEAD = false;
    for(int i = 0; i <= TOTAL_TIME; i++){
        //만약 공격이 들어온다면 체력 차감    
        if(attacks[next_attack_idx][0] == i){
            health -= attacks[next_attack_idx][1];
            next_attack_idx++;
            bandage_curr_time = 0;
            
            //만약 체력이 0이하라면 -1 리턴
            if(health <= 0){
                DEAD = true;
                break;
            }
        }
        //아니라면 붕대 감기 시전
        else{
            health += bandage[1];
            if(health > MAX_HEALTH) health = MAX_HEALTH;
            bandage_curr_time++;
            if(bandage_curr_time == bandage[0]){
                health += bandage[2];
                if(health > MAX_HEALTH) health = MAX_HEALTH;
                bandage_curr_time = 0;
            } 
        }
    }
    
    if(DEAD) answer = -1;
    else answer = health;
    return answer;
}