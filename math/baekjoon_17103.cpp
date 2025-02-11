#include <iostream>
using namespace std;

int main(void){
    int T;

    cin >> T;

    int N;
    for(int i = 0; i < T; i++){
        
        //한 케이스 입력 및 배열 초기화
        int count = 0;
        cin >> N;
        int n[N+1];
        for(int j = 0; j < N+1; j++){
            n[j] = j;
        }

        //에라토스테네스의 체
        for(int j = 1; j < N+1; j++){
            if(n[j] == 0) continue;
            if(n[j] == 1){
                n[j] = 0;
                continue;
            }
            
            for(int k = j * 2; k < N+1; k += j)
                n[k] = 0;   
        }

        //소수들 중에서 파티션 찾기
        for(int j = 2; j < N+1; j++){
            
            if(n[j] == 0 || n[N-j] == 0 || n[N-j] == 1){
                continue;
            } 
            else{
                count++;
                n[j] = 0;
                n[N-j] = 0;
            }
        }
        cout << count << "\n";
    }
}