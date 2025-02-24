#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> f;

//fibo 함수
pair<int,int> fibo(int N){
    //0, 1이 호출 시에는 count를 세기
    if(N == 0){
        return f[N];
    }
    else if(N == 1){
        return f[N];
    }

    //만약 메모이제이션 되어 있다면 가져와서 리턴
    if(f[N].first != 0 || f[N].second != 0){
        return f[N];
    }

    //아니라면 새로 계산, 그리고 저장
    pair<int,int> f_n_minus_1 = fibo(N-1);
    pair<int,int> f_n_minus_2 = fibo(N-2);
    int count_0 = f_n_minus_1.first + f_n_minus_2.first;
    int count_1 = f_n_minus_1.second + f_n_minus_2.second;
    f[N] =  make_pair(count_0, count_1);
    return f[N];
}

int main(void){
    int T;
    cin >> T;
    f = vector<pair<int,int>>(41, make_pair(0,0));
    f[0] = make_pair(1,0);
    f[1] = make_pair(0,1);


    //테스트케이스 하나씩 돌아가며 0,1 호출된 개수 출력하기
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
  
        pair<int,int> result = fibo(N);
        cout << result.first << " " << result.second << "\n";
    }
}