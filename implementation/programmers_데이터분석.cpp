#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string rsort_by;
bool compare(vector<int> a, vector<int> b){
    int sort_idx;
    if(rsort_by.compare("code") == 0) sort_idx = 0;
    else if(rsort_by.compare("date") == 0) sort_idx = 1;
    else if(rsort_by.compare("maximum") == 0) sort_idx = 2;
    else sort_idx = 3;
    return a[sort_idx] < b[sort_idx];
   
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    //ext 기준에 맞는 정보만 answer 벡터에 담기
    int ext_idx;
    if(ext.compare("code") == 0) ext_idx = 0;
    else if(ext.compare("date") == 0) ext_idx = 1;
    else if(ext.compare("maximum") == 0) ext_idx = 2;
    else ext_idx = 3;
    for(int i = 0; i < data.size(); i++)
      if(data[i][ext_idx] < val_ext) answer.push_back(data[i]);
    
    
    //sort_by에 따라 오름차순 정렬하기
    rsort_by = sort_by;
    sort(answer.begin(), answer.end(), compare);
    return answer;
}