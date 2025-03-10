#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;    
    
    //BFS로 풀기 위한 준비
    int INF = 10000000;
    vector<vector<bool>> visited = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));
    vector<vector<int>> distance = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), INF));
    queue<pair<int,int>> qu;
    
    //BFS로 모든 노드 방문
    distance[0][0] = 1;
    visited[0][0] = true;
    qu.push(make_pair(0,0));
    while(!qu.empty()){
        
        //다음 노드 꺼내기
        pair<int,int> curr = qu.front();
        qu.pop();
        
         //상하좌우 중 방문 안한 노드 큐에 삽입
        if(curr.first > 0 && !visited[curr.first-1][curr.second] && maps[curr.first-1][curr.second] == 1) {
            qu.push(make_pair(curr.first-1, curr.second));
            distance[curr.first-1][curr.second] = distance[curr.first][curr.second]  + 1;
            visited[curr.first-1][curr.second] = true;
        }
        if(curr.first < maps.size()-1 && !visited[curr.first+1][curr.second] && maps[curr.first+1][curr.second] == 1) {
            qu.push(make_pair(curr.first+1, curr.second));
            distance[curr.first+1][curr.second] = distance[curr.first][curr.second]  + 1;
            visited[curr.first+1][curr.second] = true;
        }
        if(curr.second > 0 && !visited[curr.first][curr.second-1] && maps[curr.first][curr.second-1] == 1) {
            qu.push(make_pair(curr.first, curr.second-1));
            distance[curr.first][curr.second-1] = distance[curr.first][curr.second]  + 1;
            visited[curr.first][curr.second-1] = true;
        }
        if(curr.second < maps[0].size()-1 && !visited[curr.first][curr.second+1] && maps[curr.first][curr.second+1] == 1) {
            qu.push(make_pair(curr.first, curr.second+1));
            distance[curr.first][curr.second+1] = distance[curr.first][curr.second]  + 1;
            visited[curr.first][curr.second+1] = true;
        }
    }
    
    //결과 출력
    if(distance[maps.size()-1][maps[0].size()-1] == INF)
        answer = -1;
    else 
        answer = distance[maps.size()-1][maps[0].size()-1];
    return answer;
}