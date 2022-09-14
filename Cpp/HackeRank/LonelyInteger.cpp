// Given an array of integers, where all elements but one occur twice, find the unique element.
//https://www.hackerrank.com/challenges/one-month-preparation-kit-lonely-integer/problem
#include <vector>
#include <map>
#include <iostream>
int lonelyinteger(std::vector<int> a) {
    int lonelyInteger;
    std::map<int, int> queriesMap;
    for (int i = 0; i < a.size(); i++){
        queriesMap[a[i]] = 0;
    }
    for (int i = 0; i < a.size(); i++){
        queriesMap[a[i]]++;
    }
    std::map <int, int> :: iterator it = queriesMap.begin();
    for (; it != queriesMap.end(); it++) {
        if (it->second == 1){
            lonelyInteger = it->first;
        }
    }
    return lonelyInteger;
}

int main(){
    std::vector<int> array = {1, 2, 3, 4, 3, 2, 1};
    std::cout<<lonelyinteger(array)<<std::endl;
    
}