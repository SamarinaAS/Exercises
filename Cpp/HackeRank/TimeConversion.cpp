// Given a time in -hour AM/PM format, convert it to military (24-hour) time.

// Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
// - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
//https://www.hackerrank.com/challenges/one-month-preparation-kit-time-conversion/problem

#include <iostream>

std::string timeConversion(std::string s) {
    std::string format24;
    std::string tempP = "P";
    std::string tempA = "A";
    int intHour = stoi(s.substr(0, 2));   
    if (s[s.length()-2]==tempP[0]){
        format24 = s.substr(0, s.length()-2);
        if (intHour<12){
            intHour+=12;
            format24 = std::to_string(intHour).length()< 2 ? "0"+std::to_string(intHour)+ 
            format24.substr(2, format24.length()) : std::to_string(intHour) + format24.substr(2, format24.length());
        }                
        return format24;
    }else if (s[s.length()-2]==tempA[0]){
        format24 = s.substr(0, s.length()-2);
        if (intHour>=12){
            intHour=12+intHour-24;
            format24 = std::to_string(intHour).length()< 2 ? "0"+std::to_string(intHour)+ 
            format24.substr(2, format24.length()) : std::to_string(intHour) + format24.substr(2, format24.length());
        }
        return format24;
    }
    return "";
}

int main(){
    std::string time = "07:05:45PM";
    std:: cout << timeConversion(time) <<std::endl;
    time = "07:05:45AM";
    std:: cout << timeConversion(time) <<std::endl;
    return 0;
}