#include <iostream>
using namespace std;

int next_choice(int* nums, int order, int N){
    //order는 남은 nums에서 order번째로 먼저인 수를 get한다는 뜻
    int count = 0;
    for(int i = 0; i < N; i++){
        if(nums[i] != 0){
            if(count == order){
                int result = nums[i];
                nums[i] = 0;
                return result;
            }
            count++;
        }
    }
    return 0;
}

void permutation(int* nums, int* perms, int depth, int N){

    //depth == N이라면, 모든 것을 골랐으므로 끝
    if(depth == N){
        for(int i = 0; i < N; i++){
            cout << perms[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    //하나를 고정하고, 아래 부분들 사전순 조합하기
    for(int i = 0; i < N-depth; i++){

        //지금 depth에서 선택할 것은 = i번째로 큰 수
        int next_num = next_choice(nums, i, N);
        perms[depth] = next_num;

        //하나 선택 후, 다음 depth로 넘어가기
        permutation(nums, perms, depth+1, N);

        //선택했던 것 원상복구
        nums[next_num-1] = next_num;
    }
}

int main(void){
    int N;
    cin >> N;
    int nums[N];
    int perms[N] = {0};

    //N개의 요소 초기화(0~N-1)
    for(int i = 0; i < N; i++){
        nums[i] = i+1;
    }

    permutation(nums, perms, 0, N);
    
}