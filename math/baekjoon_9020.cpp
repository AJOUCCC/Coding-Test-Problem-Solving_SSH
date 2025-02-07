#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    //범위 내 소수들 구하기
    //초기화
    int primes[10001];
    for(int i = 0; i < 10001; i++){
        primes[i] = i;
    }

    //소수 거르기
    for(int i = 1; i < 10001; i++){
        if(primes[i] == 0) continue;
        if(primes[i] == 1){
            primes[i] = 0;
            continue;
        }

        for(int j = i*2; j < 10001; j += i)
            primes[j] = 0;
    }

    //테스트 케이스 반복
    for(int k = 0; k < N; k++){
        int t;
        cin >> t;

        //소수 풀에서 2개 가져와서 합 비교
        int left = 2, right = 9973;
        int partition[2] = {2, 10000};
        while(1){
        
            //left가 right를 넘으면 종료
            if(left > right) break;
         
            //만약 합이 같다면, 이전 partition보다 폭 좁으면 적용
            if(left + right == t){ 
                if((right - left) < (partition[1] - partition[0])){
                    partition[0] = primes[left];
                    partition[1] = primes[right];
                }
                 do
                {
                    left++;
                } while  (primes[left] == 0);
                 do
                {
                    right--;
                } while  (primes[right] == 0);
                
            }
            else if(left + right < t){  //만약 합이 작다면, left 진전
                do
                {
                    left++;
                } while  (primes[left] == 0);
            }
            else{ //만약 합이 크다면, right 진전 
                do
                {
                    right--;
                } while  (primes[right] == 0);
            }
        }

        //출력
        cout << partition[0]  << " " << partition[1] << endl;
    }
}