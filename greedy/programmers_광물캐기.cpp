#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0];
    else if(a[1] != b[1]) return a[1] > b[1];
    else return a[2] < b[2];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    //실제로 캘 광물 수
    int pick_nums = picks[0] + picks[1] + picks[2];
    int avail_mineral_nums = 5 * pick_nums;
    int avail_pick_nums;
    if(avail_mineral_nums <= minerals.size()) avail_pick_nums = pick_nums;
    else avail_pick_nums = (minerals.size() % 5 == 0)? minerals.size() / 5 :minerals.size() / 5 + 1;
    
    //광물 5개씩 묶기
    vector<vector<int>> chunks;
    int i = 0, pick = 0;
    while(i < minerals.size()){
        if(pick >= avail_pick_nums) break;
        int dn = 0, in = 0, rn = 0;
        vector<int> chunk = vector<int>(3, 0);
        for(int j = 0; j < 5; j++){
            if(i > minerals.size()-1) break;
            if(minerals[i].compare("diamond") == 0) chunk[0]++;
            else if(minerals[i].compare("iron") == 0) chunk[1]++;
            else chunk[2]++;
            i++;
        }       
        chunks.push_back(chunk);
        pick++;
    }
    
    //광물 청크를 정렬하기(다이아 많은 순 -> 철 많은 순 -> 돌 많은 순)
    sort(chunks.begin(), chunks.end(), compare);
    
    for(int i = 0; i < chunks.size(); i++){ 
        cout << "dia: " << chunks[i][0] <<  " iron: " << chunks[i][1] <<  " stone: " << chunks[i][2] << "\n";
    }
    
    //광물 청크 순회하기
    for(int i = 0; i < chunks.size(); i++){
        //청크 하나를 캘 곡괭이 정하기(다이아, 철, 돌 순으로)
        if(picks[0] > 0){
            picks[0]--;
            answer += chunks[i][0] + chunks[i][1] + chunks[i][2];
        }
        else if(picks[1] > 0){
            picks[1]--;
            answer += 5 * chunks[i][0] + chunks[i][1] + chunks[i][2];
        }
        else if(picks[2] > 0){
            picks[2]--;
            answer += 25 * chunks[i][0] + 5 * chunks[i][1] + chunks[i][2];
        }
    }
        
    return answer;
}