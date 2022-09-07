// Given five positive integers, find the minimum and maximum values that can be calculated 
// by summing exactly four of the five integers. Then print the respective minimum and maximum 
// values as a single line of two space-separated long integers.
//https://www.hackerrank.com/challenges/one-month-preparation-kit-mini-max-sum/problem

#include <stdio.h>
#include <vector>
//первая пришедшая в голову реализация
void miniMaxSum(std::vector<int> arr) {
    long int min = arr[0];
    long int max = arr[0];
    long int minSum = 0;
    long int maxSum = 0;
    bool flagMin = false;
    bool flagMax = false;
    for (int i=1; i<arr.size(); i++){
        if (min>arr[i]){
            min = arr[i];
        }
        if (max<arr[i]){
            max = arr[i];
        }
    }
    for(int i = 0; i < arr.size(); i++){
        if (arr[i]!=max || flagMin == true){
            minSum+=arr[i];
        }else{
            flagMin = true;
        }
        if (arr[i]!=min || flagMax == true){
            maxSum+=arr[i];
        }else{
            flagMax = true;
        }
    }
    printf("%ld %ld", minSum, maxSum);
}
//более простое решение
void miniMaxSumv2(std::vector<int> arr) {
    long int min = arr[0];
    long int max = arr[0];
    long int sum = 0;
    for (int i=1; i<arr.size(); i++){
        if (min>arr[i]){
            min = arr[i];
        }
        if (max<arr[i]){
            max = arr[i];
        }
    }
    for(int i = 0; i < arr.size(); i++){
        sum+=arr[i];
    }
    printf("%ld %ld", sum-max, sum-min);
}


int main(){
    std::vector <int> example = {1, 2, 3, 4, 5};
    miniMaxSum(example);
    printf("\nВторой вариант\n");
    miniMaxSumv2(example);
    return 0;
}