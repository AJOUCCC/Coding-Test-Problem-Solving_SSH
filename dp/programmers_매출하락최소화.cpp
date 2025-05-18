#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<vector<int>> dp;

void search(int curr, vector<int> &sales, vector<vector<int>> &graph){    
    
    //그룹의 팀원들 순회
    int sumOfselection = 0;
    int minGap = 1000000000;
    for(int i = 0; i < graph[curr].size(); i++){
        //재귀적으로 다시 호출
        search(graph[curr][i], sales, graph);  
        sumOfselection += min(dp[graph[curr][i]][0], dp[graph[curr][i]][1]);
        if(dp[graph[curr][i]][1] - dp[graph[curr][i]][0] < minGap) 
            minGap = dp[graph[curr][i]][1] - dp[graph[curr][i]][0];
    }
        
    //dp[curr][0]은 curr이 워크숍 참여안할 시, curr 이하의 최소 매출액
    //dp[curr][1]은 curr이 워크숍 참여할 시, curr 이하의 최소 매출액
    dp[curr][1] = sumOfselection + sales[curr-1];
    dp[curr][0] = sumOfselection;
    if(minGap != 1000000000 && minGap > 0) dp[curr][0] += minGap;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    
    //인접 그래프로 만들기
    vector<vector<int>> graph = vector<vector<int>>(sales.size()+1);
    dp = vector<vector<int>>(sales.size()+1, vector<int>(2, 0));
    for(int i = 0; i < links.size(); i++){
        graph[links[i][0]].push_back(links[i][1]);
    }
    
    //DFS로 1부터 탐색
    search(1, sales, graph);

    return min(dp[1][1], dp[1][0]);
}