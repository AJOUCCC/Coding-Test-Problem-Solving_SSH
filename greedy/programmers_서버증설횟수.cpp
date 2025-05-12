#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    //players.size()만큼의 현 시간대의 서버 수 저장
    vector<int> server_cnt = vector<int>(players.size(), 1);
    int server_add_cnt = 0;
    
    //모든 시간대 순회
    for(int i = 0; i < players.size(); i++){
        //현 시간대 이용자 수 >= server_cnt_curr * m, 서버 증설
        while(players[i] >= server_cnt[i] * m){
            server_add_cnt++;
            for(int j = 0; j < k; j++){
                if(i+j == players.size()) break;
                server_cnt[i+j]++;
            }
        }
        //아니라면, 넘어감
    }

    return server_add_cnt;
}