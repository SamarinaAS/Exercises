//напишите метод для вывода последних k строк входного файла

#include <iostream>
#include <fstream>
//решение в лоб
void read_last_strings(std::string filename){
    std::string line;
    std::ifstream in(filename); // окрываем файл для чтения
    int n = 0;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            n++;
            //std::cout << line << std::endl;
        }
    }
    in.close();
    std::cout<<"Общее количество строк равно: "<< n << ". Введите количество последних k строк, которое вы хотите вывести:" << std::endl << "k = ";
    int k;
    std:: cin >> k;
         // закрываем файл
    in.open(filename);
    std::cout<<"Выводим "<<k<<" последних строк файла:"<<std::endl; 
    int i = 0;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (i>=n-k){
                std::cout << line << std::endl;
            }
            i++;
        }
    }
    in.close();  
}

int main(){
    //печатаем k последних строк файла
    int k = 3;
    read_last_strings("name.txt");
    return 0;
}
 
