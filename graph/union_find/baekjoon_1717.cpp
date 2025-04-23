#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;

int find(int a){
    //a의 대표노드가 자기 자신이라면
    if(parent[a] == a) return a;
    
    //아니라면
    return parent[a] = find(parent[a]);
}

void union_f(int a, int b){
    parent[find(a)] = find(b); 
}

int main(void){
    //시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, m;
    cin >> n >> m;
    parent = vector<int>(n+1, 0);
    for(int i = 0; i < n+1; i++)
        parent[i] = i;

    //m번의 연산 반복
    for(int i = 0; i < m; i++){
        int k, a, b;
        cin >> k >> a >> b;

        //0으로 시작 시 union
        if(k == 0){
            union_f(a, b);
        }
        //1로 시작 시 find 결과 출력
        else{
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }   
    }
}