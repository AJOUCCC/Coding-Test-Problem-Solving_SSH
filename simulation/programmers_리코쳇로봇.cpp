#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> dist;
vector<vector<int>> TYPE = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void go(vector<string> &board, vector<vector<bool>> &visited, queue<pair<int,int>> &qu, pair<int,int> &end){
    //하나 꺼내기
    if(qu.empty()) return;
    pair<int,int> curr = qu.front();
    qu.pop();
    if(curr.first == end.first && curr.second == end.second) return;
    cout << curr.first << ", " << curr.second << "\n";
    
    //주변 갈수 있는 곳 중 방문 안한 곳 큐에 넣고 방문 처리
    for(int i = 0; i < TYPE.size(); i++){
        int dx = curr.first, dy = curr.second;
        while(true){
            if(dx + TYPE[i][0] < 0 || dx + TYPE[i][0] > board.size()-1 || dy + TYPE[i][1] < 0 || dy + TYPE[i][1] > board[0].size()-1 || board[dx + TYPE[i][0]][dy + TYPE[i][1]] == 'D') break;
            dx += TYPE[i][0];
            dy += TYPE[i][1];
        }
        //cout << "i : " << i << " dx, dy: " << dx << ", " << dy << "\n";
        if(!visited[dx][dy]){
            qu.push(make_pair(dx, dy));
            visited[dx][dy] = true;
            dist[dx][dy] = dist[curr.first][curr.second] + 1;
        } 
    }
    
    //재귀 호출
    go(board, visited, qu, end);
}

int solution(vector<string> board) {
    int answer = 0;
    
    //bfs 탐색 위한 준비
    vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
    dist = vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
    queue<pair<int,int>> qu;
    pair<int,int> start, end;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'R') start = make_pair(i, j);
            else if(board[i][j] == 'G') end = make_pair(i, j);
        }
    }
    //cout << start.first << " " << end.first << "\n";
    
    //bfs 수행하기
    qu.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    go(board, visited, qu, end);
    
    //최솟값 리턴
    return dist[end.first][end.second];
}