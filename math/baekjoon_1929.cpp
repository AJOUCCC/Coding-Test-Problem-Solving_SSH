#include <iostream>
using namespace std;

int main(void){
    //입력받기
    int M, N;
    cin >> M >> N;
    int nums[N+1];

    //배열 초기화
    for(int i = 0; i < N+1; i++){
        nums[i] = i;
    }

    for(int i = 1; i < N+1; i++){
        //이미 소수 아니라면, 패스
        if(nums[i] == 0) continue;
        if(nums[i] == 1){
            nums[i] = 0;
            continue;
        }

        //이 수의 배수 지우기
        for(int j = i*2; j < N+1; j+=i){
            nums[j] = 0;
        }
    }

    //출력
    for(int i = M; i < N+1; i++){
        if(nums[i] != 0)
            cout << nums[i] << endl;
    }
    
    return 0;
}