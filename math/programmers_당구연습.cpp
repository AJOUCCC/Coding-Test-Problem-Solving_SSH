#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> dot_mirror(int dx, int dy, int tx, int ty){
    //dx,dy 점에 대하여 tx, ty 점을 점 대칭한 것을 리턴
    return {2 * dx - tx, 2 * dy - ty};
}
vector<vector<int>> DIRECT = {{1, 0}, {0, 1}, {2, 0}, {0, 2}}; //0 -> 그대로, 1 -> -1 곱함, 2 -> 2*m(또는n)-x(y)
vector<vector<int>> CLINE = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    
    //ball 순회
    for(int i = 0; i < balls.size(); i++){
        int min = 10000000;
        //4개의 꼭짓점 반복
//         for(int j = 0; j < CLINE.size(); j++){
//             //현 볼과 꼭짓점의 기울기 == 내 공과 꼭짓점의 기울기라면,
//             int cornerX = CLINE[j][0] * m;
//             int cornerY = CLINE[j][1] * n;
//             if(cornerX == startX || balls[i][0] - cornerX) continue;
            
//             if((cornerY - startY / cornerX - startX) == (balls[i][1] - cornerY / balls[i][0] - cornerX)){
//                 if((j % 2 == 1 && startX > balls[i][0]) || (j % 2 == 0 && startX < balls[i][0])){
//                     vector<int> new_ball = dot_mirror(cornerX, cornerY, balls[i][0], balls[i][1]);
//                     int dist = pow(new_ball[0] - startX, 2) + pow(new_ball[1] - startY, 2);
//                     if(dist < min) min = dist;
//                 }
//             }
//         }
        
        
        //4개의 방향으로 ball을 대칭시키기
        for(int j = 0; j < DIRECT.size(); j++){
            //현 ball과 내 공과의 거리 측정 후 업데이트
            int dx, dy;
            if(DIRECT[j][0] == 0) dx = balls[i][0];
            else if(DIRECT[j][0] == 1) dx = -1 * balls[i][0];
            else dx = 2 * m - balls[i][0];
            if(DIRECT[j][1] == 0) dy = balls[i][1];
            else if(DIRECT[j][1] == 1) dy = -1 * balls[i][1];
            else dy = 2 * n - balls[i][1];
            cout << "J: "<< j << " | " << dx << ", " << dy << "\n";
            //만약 두 점이 일자라면,
            if(dx == startX || dy == startY){
                if(j == 0 && startX > balls[i][0]) continue;
                else if(j == 1 && startY > balls[i][1]) continue;
                else if(j == 2 && startX < balls[i][0]) continue;
                else if(j == 3 && startY < balls[i][1]) continue;
            }
            int dist = pow(dx - startX, 2) + pow(dy - startY, 2);
            if(dist < min) min = dist;
        }
           
        answer.push_back(min);    
    }

    
    return answer;
}