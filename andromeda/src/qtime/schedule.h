#pragma once
#include "QDate.h"
#include "tenor.h"
#include "dategeneration.h"
#include <vector>

namespace qtime
{
	class BusinessDayConvention;
	class Calendar;

	class Schedule
	{
	public:
		Schedule(
			QDate effectiveDate,
			const QDate& terminationDate,
			const Tenor<SMONTH> & tenor,
			const qtime::Calendar& calendar,
			const BusinessDayConvention* convention,
			const BusinessDayConvention* terminationDateConvention,
			DateGeneration::Rule rule,
			bool endOfMonth);

		typedef std::vector<QDate>::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;			
		Schedule until(const QDate& truncationDate) const;

	private:
		std::vector<QDate> dates_;
		const QDate effectiveDate;
		const QDate terminationDate;
		const Tenor<SMONTH> & tenor;
		const qtime::Calendar* calendar;
		const qtime::BusinessDayConvention* convention;
		const qtime::BusinessDayConvention* terminationDateConvention;
		const DateGeneration::Rule rule;		
		void generatedates();
	};
}
