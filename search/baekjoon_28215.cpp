#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    //입력
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> houses = vector<pair<int,int>>(N, make_pair(0,0));
    for(int i = 0; i < N; i++)
        cin >> houses[i].first >> houses[i].second;

    //permuation으로 완전 탐색
    vector<int> perm = vector<int>(N, 1);
    int totalMinDist = 200000;
    for(int i = 0; i < K; i++)
        perm[i] = 0;
    do{
        //대피소 리스트
        vector<int> shelter;
        for(int i = 0; i < perm.size(); i++)
            if(perm[i] == 0) shelter.push_back(i);
        
        //모든 집을 순회
        int maxDist = 0;
        for(int i = 0; i < houses.size(); i++){
            if(perm[i] == 0) continue;
            int minDist = 200000;
            for(int j = 0; j < shelter.size(); j++){
                int dist = abs(houses[shelter[j]].first - houses[i].first) + abs(houses[shelter[j]].second - houses[i].second);
                if(dist < minDist) minDist = dist;
            }
            if(minDist > maxDist) maxDist = minDist;
        }
        if(maxDist < totalMinDist) totalMinDist = maxDist;
    }
    while(next_permutation(perm.begin(), perm.end()));

    //최솟값을 출력
    cout << totalMinDist << "\n";
}