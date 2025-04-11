#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    //모든 전화번호 해시에 저장
    unordered_set<string> hash;
    for(int i = 0; i < phone_book.size(); i++)
        hash.insert(phone_book[i]);
    
    //phone_book 순회
    for(int i = 0; i < phone_book.size(); i++)
    {
        //전화번호 길이 1씩 늘려가며 해시로 find
        for(int j = 1; j < phone_book[i].size(); j++){
            if(hash.find(phone_book[i].substr(0, j)) != hash.end())
                return false;
        }     
    }
        
    return true;
}