#pragma once
namespace qtime
{
	struct DateGeneration {
		enum Rule {
			Backward,       /*!< Backward from termination date to
								 effective date. */
			Forward,        /*!< Forward from effective date to
								 termination date. */
			Zero,           /*!< No intermediate dates between effective date
								 and termination date. */
			EndOfMonth           /*!< No intermediate dates between effective date
								 and termination date. */

		};
	};
}
