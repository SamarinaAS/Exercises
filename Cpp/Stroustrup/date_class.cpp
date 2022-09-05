class Date
{
    private:
    int day, month, year;
    enum months {jan = 1, feb, mar, aip, may, jun, jul, aug, sep, oct, nov, dec};
    public:
    Date(int day, int month, int year);
    static bool isYearLeap(int year);
    void addYear(int n);
    void addMonth(int n);
    // void addDay(int n);   
};

Date::Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    };
bool Date::isYearLeap(int year){
        if ((year)%400==0 || year%4==0 && year%100!=0){
            return true;
        }
        return false;
    }
void Date::addYear(int n){
        if (month == months::feb && !isYearLeap(year+n)){
            day = 28;
        }
        year += n;
    };
void Date::addMonth(int n){
        year+=(month+n)/12;
        month =(month+n)%12;
        if(day>28){
            if(month == months::feb && !isYearLeap(year)){
                day = 28;
            }else if (day == 31){
                if (month == months::aip||month == months::jun || month == months::sep || month == months::nov){
                    day = 30;
                }
            }
        }
    };
    // void Date::addDay(int n){

    // };

int main (){
    Date *my = new Date(29, 2, 2024);
    my->addYear(5);
    Date *my1 = new Date(31, 3, 2024);
    my1->addMonth(1);
    my1->addMonth(10);
    return 0;
}

