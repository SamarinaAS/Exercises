//7.2.Имеется центр обработки звонков с тремя уровнями сотрудников: оператор, менеджер и директор. 
//Входящий телефонный звонок адресуется свободному оператору. Если оператор не может обратать
//звонок, он автоматически перенаправляется менеджеру, если и тот занят, то директору. Разработайте
//классы и структуры данных для этой задачи. Реализуйте метод dispatchCall(), который перенаправляет
//звонок первому свободному сотруднику.
class CallCenterEmployee{
    public:
    bool free;
    CallCenterEmployee();
    CallCenterEmployee(bool free);
    isFree();
}

CallCenterEmployee::CallCenterEmployee(){true};
CallCenterEmployee::CallCenterEmployee(bool free){
    this->free = free;
};

class Operator : public CallCenterEmployee{
    Operator(){true};

}

class Manager : public CallCenterEmployee{
    Manager(){true};
}

class Director : public CallCenterEmployee{
    Director(){true};
}