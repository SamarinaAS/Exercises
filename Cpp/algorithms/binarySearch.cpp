#include <vector>
#include <iostream>
int binarySearch (std::vector<int> sortedArray, int number){
    int left = 0;
    int right = sortedArray.size()-1;
    while (left <= right){
        int middle = (left+right)/2+1;
        if (number == sortedArray[middle]){
            return middle;
        }else if (number < sortedArray[middle]){
            right = middle;
        }else{
            left = middle;
        }
    }
    return -1;
}

int main(){
    std::vector <int> arr = {1,2,3};
    std::cout<<binarySearch(arr, 3)<<std::endl;
    std::cout<<binarySearch(arr, 4)<<std::endl;;

}