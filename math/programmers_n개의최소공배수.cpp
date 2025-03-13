#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    //100 이하의 소수들 찾기
    vector<pair<int,int>> primes = vector<pair<int,int>>(101, make_pair(0, 0));
    for(int i = 0; i < primes.size(); i++)
        primes[i].first = i;
    primes[1].first = 0;
    for(int i = 2; i < primes.size(); i++){
        if(primes[i].first == 0) continue;
        for(int j = 2*i; j < primes.size(); j += i)
            primes[j].first = 0;
    }
    
    //배열의 수들 순회하며, 소인수분해하고
    //공통되는 부분을 저장하여 최소공배수 만들기
    for(int i = 0; i < arr.size(); i++){
        //1이면 소인수 없음
        if(arr[i] == 1) continue;
        
        //소인수분해
        int followed = 0;
        for(int j = 2; j < primes.size();){
            if(arr[i] == 1) break;
            else if(primes[j].first == 0) {
                j++;
                continue;
            }
            else if(arr[i] % primes[j].first == 0){
                arr[i] = arr[i] / primes[j].first;
                followed++;
                if(followed > primes[j].second)
                    primes[j].second++;
                
            }
            else {
                j++;
                followed = 0;
            }
        }
        
        // cout << "[" << i << "]";
        //  for(int j = 2; j < 10; j++)
        //      cout << primes[j].second << " ";
        // cout << "\n";
    }
    
    //최소공배수 만들기
    answer = 1;
    for(int i = 2; i < primes.size(); i++){
        if(primes[i].first == 0 || primes[i].second == 0) continue;
        for(int j = 0; j < primes[i].second; j++){
            // cout << primes[i].first << " " << answer << "\n";
            answer = answer * primes[i].first;
        }
    }
    
    return answer;
}