#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N, M;
        deque<pair<int, int>> dq;
        vector<int> priority;
        cin >> N >> M;
        for(int j = 0; j < N; j++){
            int pr;
            cin >> pr;
            dq.push_back(make_pair(pr, j));
            priority.push_back(pr);
        }

        //우선순위를 오름차순 정렬
        sort(priority.begin(), priority.end());

        //N개의 문서 출력 시까지 반복
        int count = 1;
        for(int j = 0; j < N; j++){
            while(priority.back() != dq.front().first){
                dq.push_back(dq.front());
                dq.pop_front();
            }

            if(dq.front().second == M){
                cout << count << "\n";
                break;
            }
            dq.pop_front();
            priority.pop_back();
            count++;
        }
    }
}