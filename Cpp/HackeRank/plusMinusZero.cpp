// Given an array of integers, calculate the ratios of its elements that are 
// positive, negative, and zero. 
// Print the decimal value of each fraction on a new line with 6 places after the decimal.
//https://www.hackerrank.com/challenges/one-month-preparation-kit-plus-minus/problem

#include <stdio.h>
#include <vector>

void plusMinus(std::vector<int> arr) {
    int positive = 0;
    int negative = 0;
    int zero = 0;
    for(int i=0; i < arr.size(); i++){
        if (arr[i]>0){
            positive++;
        }else if (arr[i]<0){
            negative++;
        }else{
            zero++;
        }
    }
    printf("%.6g\n%.6g\n%.6g\n", double(positive)/arr.size(), double(negative)/arr.size(), double(zero)/arr.size());
}

int main(){
    std::vector <int> example = {-4, 3, -9, 0, 4, 1};
    plusMinus(example);
}