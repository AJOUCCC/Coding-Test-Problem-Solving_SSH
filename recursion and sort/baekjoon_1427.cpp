#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(char a, char b){
    return a > b;
}

int main(void){
    string N;
    vector<char> ns;
    cin >> N;
    for(int i = 0; i < N.size(); i++){
        ns.push_back(N[i]);
    }

    sort(ns.begin(), ns.end(), compare);

    for(int i = 0; i < N.size(); i++){
        cout << ns[i];
    }
    cout << "\n";
}