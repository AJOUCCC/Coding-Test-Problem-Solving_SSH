#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int size, int from, int to, int another){

    //size가 1이면 그냥 이동
    if(size == 1){
        cout << from << " " << to << "\n";
        return;
    }

    //size-1개의 탑을 another에 이동
    hanoi(size-1, from, another, to);

    //1개의 원판을 from에서 to로 이동
    cout << from << " " << to << "\n";

    //size-1개의 탑을 to로 이동
    hanoi(size-1, another, to, from);
}

int main(void){

    //입력
    int N;
    cin >> N;
    long long count = pow(2, N) - 1;
    cout << count << "\n";

    //재귀적으로 하노이 이동 순서 출력
    hanoi(N, 1, 3, 2);

}