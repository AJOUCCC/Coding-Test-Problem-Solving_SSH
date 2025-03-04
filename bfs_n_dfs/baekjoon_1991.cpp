#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<pair<int,int>> &graph, int curr){
    //방문 처리
    char node = curr + 'A';
    cout << node;

    //왼쪽 자식 방문
    if(graph[curr].first != -1)
        preorder(graph, graph[curr].first);

    //오른쪽 자식 방문
    if(graph[curr].second != -1)
        preorder(graph, graph[curr].second);
}

void inorder(vector<pair<int,int>> &graph, int curr){
    //왼쪽 자식 방문
    if(graph[curr].first != -1)
        inorder(graph, graph[curr].first);

    //방문 처리
    char node = curr + 'A';
    cout << node;

    //오른쪽 자식 방문
    if(graph[curr].second != -1)
        inorder(graph, graph[curr].second);
}

void postorder(vector<pair<int,int>> &graph, int curr){
    //왼쪽 자식 방문
    if(graph[curr].first != -1)
        postorder(graph, graph[curr].first);

    //오른쪽 자식 방문
    if(graph[curr].second != -1)
        postorder(graph, graph[curr].second);

    //방문 처리
    char node = curr + 'A';
    cout << node;
}

int main(void){
    int N;
    cin >> N;
    vector<pair<int,int>> graph = vector<pair<int,int>>(N, make_pair(-1,-1));
    for(int i = 0; i < N; i++){
        char parent, left, right;
        int lI = -1, rI = -1;
        cin >> parent >> left >> right;
        if(left != '.') lI = left - 'A';
        if(right != '.') rI = right - 'A';
        graph[parent - 'A'] = make_pair(lI, rI);
    }

    //전위 순회
    preorder(graph, 0);
    cout << "\n";

    //중위 순회
    inorder(graph, 0);
    cout << "\n";

    //후위 순회

    postorder(graph, 0);
    cout << "\n";
}