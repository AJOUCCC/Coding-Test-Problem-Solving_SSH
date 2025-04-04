#include <iostream>
#include <vector>
using namespace std;

void move(vector<vector<int>> &puzzle, int direction, int N){
    //상하좌우 순서
    if(direction == 0){
        for(int i = 0; i < N; i++){
            int pos = 0;
            int target = -1;
            for(int j = 0; j < N; j++){
                cout << "pos: " << puzzle[j][i] << "\n";
                if(puzzle[j][i] == 0){
                    cout << "1\n";
                    continue;
                }
                else if(target == -1){
                    cout << "2\n";
                    target = puzzle[j][i];
                }
                else if(puzzle[j][i] == target){
                    cout << "3\n";
                    puzzle[pos++][i] = target * 2;
                    target = -1;
                }
                else{
                    cout << "4\n";
                    puzzle[pos++][i] = target;
                    target = puzzle[j][i];
                }
            }
            if(target != -1)
                puzzle[pos++][i] = target;
            while(pos < N) puzzle[pos++][i] = 0;
        }
    }
    else if(direction == 1){

    }
    else if(direction == 2){

    }
    else{

    }
}

void solve_puzzle(int N, int depth, vector<vector<int>> puzzle){
    //depth = 5면 종료
    if(depth == 5) return;

    //아니라면, 상하좌우로 진전
    move(puzzle, 0, N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << puzzle[i][j] << " ";
        cout << "\n";
    }
    // solve_puzzle(depth+1, )
}

int main(void){
    //입력
    int N;
    cin >> N;
    vector<vector<int>> puzzle = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> puzzle[i][j];
    
    //BFS로 완전 탐색
    solve_puzzle(N, 0, puzzle);
}