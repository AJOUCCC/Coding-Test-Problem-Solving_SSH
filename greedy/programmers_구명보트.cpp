#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //오름차순으로 정렬(시간 효율을 위함)
    sort(people.begin(), people.end());
    
    //투포인터 준비
    int start = 0;
    int end = people.size()-1;
    
    //사람들 순회
    while(true){ 
        if(start == end){
            answer++;
            break;
        }
        else if(start > end){
            break;
        }
        //혼자 태워 보내기
        else if(people[start] + people[end] > limit){
            answer++;
            end--;
        }
        //둘이 태워보내기
        else if(people[start] + people[end] <= limit){
            start++;
            end--;
            answer++;
        }   
    }
    
    return answer;
}