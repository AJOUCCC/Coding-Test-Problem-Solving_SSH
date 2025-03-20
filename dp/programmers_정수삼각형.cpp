#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //순회하면서 정보 저장
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            //왼쪽 부모가 있다면 값 가져오기
            int leftSum = 0, rightSum = 0;
            if(i > 0 && j > 0) leftSum = triangle[i-1][j-1];
            //오른쪽 부모가 있다면 값 가져오기
            if(i > 0 && j != triangle[i].size()-1) rightSum = triangle[i-1][j];
            //둘 중 더 큰 값 + 자신을 저장하기
            triangle[i][j] += (leftSum > rightSum)? leftSum : rightSum;
        }
    }

    //마지막 줄에서 가장 최대값 가져오기
    int max = 0;
    for(int i = 0; i < triangle[triangle.size()-1].size(); i++){
        if(triangle[triangle.size()-1][i] > max) max = triangle[triangle.size()-1][i];
    }
    answer = max;
    return answer;
}