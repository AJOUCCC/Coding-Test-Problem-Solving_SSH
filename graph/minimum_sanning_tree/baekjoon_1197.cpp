#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
int find(int a);

void union_f(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int find(int a){
    //만약 자기 자신이 대표라면 리턴
    if(parent[a] == a) return a;

    //아니라면 정리 후 리턴
    return parent[a] = find(parent[a]);
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int main(void){
    //입력
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges = vector<vector<int>>(E, vector<int>(3, 0));
    parent = vector<int>(V+1, 0);
    for(int i = 0; i < V+1; i++)
        parent[i] = i;
    for(int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    //엣지를 오름차순 정렬
    sort(edges.begin(), edges.end(), compare);

    //엣지 순회
    int added_edge = 0;
    int sum = 0;
    for(int i = 0; i < E; i++){
        //추가된 엣지 수가 V-1개이면 종료
        if(added_edge == V-1) break;
        
        //find(a) != find(b) 이면 현 엣지 추가(union)
        if(find(edges[i][0]) != find(edges[i][1])){
            union_f(edges[i][0], edges[i][1]);
            added_edge++;
            sum += edges[i][2];
        }
    }

    //가중치 출력
    cout << sum << "\n";
}