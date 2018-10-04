
#include <iostream>
#include <memory>
#include "../src/qtime/tenor.h"
//#include "../src/yield/YieldCurve.h"
#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>

using namespace qtime;
using namespace literals;

int main(int argc, char* args[])
{
	std::cout << "Hello Andromeda" << std::endl;
	/*yield::YieldCurveBuilder ybuilder(qtime::QDate(01,01,2018));
	std::unique_ptr<qtime::DayCounter> dc(new qtime::Thirty360(qtime::Thirty360::CONVENTION::BONDBASIS,true));
	
	instrument::CashFlow flow1(QDate(1, 01, 2018), 3.0_months,1e6);
	instrument::CashFlow flow2(QDate(1, 01, 2018), 6.0_months, 1e6);

	auto libor1m = new instrument::xIbor(qtime::QDate(01, 01, 2018),0.01, 1.0_months);
	auto libor3m = new instrument::xIbor(qtime::QDate(01, 01, 2018), 0.015, 3.0_months);
	auto libor6m = new instrument::xIbor(qtime::QDate(01, 01, 2018), 0.019, 6.0_months);
	auto libor9m = new instrument::xIbor(qtime::QDate(01, 01, 2018), 0.0197, 9.0_months);
	auto libor12m = new instrument::xIbor(qtime::QDate(01, 01, 2018), 0.02, 12.0_months);
	auto swap1 = new instrument::Swap(qtime::QDate(01, 01, 2020),0.04,flow1,flow2);
	auto swap3 = new instrument::Swap(qtime::QDate(01, 01, 2021), 0.05, flow1, flow2);
	auto swap5 = new instrument::Swap(qtime::QDate(01, 01, 2023), 0.06, flow1, flow2);
	auto swap10 = new instrument::Swap(qtime::QDate(01, 01, 2028), 0.1, flow1, flow2);
	yield::YieldCurve* oyield = ybuilder.withDayCount(std::move(dc))
									  .withInstrument(swap1)
									  .withInstrument(swap3).withInstrument(swap5).withInstrument(swap10).withInstrument(libor1m).withInstrument(libor3m)
									  .withInstrument(libor6m).withInstrument(libor9m).withInstrument(libor12m)
									  .Build();

	oyield->boostrap();

	int N = 10;
	for(auto n: boost::irange(0,N,1))
	{
		double t = 10.0 * n / double(N);
		std::cout << "t="<<t<<" r=" << oyield->rate(Tenor<SYEAR>(t)) << std::endl;
	}*/
	return 0;
}
