#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> xp = {-1, 0, 1, 0};
vector<int> yp = {0, 1, 0, -1};
int lighten_one(vector<vector<char>> &map, stack<pair<int,int>> &st, pair<int,int> pos, int direction){
    int push_cnt = 0;
    int dx = pos.first, dy = pos.second;
    while(true){
        //현 위치가 유효하지 않다면 그만
        if(dx < 0 || dx >= map.size() || dy < 0 || dy >= map[0].size()) 
            break;
        else if(map[dx][dy] == '6')
            break;        

        //유효하다면, 현 위치 밝히기
        if(map[dx][dy] == '0'){
            map[dx][dy] = '#';
            st.push(make_pair(dx, dy));
            push_cnt++;
        }
        dx += xp[direction];
        dy += yp[direction];
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
vector<vector<vector<int>>> POS_N = {
    {},
    {{0}, {1}, {2}, {3}}, 
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};
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
    int direction = map[cctvs[cctv].first][cctvs[cctv].second] - '0';
    for(int i = 0; i < POS_N[direction].size(); i++){
        int push_cnt = 0;
        for(int j = 0; j < POS_N[direction][i].size(); j++){
            push_cnt += lighten_one(map, st, cctvs[cctv], POS_N[direction][i][j]); 
        }
        simul_cctv(map, cctvs, st, cctv+1);
        unlighten_one(map, st, push_cnt);
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