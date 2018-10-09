#pragma once

#include "libdef.h"
#include "QDate.h"
#include <vector>
#include "DayCounter.h"
#include <memory>

namespace qtime
{   
    class EXPORT_SYMBOL DateSchedule
    {
    public:
        struct EXPORT_SYMBOL DatePeriod
        {   
            QDate ResetDate;
            QDate StartDate;
            QDate EndDate;
            QDate PaymentDate;

            friend std::ostream& operator << (std::ostream &ostrm, const DatePeriod &period);
        };

        enum class FREQ {W, M, Q, SA, A}; 
        enum class STUB {SS, LS};
        enum class BDayConvention {F, MF, P, MP, UNADJ};

        DateSchedule();
        friend std::ostream& operator << (std::ostream &ostrm, const DateSchedule& schedule);

    private:
        std::vector<DatePeriod> Schedule;
    };
    
    class EXPORT_SYMBOL QuickDateSchedule: public DateSchedule
    {
    public:
        QuickDateSchedule(const QDate& sd, const QDate& ed, FREQ f = FREQ::Q);

        friend std::ostream& operator << (std::ostream &ostrm, const QuickDateSchedule &schedule);
        DatePeriod& nextPeriod() const;
        DatePeriod& previousPeriod() const;

    private:
        QDate _sd;
        QDate _ed;
        FREQ _freq;
        STUB _stub;
        std::vector<DatePeriod> Schedule;
    };

    class EXPORT_SYMBOL FullDateSchedule: public DateSchedule
    {
    public:
        FullDateSchedule(   const QDate& startDate, 
                            const QDate& endDate, 
                            const std::unique_ptr<DayCounter> DCountConvention,
                            const unsigned int RESETGAP = 0, 
                            const unsigned int PAYGAP = 0,
                            const FREQ f = FREQ::Q,
                            const STUB s = STUB::SS, 
                            const BDayConvention c = BDayConvention::UNADJ);

        FullDateSchedule(   const std::vector<QDate> &resetDate,
                            const std::vector<QDate> &startDate, 
                            const std::vector<QDate> &endDate,
                            const std::vector<QDate> &payDate,
                            const std::unique_ptr<DayCounter> DCountConvention,
                            const unsigned int RESETGAP = 0, 
                            const unsigned int PAYGAP = 0,
                            const FREQ f = FREQ::Q,
                            const STUB s = STUB::SS, 
                            const BDayConvention c = BDayConvention::UNADJ);  

        DatePeriod& nextPeriod() const;
        DatePeriod& previousPeriod() const;

    private:
        QDate _sd;
        QDate _ed;
        FREQ _f;
        STUB _s;
        std::vector<DatePeriod> Schedule;
    };
    
}


