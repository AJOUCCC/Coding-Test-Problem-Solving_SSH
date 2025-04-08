#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    //stack으로 풀기 가능
    stack<int> subCont;
    int target = 0;
    int currBox = 1;
    subCont.push(0);
    while(true){
        //종결조건 = 모든 order를 다 순회하면 끝
        if(target == order.size()) break;
        
        //현재 order > stack의 top이라면, box를 stack에 넣기
        if(order[target] > subCont.top()){
            subCont.push(currBox++);
        }
        //현재 order < stack의 top이라면, 더 이상 상자를 실을 수 없음
        else if(order[target] < subCont.top()){
            break;
        }
        //현재 order == stack의 top이라면, stack의 top을 pop하고 카운팅 1
        else{
            subCont.pop();
            target++;
            answer++;
        }
    }
    return answer;
}