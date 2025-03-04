#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void search_parents(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &parent, queue<int> &qu, int curr){
    //이미 방문 시 큐에서 꺼내고 리턴
    if(visited[curr]){
        if(!qu.empty()){
            int next = qu.front();
            qu.pop();
            search_parents(graph, visited, parent, qu, next);
        }
        return;
    }

    //방문 처리
    visited[curr] = true;

    //방문 안한 자식들 큐에 넣기, 부모 정보 저장
    for(int i = 0; i < graph[curr].size(); i++){
        if(!visited[graph[curr][i]]){
            qu.push(graph[curr][i]);
            parent[graph[curr][i]] = curr;
        }
    }

    //큐에서 하나 꺼내서 방문
    if(!qu.empty()){
        int next = qu.front();
        qu.pop();
        search_parents(graph, visited, parent, qu, next);
    }

}

int main(void){
    //입력
    int N;
    cin >> N;
    vector<vector<int>> graph = vector<vector<int>>(N+1, vector<int>());
    vector<bool> visited = vector<bool>(N+1, false);
    vector<int> parent = vector<int>(N+1, 0);
    queue<int> qu;
    for(int i = 1; i < N; i++){
        int w, v;
        cin >> w >> v;
        graph[w].push_back(v);
        graph[v].push_back(w);
    }

    //BFS로 탐색
    search_parents(graph, visited, parent, qu, 1);

    //출력
    for(int i = 2; i < N+1; i++){
        cout << parent[i] << "\n";
    }
}