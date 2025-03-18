#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}
int main(void){
    //입력받기
    int N;
    cin >> N;
    vector<int> A = vector<int>(N, 0);
    vector<int> B = vector<int>(N, 0);
    long long sum = 0;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
        cin >> B[i];

    //각 배열 정렬하기
    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end());

    //S 값 구하기
    for(int i = 0; i < N; i++){
        sum += A[i] * B[i];
    }
    cout << sum << "\n";
}