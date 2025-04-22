#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int RED = 0, BLACK = 1;
int isValid = true;
void get_connected(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color, queue<int> &qu){
    //큐에서 하나 꺼내기
    if(qu.empty()) return;
    int next = qu.front();
    qu.pop();
    int curr_color = color[next];

    //노드와 연결되고 아직 방문 안한 노드 큐에 넣고 방문 처리
    for(int i = 0; i < graph[next].size(); i++){
        //이분 그래프 여부 확인
        if(color[graph[next][i]] == curr_color){
            isValid = false;     
            return;
        }
        if(!visited[graph[next][i]]) {
            qu.push(graph[next][i]);
            visited[graph[next][i]] = true;
            if(curr_color == RED) color[graph[next][i]] = BLACK;
            else color[graph[next][i]] = RED;
        }
    }

    //재귀 호출
    get_connected(graph, visited, color, qu);
}

int main(void){
    //테스트케이스 순회
    int K;
    cin >> K;

    for(int k = 0; k < K; k++){
    //입력 및 그래프 정의
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph = vector<vector<int>>(V+1, vector<int>());
    vector<bool> visited = vector<bool>(V+1, false);
    vector<int> color = vector<int>(V+1, -1);
    queue<int> qu;
    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    //BFS로 그래프 탐색 반복
    isValid = true;
    for(int i = 1; i < V+1; i++){
        if(!isValid) break;
        else if(visited[i]) continue;

        while(!qu.empty()) qu.pop();
        qu.push(i);
        visited = vector<bool>(V+1, false);
        color = vector<int>(V+1, -1);
        color[i] = RED;
        
        get_connected(graph, visited, color, qu);
    }
    

    //그래프의 수에 따라 결과 출력
    if(isValid) cout << "YES\n";
    else cout << "NO\n";
    }

}