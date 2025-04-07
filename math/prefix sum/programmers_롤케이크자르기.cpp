#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    //메모이제이션으로 풀기
    vector<int> older = vector<int>(10001, 0);
    vector<int> younger = vector<int>(10001, 0);
    int onum = 0, ynum = 0;
    
    //일단 동생에게 모두 주기로 초기화
    for(int i = 0; i < topping.size(); i++){
        if(younger[topping[i]] == 0) ynum++;
        younger[topping[i]]++;
    }
    
    //칸 한칸씩 옮겨가며 케이크 자르고, 공평한지 판단
    for(int i = 0; i < topping.size(); i++){
        younger[topping[i]]--;
        older[topping[i]]++;
        if(younger[topping[i]] == 0) ynum--;
        if(older[topping[i]] == 1) onum++;
        
        //cout << "topping: " << topping[i] << " onum: " << onum << " ynum: " << ynum << "\n"; 
        if(onum == ynum) answer++;
    }
    return answer;
}