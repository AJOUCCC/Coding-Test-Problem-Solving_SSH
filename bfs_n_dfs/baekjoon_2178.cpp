#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void find_miro(vector<vector<int>> &miro, vector<vector<bool>> &visited, vector<vector<int>> &dist, queue<pair<int,int>> &qu, pair<int, int> curr){
    //목적지 도달 시 리턴
    if(curr.first == miro.size()-1 && curr.second == miro[curr.first].size()-1){
        visited[curr.first][curr.second] = true;
        return;
    }
    
    //방문했다면 큐를 보고 리턴

    if(visited[curr.first][curr.second]){
        if(!qu.empty()){
            pair<int,int> next = qu.front();
            qu.pop();
            find_miro(miro, visited, dist, qu, next);
        }
        return;
    }

    //방문 처리
    visited[curr.first][curr.second] = true;

    //상하좌우 중 아직 방문 안한 노드를 큐에 넣기
    if(curr.first+1 < miro.size() && miro[curr.first+1][curr.second] == 1 && !visited[curr.first+1][curr.second]){
        qu.push(make_pair(curr.first+1, curr.second));
        dist[curr.first+1][curr.second] = dist[curr.first][curr.second]+1;
    }
    if(curr.second+1 < miro[curr.first].size() && miro[curr.first][curr.second+1] == 1 && !visited[curr.first][curr.second+1]){
        qu.push(make_pair(curr.first, curr.second+1));   
        dist[curr.first][curr.second+1] = dist[curr.first][curr.second]+1;
    }
    if(curr.first-1 >= 0 && miro[curr.first-1][curr.second] == 1 && !visited[curr.first-1][curr.second]){
        qu.push(make_pair(curr.first-1, curr.second));
        dist[curr.first-1][curr.second] = dist[curr.first][curr.second]+1;
    }
    if(curr.second-1 >= 0 && miro.size() && miro[curr.first][curr.second-1] == 1 && !visited[curr.first][curr.second-1]){
        qu.push(make_pair(curr.first, curr.second-1));
        dist[curr.first][curr.second-1] = dist[curr.first][curr.second]+1;
    }

    //큐에서 하나 빼서 방문
    if(!qu.empty()){
        pair<int,int> next = qu.front();
        qu.pop();
        find_miro(miro, visited, dist, qu, next);
    }
}

int main(void){
    //입력받기
    int N, M;
    cin >> N >> M;
    vector<vector<int>> miro = vector<vector<int>>(N, vector<int>(M, 0)); //미로의 값 저장
    vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(M, false)); //한 노드가 방문된 여부
    vector<vector<int>> dist = vector<vector<int>>(N, vector<int>(M, 0)); //한 노드의 방문 이전 노드
    queue<pair<int,int>> qu;
    for(int i = 0; i < N; i++){
        string row;
        cin >> row;
        for(int j = 0; j < M; j++){
            miro[i][j] = row[j] - '0';
        }
    }

    //미로 찾기 실행
    dist[0][0] = 1;
    find_miro(miro, visited, dist, qu, make_pair(0, 0));

    //결과 출력
    cout << dist[N-1][M-1];
    
}