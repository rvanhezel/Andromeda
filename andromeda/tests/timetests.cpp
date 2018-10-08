
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE differenciationTest
#include <cmath>
#include <boost/test/included/unit_test.hpp> // this work

#include <iostream>
#include <memory>
#include "../src/qtime/tenor.h"
#include "../src/yield/YieldCurve.h"
#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>

using namespace qtime;
using namespace literals;

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_CASE(DERIVATIVES)
{
	std::cout << "Testing qtime " << std::endl;

	Tenor<SMONTH> tmonth = 1.0_years;
	Tenor<SWEEK> tweek = 1.0_months; 
	yield::YieldCurveBuilder ybuilder(qtime::QDate(01,01,2018));
	std::unique_ptr<qtime::DayCounter> dc(new qtime::Actual365fixed());
	qtime::QDate T0(01, 01, 2018);
	instrument::CashFlow flow1(T0, 3.0_months,1e6);
	instrument::CashFlow flow2(T0, 6.0_months, 1e6);
	
	auto libor1m = new instrument::xIbor(T0,0.01, 1.0_months);
	auto libor3m = new instrument::xIbor(T0, 0.015, 3.0_months);
	auto libor6m = new instrument::xIbor(T0, 0.019, 6.0_months);
	auto libor9m = new instrument::xIbor(T0, 0.0197, 9.0_months);
	auto libor12m = new instrument::xIbor(T0, 0.02, 12.0_months);
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
	}

	auto f11y = oyield->forward(T0 + 365, qtime::Tenor<SDAY>(365));
	auto f16m = oyield->forward(T0 + 365, qtime::Tenor<SDAY>(30 * 6));
	auto f13m = oyield->forward(T0 + 365, qtime::Tenor<SDAY>(30 * 3));
	auto f11d = oyield->forward(T0 + 365, qtime::Tenor<SDAY>(1));
	auto d1 = oyield->discount(1.0_years);
	auto zz = 1 / (1 + f11d * to_years(Tenor<SDAY>(1)));
	
}
