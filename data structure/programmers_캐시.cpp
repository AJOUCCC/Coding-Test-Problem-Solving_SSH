#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    //캐시 구현
    unordered_map<string, int> cache;
    
    for(int i = 0; i < cities.size(); i++){
        //대문자로 변환
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        
        //캐시에서 찾고 miss라면, hit라면...
        if(cache.find(cities[i]) == cache.end()){
            
            //캐시사이즈가 0이라면 아무동작 안하기(희귀케이스 커버를 위함, 중요!!)
            if(cacheSize == 0){}
            //cache에 남은 공간이 있다면 채우기
            else if(cache.size() < cacheSize)
                cache.insert(make_pair(cities[i], i));
            //없다면 LRU를 빼고 채우기
            else{
                string LRU;
                int LRUval = 2000000000;
                for(auto i = cache.begin(); i != cache.end(); i++){
                    if(i->second < LRUval){
                        LRU = i->first;
                        LRUval = i->second;
                    } 
                }
                
                cache.erase(LRU);
                cache.insert(make_pair(cities[i], i));
            }
            
            //실행시간 업데이트
            answer += 5;
        }
        else{ 
            //hit, 해당 캐시의 timestamp 업데이트
            auto target = cache.find(cities[i]);
            target->second = i;
            
            //실행시간 업데이트
            answer += 1;
        }
    }
    return answer;
}