#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void get_island(vector<vector<int>> &matrix,  vector<vector<bool>> &visited, queue<pair<int,int>> &qu, pair<int,int> curr){
    //방문했다면 다음 것 꺼내서 방문 후 리턴
    if(visited[curr.first][curr.second]){
        if(!qu.empty()){
            pair<int,int> next = qu.front();
            qu.pop();
            get_island(matrix, visited, qu, next);
        }
        return;
    }

    //방문 처리
    visited[curr.first][curr.second] = true;

    //주변에서 방문 안한 점을 큐에 넣기
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(curr.first + i >= 0 && curr.first + i < matrix.size() && curr.second + j >= 0 && curr.second + j < matrix[curr.first].size())
                if(!visited[curr.first + i][curr.second + j] && matrix[curr.first + i][curr.second + j] == 1)
                    qu.push(make_pair(curr.first + i, curr.second + j));
        }
    }

    //큐에서 하나 꺼내서 방문
    if(!qu.empty()){
        pair<int,int> next = qu.front();
        qu.pop();
        get_island(matrix, visited, qu, next);
    }
}

int main(void){
    int w, h;
    do{
        //입력
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        vector<vector<int>> matrix = vector<vector<int>>(h, vector<int>(w, 0));
        vector<vector<bool>> visited = vector<vector<bool>>(h, vector<bool>(w, false));
        queue<pair<int,int>> qu;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> matrix[i][j];
            }
        }

        //BFS로 섬 개수 세기
        int island_cnt = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(visited[i][j] || matrix[i][j] == 0) continue;
                get_island(matrix, visited, qu, make_pair(i, j));
                island_cnt++;
            }
        }

        //출력
        cout << island_cnt << "\n";

    } while(true);
 
}