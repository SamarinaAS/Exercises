//7.2.Имеется центр обработки звонков с тремя уровнями сотрудников: оператор, менеджер и директор. 
//Входящий телефонный звонок адресуется свободному оператору. Если оператор не может обратать
//звонок, он автоматически перенаправляется менеджеру, если и тот занят, то директору. Разработайте
//классы и структуры данных для этой задачи. Реализуйте метод dispatchCall(), который перенаправляет
//звонок первому свободному сотруднику.

#include <string>
class CallCenterEmployee{
    private:
    bool free;
    std::string firstName;
    std::string lastName;
    public:
    CallCenterEmployee(std::string firstName, std::string lastName, bool free);
    bool isFree();
};

CallCenterEmployee::CallCenterEmployee(std::string firstName, std::string lastName, bool free){
    this->firstName = firstName;
    this->lastName = lastName;
    this->free = free;
}

bool CallCenterEmployee::isFree(){
    return free;
}

class Operator : public CallCenterEmployee{
    private:
    int number;
    Operator(std::string firstName, std::string lastName, bool free, int number);

};

Operator::Operator(std::string firstName, std::string lastName, bool free, int number)
:CallCenterEmployee(firstName, lastName, free){
    this->number = number;
}

// class Manager : public CallCenterEmployee{
//     Manager(){true};
// }

// class Director : public CallCenterEmployee{
//     Director(){true};
// }


int main (){
    return 0;
}