#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> in_degree;
vector<bool> visited;
queue<int> qu;
void get_order(){
    //큐 안비었다면 하나 꺼내기
    if(qu.empty()) return;
    int curr = qu.front();
    qu.pop();
    cout << curr << " ";

    //현 노드의 outgoing 엣지 지우기
    //in-degree = 0이고 visited가 false인 노드 큐에 넣기
    //방문처리도 바로 해주기
    for(int i = 0; i < graph[curr].size(); i++){
        int next = graph[curr][i];
        in_degree[next]--;
        if(in_degree[next] == 0 && !visited[next]){
            qu.push(next);
            visited[next] = true;
        }
    }

    //재귀 호출
    get_order();
}

int main(void){

    //시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int N, M;
    cin >> N >> M;

    //그래프 연결
    graph = vector<vector<int>>(N+1, vector<int>());
    in_degree = vector<int>(N+1, 0);
    visited = vector<bool>(N+1, false);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    //in-degree가 0인 것들 큐에 넣기
    //bfs로 탐색 -> 그게 바로 
    for(int i = 1; i < N+1; i++){
        if(in_degree[i] == 0){
            qu.push(i);
            visited[i] = true;
        }
    }
    get_order();
    cout << "\n";
}