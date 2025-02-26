#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void get_wormed(vector<vector<int>> &graph, vector<bool> &visited, queue<int> &qu, queue<int> &connected, int c){
    //이미 방문했다면 큐의 다음 것 꺼내고 리턴
    if(visited[c]){
        if(!qu.empty()){
            int next = qu.front();
            qu.pop();
            get_wormed(graph, visited, qu, connected, next);
        }
        return;
    }

    //방문 처리
    visited[c] = true;
    connected.push(c);

    //연결된 노드 중 방문하지 않은 노드를 큐에 넣기
    for(int i = 0; i < graph[c].size(); i++){
        if(!visited[graph[c][i]]) qu.push(graph[c][i]);
    }

    //큐에서 하나 꺼내기
    if(!qu.empty()){
        int next = qu.front();
        qu.pop();
        get_wormed(graph, visited, qu, connected, next);
    }
}

int main(void){
    //입력
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph = vector<vector<int>>(N+1, vector<int>());
    vector<bool> visited = vector<bool>(N+1, false);
    queue<int> qu;
    queue<int> connected;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //BFS로 1번과 연결된 컴퓨터 찾기
    get_wormed(graph, visited, qu, connected, 1);

    //출력
    cout << connected.size()-1 << "\n";
}