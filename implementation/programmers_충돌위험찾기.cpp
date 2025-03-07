#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int danger_cnt = 0;
void move_one_second(vector<pair<int,int>> &cur_poses, vector<int> &cur_route, vector<vector<int>> &points, vector<vector<int>> &routes, vector<bool> &finished){
   
    //현재 충돌위험 찾기
    vector<pair<int,int>> alive_poses;
    for(int i = 0; i < cur_poses.size(); i++){
        if(!finished[i]){
            alive_poses.push_back(cur_poses[i]);
        }
    }
    sort(alive_poses.begin(), alive_poses.end());
    pair<int,int> prev = make_pair(-1, -1);
    int i = 0;
    while(i < alive_poses.size()){
        if(alive_poses[i] == prev){
            danger_cnt++;
            while(alive_poses[i] == prev) i++;
        }
        prev = alive_poses[i];
        i++;
    }
   
    //로봇별로 이동
    for(int i = 0; i < cur_poses.size(); i++){
        if(!finished[i]){
            if(cur_poses[i].first < points[routes[i][cur_route[i]]-1][0])
                cur_poses[i].first++;
            else if(cur_poses[i].first > points[routes[i][cur_route[i]]-1][0])
                cur_poses[i].first--;
            else if(cur_poses[i].second < points[routes[i][cur_route[i]]-1][1])
                cur_poses[i].second++;
             else if(cur_poses[i].second > points[routes[i][cur_route[i]]-1][1])
                cur_poses[i].second--;
            else{
                if(cur_route[i] < routes[i].size()-1) {
                    cur_route[i]++;
                     if(cur_poses[i].first < points[routes[i][cur_route[i]]-1][0])
                        cur_poses[i].first++;
                    else if(cur_poses[i].first > points[routes[i][cur_route[i]]-1][0])
                        cur_poses[i].first--;
                    else if(cur_poses[i].second < points[routes[i][cur_route[i]]-1][1])
                        cur_poses[i].second++;
                     else if(cur_poses[i].second > points[routes[i][cur_route[i]]-1][1])
                        cur_poses[i].second--;
                }
                else finished[i] = true;
            }     
        }
    }
 
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {    
    //로봇 현 위치와 종료 위치 정보 초기화
    vector<pair<int,int>> cur_poses = vector<pair<int,int>>(routes.size(), make_pair(-1, -1)); //로봇의 현 위치
    vector<int> cur_route = vector<int>(routes.size(), -1); //로봇의 현재 목표 위치 index
    vector<bool> finished = vector<bool>(routes.size(), false); //로봇의 루트가 모두 끝났는지 여부
    for(int i = 0; i < routes.size(); i++){
        pair<int,int> start_p = make_pair(points[routes[i][0]-1][0], points[routes[i][0]-1][1]);
        cur_poses[i] = start_p;
        cur_route[i] = 1;
    }

    //모든 로봇이 도착할때까지 1초 이동을 반복
    while(true){
        bool finishAll = true;
        for(bool finish : finished){
            if(!finish) {
                finishAll = false;
                break;
            }
        }
        if(finishAll) break;
        move_one_second(cur_poses, cur_route, points, routes, finished);
    }
    return danger_cnt;
}