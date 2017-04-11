#include <iostream>
#include <string>
#include <array>

class Date
{
  public:
    Date(void);
    bool isValid(void);
    int day, month, year;
    int daysPassed(Date &to);

  private:
    int dayCount, weekCount, secondsCount;
    std::array<int, 12> calendar;
    bool isLeap(int y);
    int daysInMonth(int m, int y);
};

int main()
{
    Date from, to;

    std::cout << "From: ";
    std::cin >> from.day >> from.month >> from.year;
    std::cout << "To: ";
    std::cin >> to.day >> to.month >> to.year;

    if (!from.isValid() || !to.isValid())
    {
        std::cout << "Illegal Date!\n";
        return 1;
    }

    if (from.year > to.year)
    {
        std::cout << "Range error!\n";
        return 1;
    }
    
    int dayCount = from.daysPassed(to);

    std::cout << "\nYou Survived for: \n";
    std::cout << dayCount << " days\n";
    std::cout << dayCount / 7 << " weeks and " << dayCount % 7 << " day\n";
}

Date::Date(void)
{
    day = 1;
    month = 1;
    year = 1900;
    calendar = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    dayCount = weekCount = secondsCount = 0;
}

bool Date::isValid(void)
{
    return ((day <= 31 && day >= 1) && (month <= 12 && month >= 1) && (year >= 1900 && year <= 2100));
}

int Date::daysPassed(Date &to)
{
    for (int i = year + 1; i < to.year; ++i)
    {
        if(isLeap(i))
            dayCount += 366;
        else
            dayCount += 365;
    }

    if(year == to.year)
    {
        for(int i = month - 1; i < to.month; ++i)
        {
            dayCount += daysInMonth(i, year);
        }

        dayCount = dayCount - day - (daysInMonth(month - 1, year) - to.day);
        return dayCount;
    }

    for (int i = month - 1; i < 12; ++i)
        dayCount += calendar[i];

    for (int i = 0; i < to.month - 1; ++i)
        dayCount += calendar[i];

    dayCount -= day;
    dayCount += to.day;

    return dayCount;
}

bool Date::isLeap(int y)
{
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int Date::daysInMonth(int m, int y)
{
    if(m == 1)
        return calendar[y] + isLeap(y);
    
    return calendar[m];
}
