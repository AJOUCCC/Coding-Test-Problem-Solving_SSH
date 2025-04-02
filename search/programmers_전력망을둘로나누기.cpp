#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int network_cnt = 0;
void get_network(vector<vector<int>> &graph, vector<bool> &visited, queue<int> &qu){
    //큐에서 하나 꺼내기
    if(qu.empty()) return;
    int newNode = qu.front();
    cout << "get_network: " << newNode << "\n"; 
    qu.pop();
    network_cnt++;
    
    //노드와 연결된 것 중 방문 안한 노드 큐에 넣고, 방문 처리
    for(int i = 0; i < graph[newNode].size(); i++){
        if(!visited[graph[newNode][i]]){
            qu.push(graph[newNode][i]);
            visited[graph[newNode][i]] = true;
        }
    }
    
    //재귀 호출
    get_network(graph, visited, qu);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    //그래프 정의
    vector<vector<int>> graph = vector<vector<int>>(n+1, vector<int>());
    vector<bool> visited;
    queue<int> qu;
    for(int i = 0; i < wires.size(); i++){
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    
    //하나 끊고 두 전력망의 크기 계산
    vector<int> min_network_size;
    for(int i = 0; i < wires.size(); i++){
        
        cout << "cut: " << wires[i][0] << ", " << wires[i][1] << "\n";
        graph[wires[i][0]].erase(find(graph[wires[i][0]].begin(), graph[wires[i][0]].end(), wires[i][1]));
        graph[wires[i][1]].erase(find(graph[wires[i][1]].begin(), graph[wires[i][1]].end(), wires[i][0]));
        
        visited = vector<bool>(n+1, false);  
        
        vector<int> network_size;
        for(int j = 1; j < graph.size(); j++){
            if(visited[j]) continue;
            while(!qu.empty()) qu.pop();   
            network_cnt = 0;
            qu.push(j);
            visited[j] = true;
            get_network(graph, visited, qu);
            network_size.push_back(network_cnt);
        }
        cout << "network size: " << network_size[0] << ", " << network_size[1] << "\n";
        
        if(min_network_size.empty() || abs(min_network_size[0] - min_network_size[1]) > abs(network_size[0] - network_size[1])) min_network_size = network_size;
        
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    answer = abs(min_network_size[0] - min_network_size[1]);
    return answer;
}