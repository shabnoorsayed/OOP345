#pragma once

#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** c_res = nullptr;
		int c_cnt = 0;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		int size() const;
		ConfirmationSender(ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator << (ostream& os, const ConfirmationSender& res);
	};
}
