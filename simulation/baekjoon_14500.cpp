#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> TETROMINO_1 = {{0,0}, {0,1}, {0,2}, {0,3}}
vector<vector<int>> TETROMINO_2 = {{0,0}, {0,1}, {1,0}, {1,1}}
vector<vector<int>> TETROMINO_3 = {{0,0}, {1,0}, {2.0}, {2,1}}
vector<vector<int>> TETROMINO_4 = {{0,0}, {1,0}, {1,1}, {2,1}}
vector<vector<int>> TETROMINO_5 = {{0,0}, {0,1}, {0,2}, {1,1}}
int SIZE = 3;
void rotate(vector<vector<int>> &target){
    vector<vector<int>> tmp(target);
    for(int i = 0; i < target.size(); i++){
        tmp[i][0] = target[i][1];
        tmp[i][1] = SIZE - target[i][0] - 1;
    }
    target = tmp;
}

void flip(vector<vector<int>> &target){
    vector<vector<int>> tmp(target);
    for(int i = 0; i < target.size(); i++){
        tmp[i][0] = SIZE - target[i][0] - 1;
        tmp[i][1] = target[i][1];
    }
    target = tmp;
}

int main(void){
    //입력
    int N, M;
    cin >> N >> M;
    vector<vector<int>> paper = vector<vector<int>>(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> paper[i][j];
        }
    }

    //종이 순회
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            //테트로미노 순회
            for
        }
    }
        
            
}