#include <iostream>
#include <vector>
#include <string>
using namespace std;
string c[101][101];

string add(string a, string b){
    //최대 크기 + 1의 배열 선언
    int new_size;
    if(a.size() > b.size()){
        new_size = a.size();
        while(a.size() != b.size())
            b.insert(b.begin(), '0');
    }
    else{
        new_size = b.size();
        while(a.size() != b.size())
            a.insert(a.begin(), '0');
    }

       
    //덧셈 계산
    int up = 0;
    string result;
    for(int i = new_size-1; i >= -1; i--){
        //마지막 올림 자리 때
        if(i == -1){
            if(up != 0)
                result.insert(result.begin(), up +'0');
            break;
        }

        //평소에는...
        int an = a[i]-'0';
        int bn = b[i]-'0';
        int sum = an + bn + up;
        if(sum >= 10){
            up = sum / 10;
            result.insert(result.begin(), sum % 10 +'0');
        }
        else{
            up = 0;
            result.insert(result.begin(), sum +'0');
        }
    }
    return result;
}

string comb(int n, int m){
    //이미 있다면 가져오기
    if(!c[n][m].empty())
        return c[n][m];

    //끝내는 조건
    if(n == m || m == 0){
        c[n][m] = "1";
        return "1";
    }
    
    //파스칼의 삼각형
    string result = add(comb(n-1, m-1), comb(n-1, m));
    c[n][m] = result;
    return result;
}

int main(void){
    int N, M;
    cin >> N >> M;

    //계산 효율을 위한 식 변경
    if(N/2 < M){
        M = N - M;
    }

    //nCm 계산
    string result;
    result = comb(N, M);
    cout << result << "\n";

}