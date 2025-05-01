#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    //x좌표를 1~r2-1 순회
    for(long long x = 1; x < r2; x++){
        long long y1, y2;
        y2 = sqrt((long long)r2 * (long long)r2 - x * x);
        //cout << "x : " << x << " ";
        //r1 원이 없다면 y2의 점 카운트
        if((long long)r1 * (long long)r1 <= x * x) {
            answer += 2 * y2 + 1;
            //cout << 2 * y2 + 1 << "\n";
        }
        //r1 원이 있다면 y2 - y1를 카운트
        else{
            y1 = sqrt((long long)r1 * (long long)r1 - x * x); 
            //y1 결과가 정수라면, 차+1 카운트
            if(sqrt((long long)r1 * (long long)r1 - x * x) - y1 == 0){
                answer += 2 * (y2 - y1 + 1);
                //cout << 2 * (y2 - y1 + 1) << "\n";
            }     
            //아니라면 차 카운트
            else {
                answer += 2 * (y2 - y1);
                //cout << 2 * (y2 - y1) << "\n";
            }
                
        }
    }
    answer *= 2;
    answer += 2 * (r2 - r1 + 1) + 2; //x = 0과 x = -r2, r2일때
    return answer;
}