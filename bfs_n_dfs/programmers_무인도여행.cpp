#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int day = 0;
void get_island(vector<string> &maps, vector<vector<bool>> &visited, queue<pair<int,int>> &qu){
    
    //노드 하나 꺼내기, 없다면 종료
    if(qu.empty()) return;
    pair<int,int> curr = qu.front();
    qu.pop();
    cout << "i: " << curr.first << " j: " << curr.second << "\n";
    
    //노드의 상하좌우 중 아직 방문하지 않은 노드 큐에 추가 및 방문처리
    if(curr.first > 0 && !visited[curr.first-1][curr.second] && maps[curr.first-1][curr.second] != 'X'){
        qu.push(make_pair(curr.first-1, curr.second));
        visited[curr.first-1][curr.second] = true;
        day += maps[curr.first-1][curr.second] - '0';
    }
    if(curr.first < maps.size()-1 && !visited[curr.first+1][curr.second] && maps[curr.first+1][curr.second] != 'X'){
        qu.push(make_pair(curr.first+1, curr.second));
        visited[curr.first+1][curr.second] = true;
        day += maps[curr.first+1][curr.second] - '0';
    }
    if(curr.second > 0 && !visited[curr.first][curr.second-1] && maps[curr.first][curr.second-1] != 'X'){
        qu.push(make_pair(curr.first, curr.second-1));
        visited[curr.first][curr.second-1] = true;
        day += maps[curr.first][curr.second-1] - '0';
    }
    if(curr.second < maps[0].size()-1 && !visited[curr.first][curr.second+1] && maps[curr.first][curr.second+1] != 'X'){
        qu.push(make_pair(curr.first, curr.second+1));
        visited[curr.first][curr.second+1] = true;
        day += maps[curr.first][curr.second+1] - '0';
    }
    
    //계속 호출
    get_island(maps, visited, qu);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));
    queue<pair<int,int>> qu;
    vector<int> days;
    
    //다음 무인도를 탐색
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(visited[i][j] || maps[i][j] == 'X') continue;
            day = maps[i][j] - '0';
            qu.push(make_pair(i, j));
            visited[i][j] = true;
            get_island(maps, visited, qu);
            days.push_back(day);
        }
    }
    
    sort(days.begin(), days.end());
    if(days.empty()) answer.push_back(-1);
    else answer = days;
    return answer;
}