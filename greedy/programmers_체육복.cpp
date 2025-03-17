#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //lost, reserve 배열 다시 정의
    vector<bool> lost_n = vector<bool>(n+1, false);
    vector<bool> reserve_n = vector<bool>(n+1, false);
    for(int i = 0; i < lost.size(); i++)
        lost_n[lost[i]] =true;
    for(int i = 0; i < reserve.size(); i++)
        reserve_n[reserve[i]] =true;
    
    //n명의 학생 순회돌며 그리디하게 판단
    int valid_cnt = 0;
    for(int i = 1 ; i < n+1; i++){
        if(lost_n[i] && !reserve_n[i]){
            //양 옆 중 왼쪽을 우선순위로 빌릭
            if(i-1 > 0 && !lost_n[i-1] && reserve_n[i-1]){
                reserve_n[i-1] = false;
                valid_cnt++;
            }
            else if(i+1 < n+1 && !lost_n[i+1] && reserve_n[i+1]){
                reserve_n[i+1] = false;
                valid_cnt++;
            }
        }
        else{
            valid_cnt++;
        }
    }
    answer = valid_cnt;
    return answer;
}