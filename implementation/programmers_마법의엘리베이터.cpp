#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    //낮은 자리수부터 하나씩 순회, storey가 0이 될때까지 반복
    for(int i = 0; storey != 0; i++){
        int target = (storey / (int)pow(10, i)) % 10;
        
        //현 자리수 값이 1~4라면 -, 6~9라면 +, 5라면 따로 처리
        if(target >= 1 && target <= 4){
            answer += target;
            storey -= target * pow(10, i);
        }
        else if(target >= 6 && target <= 9){
            answer += (10 - target);
            storey += (10 - target) * pow(10, i);
        } 
        else if(target == 5){
            
            //5라면 이후의 숫자들을 보고 올릴리 내릴지 결정
            bool isPlus = false;
            for(int ii = i+1; ; ii++){
                if((storey / (int)pow(10, ii)) == 0) break;
                int t = (storey / (int)pow(10, ii)) % 10;
                if(t >= 0 && t <= 4){
                    isPlus = false;
                    break;
                }
                else if(t >= 6 && t <= 9){
                    isPlus = true;
                    break;
                }
                else{
                    isPlus = true;
                }
            }
            if(!isPlus){
                answer += target;
                storey -= target * pow(10, i);
            }
            else{
                answer += (10 - target);
                storey += (10 - target) * pow(10, i);
            }
        }
    }
        
    return answer;
}