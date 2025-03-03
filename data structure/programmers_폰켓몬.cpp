#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size() / 2;
    unordered_map<int,int> m;
    m.clear();
    m.reserve(200000);
    for(int i = 0; i < nums.size(); i++){
        unordered_map<int,int>::iterator it = m.find(nums[i]);
        if(it != m.end())
            it->second = it->second + 1;
        else 
            m.insert(make_pair(nums[i], 1));
    }
    
    if(m.size() > size) answer = size;
    else answer = m.size();
    
    return answer;
}