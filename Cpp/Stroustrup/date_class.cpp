#include <stdio.h>
#include <string>
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
    void setYear(unsigned year) ;
    void setMonth(unsigned month);
    void setDay(unsigned day);
    unsigned getYear() const;
    unsigned getMonth() const;
    unsigned getDay() const;    
    void addYear(unsigned n);
    void addMonth(unsigned n);
    // void addDay(unsigned n);
    void printDate() const;
    
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
    || !(month >= months::jan && month <= months::dec) || day == 0 || day > 31 || year == 0 || year > 9999){
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

unsigned Date::getDay() const {
    return day;
}

unsigned Date::getYear() const{
    return year;
}

unsigned Date::getMonth() const{
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

void Date::printDate() const{
    std::string strDay = std::to_string(day);
    std::string strMohth = std::to_string(month);
    std::string strYear = std::to_string(year);
    if (strDay.length()==1){
        strDay="0" + strDay;
    }
    if (strMohth.length()==1){
        strMohth="0" + strMohth;
    }
    if (strYear.length()<4){
        std::string zeros(4-strYear.length(), '0');
        strYear= zeros+ strYear;
    }
    printf("%s.%s.%s", strDay.c_str(), strMohth.c_str(), strYear.c_str());
}
// void Date::addDay(unsigned n){
//     while(){

//     }
//     year+=(day+n)/
// };

std::ostream& operator<<(std::ostream &os, const Date& date) {
    std::string strDay = std::to_string(date.getDay());
    std::string strMohth = std::to_string(date.getMonth());
    std::string strYear = std::to_string(date.getYear());
    if (strDay.length()==1){
        strDay="0" + strDay;
    }
    if (strMohth.length()==1){
        strMohth="0" + strMohth;
    }
    if (strYear.length()<4){
        std::string zeros(4-strYear.length(), '0');
        strYear= zeros+ strYear;
    }
    return os << strDay << "." << strMohth
        << "." << strYear;
}

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
    printf("day: %u, month: %u, year: %u\n",my1->getDay(), my1->getMonth(), my1->getYear());
    my1->printDate();
    std::cout<<std::endl;
    std::cout<<*my1<<std::endl;
    try{
        //Date *my2 = new Date(32, 3, 2024);
        my1->setMonth(13);
    }catch (...){
        printf("\nEntered incorrect date\n");
    }
    return 0;
}
