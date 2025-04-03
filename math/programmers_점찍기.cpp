#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    //x2 + y2 = r2 공식을 이용해서, x 하나를 정하면 y의 범위도 알 수 있음!
    long long r2 = (long long)d*(long long)d;
    for(int i = 0; i <= d; i += k){
        long long x2 = (long long)i*(long long)i;  
        long long y2 = r2 - x2;
        long long y = sqrt(y2);
        answer += y / k + 1;
    }
    return answer;
}