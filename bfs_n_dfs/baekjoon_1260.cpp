#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare{
    bool operator()(int p1, int p2){
        return p1 > p2;
    }
};

/**
 * vector를 인자로 넘길 때, call-by-reference로 넘기려면 &를 사용해야 한다!
 */
void dfs(vector<priority_queue<int, vector<int>, compare>> &graph, vector<bool> &visited, int V){
    //V가 이미 방문되었다면 return
    if(visited[V]) return;

    //V를 방문 처리
    visited[V] = true;
    cout << V << " ";

    //간선들 중에서 방문하지 않은 것들 중, 가장 번호가 빠른 것부터 방문
    while(!graph[V].empty()){
        int toVisit = graph[V].top();
        if(!visited[toVisit]){
            dfs(graph, visited, toVisit);
        }
        graph[V].pop();
    }
}

void bfs(vector<priority_queue<int, vector<int>, compare>> &graph, vector<bool> &visited, queue<int> &qu, int V){
    //V가 이미 방문되었다면 return
    if(visited[V]) {
        if(!qu.empty()){
            int toVisit = qu.front();
            qu.pop();
            bfs(graph, visited, qu, toVisit);
        }
        return;
    }

    //V를 방문 처리
    visited[V] = true;
    cout << V << " ";

    //간선들 중에서 방문하지 않은 것들 중, 가장 번호가 빠른 것부터 queue에 넣음
    while(!graph[V].empty()){
        int toVisit = graph[V].top();
        if(!visited[toVisit]) {
            qu.push(toVisit);
        }
        graph[V].pop();
    }

    //queue에서 다음 것을 꺼내어 방문
    if(!qu.empty()){
        int toVisit = qu.front();
        qu.pop();
        bfs(graph, visited, qu, toVisit);
    }
}

int main(void){
    //그래프 입력
    int N, M, V;
    cin >> N >> M >> V;
    vector<priority_queue<int, vector<int>, compare>> graph1 = vector<priority_queue<int, vector<int>, compare>>(N+1, priority_queue<int, vector<int>, compare>(0, 0));
    vector<bool> visited1 = vector<bool>(N+1, false);
    for(int i = 0; i < M; i++){
        int p1, p2;
        cin >> p1 >> p2;
        graph1[p1].push(p2);
        graph1[p2].push(p1);
    }
    vector<priority_queue<int, vector<int>, compare>> graph2 = vector<priority_queue<int, vector<int>, compare>>(graph1);
    vector<bool> visited2 = vector<bool>(visited1);
    queue<int> qu;

    //DFS 수행
    dfs(graph1, visited1, V);
    cout << "\n";

    //BFS 수행
    bfs(graph2, visited2, qu, V);
    cout << "\n";
}