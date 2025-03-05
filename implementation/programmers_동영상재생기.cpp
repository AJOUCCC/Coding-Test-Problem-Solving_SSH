#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int curr_time = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int last_time = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int op_start_time = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int op_end_time = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
   
    for(string command : commands){
        if(command.compare("prev") == 0){
            if(curr_time >= op_start_time && curr_time <= op_end_time)
                curr_time = op_end_time;  
            if(curr_time < 10)
                curr_time = 0;
            else
                curr_time -= 10; 
            if(curr_time >= op_start_time && curr_time <= op_end_time)
                curr_time = op_end_time;  
        }
        else if(command.compare("next") == 0){
            if(curr_time >= op_start_time && curr_time <= op_end_time)
                curr_time = op_end_time;  
            curr_time += 10;
            if(curr_time > last_time)
                curr_time = last_time;
            if(curr_time >= op_start_time && curr_time <= op_end_time)
                curr_time = op_end_time;  
        }
        else{
            cout << "error cmd\n"; 
        }
    }
    int hour = curr_time / 60;
    int second = curr_time % 60;
    string hour_s, second_s;
    if(hour == 0) hour_s = "00";
    else if(hour < 10) hour_s = to_string(hour).insert(0, "0");
    else hour_s = to_string(hour);
    if(second == 0) second_s = "00";
    else if(second < 10) second_s = to_string(second).insert(0, "0");
    else second_s = to_string(second);
    answer = hour_s.append(":").append(second_s);
    return answer;
}