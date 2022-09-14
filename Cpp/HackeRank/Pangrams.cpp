//Вам задана строка , состоящая из пробелов и латинских букв. Строка называется панграммой, 
//если она содержит каждую из 26 латинских букв хотя бы раз. 
//Определите является ли строка  панграммой.
//https://www.hackerrank.com/challenges/one-month-preparation-kit-pangrams/problem

#include <iostream>

std::string pangrams(std::string s) {
    std::string isPangram = "pangram";
    bool isPangra = true;
    for(int i = 0; i<=s.size(); i++){
        if (std::isupper(s[i])){
            s[i]=std::tolower(s[i]);
        }
    }
    for(char i = 'a'; i<='z'; i++){
        if (s.find(i)==std::string::npos){
            isPangram = "not pangram";
            return isPangram;
        }
    }
    return isPangram;
}

int main(){
    std:: string str = "We promptly judged antique ivory buckles for the next prize";
    std::cout<<pangrams(str)<<std::endl;
    str = "We promptly judged antique ivory buckles for the prize";
    std::cout<<pangrams(str)<<std::endl;
}