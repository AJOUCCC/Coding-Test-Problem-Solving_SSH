#include <iostream>
using namespace std;

int main(void){
    int N,M;
    int LN, BN;
    cin >> N >> M;

    // O(n)으로 그냥 탐색 가능
    for(int i = 1; i <= 10000; i++){
        //범위 넘으면 끝내기
        if(i > N || i > M) break;

        //최대공약수
        if(N % i == 0 && M % i == 0)
            LN = i;
    }

    for(int i = 1; true ; i++){
        //후보 최소공배수는 최대공약수의 배수수
        int tempBN = i * LN;

        //범위 넘으면 끝내기
        if(tempBN < N || tempBN < M) continue;

        //최소공배수
        if(tempBN % N == 0 && tempBN % M == 0){
            BN = tempBN;
            break;
        }
    }

    //출력
    cout << LN << endl;
    cout << BN << endl;
}