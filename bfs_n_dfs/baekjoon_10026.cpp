#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void get_space(vector<vector<char>> &matrix, vector<vector<bool>> &visited, queue<pair<int,int>> &qu, pair<int,int> curr, bool isBlind){
    //이미 방문했다면 다음 곳을 방문하고 리턴
    if(visited[curr.first][curr.second]){
        if(!qu.empty()){
            pair<int,int> next = qu.front();
            qu.pop();
            get_space(matrix, visited, qu, next, isBlind);
        }
        return;
    }

    //방문 처리
    visited[curr.first][curr.second] = true;

    //상하좌우 중 색이 같고, 방문 안한 곳들을 큐에 넣기
    char color = matrix[curr.first][curr.second];
    if(curr.first < matrix.size()-1 && !visited[curr.first+1][curr.second])
        if(matrix[curr.first+1][curr.second] == color || (isBlind && ((color == 'R' && matrix[curr.first+1][curr.second] == 'G') || (color == 'G' && matrix[curr.first+1][curr.second] == 'R'))))
            qu.push(make_pair(curr.first+1, curr.second));
    if(curr.first > 0 && !visited[curr.first-1][curr.second])
        if(matrix[curr.first-1][curr.second] == color || (isBlind && ((color == 'R' && matrix[curr.first-1][curr.second] == 'G') || (color == 'G' && matrix[curr.first-1][curr.second] == 'R'))))
            qu.push(make_pair(curr.first-1, curr.second));
    if(curr.second < matrix.size()-1 && !visited[curr.first][curr.second+1])
        if(matrix[curr.first][curr.second+1] == color || (isBlind && ((color == 'R' && matrix[curr.first][curr.second+1] == 'G') || (color == 'G' && matrix[curr.first][curr.second+1] == 'R'))))
            qu.push(make_pair(curr.first, curr.second+1));
    if(curr.second > 0 && !visited[curr.first][curr.second-1])
        if(matrix[curr.first][curr.second-1] == color || (isBlind && ((color == 'R' && matrix[curr.first][curr.second-1] == 'G') || (color == 'G' && matrix[curr.first][curr.second-1] == 'R'))))
            qu.push(make_pair(curr.first, curr.second-1));

    //큐에서 하나 꺼내서 방문
    if(!qu.empty()){
        pair<int,int> next = qu.front();
        qu.pop();
        get_space(matrix, visited, qu, next, isBlind);
    }
}

int main(void){
    //입력
    int N;
    cin >> N;
    vector<vector<char>> matrix = vector<vector<char>>(N, vector<char>(N, 0));
    vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(N, false));
    queue<pair<int,int>> qu;
    for(int i = 0; i < N; i++){
        string line;
        cin >> line;
        for(int j = 0; j < N; j++){
            matrix[i][j] = line[j];
        }   
    }

    //BFS로 구역 수 세기
    int space_cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) continue;
            while(!qu.empty()) qu.pop();
            get_space(matrix, visited, qu, make_pair(i,j), false);
            space_cnt++;
        }
    }

    //BFS로 적록색약인 사람의 구역 수 세기
    int space_blind_cnt = 0;
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) continue;
            while(!qu.empty()) qu.pop();
            get_space(matrix, visited, qu, make_pair(i,j), true);
            space_blind_cnt++;
        }
    }
    
    //출력
    cout << space_cnt << " " << space_blind_cnt << "\n";
}