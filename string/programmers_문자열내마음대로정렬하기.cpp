#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int idx;
bool compare(string a, string b){
    cout << a << " " << b << " " << a.compare(b) << "\n";
    int m = a < b;
    cout << a << " " << b << " " << m << "\n";
    if(a[idx] == b[idx])
        return (a.compare(b) < 0)? true: false;
    else 
        return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    stable_sort(strings.begin(), strings.end(), compare);
    answer = strings;
    return answer;
}