#pragma once
#include "CalendarCommons.h"
#include "DateSchedule.h"

namespace qtime
{
  
    int monthInt(MONTH Month);
    int daysInMonth(MONTH Month, bool LeapYear);
    int daysInMonth(int Month, bool LeapYear);
    QDate addFREQ(const QDate& sd, DateSchedule::FREQ f);
    QDate minusFREQ(const QDate& sd, DateSchedule::FREQ f);

}