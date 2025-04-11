#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Job{
    int index;
    int request_t;
    int endure_t;
    int runned_t;
    
    Job(int i, int r, int e){
        index = i;
        request_t = r;
        endure_t = e;
        runned_t = 0;
    }
};

struct compare{
    bool operator()(const Job &j1, const Job &j2){
        if(j1.endure_t == j2.endure_t && j1.request_t == j2.request_t)
            return j1.index > j2.index;
        else if(j1.endure_t == j2.endure_t)
            return j1.request_t > j2.request_t;
        else
            return j1.endure_t > j2.endure_t;
    }
};

bool compareToSort(Job &j1, Job &j2){
    return j1.request_t < j2.request_t;
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    //우선순위 큐 선언
    priority_queue<Job, vector<Job>, compare> pq;
    vector<int> return_ts;
    
    //작업을 요청 시각 순으로 정렬 & 반환시간 저장 칸 생성
    vector<Job> jobs_new;
    for(int i = 0; i < jobs.size(); i++){
        jobs_new.push_back(Job(i, jobs[i][0], jobs[i][1]));
    }
    sort(jobs_new.begin(), jobs_new.end(), compareToSort);
    
    //시간 1초씩 늘려가며 판단
    bool isRun = false;
    Job *runningJob;
    for(int t = 0; ; t++){
        // if(t == 2) break;
        //cout << "t: " << t << "\n";
        
        //현 작업 X, 큐 작업 X면 종료
        if(!isRun && jobs_new.empty() && pq.empty()) break;
        
        //현 작업 O, 실행된 정도 추가
        //현 작업 O, 작업을 끝내는 타이밍이라면 끝
        if(isRun){
            //cout << "task 1 \n";
            runningJob->runned_t++;
            if(runningJob->runned_t == runningJob->endure_t){
                return_ts.push_back(t - runningJob->request_t);
                isRun = false;
            }
        }
        
        //요청시각 = t인 작업을 대기 큐에 넣기
        while(!jobs_new.empty() && jobs_new[0].request_t == t){
            //cout << "task 2\n";
            pq.push(jobs_new[0]);
            jobs_new.erase(jobs_new.begin());
        }
        
        //현 작업 X, 대기 큐에서 우선순위 1위인 것을 pop해서 시작
        if(!isRun && !pq.empty()){
            //cout << "task 3 \n";
            runningJob = new Job(pq.top());
            isRun = true;
            pq.pop(); 
        }
        
    }
    
    //return_ts 평균내기
    int avg = 0;
    for(int i = 0; i < return_ts.size(); i++){
        avg += return_ts[i];
        //cout << return_ts[i] << "\n";
    }
    avg /= return_ts.size();
    
    return avg;
}