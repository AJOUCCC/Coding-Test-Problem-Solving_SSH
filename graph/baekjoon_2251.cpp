#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> total;
vector<vector<vector<bool>>> visited;
unordered_set<int> quantities;

void water_move(vector<int> water, int from, int to){
    //이미 방문한 상태거나, 물 붓기 불가능한 경우 종료
    //cout << "[water]: " << water[0] << ", " << water[1] << ", " << water[2] << " from: " << from << " to: " << to << "\n";
    if(from == to){
        return;
    } 
    else if(water[from] == 0){
        return;
    } 
    else if(water[to] == total[to]) {
        return;
    }

    //from에서 to로 물 옮기기
    if(water[from] >= total[to] - water[to]){
        water[from] -= total[to] - water[to];
        water[to] = total[to];
    }
    else{
        water[to] += water[from];
        water[from] = 0;     
    }
    
    //A가 비었다면 이때의 C의 양 추가
    if(water[0] == 0)
        quantities.insert(water[2]);

    //또다시 옮길 수 있는 경우 진행
    if(visited[water[0]][water[1]][water[2]])
        return;
    else{
        visited[water[0]][water[1]][water[2]] = true;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                water_move(water, i, j);
    }
}

int main(void){
    //입력
    int A, B, C;
    cin >> A >> B >> C;
    total.push_back(A);
    total.push_back(B);
    total.push_back(C);

    //visited[] 선언
    visited = vector<vector<vector<bool>>>(A+1, vector<vector<bool>>(B+1, vector<bool>(C+1, false)));

    //DFS로 물 붓기 진행
    water_move({0,0,C}, 2, 0);
    water_move({0,0,C}, 2, 1);

    //용량 오름차순으로 정렬 및 출력
    vector<int> quan;
    for(auto quantity : quantities)
        quan.push_back(quantity);
    sort(quan.begin(), quan.end());
    for(auto i = 0; i < quan.size(); i++)
        cout << quan[i] << " ";
    cout << "\n";
}