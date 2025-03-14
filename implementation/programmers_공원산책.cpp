#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    //시작 지점 초기화
     int curr_x, curr_y;
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[i].size(); j++){
            if(park[i][j] == 'S'){
                curr_x = i;
                curr_y = j;
                break;
            }
        }
    }
    
    //routes를 순회
    for(int i = 0; i < routes.size(); i++){
        //route의 정보 변환하기
        char op = routes[i][0];
        int n = routes[i][2] -'0';
        int xdir = 0, ydir = 0;
        switch(op){
            case 'E':   
                ydir = 1;
                break;
            case 'S':
                xdir = 1;
                break;
            case 'W':
                ydir = -1;
                break;
            case 'N':
                xdir = -1;
                break;
            default:
                break;
        }
        
        //route로 한 칸씩 이동시키면서 조건 만족 확인
        int next_x = curr_x;
        int next_y = curr_y;
        bool valid = true;
        for(int i = 0; i < n; i++){
            // 칸 이동
            next_x += xdir;
            next_y += ydir;
            
            //범위를 넘으면 무시
            if(next_x < 0 || next_x > park.size()-1 || next_y < 0 || next_y > park[0].size()-1){
                valid = false;
                //cout << "Invalid1: " << next_x << "," << next_y << "\n";
                break;
            }
            //장애물이 있으면 무시
            else if(park[next_x][next_y] == 'X'){
                valid = false;
                //cout << "Invalid2: " << next_x << "," << next_y << "\n";
                break;
            }
            
        }
        
        if(valid){
            curr_x = next_x;
            curr_y = next_y;
            //cout << "valid: " << curr_x << "," << curr_y << "\n";
        }
            
    }
    answer.push_back(curr_x);
    answer.push_back(curr_y);
    return answer;
}