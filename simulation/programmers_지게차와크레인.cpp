#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> POS_X = {1, -1, 0, 0};
vector<int> POS_Y = {0, 0, 1, -1};
queue<pair<int,int>> qu;
void get_outed(int m, int n, vector<vector<bool>> &visited, vector<vector<bool>> &outed){
    //큐 안비었으면 꺼내기
    if(qu.empty()) return;
    pair<int,int> curr = qu.front();
    qu.pop();
    int x = curr.first;
    int y = curr.second;
    //cout << "get_outed: " << x << "," << y << "\n";
    
    //사방 탐색
    for(int k = 0; k < POS_X.size(); k++){
        int dx = x + POS_X[k];
        int dy = y + POS_Y[k];
        if(dx >= 0 && dx < m && y + dy >= 0 && dy < n){
            //visited라면, 큐에 넣기
            if(visited[dx][dy] && !outed[dx][dy]) qu.push(make_pair(dx, dy));
            
            //outed 처리
            if(!outed[dx][dy]) outed[dx][dy] = true;   
        }
    }
    
    //재귀 호출
    get_outed(m, n, visited, outed);
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    //방문 정보 정의
    int m = storage.size();
    int n = storage[0].size();
    vector<vector<bool>> visited = vector<vector<bool>>(storage.size(), vector<bool>(storage[0].size(), false));
    vector<vector<bool>> outed = vector<vector<bool>>(storage.size(), vector<bool>(storage[0].size(), false));
    for(int x = 0; x < storage.size(); x++){
        for(int y = 0; y < storage[0].size(); y++){
            if(x == 0 || x == storage.size()-1 || y == 0 || y == storage[0].size()-1)
                outed[x][y] = true;
        }
    }
    
    //request 수만큼 순회
    for(int i = 0; i < requests.size(); i++){
        char request = requests[i][0];
        //크레인 요청일 경우, 
        if(requests[i].size() == 2){
            //컨테이너 모두 순회
            for(int x = 0; x < storage.size(); x++){
                for(int y = 0; y < storage[0].size(); y++){
                     //해당하면 제거
                    if(visited[x][y]) continue;
                    if(storage[x][y] == request){
                        visited[x][y] = true;
                        cout << "crain: " << x << ", " << y << "\n";
                        //만약 접근 가능한 컨테이너라면, 사방의 컨테이너를 접근가능하게 만듬
                        if(outed[x][y]){
                            qu.push(make_pair(x,y));
                            get_outed(m, n, visited, outed);
                        }
                    } 
                }
            }
        }
        //지게차 요청일 경우,
        else{
            //방문 정보 오리지널 저장
            vector<vector<bool>> outed_origin(outed);
            
            //컨테이너 모두 순회
            for(int x = 0; x < storage.size(); x++){
                for(int y = 0; y < storage[0].size(); y++){
                    //한 컨테이너가 접근 가능하다면 제거
                    if(visited[x][y]) continue;
                    if(storage[x][y] == request && outed_origin[x][y]){
                        visited[x][y] = true;
                        qu.push(make_pair(x,y));
                        get_outed(m, n, visited, outed);
                    } 
                }
            }             
        }  
    }

    //남은 컨테이너 수 세기
    for(int x = 0; x < storage.size(); x++){
        for(int y = 0; y < storage[0].size(); y++){
            if(!visited[x][y]) answer++;
        }
    }
    return answer;
}