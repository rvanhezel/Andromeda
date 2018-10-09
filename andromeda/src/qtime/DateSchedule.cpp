#include "DateSchedule.h"
#include "CalendarHelper.h"

namespace qtime
{
    std::ostream& operator << (std::ostream &ostrm, const DateSchedule::DatePeriod &period)
    {
        ostrm << period.ResetDate  << " | " << period.StartDate << " | " <<
                            period.EndDate << " | " << period.PaymentDate;

        return ostrm;
    }

    DateSchedule::DateSchedule(){};

    std::ostream& operator << (std::ostream &ostrm, const DateSchedule& schedule)
    {
        std::cout << "Reset Date  |  Start Date  |  End Date  |  Pay Date" << std::endl;
        for(const auto& it: schedule.Schedule)
        {      
            ostrm << it << std::endl;
        }

        return ostrm;
    }

    std::ostream& operator << (std::ostream &ostrm, const QuickDateSchedule &schedule)
    {
        std::cout << "Reset Date  |  Start Date  |  End Date  |  Pay Date" << std::endl;
        for(const auto& it: schedule.Schedule)
        {      
            ostrm << it << std::endl;
        }

        return ostrm;
    }

    QuickDateSchedule::QuickDateSchedule(const QDate& sd, const QDate& ed, FREQ f) :
        _sd(sd), _ed(ed), _freq(f)
    {
        _stub = STUB::SS;
        int FREQLength = 0;
        int stublength = 0;  

        switch(_freq)
        {
            case(FREQ::M):
                FREQLength = 31;
                stublength = (ed - sd) % FREQLength;
                break; 
            case(FREQ::Q):
                FREQLength = 31*3;
                stublength = (ed - sd) % FREQLength;
                break;
            case(FREQ::SA):
                FREQLength = 182;
                stublength = (ed - sd) % FREQLength;
                break;
            case(FREQ::A):
                FREQLength = 365;
                stublength = (ed - sd) % FREQLength;
                break;
            default:
                throw "Frequency not recognised";
        }

        //first period
        QDate latestSD(_sd);
        QDate latestED(latestSD + stublength);

        while(latestED <= _ed)
        {
            DatePeriod _tmpPeriod {latestSD, latestSD, latestED, latestED};
            Schedule.push_back(_tmpPeriod);
            latestSD = latestED;
            latestED = latestED + FREQLength;
        }

    }

    



}