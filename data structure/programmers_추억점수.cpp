#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    //해시에 그리워하는 사람들 정보 저장
    unordered_map<string, int> yearn_people;
    for(int i = 0; i < name.size(); i++){
        yearn_people.insert(make_pair(name[i], yearning[i]));
    }
    
    //photo마다 추억 점수 집계
    for(int i = 0; i < photo.size(); i++){
        int score = 0;
        for(int j = 0; j < photo[i].size(); j++){
            auto target = yearn_people.find(photo[i][j]);
            if(target == yearn_people.end()) continue;
            else
                score += target->second;
        }
        answer.push_back(score);
    }
    return answer;
}