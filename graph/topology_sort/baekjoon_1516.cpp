#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> in_degree;
vector<int> time;
vector<int> prev_time;
vector<int> total_time;
queue<int> qu;

void build(){
    //큐 안비었다면 노드 꺼내기
    if(qu.empty()) return;
    int curr = qu.front();
    qu.pop();

    //현 노드의 최종 시간 값 출력
    total_time[curr] = prev_time[curr] + time[curr];

    //현 노드와 연결된 다음 노드들의 in-degree--, value update
    //노드가 in-degree = 0이고 !visited면 큐에 넣고 방문 처리
    for(int i = 0; i < graph[curr].size(); i++){
        int next = graph[curr][i];
        in_degree[next]--;
        prev_time[next] = max(prev_time[next], prev_time[curr] + time[curr]);
        if(in_degree[next] == 0 && !visited[next]){
            qu.push(next);
            visited[next] = true;
        }
    }

    //재귀 호출
    build();

}

int main(void){
    //입력
    int N;
    cin >> N;
    graph = vector<vector<int>>(N+1, vector<int>());
    visited = vector<bool>(N+1, false);
    in_degree = vector<int>(N+1, 0);
    time = vector<int>(N+1, 0);
    prev_time = vector<int>(N+1, 0);
    total_time = vector<int>(N+1, 0);
    for(int i = 0; i < N; i++){
        int t, a;
        cin >> t >> a;
        time[i+1] = t;
        while(a != -1){
            //in-degree 세팅 및 초기화
            graph[a].push_back(i+1);
            in_degree[i+1]++;
            cin >> a;
        }
    }  
    
    //bfs 수행
    for(int i = 1; i < N+1; i++){
        if(in_degree[i] == 0){
            qu.push(i);
        }
    }
    build();

    //출력
    for(int i = 1; i < N+1; i++)
        cout << total_time[i] << "\n";
}