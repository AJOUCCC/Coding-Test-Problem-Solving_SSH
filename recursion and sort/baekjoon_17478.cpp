#include <iostream>
using namespace std;

void underbar(int i){
    for(int j = 0; j < i; j++)
        cout << "____";
}

void recursive(int i, int size){
   
    underbar(i);
    cout << "\"����Լ��� ������?\"\n";
    if(i == size){
        underbar(i);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    else {
        underbar(i);
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        underbar(i);
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        underbar(i);
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        recursive(i+1, size);
    }
    underbar(i);
    cout << "��� �亯�Ͽ���.\n";
    
}

int main(void){
    int N;
    cin >> N;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursive(0, N);
}