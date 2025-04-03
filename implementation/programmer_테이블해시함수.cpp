#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int criterion_col;
bool compare(vector<int> a, vector<int> b){
    if(a[criterion_col] == b[criterion_col])
        return a[0] > b[0];
    else
        return a[criterion_col] < b[criterion_col];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    //테이블을 col번째 컬럼 기준으로 정렬
    criterion_col = col-1;
    sort(data.begin(), data.end(), compare);
   
    //각 행마다 Si값을 구하기
    int hash = 0;
    for(int i = row_begin-1; i < row_end; i++){
        int Si = 0;
        for(int j = 0; j < data[i].size(); j++){
            Si += data[i][j] % (i+1);
        }
        cout << Si << "\n";
        hash = hash ^ Si;
    }
    
    answer = hash;
    return answer;
}