#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int quotient, remainder;
    while(quotient != 0){
        quotient = n / 3;
        remainder = n % 3;
        
        //나머지가 0일 경우에는 3으로 만들기
        if(remainder == 0){
            quotient = quotient - 1;
            remainder = 3;
        }
        
        //나머지에 따라 숫자 1,2,4 push
        switch(remainder){
            case 1: 
                answer.insert(answer.begin(), '1');
                break;
            case 2:
                answer.insert(answer.begin(), '2');
                break;
            case 3:
                answer.insert(answer.begin(), '4');
                break;
            default:
                break;
        }
        n = quotient;
    }
    return answer;
}