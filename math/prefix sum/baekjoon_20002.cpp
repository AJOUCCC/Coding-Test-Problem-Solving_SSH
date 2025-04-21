#include <iostream>
#include <vector>
using namespace std;

int main(void){
    //입력
    int N;
    cin >> N;
    vector<vector<int>> trees = vector<vector<int>>(N+1, vector<int>(N+1, 0));
    vector<vector<int>> prefix_sum = vector<vector<int>>(N+1, vector<int>(N+1, 0));
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            cin >> trees[i][j];
        }
    }

    //구간합 배열 저장
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + trees[i][j];
            //cout << prefix_sum[i][j] << " ";
        }
        //cout << "\n";
    }

    //1~n까지 순회하며 윈도우의 크기 결정
    //0~(n-k) + 1까지 순회하며 윈도우의 시작점 결정
    int max = -1;
    for(int k = 1; k <= N; k++){
        for(int i = 1; i < (N-k+2); i++){
            for(int j = 1; j < (N-k+2); j++){
                //정해진 윈도우의 총이익 값 계산
                int x_end = i + k - 1;
                int y_end = j + k - 1;
                int total = prefix_sum[x_end][y_end] - prefix_sum[i-1][y_end] - prefix_sum[x_end][j-1] + prefix_sum[i-1][j-1];
                
                //값이 max보다 크면 업데이트
                if(total > max) max = total;
            }
        }
    }
    
    //출력
    cout << max << "\n";
}