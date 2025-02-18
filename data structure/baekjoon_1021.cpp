#include <iostream>
#include <deque>
using namespace std;

int main(void){
    int N, M;
    deque<int> qu;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        qu.push_back(i+1);
    }
    
    int count = 0;
    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        deque<int> backupL(qu);
        deque<int> backupR(qu);

        //target 나올때까지 왼쪽으로 이동
        int countL = 0;
        while(backupL.front() != target){
            backupL.push_back(backupL.front());
            backupL.pop_front();
            countL++;
        }
        backupL.pop_front();

        //target 나올때까지 오른쪽으로 이동
        int countR = 0;
        while(backupR.front() != target){
            backupR.push_front(backupR.back());
            backupR.pop_back();
            countR++;
        }
        backupR.pop_front();

        if(countL < countR){
            qu = backupL;
            count += countL;
        }
        else{
            qu = backupR;
            count += countR;
        }
    }

    cout << count << "\n";
}