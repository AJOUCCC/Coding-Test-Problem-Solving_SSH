#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

bool compare(vector<string> a, vector<string> b){
    return a[1] < b[1];    
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    //plans를 시작하는 순서대로 오름차순 정렬
    sort(plans.begin(), plans.end(), compare);
    
    //plans를 정수형으로 변경
    vector<pair<int,int>> times = vector<pair<int,int>>(plans.size(), make_pair(0,0));
    for(int i = 0; i < times.size(); i++){
        int start = stoi(plans[i][1].substr(0,2)) * 60 + stoi(plans[i][1].substr(3,2));
        int duration = stoi(plans[i][2]);
        times[i] = make_pair(start, duration);
    }
    
    //스택을 이용해서 잠시 멈춘 과제를 관리
    stack<int> st;
    int curr = 0;
    int next = 1;
    while(answer.size() < plans.size()){
        //현 과제 종료시간 > 다음 과제 시작시간이면, 중단
        if(next < plans.size() && times[curr].first + times[curr].second > times[next].first){
            st.push(curr);
            times[curr].second = times[curr].second - times[next].first + times[curr].first;
            curr = next;
            next++;
        }
        //현 과제 종료시간 <= 다음 과제 시작시간이라면, 과제 종료
        else{
            answer.push_back(plans[curr][0]);
            if(!st.empty()){
                int nextStartTime = times[curr].first + times[curr].second;
                curr = st.top();
                st.pop();
                times[curr].first = nextStartTime;
            }
            else{
                curr = next;
                next++;
            }
        }
    }
    
        
    return answer;
}