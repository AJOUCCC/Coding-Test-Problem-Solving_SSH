#include <iostream>
#include <vector>
using namespace std;

void hanoi(int size, int from, int to){
    //만약 size가 1이면 바로 이동
    if(size == 1){
        cout << from << " " << to << "\n"; 
        return;
    }

    //size-1만큼의 탑을 다른 곳으로 옮김
    int another;
    int pos[4];
    for(int i = 0; i < 4; i++)
        pos[i] = i;
    pos[from] = 0;
    pos[to] = 0;
    for(int i = 1; i < 4; i++){
        if(pos[i] != 0) another = i;
    }
    hanoi(size-1, from, another);

    //마지막 원판을 to로 옮김
    cout << from << " " << to << "\n"; 

    //size-1만큼의 탑을 to로 옮김
    hanoi(size-1, another, to);
}

string pow(int N){
    if(N == 1) return "1";

    string pow_before = pow(N-1);
    string result(pow_before);

    //곱하기 2 계산
    int up = 0;
    result.insert(result.begin(), '0');
    for(int i = result.size()-1; i >= 0; i--){
        int sum = up + (result[i] - '0') * 2;
        result[i] =  sum % 10 + '0';
        if(sum >= 10)
            up =  sum / 10;   
        else {
            up = 0;    
        }
    }
    if(result[0] == '0') result.erase(0, 1);
    return result;   
}

string minus1(string value){
    string result(value);
    for(int i = result.size()-1; i >= 0; i--){
        int intVal = result[i] - '0';
        if(intVal == 0){
            result[i] = '9';
            continue;
        }
        else{
            result[i] = intVal - 1 + '0'; 
            break;
        }
    }
    if(result[0] == '0') result.erase(0, 1);
    return result;
}

int main(void){
    int N;
    cin >> N;

    //옮긴 회수는 단순 계산으로 도출 가능(2^N - 1)
    string cnt = minus1(pow(N+1)); 
    cout << cnt << "\n";

    //20이하일때만 출력
    if(N <= 20){
        hanoi(N, 1, 3);
    }   
}
