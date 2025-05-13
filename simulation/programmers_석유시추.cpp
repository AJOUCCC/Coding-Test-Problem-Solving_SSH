#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> orders; //현 위치의 석유 덩어리 번호
vector<int> sizes; //석유 덩어리 번호에 따른 크기
queue<pair<int,int>> qu;
int qauntity = 0;
int k = 0;
vector<vector<int>> NEIGHBOR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void get_land(vector<vector<int>> &land){
    //큐에서 하나 꺼내기
    if(qu.empty()) return;
    pair<int,int> curr = qu.front();
    qu.pop();
    qauntity++;
    orders[curr.first][curr.second] = k;
    //cout << "get_land: " << curr.first << ", " << curr.second << "\n";
    
    //위치의 주변에서 석유이고 && 방문 안한 것을 큐에 넣고, 방문 처리
    for(int i  = 0; i < NEIGHBOR.size(); i++){
        int x = curr.first + NEIGHBOR[i][0];
        int y = curr.second + NEIGHBOR[i][1];
        if(x >= 0 && x < land.size() && y >= 0 && y < land[0].size()){
            if(land[x][y] == 1 && !visited[x][y]){
                qu.push(make_pair(x, y));
                visited[x][y] = true;
            }
        }
    }
    
    //재귀 호출
    get_land(land);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    //bfs로 탐색해서 풀기    
    visited = vector<vector<bool>>(land.size(), vector<bool>(land[0].size(), false));
    orders = vector<vector<int>>(land.size(), vector<int>(land[0].size(), -1));
    
    //전체 탐색하며 모든 덩어리 추출
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < land[0].size(); j++){
            qauntity = 0;
            //visited라면 continue
            if(visited[i][j]) continue;
            //석유이면 get_land() 시작
            if(land[i][j] == 1){
                qu.push(make_pair(i, j));
                visited[i][j] = true;
                get_land(land);
                
                //새 덩어리를 저장
                sizes.push_back(qauntity);
                k++; 
                //cout << "new size: " << sizes[k-1] << "\n";
            }  
        }
    }
    
    //열별로 탐색하며 시추관 넣기
    int max_q = 0;
    for(int j = 0; j < land[0].size(); j++){
        unordered_set<int> targets;
        int q = 0;
        for(int i = 0; i < land.size(); i++){
            if(orders[i][j] != -1){
                targets.insert(orders[i][j]);
            }
        }
        for(int target : targets){
            q += sizes[target];
        }
        if(q > max_q) max_q = q;
    }
  
    return max_q;
}