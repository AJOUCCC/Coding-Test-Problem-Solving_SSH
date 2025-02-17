#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    int nums[10001] = {0};
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < N; i++){
        int X;
        cin >> X;
        nums[X]++;
    }

    for(int i = 0; i < 10001; i++){
        if(nums[i] != 0){
            for(int j = 0; j < nums[i]; j++){
                cout << i << "\n";
            }
        }
    }
}