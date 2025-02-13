#include <iostream>
#include <vector>
using namespace std;
int blueCount = 0;
int whiteCount = 0;
void make_paper(int (*paper)[128], int size, pair<int, int> start, pair<int, int> end){
    //cout << "make_paper, size: " << size << " start: (" << start.first << ", " << start.second << ") end: (" << end.first << ", " << end.second << ")\n";
    //종이가 모두 같은 색인지 확인인
    bool success = true;
    int color = paper[start.first][start.second];
    for(int i = start.first; i <= end.first; i++){
        if(success == false) break;
        for(int j = start.second; j <= end.second; j++){
            if(paper[i][j] != color){
                success = false;
                break;
            }
        }
    }

    //같은 색이라면 끝내기
    if(success){
        if(color == 0) whiteCount++;
        else blueCount++;
        return;
    }

    //아니라면 종이를 4개로 나누기
    int new_size = size/2;
    make_paper(paper, new_size, make_pair(start.first, start.second), make_pair(start.first + new_size -1, start.second + new_size -1));
    make_paper(paper, new_size, make_pair(start.first + new_size, start.second), make_pair(start.first + new_size*2 -1, start.second + new_size -1));
    make_paper(paper, new_size, make_pair(start.first, start.second + new_size), make_pair(start.first + new_size -1, start.second + new_size*2 -1));
    make_paper(paper, new_size, make_pair(start.first + new_size, start.second + new_size), make_pair(start.first + new_size*2 -1, start.second + new_size*2 -1));
}

int main(void){
    
    //입력
    int N;
    cin >> N;
    int paper[128][128];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }

    //재귀적으로 색종이 수 count
    make_paper(paper, N, make_pair(0, 0), make_pair(N-1, N-1));

    //count 출력
    cout << whiteCount << "\n";
    cout << blueCount << "\n";

}