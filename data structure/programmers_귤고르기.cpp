#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    //해시에 귤 크기마다 저장
    unordered_map<int,int> hash;
    for(int i = 0; i < tangerine.size(); i++){
        if(hash.find(tangerine[i]) != hash.end()){
            hash.find(tangerine[i])->second++;
        }
        else{
            hash.insert(make_pair(tangerine[i],1));
        }
    }
    
    //해시 귤 개수 기준 내림차순 정렬
    vector<pair<int,int>> pairs;
    for(auto item = hash.begin(); item != hash.end(); item++){
        pairs.push_back(make_pair(item->first, item->second));
    }
    sort(pairs.begin(), pairs.end(), compare);
    
    //앞에서부터 더해가다 총 개수 k이상이면 종료
    int nums = 0, sum = 0;
    for(int i = 0; i < pairs.size(); i++){
        sum += pairs[i].second;
        nums++;
        if(sum >= k) break;
    }
    
    answer = nums;
    return answer;
}