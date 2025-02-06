#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    //입력받기
    int M, N;
    cin >> M >> N;

    for(int i = M; i <= N; i++){
        //1이면 소수 아님
        if(i == 1) continue;

        //소수인지 확인
        bool sosu = true;
        for(int j = 2; j <= sqrt(i); j++){
            
            if(i % j == 0){
                sosu = false;
                break;
            }
        }

        //소수라면 출력
        if(sosu) cout << i << endl;
    }

    return 0;
}