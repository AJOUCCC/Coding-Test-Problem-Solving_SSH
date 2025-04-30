#include <iostream>
#include <vector>
using namespace std;

int INF = 1000000000;
int main(void){
    //입력
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist = vector<vector<int>>(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    for(int i = 1; i < n+1; i++){
        dist[i][i] = 0;
    }

    //플로이드 워셜: 중간점 역할 k를 순회
    //시작점 a 지정 순회
    //종료점 b 지정 순회
    for(int k = 1; k < n+1; k++){
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                //min(dist[i][j], dist[i][k] + dist[k][j])로 업뎃
                if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    //i->j로 가는 모든 경로의 최소 비용 출력
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}   