#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    //숫자, 기호 구분해서 입력받기
    string str;
    cin >> str;
    vector<int> nums;
    bool positive = true;
    int start = 0;
    while(true){
        int findMinus = -1;
        int findPlus = -1;
        if(str.find('-') != string::npos)
            findMinus = str.find('-');
        if(str.find('+') != string::npos)
            findPlus = str.find('+');

        if((findMinus != -1 && findPlus != -1 && findMinus < findPlus) || (findMinus != -1 && findPlus == -1)){
            if(positive)
                nums.push_back(stoi(str.substr(start, str.find('-')-start+1)));
            else
                nums.push_back(-1 * stoi(str.substr(start, str.find('-')-start+1)));
            positive = false;
            str.erase(0, str.find('-')+1);
        }
        else if((findMinus != -1 && findPlus != -1 && findPlus < findMinus) || (findPlus != -1 && findMinus == -1)){
            if(positive)
                nums.push_back(stoi(str.substr(start, str.find('+')-start+1)));
            else
                nums.push_back(-1 * stoi(str.substr(start, str.find('+')-start+1)));
            positive = true;
            str.erase(0, str.find('+')+1);
        }
        else{
            if(positive)
                nums.push_back(stoi(str));
            else
            nums.push_back(-1 * stoi(str));
            break;
        }
    }
  
    //숫자 순회하면서 음수 나오면 그 뒤 연속되는 양수는 모두 음수 처리
    bool make_negative = false;
    long long sum = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 0){
            make_negative = true;
            sum += nums[i];
        }else{
            if(make_negative)
                sum -= nums[i];
            else 
                sum += nums[i];
        }
    }
    cout << sum << "\n";
}