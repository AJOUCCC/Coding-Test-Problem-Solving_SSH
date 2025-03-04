#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void get_area( vector<vector<int>> &cabs, vector<vector<bool>> &visited, queue<pair<int,int>> &qu, pair<int,int> curr){
    //방문 이미 했다면 다음 것 꺼내고 리턴
    if(visited[curr.first][curr.second]){
        if(!qu.empty()){
            pair<int,int> next = qu.front();
            qu.pop();
            get_area(cabs, visited, qu, next);
        }
        return;
    }

    //방문 처리
    visited[curr.first][curr.second] = true;

    //노드의 상하좌우 중 아직 방문 안한 배추를 방문
    if(curr.first > 0 && !visited[curr.first-1][curr.second] && cabs[curr.first-1][curr.second] == 1)
        qu.push(make_pair(curr.first-1, curr.second));
    if(curr.first < cabs.size()-1 && !visited[curr.first+1][curr.second]  && cabs[curr.first+1][curr.second] == 1)
        qu.push(make_pair(curr.first+1, curr.second));
    if(curr.second > 0 && !visited[curr.first][curr.second-1]  && cabs[curr.first][curr.second-1] == 1)
        qu.push(make_pair(curr.first, curr.second-1));
    if(curr.second < cabs[0].size()-1 && !visited[curr.first][curr.second+1]  && cabs[curr.first][curr.second+1] == 1)
        qu.push(make_pair(curr.first, curr.second+1));

    //다음 것 꺼내기
    if(!qu.empty()){
        pair<int,int> next = qu.front();
        qu.pop();
        get_area(cabs, visited, qu, next);
    }
}

int main(void){
    //입력
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<int>> cabs = vector<vector<int>>(N, vector<int>(M, 0));
        vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(M, false));
        queue<pair<int,int>> qu;
       
        for(int j = 0; j < K; j++){ 
            int w, v;
            cin >> w >> v;
            cabs[v][w] = 1;
        }

        //BFS로 배추 영역들 탐색
        int warm_cnt = 0;
        for(int j = 0; j < N; j++){ 
            for(int k = 0; k < M; k++){
                if(visited[j][k] || cabs[j][k] == 0) continue;
                while(!qu.empty()) qu.pop();
                get_area(cabs, visited, qu, make_pair(j, k));
                warm_cnt++;
            }
        }

        //출력
        cout << warm_cnt << "\n";
    }
}