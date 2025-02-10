#include <iostream>
#include <vector>
#include <string>
using namespace std;

void push_factor(vector<pair<int, int>>* factors, int factor){
    for(int i = 0; i < factors->size(); i++){
        if(factors->at(i).first == factor){
            factors->at(i).second++;
            return;
        }
    }
    factors->push_back(make_pair(factor, 1));
}

string mult_big(string n1, string n2){
    //n2 x n1+n2 크기의 벡터 생성
    vector<vector<int>> mult_matrix(n2.size(), vector<int>(n1.size() + n2.size(), 0));

    //한 자리씩 계산하여 매트릭스 채움
    for(int i  = 0; i < n1.size(); i++){
        for(int j = 0; j < n2.size(); j++){
            int nn1 = n1[n1.size()-1-i] - '0';
            int nn2 = n2[n2.size()-1-j] - '0';
            mult_matrix[j][i+j] = nn1 * nn2;
        }
    }

    //합계 계산(올림)
    string result;
    int up = 0;
    for(int i = 0; i < n1.size() + n2.size(); i++){
        int sum = up;
        for(int j = 0; j < n2.size(); j++)
            sum += mult_matrix[j][i];
        if(sum >= 10)
            up = sum / 10;
        else 
            up = 0;
        result.insert(result.begin(), sum % 10 + '0'); 
    }
    if(result.at(0) == '0') result.erase(0, 1);
    
    //결과 리턴
    return result;
}

int main(void){
    //입력
    int N, M;
    cin >> N;
    int n[N];
    for(int i = 0; i < N; i++){
        cin >> n[i];
    }
    cin >> M;
    int m[M];
      for(int i = 0; i < M; i++){
        cin >> m[i];
    }

    //소인수 담을 pair 각각 생성
    vector<pair<int, int>> nFactors; 
    vector<pair<int, int>> mFactors;
    
    //범위 내의 int를 순회하며 소인수분해
    for(int i = 2; i < 1000000000; i++){
        for(int j = 0; j < N; j++){    
            if(n[j] == 1) continue;
            while(n[j] % i == 0){
                push_factor(&nFactors, i);
                n[j] /= i;
            }
        }  
        for(int j = 0; j < M; j++){    
            if(m[j] == 1) continue;
            while(m[j] % i == 0){
                push_factor(&mFactors, i);
                m[j] /= i;
            }
        }  
    }

    //공통된 인수들 추출
    vector<pair<int, int>> idFactors; 
    for(int i = 0; i < nFactors.size(); i++){
        for(int j = 0; j < mFactors.size(); j++){
            if(nFactors[i].first == mFactors[j].first){
                if(nFactors[i].second >= mFactors[j].second)
                    idFactors.push_back(make_pair(nFactors[i].first, mFactors[j].second));
                else
                    idFactors.push_back(make_pair(nFactors[i].first, nFactors[i].second));
            }
        }
    }

    //큰 수의 곱셈
    string result = "1";
    for(int i = 0; i < idFactors.size(); i++){
        for(int j = 0; j < idFactors[i].second; j++){
            string factor_to_str = to_string(idFactors[i].first);
            result = mult_big(result, factor_to_str);
        }
    }

    //결과 출력
    if(result.size() > 9){
        string result_9 = result.substr(result.size()-9, 9);
        cout << result_9 << "\n";
    }
    else{
        cout << result << "\n";
    }
    
}