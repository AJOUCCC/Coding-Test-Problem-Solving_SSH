#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    vector<int> nums;
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < N; i++){
        int X;
        cin >> X;
        nums.push_back(X);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\n";
    }
    
}