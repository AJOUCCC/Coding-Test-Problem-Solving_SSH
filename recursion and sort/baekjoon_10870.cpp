#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    if(N < 2) {
        cout << N << "\n";
        return 0;
    }

    int pibo[N+1];
    pibo[0] = 0;
    pibo[1] = 1;
    for(int i = 2; i <= N; i++){
        pibo[i] = pibo[i-1] + pibo[i-2];
    }

    cout << pibo[N] << "\n";
}