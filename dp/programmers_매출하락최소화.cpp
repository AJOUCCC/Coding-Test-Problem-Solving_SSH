#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> minPerson;
vector<int> minValue;
vector<int> prime;
vector<bool> isLeader;
vector<int> parent;
queue<int> qu;

void search(vector<int> &sales, vector<vector<int>> &graph){    
    //가장 cost 작은 팀원을 선정: prime[9] = 7
    if(qu.empty()) return;
    int curr = qu.front();
    qu.pop();
    prime[curr] = minPerson[curr];
    
    //그룹의 팀원들 순회
    for(int i = 0; i < graph[curr].size(); i++){
        //팀원이 팀장이면, 재귀적으로 다시 호출
        if(isLeader[graph[curr][i]]){
            qu.push(graph[curr][i]);
            search(sales, graph);
        } 
    }
        
    //min(prime[9] + prime[parent], curr)을 최종 선정
    //이는 1번 노드이면 안함
    if(curr != 1){
        if(!isLeader[prime[curr]]){
            if(sales[curr-1] < sales[prime[curr]-1] + sales[prime[parent[curr]]-1]){
                prime[curr] = curr;
                prime[parent[curr]] = curr;
            }
        }
    }
    cout << curr << ", " << prime[curr] << "\n";
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    
    //인접 그래프로 만들기
    vector<vector<int>> graph = vector<vector<int>>(sales.size()+1);
    minPerson = vector<int>(sales.size()+1, -1);
    minValue = vector<int>(sales.size()+1, 100000);
    prime = vector<int>(sales.size()+1, -1);
    isLeader = vector<bool>(sales.size()+1, false);
    parent = vector<int>(sales.size()+1, -1);
    for(int i = 0; i < links.size(); i++){
        graph[links[i][0]].push_back(links[i][1]);
        parent[links[i][1]] = links[i][0];
    }
    
    //각 그룹의 min인 직원 정보
    for(int i = 0; i < graph.size(); i++){
        if(graph[i].empty()) continue;
        minValue[i] = sales[i-1];
        minPerson[i] = i;
        isLeader[i] = true;
        for(int j = 0; j < graph[i].size(); j++){
            if(sales[graph[i][j]-1] < minValue[i]){
                minValue[i] = sales[graph[i][j]-1];
                minPerson[i] = graph[i][j];
            }
        }
    }
    
    for(int i = 0; i < isLeader.size(); i++){
    }
    
    //BFS로 1부터 탐색
    qu.push(1);
    search(sales, graph);
    
    //prime들 다 더하기
    unordered_set<int> primes;
    for(int i = 1; i < prime.size(); i++){
        if(prime[i] != -1){
            primes.insert(prime[i]);
        }
    }
    cout << "------------------\n";
    for(auto i = primes.begin(); i != primes.end(); i++){
        cout << *i << ", " << sales[*i-1] << "\n";
        answer += sales[*i-1];
    }
    
    return answer;
}