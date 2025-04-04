#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
     
    //유클리드 호제법으로 arrayA, B의 최대공약수 찾기
    sort(arrayA.begin(), arrayA.end(), compare);
    sort(arrayB.begin(), arrayB.end(), compare);
    int aGCB = arrayA[0], bGCB = arrayB[0];
    for(int i = 0; i < arrayA.size()-1; i++){
        int quo = aGCB, rem = arrayA[i+1];
        if(rem > quo){
            int temp = quo;
            quo = rem;
            rem = temp;
        }
        while(rem != 0){
            //cout << "quo: " << quo << " rem: " << rem << "\n";
            int temp = rem;
            rem = quo % rem;
            quo = temp;       
        }
        aGCB = quo;
    }
    for(int i = 0; i < arrayB.size()-1; i++){
        int quo = bGCB, rem = arrayB[i+1];
        if(rem > quo){
            int temp = quo;
            quo = rem;
            rem = temp;
        }
        while(rem != 0){
            int temp = rem;
            rem = quo % rem;
            quo = temp;
        }
        bGCB = quo;
    }
 
    //cout << "aGCB: " << aGCB << " bGCB: " << bGCB << "\n";
    
    //a 값 구하기
    bool aGCBValid = true, bGCBValid = true;
    for(int i = 0; i < arrayA.size(); i++){
        if(arrayA[i] % bGCB == 0 || bGCB == 1){
            bGCBValid = false;
            break;
        }
    }
    for(int i = 0; i < arrayB.size(); i++){
        if(arrayB[i] % aGCB == 0|| aGCB == 1){
            aGCBValid = false;
            break;
        }
    }
    if(aGCBValid && bGCBValid) return (aGCB > bGCB)? aGCB : bGCB;
    else if(aGCBValid && !bGCBValid) return aGCB;
    else if(!aGCBValid && bGCBValid) return bGCB;
    else return 0;
    return 0;
}