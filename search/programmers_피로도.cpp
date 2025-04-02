#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> perm;
    for(int i = 0; i < dungeons.size(); i++)
        perm.push_back(i);
    
    int max = 0;
    //다음 조합 보기
    do{
       //현 조합에서 던전 탐험 수 세기
        int lives = k;
        int dnum = 0;
        for(int i = 0; i < perm.size(); i++){
            if(lives < dungeons[perm[i]][0]) break;
            lives -= dungeons[perm[i]][1];
            dnum++;
        }
        
        //최대 던전 탐험 수 업데이트
        if(dnum > max) max = dnum;
        
    }while(next_permutation(perm.begin(), perm.end()));
    
    answer = max;
    return answer;
}