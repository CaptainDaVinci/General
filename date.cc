#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <array>

class Date_Range_Calculator
{
  public:
    Date_Range_Calculator(void);
    void setFromDate(int day, int month, int year);
    void setToDate(int day, int month, int year);
    int daysPassed(void);

  private:
    struct Date
    {
        int day, month, year;
    } from, to;

    int dayCount;
    std::array<int, 12> calendar;

    bool isLeap(int y);
    int daysInMonth(int m, int y);
};

void getDate(Date_Range_Calculator &date);
bool isValid(int day, int month, int year);

int main()
{
    Date_Range_Calculator date;
    getDate(date);

    int dayCount = date.daysPassed();

    std::cout << "\nYou Survived for: \n";
    std::cout << dayCount << " days\n";
    std::cout << dayCount / 7 << " weeks and " << dayCount % 7 << " day\n";
}

void getDate(Date_Range_Calculator &date)
{
    std::string dateString;
    int day, month, year;
    char ch;

    std::cout << "From: ";
    getline(std::cin, dateString);

    {
        std::istringstream parser(dateString);
        parser >> day >> ch >> month >> ch >> year;
    }

    if (!isValid(day, month, year))
    {
        std::cout << "Illegal Date!\n";
        exit(EXIT_FAILURE);
    }
    std::cout << day << ' ' << month << ' ' << year << '\n';
    date.setFromDate(day, month, year);

    std::cout << "To: ";
    getline(std::cin, dateString);
    
    {
        std::istringstream parser(dateString);
        parser >> day >> ch >> month >> ch >> year;
    }

    if (!isValid(day, month, year))
    {
        std::cout << "Illegal Date!\n";
        exit(EXIT_FAILURE);
    }

    date.setToDate(day, month, year);
}

bool isValid(int day, int month, int year)
{
    return ((day <= 31 && day >= 1) && (month <= 12 && month >= 1) && (year >= 1900 && year <= 2100));
}

void Date_Range_Calculator::setToDate(int day, int month, int year)
{
    to.day = day;
    to.month = month;
    to.year = year;
}

void Date_Range_Calculator::setFromDate(int day, int month, int year)
{
    from.day = day;
    from.month = month;
    from.year = year;
}

Date_Range_Calculator::Date_Range_Calculator(void)
{
    from.day = to.day = 1;
    from.month = to.month = 1;
    from.year = to.year = 1900;
    calendar = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    dayCount = 0;
}

int Date_Range_Calculator::daysPassed(void)
{
    for (int i = from.year + 1; i < to.year; ++i)
    {
        if (isLeap(i))
            dayCount += 366;
        else
            dayCount += 365;
    }

    if (from.year == to.year)
    {
        for (int i = from.month - 1; i < to.month; ++i)
        {
            dayCount += daysInMonth(i, from.year);
        }

        dayCount = dayCount - from.day - (daysInMonth(to.month - 1, from.year) - to.day);
        return dayCount;
    }

    for (int i = from.month - 1; i < 12; ++i)
        dayCount += calendar[i];

    for (int i = 0; i < to.month - 1; ++i)
        dayCount += calendar[i];

    dayCount = dayCount + to.day - from.day;
    // dayCount = dayCount + to.day;

    return dayCount;
}

bool Date_Range_Calculator::isLeap(int y)
{
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int Date_Range_Calculator::daysInMonth(int m, int y)
{
    if (m == 1)
        return calendar[y] + isLeap(y);

    return calendar[m];
}
