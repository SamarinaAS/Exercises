//напишите метод для вывода последних k строк входного файла
//подавать файл в строку при вызове программы?
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
    int k;
    std::cout<<"Общее количество строк в файле равно: "<< n << ". Введите количество последних k строк, которое вы хотите вывести:" << std::endl << "k = ";
    std:: cin >> k;
    while (k > n){
        std::cout<<"Общее количество строк в файле меньше "<<k<<", оно равно "<<n<<". Введите k, меньшее или равное количеству строк в файле: "<<std::endl<<"k = ";
        std:: cin >> k;
    }
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

int main(int argc, char* argv[]){
    //печатаем k последних строк файла
    if (argc < 2){
       std::cout<<"Название файла не введено"<<std::endl;
       return 0;
    }
    int k = 3;
    read_last_strings(argv[1]);
    return 0;
}
 
