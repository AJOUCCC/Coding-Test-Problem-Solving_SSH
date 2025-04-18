#include <iostream>
#include <vector>
using namespace std;

void print_board(const vector<vector<int>>& board) {
    cout << "current board: \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 0)
                cout << " X ";
            else
                cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "---------------\n";
}

int main(void){
    //입력
    vector<vector<int>> board = vector<vector<int>>(5, vector<int>(5, 0));
    vector<int> answer = vector<int>(25, 0);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
    }
    for(int i = 0; i < 25; i++)
        cin >> answer[i];
    
    //외치는 수 순회
    int bingo_cnt = 0;
    for(int i = 0; i < 25; i++){
        int target = answer[i];

        //해당 수 찾기
        pair<int,int> pos;
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(board[j][k] == target){
                    board[j][k] = 0;
                    pos = make_pair(j, k);
                    break;
                }
            }
        }
        // cout << "target: " << target << "\n";
        // print_board(board);

        //수 부른 뒤 가로, 세로 빙고 확인
        bool vertical = true, horizontal = true, upstair = true, downstair = true;
        for(int k = 0; k < 5; k++)
            if(board[pos.first][k] != 0) 
                horizontal = false;
        for(int k = 0; k < 5; k++)
            if(board[k][pos.second] != 0) 
                vertical =false;
        if(vertical) bingo_cnt++;
        if(horizontal) bingo_cnt++;

        //만약 대각선 쪽이라면, 대각선 빙고 추가로 확인
        if(pos.first == pos.second){
            for(int k = 0; k < 5; k++){
                if(board[k][k] != 0) 
                    downstair = false;
            }
            if(downstair) bingo_cnt++;
        }
        if(pos.first == 4 - pos.second){
            for(int k = 0; k < 5; k++){
                if(board[4-k][k] != 0) 
                    upstair = false;
            }
            if(upstair) bingo_cnt++;        
        }
        
        //3줄 완성되었다면 출력
        if(bingo_cnt >= 3){
            cout << i+1 << "\n";
            return 0;
        }
      
    }
}