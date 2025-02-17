#include <iostream>
using namespace std;

void print(int woods[]){
    for(int i = 0; i < 5; i++){
        cout << woods[i] << " ";
    }
    cout << "\n";
}

int main(void){
    int woods[5];
    for(int i = 0; i < 5; i++){
        cin >> woods[i];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5-i-1; j++){
            if(woods[j] > woods[j+1]){
                int swap = woods[j];
                woods[j] = woods[j+1];
                woods[j+1] = swap;
                print(woods);
            }
        }
    }
}