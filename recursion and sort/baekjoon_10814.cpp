#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b){
    //a가 작으면 -> 오름차순
    return a.first < b.first;
}

int main(void){
    int N;
    vector<pair<int, string>> mans;
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age >> name;
        mans.push_back(make_pair(age, name));
    }

    stable_sort(mans.begin(), mans.end(), compare);
    for(int i = 0; i < N; i++){
        cout << mans[i].first << " " << mans[i].second << "\n";
    }

}