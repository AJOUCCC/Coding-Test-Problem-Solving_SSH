#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){

    //A, B 길이가 같다면 숫자의 합을 비교교
    if(a.size() == b.size()){
        int asum = 0, bsum = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] <= '9' && a[i] >= '0')
                asum += a[i] - '0';
        }
        for(int i = 0; i < b.size(); i++){
            if(b[i] <= '9' && b[i] >= '0')
                bsum += b[i] - '0';
        }

        //숫자의 합도 같다면 사전순 비교교
        if(asum == bsum){
            return a < b;
        }
        else
            return asum < bsum;
    }
    //A,B 길이가 다르다면 짧은 것이 앞으로로
    else
        return a.size() < b.size();
}

int main(void){
    int N;
    cin >> N;
    vector<string> serials;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        serials.push_back(str);
    }

    sort(serials.begin(), serials.end(), compare);

    for(int i = 0; i < N; i++){
        cout << serials[i] << "\n"; 
    }
}