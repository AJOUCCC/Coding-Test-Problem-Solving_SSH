#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int minOperation = -1;
void bfs(vector<bool> &visited, queue<pair<int,int>> &qu, int &y, int &n){
    //큐가 비어있지 않다면 꺼내기
    if(qu.empty()) return;
    pair<int,int> x = qu.front();
    qu.pop();
    //cout << "x: " << x.first << ", " << x.second << "\n";

    //만약 값 찾았다면 업데이트
    if(x.first == y){
        minOperation = x.second;
        return;
    }
    //다음 노드들 큐에 넣기
    else{ 
        if(x.first * 2 <= y && !visited[x.first * 2]){
            qu.push(make_pair(x.first*2, x.second+1));
            visited[x.first * 2] = true;
        } 
        if(x.first * 3 <= y && !visited[x.first * 3]){
            qu.push(make_pair(x.first*3, x.second+1));
            visited[x.first * 3] = true;
        } 
            
        
        if(x.first + n <= y && !visited[x.first + n]){
            qu.push(make_pair(x.first+n, x.second+1));
            visited[x.first + n] = true;
        }
    }
    
    //함수 재귀적으로 호출
    bfs(visited, qu, y, n);
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    //BFS
    queue<pair<int,int>> qu;
    vector<bool> visited = vector<bool>(1000001, false);
    qu.push(make_pair(x, 0));
    bfs(visited, qu, y, n);
    
    //결과 출력
    answer = minOperation;
    return answer;
}