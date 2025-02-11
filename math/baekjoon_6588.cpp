#include <iostream>
#include <vector>
const int MAX_SIZE = 1000001;
using namespace std;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //소수 얻기(에라토스테네스의 체)
    bool primes[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++){
        primes[i] = true;
    }
    primes[1] = false;
    for(int i = 1; i < MAX_SIZE; i += 2){
        if(primes[i] == false) continue;
        for(int j = i*2; j < MAX_SIZE; j += i)
            primes[j] = false;
    }

    //출력
    int N;
    while(true){
        cin >> N;
        if(N == 0) return 0;

        bool right = false;
        //골드바흐 파티션 중 차가 가장 큰 걸 구하기 위해 값 저장 후 비교를 했었는데
        //맨 처음 발견된 파티션이 차가 가장 큰 것이므로, 비교가 불필요
        //-> 이것때문에 시간초과 발생쓰쓰
        for(int i = 1; i < N; i += 2){
            if(primes[i] == true && primes[N-i] == true){
                cout << N << " = " << i << " + " << N-i << "\n";
                right = true;
                break;
            }
            else if(i > N-i) break;
        }
        if(!right) cout << "Goldbach's conjecture is wrong.\n";
    }
}