#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    //want를 순회하며 해시에 저장
    unordered_map<string, pair<int,int>> hash;
    for(int i = 0; i < want.size(); i++){
        hash.insert(make_pair(want[i], make_pair(number[i], 0)));
    }
    
    //10개의 discount 목록을 해시에 적용
    for(int i = 0; i < 10; i++){
        if(hash.find(discount[i]) != hash.end()){
            hash.find(discount[i])->second.second++;
        }
    }
    
    //discount.size() - 9번 순회
    for(int i = 0; i < discount.size() - 9; i++){
        //cout << "i : " << i << "\n";
        //want == curr라면 카운팅
        bool isValid = true;
        for(auto j = hash.begin(); j != hash.end(); j++){
            //cout << j->first << ": " << j->second.first << ", " << j->second.second << "\n";
            if(j->second.first > j->second.second) 
                isValid = false;
        }
        if(isValid) answer++;
        if(i == discount.size()-10) break;
    
        //discount 아이템 하나 빼고 하나 추가
        if(hash.find(discount[i]) != hash.end()){
            hash.find(discount[i])->second.second--;
        }
        if(hash.find(discount[i+10]) != hash.end()){
            hash.find(discount[i+10])->second.second++;
        }
    }
    
    return answer;
}