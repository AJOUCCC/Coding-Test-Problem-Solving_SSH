#include <string>
#include <vector>

using namespace std;

int cnt = 0;
void dfs(vector<int> &numbers, int curr, int target, int sum){
    //만약 종료 단계라면 target과 sum 비교 후 카운팅
    if(curr == numbers.size()){
        if(sum == target) cnt++;
        return;
    }
    
    //아니라면, 다음 숫자 값 경우의 수 2개 나누어서 전진
    dfs(numbers, curr+1, target, sum + numbers[curr]);
    dfs(numbers, curr+1, target, sum - numbers[curr]);
}

int solution(vector<int> numbers, int target) {
    
    //dfs로 풀기
    dfs(numbers, 0, target, 0);
    
    return cnt;
}