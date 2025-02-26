#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void find_room(vector<vector<int>> &m, vector<vector<bool>> &visited, vector<pair<int,int>> &rooms, queue<pair<int,int>> &qu, pair<int,int> curr){
    //만약 이미 방문했다면, 큐에서 꺼내고 리턴
    if(visited[curr.first][curr.second]){
        if(!qu.empty()){
            pair<int, int> next = qu.front();
            qu.pop();
            find_room(m, visited, rooms, qu, next);
        }
        return;
    }

    //방문 처리
    visited[curr.first][curr.second] = true;
    rooms.push_back(curr);

    //인접한 노드 중 방문하지 않은 것을 큐에 넣기
    if(!(m[curr.first][curr.second] & 1) && !visited[curr.first][curr.second-1])
        qu.push(make_pair(curr.first, curr.second-1));
    if(!(m[curr.first][curr.second] & 2) && !visited[curr.first-1][curr.second])
        qu.push(make_pair(curr.first-1, curr.second));    
    if(!(m[curr.first][curr.second] & 4) && !visited[curr.first][curr.second+1])
        qu.push(make_pair(curr.first, curr.second+1));
    if(!(m[curr.first][curr.second] & 8) && !visited[curr.first+1][curr.second])
        qu.push(make_pair(curr.first+1, curr.second));

    //큐에서 꺼내서 이동
    if(!qu.empty()){
        pair<int, int> next = qu.front();
        qu.pop();
        find_room(m, visited, rooms, qu, next);
    }
}

int main(void){
    //입력받기
    int N, M;
    cin >> M >> N;
    vector<vector<int>> m = vector<vector<int>>(N, vector<int>(M, 0)); //성곽 정보
    vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(M, false)); // 방문 여부
    vector<pair<int,int>> rooms; //방 속 노드의 수
    queue<pair<int,int>> qu;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
        }
    }

    //bfs를 돌려서 방 찾아내기
    int room_cnt = 0;
    int max_size = 0; //rooms.size()의 반환값은 size_t(unsigned)이고, max_size는 int(signed)임 
                      // -> 만약 max_size = -1로 해서, -1과 size_t(unsgined)를 비교하면 -1은 signed로 cast되어 4294967295가 되어버림
                      // 따라서 0을 사용해야함함
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;
            rooms.clear();
            find_room(m, visited, rooms, qu, make_pair(i, j));
            if(rooms.size() > max_size) max_size = rooms.size();
            room_cnt++;
        }   
    }

    cout << room_cnt << "\n";
    cout << max_size << "\n";

    //벽 하나를 부순 뒤 bfs를 돌려서 방 찾아내기
    max_size = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){

                //테두리라면 리턴
                if(k == 0 && j == 0) continue;
                else if(k == 1 && i == 0) continue;
                else if(k == 2 && j == M-1) continue;
                else if(k == 3 && i == N-1) continue;

                //초기화
                for(int ii = 0; ii < N; ii++){
                    for(int jj = 0; jj < M; jj++){
                        visited[ii][jj] = false;
                    }
                }
                rooms.clear();
                while(!qu.empty()){
                    qu.pop();
                }

                //하나의 벽을 허문 뒤의 값으로 세팅 후 bfs 실행
                int mask = (~(1 << k)) & 15;
                int new_val = m[i][j] & mask;
                int prev_val = m[i][j];
                m[i][j] = new_val;
                find_room(m, visited, rooms, qu, make_pair(i, j));

                //나온 방의 크기가 max보다 크면 업데이트
                if(rooms.size() > max_size) max_size = rooms.size();
                m[i][j] = prev_val;
            }
        }
    }
    cout << max_size << "\n";
}