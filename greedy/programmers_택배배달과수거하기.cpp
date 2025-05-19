#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*그리디*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    //전체 배달할 택배 수 합산, 수거할 택배 수 합산
    int total_d = 0;
    int total_p = 0;
    for(auto d : deliveries)
        total_d += d;
    for(auto p : pickups)
        total_p += p;
    //cout << "total_d: " << total_d << " total_p: " << total_p << "\n";
    
    //배달 수와 수거 수가 0이 될때까지 반복
    int history = n-1;
    while(total_d != 0 || total_p != 0){
        
        //min(cap, 남은 배달할 택배 수)만큼 싣기
        int boxes_d = min(cap, total_d); //새 택배
        int boxes_p = 0; //수거한 택배
        int distance = 0;
        
        //거리 정하기
        for(int i = history; i >= 0; i--){
            if(deliveries[i] != 0 || pickups[i] != 0) {
                distance = i+1;
                break;
            }
        }
        
        //맨 뒷집부터 차례로 순회
       for(int i = distance-1; i >= 0; i--){
           if(boxes_d == 0) break;
            //최대한 배달
            int boxes_to_deliever = min(boxes_d, deliveries[i]);
            boxes_d -= boxes_to_deliever;
            deliveries[i] -= boxes_to_deliever;
            total_d -= boxes_to_deliever;
        }
        
        //맨 뒷집부터 차례로 순회
        for(int i = distance-1; i >= 0; i--){
            if((boxes_d + boxes_p) == cap) break;
            //최대한 수거
            int capacity = cap - (boxes_d + boxes_p);
            int boxes_to_pickup = min(capacity, pickups[i]);
            boxes_p += boxes_to_pickup;
            pickups[i] -= boxes_to_pickup;
            total_p -= boxes_to_pickup;
        }
        
        //이번의 이동 거리
        answer += 2 * distance;
        history = distance-1;
        //cout << 2 * distance << " total_d: " << total_d << " total_p: " << total_p << "\n";
    }

            
    return answer;
}