#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    //택배 쌓아올리기
    int n_quotient = n / w;
    int boxes_row_num = (n % w == 0)? n / w : n / w + 1;
    vector<vector<int>> boxes = vector<vector<int>>(boxes_row_num, vector<int>(w, 0));
    int r = 0, c = 0;
    bool goRight = true;
    for(int i = 1; i <= n; i++){
        boxes[r][c] = i;
        if(goRight && c == w-1){
            r++;
            goRight = false;
        }
        else if(!goRight && c == 0){
            r++;
            goRight = true;
        }
        else if(goRight)
            c++;
        else if(!goRight)
            c--;  
    }
    
    // for(int i = 0; i < boxes.size(); i++){
    //     for(int j = 0; j < w; j++){
    //         cout << boxes[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    //column 값만 구해서 꺼낼 택배 수 구하기
    int column = -1;
    for(int i = 0; i < boxes.size(); i++)
        for(int j = 0; j < w; j++)
            if(boxes[i][j] == num)
                column = j;
    for(int i = 0; i < boxes.size(); i++)
        if(boxes[i][column] >= num)
            answer++;    
    
    return answer;
}