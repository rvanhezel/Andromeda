#include "CalendarHelper.h"
#include <vector>
#include <iostream>

namespace qtime
{
  
    int monthInt(MONTH Month)
    {
        switch(Month)
        {
            case(MONTH::JAN):
            return 1;
            break;
            case(MONTH::FEB):
            return 2;
            break;  
            case(MONTH::MAR):
            return 3;
            break;  
            case(MONTH::APR):
            return 4;
            break;  
            case(MONTH::MAY):
            return 5;
            break;  
            case(MONTH::JUN):
            return 6;
            break;  
            case(MONTH::JUL):
            return 7;
            break;   
            case(MONTH::AUG):
            return 8;
            break;  
            case(MONTH::SEP):
            return 9;
            break;  
            case(MONTH::OCT):
            return 10;
            break;  
            case(MONTH::NOV):
            return 11;
            break;  
            case(MONTH::DEC):
            return 12;
            break;
            default:
                throw "Bizarre case";
        }
    }

    int daysInMonth(MONTH Month, bool LeapYear)
    {
        std::vector<int> MonthDays {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        std::vector<int> MonthDaysLeap {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (LeapYear ? MonthDaysLeap[monthInt(Month) - 1] :  MonthDays[monthInt(Month) - 1]);
    }

    int daysInMonth(int Month, bool LeapYear)
    {
        std::vector<int> MonthDays {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        std::vector<int> MonthDaysLeap {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (LeapYear ? MonthDaysLeap[Month - 1] :  MonthDays[Month - 1]);
    }

    QDate addFREQ(const QDate& sd, DateSchedule::FREQ freq)
    {
        QDate newDate(sd);

        switch(freq)
        {
            case(DateSchedule::FREQ::W):
            newDate = newDate + 7;
            break;
            case(DateSchedule::FREQ::M):
            {
                auto currentDay(sd.DayOfTheMonth());
                auto currentMonth(monthInt(sd.Month()));
                auto currentYear(sd.Year());

                currentMonth++;
                if (currentMonth > 12)
                {
                    currentMonth = 1;
                    currentYear++;
                }

                if(sd.DayOfTheMonth() > daysInMonth(currentMonth, sd.isLeapYear(sd.Year())))
                {
                    currentDay = daysInMonth(currentMonth, sd.isLeapYear(sd.Year()));
                }

                newDate = QDate(currentDay, currentMonth, currentYear);

            break;
            }
            case(DateSchedule::FREQ::Q):
            break;
            case(DateSchedule::FREQ::SA):
            break;
            case(DateSchedule::FREQ::A):
            break;
            default:
                throw "Shouldn't be here";

        }

        return newDate;
    }

    QDate minusFREQ(const QDate& sd, DateSchedule::FREQ freq)
    {
        QDate newDate(sd);

        switch(freq)
        {
            case(DateSchedule::FREQ::W):
            newDate = newDate - 7;
            break;
            case(DateSchedule::FREQ::M):
            {
                auto currentDay(sd.DayOfTheMonth());
                auto currentMonth(monthInt(sd.Month()));
                auto currentYear(sd.Year());

                currentMonth--;
                if (currentMonth == 0)
                {
                    currentMonth = 12;
                    currentYear--;
                }

                if(sd.DayOfTheMonth() > daysInMonth(currentMonth, sd.isLeapYear(sd.Year())))
                {
                    currentDay = daysInMonth(currentMonth, sd.isLeapYear(sd.Year()));
                }

                newDate = QDate(currentDay, currentMonth, currentYear);

            break;
            }
            case(DateSchedule::FREQ::Q):
            break;
            case(DateSchedule::FREQ::SA):
            break;
            case(DateSchedule::FREQ::A):
            break;
            default:
                throw "Shouldn't be here";

        }

        return newDate;
    }


}