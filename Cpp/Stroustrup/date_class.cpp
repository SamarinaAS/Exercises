#include <iostream>
class Date
{
private:
    unsigned day, month, year;
    enum months
    {
        jan = 1,
        feb,
        mar,
        aip,
        may,
        jun,
        jul,
        aug,
        sep,
        oct,
        nov,
        dec
    };
    void isDateCorrect(unsigned day, unsigned month, unsigned year);

public:
    Date(unsigned day, unsigned month, unsigned year);
    static bool isYearLeap(unsigned year);
    void setYear(unsigned year);
    void setMonth(unsigned month);
    void setDay(unsigned day);
    unsigned getYear();
    unsigned getMonth();
    unsigned getDay();    
    void addYear(unsigned n);
    void addMonth(unsigned n);
    // void addDay(unsigned n);
};

Date::Date(unsigned day, unsigned month, unsigned year)
{
    isDateCorrect(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
};
void Date::isDateCorrect(unsigned day, unsigned month, unsigned year)
{
    if (month == months::feb && (day == 29 && !isYearLeap(year) || day > 29) 
    || (month == months::aip || month == months::jun || month == months::sep || month == months::nov) && day == 31
    || !(month >= months::jan && month <= months::dec) || day == 0 || day > 31 || year == 0){
        throw "Incorrect date";
    }
}

void Date::setYear(unsigned year){
    isDateCorrect(day, month, year);
    this->year = year;
}

void Date::setMonth(unsigned month){
    isDateCorrect(day, month, year);
    this->month = month;
}

unsigned Date::getDay(){
    return day;
}

unsigned Date::getYear(){
    return year;
}

unsigned Date::getMonth(){
    return month;
}

void Date::setDay(unsigned day){
    isDateCorrect(day, month, year);
    this->day = day;
}

bool Date::isYearLeap(unsigned year)
{
    if ((year) % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    return false;
}
void Date::addYear(unsigned n)
{
    if (month == months::feb && !isYearLeap(year + n))
    {
        day = 28;
    }
    year += n;
};
void Date::addMonth(unsigned n)
{
    year += (month + n) / 12;
    month = (month + n) % 12;
    if (day > 28)
    {
        if (month == months::feb && !isYearLeap(year))
        {
            day = 28;
        }
        else if (day == 31)
        {
            if (month == months::aip || month == months::jun || month == months::sep || month == months::nov)
            {
                day = 30;
            }
        }
    }
};
// void Date::addDay(unsigned n){
//     while(){

//     }
//     year+=(day+n)/
// };

int main()
{
    Date *my = new Date(29, 2, 2024);
    my->addYear(5);
    Date *my1 = new Date(31, 3, 2024);
    my1->addMonth(1);
    my1->addMonth(10);
    my1->setDay(20);
    my1->setMonth(8);
    my1->setYear(2019);
    std::cout<<"day: "<<my1->getDay()<<", month: "<<my1->getMonth()<<", year: "<<my1->getYear()<<std::endl;
    try{
        //Date *my2 = new Date(32, 3, 2024);
        my1->setMonth(13);
    }catch (...){
        std::cout<<"Entered incorrect date"<<std::endl;
    }
    return 0;
}
