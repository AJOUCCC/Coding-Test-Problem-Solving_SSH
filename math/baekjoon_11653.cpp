#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    int cur = 0;
    while(N != 1){
        for(int i = 2; true; i++){
            if(N % i == 0){
                N /= i;
                cout << i << endl;
                break;
            }
        }
    }
}