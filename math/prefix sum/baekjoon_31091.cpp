#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int N;
    cin >> N;
    vector<int> liers = vector<int>(2*N+1, 0);
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        liers[N + a]++;  
    }
    
    //누적합 계산
    vector<int> prefix_sum = vector<int>(2*N+1, 0);
    prefix_sum[0] = liers[0];
    for(int i = 1; i < 2*N+1; i++){
        prefix_sum[i] = prefix_sum[i-1] + liers[i];
    }
    // cout << "pefix sum: ";
    //  for(int i = 0; i < 2*N+1; i++){
    //     cout << prefix_sum[i] << " "; 
    // }
    // cout << "\n";

    //가능한 거짓말 사람 수 출력
    int num = 0;
    vector<int> avails;
    if(prefix_sum[2*N] - prefix_sum[N] == 0){
        num++;
        avails.push_back(0);
    }
    for(int i = 1; i < N+1; i++){
        if(prefix_sum[2*N] - prefix_sum[N+i] + prefix_sum[N] - prefix_sum[N-i] == i){
            num++;
            avails.push_back(i);
        }
    }
    cout << num << "\n";
    if(num != 0){
        for(int i = 0; i < avails.size(); i++)
            cout << avails[i] << " ";
        cout << "\n";
    }
}