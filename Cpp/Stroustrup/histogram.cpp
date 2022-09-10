//в конструктор вектор интервалов нужно подавать в отсортированном порядке - иначе
//вызовется исключение

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <iostream>

class Histogram{
    private:
    std::vector <int> data;
    std::vector <int> intervals;
    std::map<std::string, int> histogramMap;
    public:
    Histogram(std::vector <int> data, std::vector <int> intervals);
    void printHistogram () const;
};

Histogram::Histogram(std::vector <int> data, std::vector <int> intervals){
    if (data.size()==0 || intervals.size()==0){
        throw "Empty data or intervals";
    }
    std::vector <int> copyData = data;
    sort (copyData.begin(), copyData.end());
    if (copyData != data){
        throw "Wrong sequence of interval boundaries";
    }
    for(int i=0; i<intervals.size()-1; i++){
        int left = intervals[i];
        int right = intervals[i+1];
        if (right<left-1){
            throw "Incorrect interval boundary";
        }
        
        std::string strInterval = "[" + std::to_string(left) + ", " + std::to_string(right-1) + "]";
        histogramMap[strInterval]= 0;
        for (int i = 0; i<data.size(); i++){
            if (data[i]>=left && data[i]<right){
                histogramMap[strInterval]++;
            }
        }
    }
    this->data = data;
    this->intervals = intervals;
}

void Histogram::printHistogram() const{
    std::map <std::string, int> :: const_iterator it = histogramMap.begin();
    for (; it != histogramMap.end(); it++) {
        std::cout<<it->first<<": "<<it->second<<std::endl;
    }
 }

int main(){
    std::vector <int> data = {2, 1, 3, 4, 5, 6};
    std::vector <int> intervals = {1, 3, 6};
    Histogram* hist = new Histogram(data, intervals);
    hist->printHistogram();
    int i =0;
    return 0;
}
