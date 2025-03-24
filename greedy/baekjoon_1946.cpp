#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    //입력받기
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        vector<pair<int,int>> members = vector<pair<int,int>>(N, make_pair(0,0));
        for(int j = 0; j < N; j++){
            cin >> members[j].first >> members[j].second;
        }

        //정렬
        sort(members.begin(), members.end());

        //서류성적을 기준으로 오름차순됨
        //한 멤버는 이후 멤버들보다는 무조건 선발되고, 이전 멤버들과 면접성적을 비교 시에 더 등수가 높아야만 선발됨
        int cnt = 0;
        int min = N+1;
        for(int j = 0; j < N; j++){
            if(members[j].second < min){
                cnt++;
                min = members[j].second;
            }
        }

        //출력
        cout << cnt << "\n";
    }
}