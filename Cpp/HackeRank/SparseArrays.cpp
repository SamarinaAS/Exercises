// There is a collection of input strings and a collection of query strings. For each query string, 
// determine how many times it occurs in the list of input strings. Return an array of the results.
// https://www.hackerrank.com/challenges/one-month-preparation-kit-sparse-arrays/problem
#include <iostream>
#include <vector>
#include <map>

std::vector<int> matchingStrings(std::vector<std::string> strings, std::vector<std::string> queries) {
    std::vector <int> result (queries.size());
    std::map<std::string, int> queriesMap;
    for (int i = 0; i < queries.size(); i++){
        queriesMap[queries[i]] = 0;
    }
    for (int i=0; i<strings.size(); i++){
        if(queriesMap.find(strings[i])!=queriesMap.end()){
            queriesMap[strings[i]]++;
        }
    }
    for (int i = 0; i < queries.size(); i++){
        result[i]=queriesMap[queries[i]];
    }
    return result;
}


int main(){
    std::vector <std::string> str = {"aba", "baba", "aba", "xzxb"};
    std::vector <std::string> queries = {"aba", "xzxb", "ab"};
    std::vector <int> result = matchingStrings (str, queries);
    for (int i = 0; i<result.size(); i++){
        std::cout <<result[i]<<" ";
    }
}