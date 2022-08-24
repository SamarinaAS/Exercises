//реализуйте функцию void reverse (char* str) для перестановки символов строки, завершенной
//нуль-символом, в обратном порядке
#include <iostream>
#include <string.h>
void reverse (char* str){
    if (!str){
        std::cout<<"Пустой указатель"<<std::endl;
        return;
    }
    if (strlen(str)==0){
        std::cout<<"Строка пуста"<<std::endl;
        return;
    }
    char *end = str;
    while(*end){
        end++;
    }
    end--;
    while(end > str){
        std::swap(*str, *end);
        str++;
        end--;
    }
}


int main(){
    char* str = new char[5];
    std::string str1 = "abcd";
    strcpy(str, str1.c_str());
    std::cout<<"Исходная строка: "<<str<<std::endl;
    reverse(str);
    std::cout<<"Перевернутая строка: "<<str<<std::endl;
    str = nullptr;
    std::cout<<"Исходная строка: "<<"nullptr"<<std::endl;
    reverse(str);
    str = "";
    std::cout<<"Исходная строка: "<<str<<std::endl;
    reverse(str);
}
