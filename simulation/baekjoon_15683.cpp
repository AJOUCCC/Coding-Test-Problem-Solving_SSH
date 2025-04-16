#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int lighten_one(vector<vector<char>> &map, stack<pair<int,int>> &st, pair<int,int> pos, int direction){
    int push_cnt = 0;
    switch(direction){
        case 0: //위
            for(int i = pos.first; i >= 0; i--){
                if(map[i][pos.second] == '0'){
                    map[i][pos.second] = '#';
                    st.push(make_pair(i, pos.second));
                    push_cnt++;
                }
                else if(map[i][pos.second] == '6')
                    break;
            }
            break;
        case 1: //오른쪽 
            for(int i = pos.second; i < map[0].size(); i++){
                if(map[pos.first][i] == '0'){
                    map[pos.first][i] = '#';
                    st.push(make_pair(pos.first, i));
                    push_cnt++;
                }
                else if(map[pos.first][i] == '6')
                    break;
            }
            break;
        case 2:  //아래 
            for(int i = pos.first; i < map.size(); i++){
                if(map[i][pos.second] == '0'){
                    map[i][pos.second] = '#';
                    st.push(make_pair(i, pos.second));
                    push_cnt++;
                }
                else if(map[i][pos.second] == '6')
                    break;
            }
            break;
        case 3: //왼쪽 
            for(int i = pos.second; i >= 0; i--){
                if(map[pos.first][i] == '0'){
                    map[pos.first][i] = '#';
                    st.push(make_pair(pos.first, i));
                    push_cnt++;
                }
                else if(map[pos.first][i] == '6')
                    break;
            }
            break;
        default: break;
    }  
    return push_cnt;
}

void unlighten_one(vector<vector<char>> &map, stack<pair<int,int>> &st, int push_cnt){
    while(push_cnt != 0){
        pair<int,int> poped = st.top();
        map[poped.first][poped.second] = '0';
        st.pop();
        push_cnt--;
    }
}

int min_cnt = 0;
void simul_cctv(vector<vector<char>> &map, vector<pair<int,int>> &cctvs, stack<pair<int,int>> &st, int cctv){
    //cctv == CCTV_SIZE라면 현 지도에서 0을 세서 최솟값이면 업데이트 후 리턴
    if(cctv == cctvs.size()){
        int zero_cnt = 0;
        for(int i = 0; i < map.size(); i++)
            for(int j = 0; j < map[0].size(); j++)
                if(map[i][j] == '0') zero_cnt++;  
        if(zero_cnt < min_cnt) min_cnt = zero_cnt;
        //cout << zero_cnt << "\n";
        return;
    }

    //아니라면 cctv번째의 cctv의 방향을 세부 설정(for문)
    switch(map[cctvs[cctv].first][cctvs[cctv].second]){
        case '1':
            //방향을 선택
            //방향 선택에 따른 map 수정 및 큐에 수정된 좌표 넣기
            //재귀 호출
            //큐에서 수정된 좌표 꺼내고, map 원상복귀
            {
                for(int i = 0; i < 4; i++){
                    int push_cnt = lighten_one(map, st, cctvs[cctv], i);
                    simul_cctv(map, cctvs, st, cctv+1);
                    unlighten_one(map, st, push_cnt);
                }
            }
            break;
        case '2':
            {
                for(int i = 0; i < 2; i++){
                    int push_cnt = lighten_one(map, st, cctvs[cctv], i);
                    push_cnt += lighten_one(map, st, cctvs[cctv], i+2);
                    simul_cctv(map, cctvs, st, cctv+1);
                    unlighten_one(map, st, push_cnt);
                }
            }
            break;
        case '3':
            {
                for(int i = 0; i < 4; i++){
                    int push_cnt = lighten_one(map, st, cctvs[cctv], i);
                    push_cnt += lighten_one(map, st, cctvs[cctv], (i+1) % 4);
                    simul_cctv(map, cctvs, st, cctv+1);
                    unlighten_one(map, st, push_cnt);
                }
            }
            break;
        case '4':
            {
                for(int i = 0; i < 4; i++){
                    int push_cnt = lighten_one(map, st, cctvs[cctv], i);
                    push_cnt += lighten_one(map, st, cctvs[cctv], (i+1) % 4);
                    push_cnt += lighten_one(map, st, cctvs[cctv], (i+2) % 4);
                    simul_cctv(map, cctvs, st, cctv+1);
                    unlighten_one(map, st, push_cnt);
                }
            }
            break;
        case '5':
            {
                int push_cnt = lighten_one(map, st, cctvs[cctv], 0);
                push_cnt += lighten_one(map, st, cctvs[cctv], 1);
                push_cnt += lighten_one(map, st, cctvs[cctv], 2);
                push_cnt += lighten_one(map, st, cctvs[cctv], 3);
                simul_cctv(map, cctvs, st, cctv+1);
                unlighten_one(map, st, push_cnt);
            }
            break;
        default: break;
    }        
}

int main(void){
    //입력
    int N, M;
    cin >> N >> M;
    vector<vector<char>> map = vector<vector<char>>(N, vector<char>(M, '0'));
    vector<pair<int,int>> cctvs;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] >= '1' && map[i][j] <= '5')
                cctvs.push_back(make_pair(i, j));  
        }
    }

    //완전탐색하는 함수 선언
    stack<pair<int,int>> st;
    min_cnt = M * N;
    simul_cctv(map, cctvs, st, 0);

    //최솟값 출력
    cout << min_cnt << "\n";
}