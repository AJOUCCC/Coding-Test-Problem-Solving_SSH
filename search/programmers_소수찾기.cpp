#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt = 0;
int k = 0;
void cnt_prime(vector<pair<bool,bool>> &primes, string numbers, string target){ 
    //소수인지 확인하기
    if(!target.empty()){
        if(primes[stoi(target)].first && !primes[stoi(target)].second){ 
            cnt++;
            primes[stoi(target)].second = true;
        }
        //cout << target << "\n";
    }

    //다음 조합 만들기
    if(!numbers.empty()){
        for(int i = 0; i < numbers.size(); i++){
            char num = numbers[i];
            numbers.erase(i,1);
            target.push_back(num);
            cnt_prime(primes, numbers, target);
            target.pop_back();
            numbers.insert(i, 1, num);
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    //소수 구하기
    vector<pair<bool,bool>> primes = vector<pair<bool,bool>>(10000000, make_pair(true, false));
    primes[0].first = false;
    primes[1].first = false;
    for(int i = 2; i < primes.size(); i++){
        if(!primes[i].first) continue;
        for(int j = 2*i; j < primes.size(); j += i){
            primes[j].first = false;
        }
    }
    
    //종이조각으로 만들 수 있는 소수의 개수 카운팅하기
    cnt_prime(primes, numbers, "");
    answer = cnt;
    return answer;
}