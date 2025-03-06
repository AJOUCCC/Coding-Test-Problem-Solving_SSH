#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void get_identical(vector<vector<string>> &board,int &count, pair<int,int> curr){
    
    //인접한 것들 중 같은 색을 카운트
    string cur_color = board[curr.first][curr.second];
    if(curr.first > 0 && board[curr.first-1][curr.second].compare(cur_color) == 0)
        count++;
    if(curr.first < board.size()-1 && board[curr.first+1][curr.second].compare(cur_color) == 0)
        count++;
    if(curr.second > 0 && board[curr.first][curr.second-1].compare(cur_color) == 0)
        count++;
    if(curr.second < board.size()-1 && board[curr.first][curr.second+1].compare(cur_color) == 0)
        count++;
    
}

int solution(vector<vector<string>> board, int h, int w) {
    
    //BFS로 인접 색 칠하기
    int count = 0;
    get_identical(board, count, make_pair(h, w));
    
    //count 출력
    return count;
}