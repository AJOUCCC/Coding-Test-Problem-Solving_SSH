#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    //permuatation할 배열 초기화
    vector<int> perm = vector<int>(n, 0);
    for(int i = n-5; i < n; i++){
        perm[i] = 1;
    }
    
    //다음 permutation을 호출해서 q 정보들과 모두 match되는지 확인
    do{
        vector<int> answer_vals;
        int k = 0;
        //cout << "next_perm is...\n";
        for(int i = 0; i < n; i++){
            if(perm[i] == 1)
                answer_vals.push_back(i+1);
        }
       
        bool match_all = true;
        for(int i = 0; i < q.size(); i++){
            int cnt = 0;
            for(int j = 0; j < 5; j++){
                if(q[i][j] == answer_vals[0] || q[i][j] == answer_vals[1] || q[i][j] == answer_vals[2] || q[i][j] == answer_vals[3] || q[i][j] == answer_vals[4]){
                    cnt++;
                }
            }
            if(cnt != ans[i]){
                match_all = false;
                break;
            }                                                           
        }
        if(match_all)
            answer++;
    }while(next_permutation(perm.begin(), perm.end()));
    return answer;
}