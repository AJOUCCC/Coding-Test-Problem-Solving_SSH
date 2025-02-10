#include <iostream>
#include <vector>
#include <string>
using namespace std;

string mult(string n1, string n2){
    //계산을 위한 n2 x n1+n2-1 배열 선언
    vector<vector<int>> mult_matrix(n2.size(), vector<int>(n1.size() + n2.size() -1, 0));
    
    for(int i = n1.size() - 1; i > 0; i--){
        for(int j = n2.size() - 1; j > 0; j--){
            int rn1 = n1[i] - '0';
            int rn2 = n2[j] = '0';
            mult_matrix[j][i+j] = rn1 * rn2;
        }
    }

    //각각의 곱셈된 것을 합치기
    string new_num;
    int over_number = 0;
    for(int i = n1.size() + n2.size() -1; i > 0; i--){
        int sum = 0;
        for(int j = n2.size() - 1; j > 0; j--){
            sum += mult_matrix[j][i];
        } 
        sum += over_number;

        if(sum > 10){
            over_number = sum / 10;
            sum = sum % 10;
        } 

        new_num.push_back(sum + '0');
    }

    return new_num;
}

char* div(char* n1, char* n2){

}

string fatorial(string n){
  
    if(n.size() <= 1 && n[0]-'0' == 0) return n; 
    else{
        string lower_str(n);
        int end = lower_str.size()-1;
        if(lower_str[end] % 10 != 0){
            lower_str[end] = lower_str[end] % 10 - 1;
        }
        else{
            lower_str[end-1] = lower_str[end-1] - 1;
        }
        return mult(n, factorial(lower_str));
    }
}

int main(void){
    int N, M;
    cin >> N >> M;

    //계산 효율을 위한 식 변경
    if(M > 50){
        M = 100 - M;
    }

    //nCm 계산
    unsigned long long big = 1;
    unsigned long long small = 1;
    int temp = N;
    for(int i = M; i > 1; i--){
        small *= i;
    }
    for(int i = 0; i < M; i++){
        big *= temp--;
        for(int j = 0; j < M; j++){
            if(smalls[j+1] != 0 && big % smalls[j+1] == 0) {
                big /= smalls[j+1];
                smalls[j+1] = 0;
            }
        }
    }
    cout << big << endl;

}