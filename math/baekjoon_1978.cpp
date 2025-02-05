#include <iostream>
using namespace std;

int main(void){

    //입력 받을 변수 선언
    int N, num, total = 0;
    cin >> N;
    
    //N개의 수 하나씩 살펴보기
    for(int i = 0;i < N; i++){
        bool sosu = true;
        cin >> num;
        
        //2~num-1까지의 수로 나누어 떨어지는 경우가 있다면, 소수가 아님
        if(num == 1){ 
            sosu = false;
        }
        else{
            for(int j = 2; j < num; j++){
                if(num % j == 0){
                    sosu = false;
                    break;
                } 
            }
        }
       
        //소수라면 카운팅
        if(sosu == true)
            total++;
        
    }

    //출력
    cout << total << endl;
}