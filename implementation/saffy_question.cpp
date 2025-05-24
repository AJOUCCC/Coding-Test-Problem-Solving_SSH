#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * a의 절댓값을 리턴하는 함수
 */
int eval(int a){
    if(a < 0) return -1 * a;
    else return a;
}

int main(void){
    int T;
    cin >> T;
    vector<int> result;

    for(int t = 0; t < T; t++){
        //입력받기
        int N, K;
        cin >> N >> K;
        vector<int> nums = vector<int>(N, 0);
        for(int i = 0; i < N; i++)
            cin >> nums[i];

        //N을 오름차순 정렬
        sort(nums.begin(), nums.end());

        //N을 순회하기
        //이때 답은 연속해서 있을 것이라고 가정하여, K개씩 연속되 것을 검사
        int min_sum = 10000000;
        for(int i = 0; i < N-K+1; i++){

            //현 묶음에 대해 거리합 측정
            int sum = 0;
            vector<int> perm = vector<int>(K, 2);
            perm[0] = 1;
            perm[1] = 1;
            do{
                //cout << "Let's select\n";
                vector<int> selected;
                for(int j = 0; j < perm.size(); j++){
                    //선택된 두 점 구하기
                    if(perm[j] == 1){
                        selected.push_back(nums[i+j]);
                        //cout << "selected: " << i+j << "\n";
                    }
                }
                //선택된 두 점의 거리 구하기
                sum += eval(selected[0] - selected[1]);

            }
            while(next_permutation(perm.begin(), perm.end()));

            //거리합이 최소이면 업데이트
            if(sum < min_sum) min_sum = sum;
            cout << sum << "\n";
        }

        //정답 출력
        cout << "#" << t+1 << " " << min_sum << "\n";

    }
}