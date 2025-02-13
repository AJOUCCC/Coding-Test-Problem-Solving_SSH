#include <iostream>
#include <vector>
using namespace std;
char arr[2187][2187];

void make_star(char arr[][2187], int size, pair<int, int> s, pair<int, int> e){
    //3이라면 별 찍기
    if(size == 3){
        arr[s.first][s.second] = '*';
        arr[s.first+1][s.second] = '*';
        arr[s.first+2][s.second] = '*';
        arr[s.first][s.second+1] = '*';
        arr[s.first][s.second+2] = '*';
        arr[s.first+1][s.second+2] = '*';
        arr[s.first+2][s.second+1] = '*';
        arr[s.first+2][s.second+2] = '*';
        return;
    }

    //3보다 크다면, 9구역으로 나누기
    int nsize = size / 3;
    make_star(arr, nsize, make_pair(s.first, s.second), make_pair(s.first + nsize -1, s.second + nsize -1));
    make_star(arr, nsize, make_pair(s.first, s.second + nsize), make_pair(s.first + nsize -1, s.second + nsize*2 -1));
    make_star(arr, nsize, make_pair(s.first, s.second + nsize*2), make_pair(s.first + nsize -1, s.second + nsize*3 -1));
    make_star(arr, nsize, make_pair(s.first + nsize, s.second), make_pair(s.first + nsize*2 -1, s.second + nsize -1));
    make_star(arr, nsize, make_pair(s.first + nsize*2, s.second), make_pair(s.first + nsize*3 -1, s.second + nsize -1));
    make_star(arr, nsize, make_pair(s.first + nsize*2, s.second + nsize), make_pair(s.first + nsize*3 -1, s.second + nsize*2 -1));
    make_star(arr, nsize, make_pair(s.first + nsize, s.second + nsize*2), make_pair(s.first + nsize*2 -1, s.second + nsize*3 -1));
    make_star(arr, nsize, make_pair(s.first + nsize*2, s.second + nsize*2), make_pair(s.first + nsize*3 -1, s.second + nsize*3 -1));
}

int main(void){
    //입력 및 N x N 배열 선언, 공백으로 채움
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = ' ';
        }
    }

    //재귀적으로 패턴 새김
    make_star(arr, N, make_pair(0,0), make_pair(N-1, N-1));

    //저장된 것을 출력
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}