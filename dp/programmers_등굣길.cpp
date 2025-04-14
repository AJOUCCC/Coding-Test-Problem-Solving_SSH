#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //DP로 풀기(경우의 수를 저장)
    vector<vector<bool>> isValid = vector<vector<bool>>(n, vector<bool>(m, true));
    for(int i = 0; i < puddles.size(); i++)
        isValid[puddles[i][1]-1][puddles[i][0]-1] = false;
    vector<vector<int>> ways = vector<vector<int>>(n, vector<int>(m, 0));
    ways[0][0] = 1;
    
    //n,m을 모두 순회
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //웅덩이라면 넘어가기
            if(!isValid[i][j]) continue;
            
            //(n,m)에서 오른쪽, 아래로 이동가능하다면, 이동한 좌표의 ways += 현 ways
            if(i < n-1 && isValid[i+1][j]) 
                ways[i+1][j] = (ways[i][j] + ways[i+1][j]) % 1000000007;
            if(j < m-1 && isValid[i][j+1])
                ways[i][j+1] = (ways[i][j] + ways[i][j+1]) % 1000000007;
        }
    }
    
    //출력
    answer = ways[n-1][m-1];   
    return answer;
}