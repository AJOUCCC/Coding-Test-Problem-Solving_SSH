#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    //입력
    int N, K;
    cin >> N >> K;
    vector<int> diff = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        //각 광고마다의 차이값 계산
        diff[i] = b - a;
    }

    //오름차순 정렬
    sort(diff.begin(), diff.end());

    //diff[K-1] <= 0이면, 0 출력
    //> 0 이면, diff[K-1] 출력
    if(diff[K-1] <= 0) cout << 0 << "\n";
    else cout << diff[K-1] << "\n";

}