#include <iostream>
using namespace std;

int main(void){
    int n;
    while(cin >> n){
        if(n == 0) return 0;

        //배열 초기화
        int nums[2*n+1];
        for(int i = 0; i < 2*n+1; i++){
            nums[i] = i;
        }

        //소수 찾기
        for(int i = 1; i < 2*n+1; i++){
            //1이거나 이미 소수 아니면, 패스
            if(nums[i] == 0) continue;
            if(nums[i] == 1){
                nums[i] = 0;
                continue;
            }

            //이 수의 배수들은 소수 아님
            for(int j = 2*i; j < 2*n+1; j += i)
                nums[j] = 0;
        }

        //개수 출력
        int sum = 0;
        for(int i = n+1; i < 2*n+1; i++){
            if(nums[i] != 0) sum++;
        }
        cout << sum << endl;
    }
}