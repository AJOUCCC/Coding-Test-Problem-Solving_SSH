#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void get_connected(vector<vector<int>> &graph, vector<bool> &visited, queue<int> &qu, vector<int> &connected, int c){
    //방문했다면 큐에서 하나 빼서 방문 후 리턴
    if(visited[c]){
        if(!qu.empty()){
            int next = qu.front();
            qu.pop();
            get_connected(graph, visited, qu, connected, next);
        }
        return;
    }

    //방문 처리
    visited[c] = true;
    connected.push_back(c);

    //연결된 요소들 중 방문하지 않은 것을 큐에 넣기
    for(int i = 0; i < graph[c].size(); i++){
        if(!visited[graph[c][i]]) qu.push(graph[c][i]);
    }

    //큐에서 하나 빼서 방문
    if(!qu.empty()){
        int next = qu.front();
        qu.pop();
        get_connected(graph, visited, qu, connected, next);
    }
}

int main(void){
    //입력
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph = vector<vector<int>>(N+1, vector<int>());
    vector<bool> visited = vector<bool>(N+1, false);
    queue<int> qu;
    vector<int> connected;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //BFS로 연결 요소 구하기
    int count = 0;
    for(int i = 1; i < N+1; i++){
        if(visited[i]) continue;
        connected.clear();
        get_connected(graph, visited, qu, connected, i);
        count++;
    }

    //출력
    cout << count << "\n";
}