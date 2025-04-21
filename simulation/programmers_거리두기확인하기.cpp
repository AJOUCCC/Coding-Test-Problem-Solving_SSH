#include <string>
#include <vector>
#include <iostream>
using namespace std;


/*응시자의 맨해튼거리 2의 주변을 검사*/
vector<vector<int>> STEP_ONE = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> STEP_TWO = {{1, 1}, {-1, 1}, {-1, 1}, {-1, -1}};
vector<vector<int>> STEP_THREE = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};
bool look_distance(vector<string> &places, pair<int,int> curr){
    //step 1: 바로 옆 자리는 P라면 거리두기 지키지 않은 것
    for(int i = 0; i < STEP_ONE.size(); i++){
        int x = curr.first + STEP_ONE[i][0];
        int y = curr.second + STEP_ONE[i][1];
        if(x >= 0 && x < 5 && y >= 0 && y < 5){
            //cout << places[x][y] << "\n";
            if(places[x][y] == 'P') return false;
        }
    }
    
    //step 2: 대각선은 사이의 두 점이 모두 파티션이지 않으면 지키지 않은 것
    for(int i = 0; i < STEP_TWO.size(); i++){
        int x = curr.first + STEP_TWO[i][0];
        int y = curr.second + STEP_TWO[i][1];
        if(x >= 0 && x < 5 && y >= 0 && y < 5){
            if(places[x][y] == 'P'){
                if(places[x][curr.second] != 'X' || places[curr.first][y] != 'X')
                    return false;
            }
        }
    }
    
    //step 3
    for(int i = 0; i < STEP_THREE.size(); i++){
        int x = curr.first + STEP_THREE[i][0];
        int y = curr.second + STEP_THREE[i][1];
        if(x >= 0 && x < 5 && y >= 0 && y < 5){
            if(places[x][y] == 'P'){
                int mx = curr.first + STEP_ONE[i][0];
                int my = curr.second + STEP_ONE[i][1];
                if(places[mx][my] != 'X')
                    return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    //모든 대기실에 대해 순회
    for(int k = 0; k < places.size(); k++){
        bool isValid = true;
        //모든 칸에 대해 순회
        for(int i = 0; i < places.size(); i++){
            if(!isValid) break;
            for(int j = 0; j < places.size(); j++){
                //응시자가 않지 않은 칸이면 넘어가기
                if(places[k][i][j] != 'P') continue;
                //응시자가 않은 칸이면 검사하기
                isValid = look_distance(places[k], make_pair(i,j));
                if(!isValid) break;
            }
        }
        if(isValid) answer.push_back(1);
        else answer.push_back(0);
    }
   
    return answer;
}