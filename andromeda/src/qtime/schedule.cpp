#include "schedule.h"


qtime::Schedule::Schedule(QDate effectiveDate, const QDate& terminationDate, const Tenor<SMONTH>& tenor, const qtime::Calendar& calendar, BusinessDayConvention convention, BusinessDayConvention terminationDateConvention, DateGeneration::Rule rule, bool endOfMonth)
{
	generatedates();
}

qtime::Schedule::const_iterator qtime::Schedule::begin() const
{ 
	return dates_.begin(); 
}

qtime::Schedule::const_iterator qtime::Schedule::end() const
{
	return dates_.end();
}

qtime::Schedule qtime::Schedule::until(const QDate& truncationDate) const
{
	throw "not implemented";
}

void qtime::Schedule::generatedates()
{
	dates_.push_back(effectiveDate);

}
