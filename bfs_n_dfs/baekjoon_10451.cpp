#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void get_cycle(vector<int> &graph, vector<bool> &visited, int c){
    //이미 방문했다면 리턴
    if(visited[c]) return;

    //방문 처리
    visited[c] = true;

    //연결된 노드로 진전
    get_cycle(graph, visited, graph[c]);
}

int main(void){
    //입력
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        vector<int> graph = vector<int>(N+1, 0);
        vector<bool> visited = vector<bool>(N+1, false);
        for(int j = 0; j < N; j++){
            cin >> graph[j+1];
        }

        //BFS로 순열 사이클 구하기
        int cycle_count = 0;
        for(int  j = 1; j < N+1; j++){
            if(visited[j]) continue;
            get_cycle(graph, visited, j);
            cycle_count++;
        }

        //출력
        cout << cycle_count << "\n";
    }
}