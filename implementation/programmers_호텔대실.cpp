#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    //예약 정보 정수로 바꾸기
    vector<pair<int,int>> books = vector<pair<int,int>>(book_time.size(), make_pair(0,0));
    for(int i = 0; i < books.size(); i++){
        books[i].first = stoi(book_time[i][0].substr(0,2)) * 60 + stoi(book_time[i][0].substr(3,2));
        books[i].second = stoi(book_time[i][1].substr(0,2)) * 60 + stoi(book_time[i][1].substr(3,2));
    }
    
    //시작시간 오름차순으로 정렬
    sort(books.begin(), books.end());
    
    //예약 정보를 순회하며 해당 예약 정보를 올바른 객실에 배정
    vector<int> rooms;
    for(int i = 0; i < books.size(); i++){
        //객실들을 순회하며 예약시작시간 >= 객실 종료시간인 곳에 배정
        bool needNewRoom = true;
        for(int j = 0; j < rooms.size(); j++){
            if(books[i].first >= rooms[j]){
                rooms[j] = books[i].second + 10;
                needNewRoom = false;
                cout << "room #" << j << " with booking #" << i << "\n";
                break;
            }
        }
        //그런 객실이 없다면 새 객실 생성
        if(needNewRoom){
            cout << "room #" << rooms.size() << " newly created\n";
            rooms.push_back(books[i].second + 10);
        }
    }
    
    answer = rooms.size();
    return answer;
}