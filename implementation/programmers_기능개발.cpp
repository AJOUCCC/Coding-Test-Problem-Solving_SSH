#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    //하루마다 순회
    int LAST_INDEX = progresses.size()-1;
    int last_deployed = -1;
     while(true){
        
        //모든 태스크를 배포 시 중지
        if(last_deployed == LAST_INDEX) break;
        
        //다음 태스크가 배포 가능하다면 배포
        int deploy_tasks = 0;
        if(progresses[last_deployed + 1] >= 100){
            deploy_tasks++;
            last_deployed++;
            for(int j = last_deployed + 1; j <= LAST_INDEX; j++){
                if(progresses[j] >= 100){
                    deploy_tasks++;
                    last_deployed++;
                }
                else break;
            }
            answer.push_back(deploy_tasks);
        }
        
        //나머지 진척도 업데이트
        for(int j = last_deployed + 1; j <= LAST_INDEX; j++)
            progresses[j] += speeds[j];    
        
        
    }
    
    return answer;
}