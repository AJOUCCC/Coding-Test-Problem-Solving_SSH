#include <iostream>
#include <vector>
using namespace std;


vector<vector<pair<int,int>>> VERTICAL = {
    {{0,0},{1,0},{2,0}}, {{0,1},{1,1},{2,1}}, {{0,2},{1,2},{2,2}}};
vector<vector<pair<int,int>>> HORIZONTAL = {
    {{0,0},{0,1},{0,2}}, {{1,0},{1,1},{1,2}}, {{2,0},{2,1},{2,2}}};    
vector<vector<pair<int,int>>> DIAGONAL = {
    {{0,0},{1,1},{2,2}}, {{0,2},{1,1},{2,0}}};   


int main(void){

    //테스트 케이스마다 순회
    while(true){

        //현 테스트 케이스 입력
        vector<vector<char>> board = vector<vector<char>>(3, vector<char>(3, '.'));
        string testcase;
        cin >> testcase;
        if(testcase == "end") break;
        for(int i = 0; i < testcase.size(); i++)
            board[i/3][i%3] = testcase[i];

        //X,O, .의 개수 세기
        int x_cnt = 0, o_cnt = 0, dot_cnt = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X') x_cnt++;
                else if(board[i][j] == 'O') o_cnt++;
                else dot_cnt++;
            }
        }

        //가로, 세로, 대각선 방향 빙고 세기
        int x_bingo_cnt = 0, o_bingo_cnt = 0, x_diagonal_cnt = 0, o_diagonal_cnt = 0;
        for(int i = 0; i < VERTICAL.size(); i++){
            char target = board[VERTICAL[i][0].first][VERTICAL[i][0].second];
            bool bingo = true;
            for(int j = 0; j < VERTICAL[i].size(); j++){
                if(board[VERTICAL[i][j].first][VERTICAL[i][j].second] != target)
                    bingo = false;
                if(!bingo) break;
            }
            if(bingo && target == 'X') x_bingo_cnt++;
            else if(bingo && target == 'O') o_bingo_cnt++;
        }
        for(int i = 0; i < HORIZONTAL.size(); i++){
            char target = board[HORIZONTAL[i][0].first][HORIZONTAL[i][0].second];
            bool bingo = true;
            for(int j = 0; j < HORIZONTAL[i].size(); j++){
                if(board[HORIZONTAL[i][j].first][HORIZONTAL[i][j].second] != target)
                    bingo = false;
                if(!bingo) break;
            }
            if(bingo && target == 'X') x_bingo_cnt++;
            else if(bingo && target == 'O') o_bingo_cnt++;
        }
        for(int i = 0; i < DIAGONAL.size(); i++){
            char target = board[DIAGONAL[i][0].first][DIAGONAL[i][0].second];
            bool bingo = true;
            for(int j = 0; j < DIAGONAL[i].size(); j++){
                if(board[DIAGONAL[i][j].first][DIAGONAL[i][j].second] != target)
                    bingo = false;
                if(!bingo) break;
            }
            if(bingo && target == 'X') {
                x_bingo_cnt++;
                x_diagonal_cnt++;
            }
            else if(bingo && target == 'O') {
                o_bingo_cnt++;
                o_diagonal_cnt++;
            }
        }
        //cout << x_bingo_cnt << ", " << o_bingo_cnt << ", " << x_diagonal_cnt << ", " << o_diagonal_cnt << "\n";

        //valid 여부 판단하기
        bool isValid = true;
        if(x_cnt != o_cnt && x_cnt != o_cnt + 1) isValid = false;
        else if(dot_cnt > 0){
            if(x_bingo_cnt == 1 && o_bingo_cnt == 0 && x_cnt == o_cnt + 1) isValid = true;
            else if(o_bingo_cnt == 1 && x_bingo_cnt == 0 && x_cnt == o_cnt) isValid = true;
            else isValid = false;
        }
        else if(dot_cnt == 0){
            if(x_cnt != o_cnt + 1) isValid = false;
            if(x_bingo_cnt == 0 && o_bingo_cnt == 0) isValid = true;
            else if(x_bingo_cnt > 0 && o_bingo_cnt > 0) isValid = false;
            else if(o_bingo_cnt > 0) isValid = false;
            else if(x_bingo_cnt > 0 && x_bingo_cnt <= 2) isValid = true;
            else isValid = false;
        }
        if(isValid) cout << "valid\n"; else cout << "invalid\n";
    }
}